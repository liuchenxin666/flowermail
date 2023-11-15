#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include<QtSql/QSqlDatabase>
#include<QDebug>
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlError>
#include<QtSql/QSqlRecord>
#include<QMouseEvent>
#include<rregist.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();
    void init();

private slots:
    void on_regist_released();

    void on_login_clicked();

    void on_back_clicked();

private:
    Ui::Login *ui;
};
#endif // LOGIN_H
