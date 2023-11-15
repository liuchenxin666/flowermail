#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include<QLabel>
#include<QFont>
#include<rregist.h>
#include<QMessageBox>
#include<QLineEdit>

//Login页面初始化
Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    ui->widget_4->setAutoFillBackground(true);
    QPalette palette1;
    QPixmap pixmap1(":/new/prefix1/Login.png");
    palette1.setBrush(QPalette::Window,QBrush(pixmap1.scaled(this->size())));
    ui->widget_4->setPalette(palette1);
    ui->widget_4->show();

    //Login页面中字体的大小
    QFont ft;
    ft.setPointSize(10);
    ui->username->setFont(ft);
    ui->password->setFont(ft);
    ui->username->installEventFilter(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);    //输入密码时不可见

    setWindowTitle("登录");
    init();

}

Login::~Login()
{
    delete ui;
}

void Login::init()    //初始化数据库
{

    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setDatabaseName("data");
    db.open();
    bool ok=db.open();
    if(ok){
        qDebug()<<"open database success";
    }
    else{
        qDebug()<<"error open database because";
    }

    //用户账号、密码、密保问题、密保问题答案
    QSqlQuery qry;
    qry.prepare( "CREATE TABLE IF NOT EXISTS user "
                 "(userid VARCHAR(30) PRIMARY KEY, "
                 "passwd VARCHAR(30), "
                 "question VARCHAR(40), "
                 "answer VARCHAR(30), "
                 "name VARCHAR(40), "
                 "address VARCHAR(60), "
                 "phone VARCHAR(40), "
                 "time DATE, "
                 "icon VARCHAR(60)"
                 ")" );
    if( !qry.exec() )
        qDebug()<<"Table created error "<<qry.lastError();
    else
        qDebug()<<"Table created!";
}


void Login::on_regist_released()   //当按注册按钮时触发的相应
{
    RRegist *reg=new RRegist;
    reg->show();
    this->hide();
}

void Login::on_back_clicked() //按退出按钮时触发的相应
{
    this->hide();
}

void Login::on_login_clicked() //按登录按钮时触发的相应
{
    QString str;
    QString pwd;
    str=ui->lineEdit->text();
    pwd=ui->lineEdit_2->text();

    if(str=="")
        QMessageBox::warning(this,"","用户名不能为空!");
    else if(pwd=="")
        QMessageBox::warning(this,"","密码不能为空!");
    else
    {
        //查找数据库
        QSqlQuery qry;
        qry.prepare( "select count(*) from user where userid = '"+str+"'" );
          if( !qry.exec() )
            qDebug() <<"Select error"<<qry.lastError();
          else
            qDebug( "Select success!" );
        qry.next();
        qDebug()<<qry.value(0).toInt();
        if(qry.value(0).toInt()==0){
            QMessageBox::information(this,"提示","用户不存在！");
        }
        else{
            qry.prepare( "select passwd from user where userid = '"+str+"'" );
              if( !qry.exec() )
                qDebug() <<"Select error"<<qry.lastError();
              else
                qDebug( "Select success!" );
            qry.next();
            qDebug() << "密码："<<qry.value(0).toString();

            //验证成功，进入邮箱主页面
            if(pwd==qry.value(0).toString()){
                mainwindow *win = new mainwindow(str);
                win->show();
                this->close();

            }
            else{
                QMessageBox::information(this,"提示","密码错误！");
            }
        }
    }
}




