/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *widget_4;
    QWidget *widget;
    QLabel *username;
    QLabel *password;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QWidget *widget_3;
    QPushButton *regist;
    QPushButton *login;
    QPushButton *back;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(879, 553);
        widget_4 = new QWidget(Login);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(0, 0, 881, 551));
        widget = new QWidget(widget_4);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 60, 781, 241));
        username = new QLabel(widget);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(210, 120, 111, 51));
        username->setStyleSheet(QString::fromUtf8(""));
        password = new QLabel(widget);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(210, 170, 81, 41));
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(300, 130, 351, 31));
        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(300, 180, 351, 31));
        widget_2 = new QWidget(widget_4);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(180, 320, 681, 101));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        regist = new QPushButton(widget_3);
        regist->setObjectName(QString::fromUtf8("regist"));
        regist->setGeometry(QRect(160, 20, 93, 28));
        login = new QPushButton(widget_3);
        login->setObjectName(QString::fromUtf8("login"));
        login->setGeometry(QRect(290, 20, 93, 28));
        back = new QPushButton(widget_3);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(420, 20, 93, 28));

        gridLayout->addWidget(widget_3, 0, 0, 1, 1);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Login", nullptr));
        username->setText(QApplication::translate("Login", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        password->setText(QApplication::translate("Login", "\345\257\206\347\240\201\357\274\232", nullptr));
        regist->setText(QApplication::translate("Login", "\346\263\250\345\206\214\350\264\246\345\217\267", nullptr));
        login->setText(QApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
        back->setText(QApplication::translate("Login", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
