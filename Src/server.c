/*socket tcp服务器端*/
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SERVER_PORT 8808
#define SEND "SEND"
#define RECEIVE "RECV"
#define CONN "CONN"
#define QUIT "QUIT"
#define DELETE "DELE"
#define HAVESENT "SENT"
#define IMPORTANT "IMPO"
#define BIN "BINR"
#define READALL "READ"
#define RECOVER "RECO"
#define DRAFT "DRAF"
#define DISPLAY "DISP"

#define HOST "localhost"
#define USER_NAME "root"
#define PASSWD "123456"
#define DATABASE "server"
#define PORT 3306

struct st_mail
{
    char operation[4];
    char frid[16];
    char toid[16];
    char title[64];
    char datetime[32];
    char content[892];
};

struct st_mail_list
{
    int sum;
    struct st_mail list[10];
};

/*
 监听后，一直处于accept阻塞状态，
 直到有客户端连接，
 当客户端如数quit后，断开与客户端的连接
 */

int main()
{
    //调用socket函数返回的文件描述符
    int serverSocket;
    //声明两个套接字sockaddr_in结构体变量，分别表示客户端和服务器
    struct sockaddr_in server_addr;
    struct sockaddr_in clientAddr;
    int addr_len = sizeof(clientAddr);
    int client;
    char buffer[1024];
    int iDataNum;
    char msg[64] = "This is server!\n";
    struct st_mail mail;
    struct st_mail_list lcx;
    MYSQL *conn_ptr;
    MYSQL_RES *res_ptr;
    MYSQL_ROW sqlrow;
    int res;
    char sql[1024];
    char type;
    unsigned long rows;
    int cols;
    int i;
    int j;
    int id;

    //socket函数，失败返回-1
    //int socket(int domain, int type, int protocol);
    //第一个参数表示使用的地址类型，一般都是ipv4，AF_INET
    //第二个参数表示套接字类型：tcp：面向连接的稳定数据传输SOCK_STREAM
    //第三个参数设置为0
    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket");
        return 1;
    }

    bzero(&server_addr, sizeof(server_addr));
    //初始化服务器端的套接字，并用htons和htonl将端口和地址转成网络字节序
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    //ip可是是本服务器的ip，也可以用宏INADDR_ANY代替，代表0.0.0.0，表明所有地址
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    //对于bind，accept之类的函数，里面套接字参数都是需要强制转换成(struct sockaddr *)
    //bind三个参数：服务器端的套接字的文件描述符，
    if (bind(serverSocket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("connect");
        return 1;
    }
    //设置服务器上的socket为监听状态
    if (listen(serverSocket, 5) < 0)
    {
        perror("listen");
        return 1;
    }

    while (1)
    {
        printf("Listening on port: %d\n", SERVER_PORT);
        //调用accept函数后，会进入阻塞状态
        //accept返回一个套接字的文件描述符，这样服务器端便有两个套接字的文件描述符，
        //serverSocket和client。
        //serverSocket仍然继续在监听状态，client则负责接收和发送数据
        //clientAddr是一个传出参数，accept返回时，传出客户端的地址和端口号
        //addr_len是一个传入-传出参数，传入的是调用者提供的缓冲区的clientAddr的长度，以避免缓冲区溢出。
        //传出的是客户端地址结构体的实际长度。
        //出错返回-1
        client = accept(serverSocket, (struct sockaddr *)&clientAddr, (socklen_t *)&addr_len);
        if (client < 0)
        {
            perror("accept");
            continue;
        }
        if (!fork())
        {
            //printf("\nrecv client data...n");
            //inet_ntoa ip地址转换函数，将网络字节序IP转换为点分十进制IP
            //表达式：char *inet_ntoa (struct in_addr);
            //printf("IP is %s\n", inet_ntoa(clientAddr.sin_addr));
            printf("Port is %d\n", htons(clientAddr.sin_port));
            memset(buffer, 0, 1024);
            iDataNum = recv(client, buffer, 1024, 0);
            if (iDataNum < 0)
            {
                perror("recv");
                continue;
            }
            //printf("%drecv data is %s\n", iDataNum, buffer);
            if (strncmp(buffer, QUIT, 4) == 0)
            {
                close(client);
            }
            else if (strncmp(buffer, SEND, 4) == 0)
            {
                printf("Client send new mail.\n");
                memset(&mail, 0, 1024);
                memcpy(&mail, buffer, 1024);
                printf("SEND\n");
                printf("%s\n", mail.frid);
                printf("%s\n", mail.toid);
                printf("%s\n", mail.title);
                printf("%s\n", mail.content);
                printf("%s\n", mail.datetime);

                conn_ptr = mysql_init(NULL);
                if (!conn_ptr)
                {
                    printf("mysql_init failed\n");
                    return EXIT_FAILURE;
                }
                conn_ptr = mysql_real_connect(conn_ptr, HOST, USER_NAME, PASSWD, DATABASE, PORT, NULL, 0);
                if (conn_ptr)
                {
                    printf("Datebase connect OK\n");
                    memset(sql, 0, 1024);

                    sprintf(sql, "insert into posts (fr_name, to_name, theme, content, status, al_read, important, date) values ('%s', '%s', '%s', '%s', 'sended', 'no', 'no', '%s');", mail.frid, mail.toid, mail.title, mail.content, mail.datetime);
                    printf("%s\n", sql);
                    res = mysql_query(conn_ptr, sql); //可以把insert语句替换成delete或者update语句，都一样的
                    if (!res)
                    { //输出受影响的行数
                        printf("Inserted %lu rows\n", (unsigned long)mysql_affected_rows(conn_ptr));
                    }
                    else
                    { //打印出错误代码及详细信息
                        fprintf(stderr, "Insert error %d: %sn", mysql_errno(conn_ptr), mysql_error(conn_ptr));
                    }
                }
                else
                {
                    printf("Connection failed\n");
                }
                mysql_close(conn_ptr);
                send(client, "Mail send ok!", strlen("Mail send ok!"), 0);
            }
            else if (strncmp(buffer, RECEIVE, 4) == 0)
            {
                printf("Client send new mail.\n");
                memset(&mail, 0, 1024);
                memcpy(&mail, buffer, 1024);
                printf("RECEIVE\n");
                printf("%s\n", mail.toid);

                memset(&lcx, 0, sizeof(struct st_mail_list));

                conn_ptr = mysql_init(NULL);
                if (!conn_ptr)
                {
                    printf("mysql_init failed\n");
                    return EXIT_FAILURE;
                }
                conn_ptr = mysql_real_connect(conn_ptr, HOST, USER_NAME, PASSWD, DATABASE, PORT, NULL, 0);
                if (conn_ptr)
                {
                    printf("Datebase connect OK\n");
                    memset(sql, 0, 1024);

                    sprintf(sql, "select fr_name, to_name, theme, content, date from posts where to_name = '%s' and status = 'sended' ;", mail.toid);
                    printf("%s\n", sql);
                    res = mysql_query(conn_ptr, sql); //查询语句
                    if (!res)
                    {
                        res_ptr = mysql_store_result(conn_ptr); //取出结果集
                        if (res_ptr)
                        {
                            rows = (unsigned long)mysql_num_rows(res_ptr);
                            printf("SELECT %lu Rows\n", rows);
                            lcx.sum = rows;
                            printf("%d\n", lcx.sum);
                            cols = mysql_num_fields(res_ptr); //列数
                            printf("%d Cols\n", cols);
                            j = 0;
                            while ((sqlrow = mysql_fetch_row(res_ptr)))
                            { //依次取出记录
                                for (i = 0; i < cols; i++)
                                {
                                    printf("%s\t", sqlrow[i]); //输出
                                }
                                printf("\n");
                                strncpy(lcx.list[j].frid, sqlrow[0], 16);
                                strncpy(lcx.list[j].toid, sqlrow[1], 16);
                                strncpy(lcx.list[j].title, sqlrow[2], 64);
                                strncpy(lcx.list[j].datetime, sqlrow[4], 32);
                                strncpy(lcx.list[j].content, sqlrow[3], 892);
                                j++;
                            }
                            if (mysql_errno(conn_ptr))
                            {
                                fprintf(stderr, "Retrive error:s\n", mysql_error(conn_ptr));
                            }
                        }
                        mysql_free_result(res_ptr);
                    }
                }
                else
                {
                    printf("Connection failed\n");
                }
                mysql_close(conn_ptr);
                printf("===========\n");
                printf("%d\n", lcx.sum);
                for (i = 0; i < lcx.sum; i++)
                {
                    printf("%s\n", lcx.list[i].frid);
                    printf("%s\n", lcx.list[i].toid);
                    printf("%s\n", lcx.list[i].title);
                    printf("%s\n", lcx.list[i].content);
                    printf("%s\n", lcx.list[i].datetime);
                }
                send(client, &lcx, sizeof(struct st_mail_list), 0);
            }
            else if (strncmp(buffer, DELETE, 4) == 0)
            {
                memset(&mail, 0, 1024);
                memcpy(&mail, buffer, 1024);
                printf("DELETE\n");
                printf("%s\n", mail.toid);
                printf("%s\n", mail.datetime);

                conn_ptr = mysql_init(NULL);
                if (!conn_ptr)
                {
                    printf("mysql_init failed\n");
                    return EXIT_FAILURE;
                }
                conn_ptr = mysql_real_connect(conn_ptr, HOST, USER_NAME, PASSWD, DATABASE, PORT, NULL, 0);
                if (conn_ptr)
                {
                    printf("Datebase connect OK\n");
                    memset(sql, 0, 1024);

                    sprintf(sql, "delete from posts   where to_name = '%s' and date = '%s';", mail.toid, mail.datetime);
                    printf("%s\n", sql);
                    res = mysql_query(conn_ptr, sql); //可以把insert语句替换成delete或者update语句，都一样的
                    if (!res)
                    { //输出受影响的行数
                        printf("Deleted %lu rows\n", (unsigned long)mysql_affected_rows(conn_ptr));
                    }
                    else
                    { //打印出错误代码及详细信息
                        fprintf(stderr, "Delete error %d: %sn", mysql_errno(conn_ptr), mysql_error(conn_ptr));
                    }
                }
                else
                {
                    printf("Connection failed\n");
                }
                mysql_close(conn_ptr);
                send(client, "Mail delete ok!", strlen("Mail delete ok!"), 0);
            }
            else if (strncmp(buffer, BIN, 4) == 0)
            {
                memset(&mail, 0, 1024);
                memcpy(&mail, buffer, 1024);
                printf("BIN\n");
                printf("%s\n", mail.toid);
                printf("%s\n", mail.datetime);

                conn_ptr = mysql_init(NULL);
                if (!conn_ptr)
                {
                    printf("mysql_init failed\n");
                    return EXIT_FAILURE;
                }
                conn_ptr = mysql_real_connect(conn_ptr, HOST, USER_NAME, PASSWD, DATABASE, PORT, NULL, 0);
                if (conn_ptr)
                {
                    printf("Datebase connect OK\n");
                    memset(sql, 0, 1024);

                    sprintf(sql, "update posts  set status = 'bin' where to_name = '%s' and date = '%s';", mail.toid, mail.datetime);
                    printf("%s\n", sql);
                    res = mysql_query(conn_ptr, sql); //可以把insert语句替换成delete或者update语句，都一样的
                    if (!res)
                    { //输出受影响的行数
                        printf("Bin %lu rows\n", (unsigned long)mysql_affected_rows(conn_ptr));
                    }
                    else
                    { //打印出错误代码及详细信息
                        fprintf(stderr, "Bin error %d: %sn", mysql_errno(conn_ptr), mysql_error(conn_ptr));
                    }
                }
                else
                {
                    printf("Connection failed\n");
                }
                mysql_close(conn_ptr);
            }
            else if (strncmp(buffer, READALL, 4) == 0)
            {
                memset(&mail, 0, 1024);
                memcpy(&mail, buffer, 1024);
                printf("READALL\n");
                printf("%s\n", mail.toid);

                conn_ptr = mysql_init(NULL);
                if (!conn_ptr)
                {
                    printf("mysql_init failed\n");
                    return EXIT_FAILURE;
                }
                conn_ptr = mysql_real_connect(conn_ptr, HOST, USER_NAME, PASSWD, DATABASE, PORT, NULL, 0);
                if (conn_ptr)
                {
                    printf("Datebase connect OK\n");
                    memset(sql, 0, 1024);

                    sprintf(sql, "update posts  set al_read = 'yes' where to_name = '%s' and status = 'sended';", mail.toid);
                    printf("%s\n", sql);
                    res = mysql_query(conn_ptr, sql); //可以把insert语句替换成delete或者update语句，都一样的
                    if (!res)
                    { //输出受影响的行数
                        printf("READALL %lu rows\n", (unsigned long)mysql_affected_rows(conn_ptr));
                    }
                    else
                    { //打印出错误代码及详细信息
                        fprintf(stderr, "Readall error %d: %sn", mysql_errno(conn_ptr), mysql_error(conn_ptr));
                    }
                }
                else
                {
                    printf("Connection failed\n");
                }
                mysql_close(conn_ptr);
            }
            else if (strncmp(buffer, RECOVER, 4) == 0)
            {
                memset(&mail, 0, 1024);
                memcpy(&mail, buffer, 1024);
                printf("RECOVER\n");
                printf("%s\n", mail.toid);
                printf("%s\n", mail.datetime);

                conn_ptr = mysql_init(NULL);
                if (!conn_ptr)
                {
                    printf("mysql_init failed\n");
                    return EXIT_FAILURE;
                }
                conn_ptr = mysql_real_connect(conn_ptr, HOST, USER_NAME, PASSWD, DATABASE, PORT, NULL, 0);
                if (conn_ptr)
                {
                    printf("Datebase connect OK\n");
                    memset(sql, 0, 1024);

                    sprintf(sql, "update posts  set status = 'sended' where to_name = '%s' and date = '%s';", mail.toid, mail.datetime);
                    printf("%s\n", sql);
                    res = mysql_query(conn_ptr, sql); //可以把insert语句替换成delete或者update语句，都一样的
                    if (!res)
                    { //输出受影响的行数
                        printf("RECOVER %lu rows\n", (unsigned long)mysql_affected_rows(conn_ptr));
                    }
                    else
                    { //打印出错误代码及详细信息
                        fprintf(stderr, "Recover error %d: %sn", mysql_errno(conn_ptr), mysql_error(conn_ptr));
                    }
                }
                else
                {
                    printf("Connection failed\n");
                }
                mysql_close(conn_ptr);
            }
            else if (strncmp(buffer, DRAFT, 4) == 0)
            {
                memset(&mail, 0, 1024);
                memcpy(&mail, buffer, 1024);
                printf("DRAFT\n");
                printf("%s\n", mail.frid);
                printf("%s\n", mail.toid);
                printf("%s\n", mail.title);
                printf("%s\n", mail.content);
                printf("%s\n", mail.datetime);

                conn_ptr = mysql_init(NULL);
                if (!conn_ptr)
                {
                    printf("mysql_init failed\n");
                    return EXIT_FAILURE;
                }
                conn_ptr = mysql_real_connect(conn_ptr, HOST, USER_NAME, PASSWD, DATABASE, PORT, NULL, 0);
                if (conn_ptr)
                {
                    printf("Datebase connect OK\n");
                    memset(sql, 0, 1024);

                    sprintf(sql, "insert into posts (fr_name, to_name, theme, content, status, al_read, important, date) values ('%s', '%s', '%s', '%s', 'draft', 'no', 'no', '%s');", mail.frid, mail.toid, mail.title, mail.content, mail.datetime);
                    printf("%s\n", sql);
                    res = mysql_query(conn_ptr, sql); //可以把insert语句替换成delete或者update语句，都一样的
                    if (!res)
                    { //输出受影响的行数
                        printf("DRAFT %lu rows\n", (unsigned long)mysql_affected_rows(conn_ptr));
                    }
                    else
                    { //打印出错误代码及详细信息
                        fprintf(stderr, "Draft error %d: %sn", mysql_errno(conn_ptr), mysql_error(conn_ptr));
                    }
                }
                else
                {
                    printf("Connection failed\n");
                }
                mysql_close(conn_ptr);
            }
            else if(strncmp(buffer, IMPORTANT, 4) == 0)
            {
                memset(&mail, 0, 1024);
                memcpy(&mail, buffer, 1024);
                printf("IMPORTANT\n");
                printf("%s\n", mail.toid);
                printf("%s\n", mail.datetime);

                conn_ptr = mysql_init(NULL);
                if (!conn_ptr)
                {
                    printf("mysql_init failed\n");
                    return EXIT_FAILURE;
                }
                conn_ptr = mysql_real_connect(conn_ptr, HOST, USER_NAME, PASSWD, DATABASE, PORT, NULL, 0);
                if (conn_ptr)
                {
                    printf("Datebase connect OK\n");
                    memset(sql, 0, 1024);

                    sprintf(sql, "update posts  set important = 'no' where to_name = '%s' and date = '%s';", mail.toid, mail.datetime);
                    printf("%s\n", sql);
                    res = mysql_query(conn_ptr, sql); //可以把insert语句替换成delete或者update语句，都一样的
                    if (!res)
                    { //输出受影响的行数
                        printf("IMPORTANT %lu rows\n", (unsigned long)mysql_affected_rows(conn_ptr));
                    }
                    else
                    { //打印出错误代码及详细信息
                        fprintf(stderr, "Important error %d: %sn", mysql_errno(conn_ptr), mysql_error(conn_ptr));
                    }
                }
                else
                {
                    printf("Connection failed\n");
                }
                mysql_close(conn_ptr);
                send(client, msg, strlen(msg), 0);
            }
            else if(strncmp(buffer, DISPLAY, 4) == 0)
            {
                printf("Client send new mail.\n");
                memset(&mail, 0, 1024);
                memcpy(&mail, buffer, 1024);
                printf("DISPLAY\n");
                printf("%s\n", mail.frid);

                memset(&lcx, 0, sizeof(struct st_mail_list));

                conn_ptr = mysql_init(NULL);
                if (!conn_ptr)
                {
                    printf("mysql_init failed\n");
                    return EXIT_FAILURE;
                }
                conn_ptr = mysql_real_connect(conn_ptr, HOST, USER_NAME, PASSWD, DATABASE, PORT, NULL, 0);
                if (conn_ptr)
                {
                    printf("Datebase connect OK\n");
                    memset(sql, 0, 1024);

                    sprintf(sql, "select fr_name, to_name, theme, content, date from posts where fr_name = '%s' and status = 'draft' ;", mail.frid);
                    printf("%s\n", sql);
                    res = mysql_query(conn_ptr, sql); //查询语句
                    if (!res)
                    {
                        res_ptr = mysql_store_result(conn_ptr); //取出结果集
                        if (res_ptr)
                        {
                            rows = (unsigned long)mysql_num_rows(res_ptr);
                            printf("SELECT %lu Rows\n", rows);
                            lcx.sum = rows;
                            printf("%d\n", lcx.sum);
                            cols = mysql_num_fields(res_ptr); //列数
                            printf("%d Cols\n", cols);
                            j = 0;
                            while ((sqlrow = mysql_fetch_row(res_ptr)))
                            { //依次取出记录
                                for (i = 0; i < cols; i++)
                                {
                                    printf("%s\t", sqlrow[i]); //输出
                                }
                                printf("\n");
                                strncpy(lcx.list[j].frid, sqlrow[0], 16);
                                strncpy(lcx.list[j].toid, sqlrow[1], 16);
                                strncpy(lcx.list[j].title, sqlrow[2], 64);
                                strncpy(lcx.list[j].datetime, sqlrow[4], 32);
                                strncpy(lcx.list[j].content, sqlrow[3], 892);
                                j++;
                            }
                            if (mysql_errno(conn_ptr))
                            {
                                fprintf(stderr, "Retrive error:s\n", mysql_error(conn_ptr));
                            }
                        }
                        mysql_free_result(res_ptr);
                    }
                }
                else
                {
                    printf("Connection failed\n");
                }
                mysql_close(conn_ptr);
                printf("===========\n");
                printf("%d\n", lcx.sum);
                for (i = 0; i < lcx.sum; i++)
                {
                    printf("%s\n", lcx.list[i].frid);
                    printf("%s\n", lcx.list[i].toid);
                    printf("%s\n", lcx.list[i].title);
                    printf("%s\n", lcx.list[i].content);
                    printf("%s\n", lcx.list[i].datetime);
                }
                send(client, &lcx, sizeof(struct st_mail_list), 0);
            }
            else
            {
                send(client, msg, strlen(msg), 0);
            }
        }
    }
    return 0;
}
