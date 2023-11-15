#include "rregist.h"
#include "ui_rregist.h"
#include<login.h>
#include<QMessageBox>
#include<QtSql/QSqlQuery>

RRegist::RRegist(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RRegist)
{
    ui->setupUi(this);

    ui->centralwidget->setAutoFillBackground(true);
    QPalette palette2;
    QPixmap pixmap2(":/new/prefix1/register.png");
    palette2.setBrush(QPalette::Window,QBrush(pixmap2.scaled(this->size())));
    ui->centralwidget->setPalette(palette2);
    ui->centralwidget->show();

}

RRegist::~RRegist()
{
    delete ui;
}


//检查:
int RRegist::check_name()
{
    QString s = ui->lineEdit->text();
    for(int i=0;i<s.size();i++)
    {
        if(!( (s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||s[i]=='_'||(s[i]>='0'&&s[i]<='9'))) return 1;
    }
    return 0;
}
int RRegist::check_passwd()
{
    QString x =  ui->lineEdit_2->text();
    if(x.size()<6) return 1;
    return 0;
}
int RRegist::check_passwd_same()
{
    QString a = ui->lineEdit_2->text();
    QString b = ui->lineEdit_3->text();
    if(a!=b)
    {
        return 1;
    }
    else return 0;
}


void RRegist::on_pushButton_2_clicked()  //返回按钮出发的相应
{
    Login *lg_1=new Login;
    lg_1->show();
    this->hide();

}

void RRegist::on_pushButton_clicked()  //立即注册按钮触发的相应
{
    QString user_1;
    QString pwd_1;

    user_1=ui->lineEdit->text();
    pwd_1=ui->lineEdit_2->text();
    if(user_1=="")
        QMessageBox::warning(this,"","用户名不能为空!");
    else if(pwd_1=="")
        QMessageBox::warning(this,"","密码不能为空!");
    else
    {
        if(check_name()==1) QMessageBox::warning(this,"","存在不合法的字符!");
        if(check_passwd()==1) QMessageBox::warning(this,"","密码不能少于6位!");
        if(check_passwd_same()==1) QMessageBox::warning(this,"","两次输入的密码不一致!");

        if(check_name()==0 && check_passwd()==0 && check_passwd_same()==0)
        {
            QMessageBox::warning(this,"","注册成功!");

            //加入数据库
            QSqlQuery query;
            QString namey = ui->lineEdit->text();
            QString passwd = ui->lineEdit_2->text();
            QDateTime time = QDateTime::currentDateTime();
            QString InsertStr = QString("INSERT INTO user("
                                         "userid, "
                                         "passwd, "
                                         "time "
                                         ") "
                                         "VALUES("
                                         "'"+namey+"', "
                                         "'"+passwd+"', "
                                         "'"+time.toString("yyyy-MM-dd hh:mm:ss")+"' "
                                         ");");
            query.prepare(InsertStr);
            qDebug()<<InsertStr;
            qDebug()<<namey;
            qDebug()<<passwd;
            if(!query.exec())
            {
                qDebug()<<"Insert error :"<<query.lastError();
            }
            else
            {
                qDebug()<<"insert data success!";

                Login *lg_2=new Login;
                lg_2->show();
                this->hide();
            }
        }
    }
}




