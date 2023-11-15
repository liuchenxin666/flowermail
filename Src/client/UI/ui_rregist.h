/********************************************************************************
** Form generated from reading UI file 'rregist.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RREGIST_H
#define UI_RREGIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RRegist
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QLabel *label;
    QWidget *widget_2;
    QWidget *widget_5;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *widget_3;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QWidget *widget_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RRegist)
    {
        if (RRegist->objectName().isEmpty())
            RRegist->setObjectName(QString::fromUtf8("RRegist"));
        RRegist->resize(750, 630);
        centralwidget = new QWidget(RRegist);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 10, 101, 527));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 131, 51));
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(130, 10, 151, 527));
        widget_5 = new QWidget(widget_2);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(10, 50, 121, 391));
        gridLayout = new QGridLayout(widget_5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(widget_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_3 = new QLabel(widget_5);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_4 = new QLabel(widget_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label_5 = new QLabel(widget_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        label_6 = new QLabel(widget_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 4, 0, 1, 1);

        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(280, 20, 271, 527));
        widget_6 = new QWidget(widget_3);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setGeometry(QRect(0, 20, 241, 431));
        verticalLayout_2 = new QVBoxLayout(widget_6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit = new QLineEdit(widget_6);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout_2->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(widget_6);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        verticalLayout_2->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(widget_6);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        verticalLayout_2->addWidget(lineEdit_3);

        lineEdit_4 = new QLineEdit(widget_6);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        verticalLayout_2->addWidget(lineEdit_4);

        lineEdit_5 = new QLineEdit(widget_6);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        verticalLayout_2->addWidget(lineEdit_5);

        widget_4 = new QWidget(centralwidget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(540, 10, 189, 527));
        pushButton = new QPushButton(widget_4);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 350, 93, 28));
        pushButton_2 = new QPushButton(widget_4);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 430, 93, 28));
        RRegist->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RRegist);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 750, 26));
        RRegist->setMenuBar(menubar);
        statusbar = new QStatusBar(RRegist);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        RRegist->setStatusBar(statusbar);

        retranslateUi(RRegist);

        QMetaObject::connectSlotsByName(RRegist);
    } // setupUi

    void retranslateUi(QMainWindow *RRegist)
    {
        RRegist->setWindowTitle(QApplication::translate("RRegist", "MainWindow", nullptr));
        label->setText(QApplication::translate("RRegist", "\346\254\242\350\277\216\346\263\250\345\206\214\357\274\232", nullptr));
        label_2->setText(QApplication::translate("RRegist", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_3->setText(QApplication::translate("RRegist", "\345\257\206\347\240\201\357\274\232", nullptr));
        label_4->setText(QApplication::translate("RRegist", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
        label_5->setText(QApplication::translate("RRegist", "\346\200\247\345\210\253\357\274\232", nullptr));
        label_6->setText(QApplication::translate("RRegist", "\345\271\264\351\276\204\357\274\232", nullptr));
        pushButton->setText(QApplication::translate("RRegist", "\347\253\213\345\215\263\346\263\250\345\206\214", nullptr));
        pushButton_2->setText(QApplication::translate("RRegist", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RRegist: public Ui_RRegist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RREGIST_H
