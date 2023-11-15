/********************************************************************************
** Form generated from reading UI file 'reveiver.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REVEIVER_H
#define UI_REVEIVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Reveiver
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *Btn_readatttach;
    QPushButton *Btn_back;
    QLabel *label3;
    QLabel *label_Title;
    QLabel *label_sender;
    QPushButton *Btn_delete;
    QLabel *label_attachname;
    QLabel *label_time;
    QLabel *label5;
    QPushButton *Btn_reply;
    QLabel *label8;
    QPushButton *Btn_readatttach_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label2;
    QLabel *label_reciever;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Reveiver)
    {
        if (Reveiver->objectName().isEmpty())
            Reveiver->setObjectName(QString::fromUtf8("Reveiver"));
        Reveiver->resize(880, 632);
        centralwidget = new QWidget(Reveiver);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 871, 581));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Btn_readatttach = new QPushButton(gridLayoutWidget);
        Btn_readatttach->setObjectName(QString::fromUtf8("Btn_readatttach"));

        gridLayout->addWidget(Btn_readatttach, 5, 4, 1, 1);

        Btn_back = new QPushButton(gridLayoutWidget);
        Btn_back->setObjectName(QString::fromUtf8("Btn_back"));

        gridLayout->addWidget(Btn_back, 0, 0, 1, 1);

        label3 = new QLabel(gridLayoutWidget);
        label3->setObjectName(QString::fromUtf8("label3"));

        gridLayout->addWidget(label3, 3, 0, 1, 1);

        label_Title = new QLabel(gridLayoutWidget);
        label_Title->setObjectName(QString::fromUtf8("label_Title"));

        gridLayout->addWidget(label_Title, 1, 0, 1, 6);

        label_sender = new QLabel(gridLayoutWidget);
        label_sender->setObjectName(QString::fromUtf8("label_sender"));

        gridLayout->addWidget(label_sender, 2, 1, 1, 5);

        Btn_delete = new QPushButton(gridLayoutWidget);
        Btn_delete->setObjectName(QString::fromUtf8("Btn_delete"));

        gridLayout->addWidget(Btn_delete, 0, 2, 1, 1);

        label_attachname = new QLabel(gridLayoutWidget);
        label_attachname->setObjectName(QString::fromUtf8("label_attachname"));

        gridLayout->addWidget(label_attachname, 5, 1, 1, 1);

        label_time = new QLabel(gridLayoutWidget);
        label_time->setObjectName(QString::fromUtf8("label_time"));

        gridLayout->addWidget(label_time, 4, 1, 1, 5);

        label5 = new QLabel(gridLayoutWidget);
        label5->setObjectName(QString::fromUtf8("label5"));

        gridLayout->addWidget(label5, 5, 0, 1, 1);

        Btn_reply = new QPushButton(gridLayoutWidget);
        Btn_reply->setObjectName(QString::fromUtf8("Btn_reply"));

        gridLayout->addWidget(Btn_reply, 0, 1, 1, 1);

        label8 = new QLabel(gridLayoutWidget);
        label8->setObjectName(QString::fromUtf8("label8"));

        gridLayout->addWidget(label8, 4, 0, 1, 1);

        Btn_readatttach_2 = new QPushButton(gridLayoutWidget);
        Btn_readatttach_2->setObjectName(QString::fromUtf8("Btn_readatttach_2"));

        gridLayout->addWidget(Btn_readatttach_2, 5, 5, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 3, 1, 1);

        label2 = new QLabel(gridLayoutWidget);
        label2->setObjectName(QString::fromUtf8("label2"));

        gridLayout->addWidget(label2, 2, 0, 1, 1);

        label_reciever = new QLabel(gridLayoutWidget);
        label_reciever->setObjectName(QString::fromUtf8("label_reciever"));

        gridLayout->addWidget(label_reciever, 3, 1, 1, 5);

        textBrowser = new QTextBrowser(gridLayoutWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        gridLayout->addWidget(textBrowser, 6, 0, 1, 6);

        Reveiver->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Reveiver);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 880, 26));
        Reveiver->setMenuBar(menubar);
        statusbar = new QStatusBar(Reveiver);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Reveiver->setStatusBar(statusbar);

        retranslateUi(Reveiver);

        QMetaObject::connectSlotsByName(Reveiver);
    } // setupUi

    void retranslateUi(QMainWindow *Reveiver)
    {
        Reveiver->setWindowTitle(QApplication::translate("Reveiver", "MainWindow", nullptr));
        Btn_readatttach->setText(QApplication::translate("Reveiver", "\346\237\245\347\234\213\351\231\204\344\273\266", nullptr));
        Btn_back->setText(QApplication::translate("Reveiver", "\350\277\224\345\233\236", nullptr));
        label3->setText(QApplication::translate("Reveiver", "\346\224\266\344\273\266\344\272\272\357\274\232", nullptr));
        label_Title->setText(QApplication::translate("Reveiver", "Receive\357\274\232", nullptr));
        label_sender->setText(QString());
        Btn_delete->setText(QApplication::translate("Reveiver", "\345\210\240\351\231\244", nullptr));
        label_attachname->setText(QString());
        label_time->setText(QString());
        label5->setText(QApplication::translate("Reveiver", "\351\231\204\344\273\266\357\274\232", nullptr));
        Btn_reply->setText(QApplication::translate("Reveiver", "\345\233\236\345\244\215", nullptr));
        label8->setText(QApplication::translate("Reveiver", "\346\227\266\351\227\264\357\274\232", nullptr));
        Btn_readatttach_2->setText(QApplication::translate("Reveiver", "\344\270\213\350\275\275\351\231\204\344\273\266", nullptr));
        label2->setText(QApplication::translate("Reveiver", "\345\217\221\344\273\266\344\272\272\357\274\232", nullptr));
        label_reciever->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Reveiver: public Ui_Reveiver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REVEIVER_H
