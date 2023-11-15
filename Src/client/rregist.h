#ifndef RREGIST_H
#define RREGIST_H

#include <QMainWindow>
#include <QMessageBox>
#include<QtSql/QSqlDatabase>
#include<QDebug>
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlError>
#include<QtSql/QSqlRecord>
#include <QMouseEvent>
#include<QTimer>
#include<QDateTime>
#include <verificationcodelabel.h>

namespace Ui {
class RRegist;
}

class RRegist : public QMainWindow
{
    Q_OBJECT

public:
    explicit RRegist(QWidget *parent = nullptr);
    ~RRegist();

    int check_name();
    int check_passwd();
    int check_passwd_same();


private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::RRegist *ui;
    QTimer *timer;
};

#endif // RREGIST_H
