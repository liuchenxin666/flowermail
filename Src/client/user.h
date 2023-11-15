#ifndef USER_H
#define USER_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlError>
#include <QDebug>

class User
{
public:
    bool ison;
    QString username;
    User(QString name);

    void init();

    void changePasswd();//修改密码

    void retrievePasswd();//找回密码
};

#endif // USER_H
