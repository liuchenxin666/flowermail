/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainwindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page_Homepage;
    QLabel *label_2;
    QWidget *page_Writeletter;
    QPushButton *Btn_preview;
    QPushButton *Btn_draft;
    QPushButton *Btn_cancel;
    QPushButton *Btn_send;
    QLabel *label_reciever;
    QLabel *label_theme;
    QLineEdit *Editor_reciever;
    QPushButton *Btn_resend;
    QPushButton *Btn_sendsecret;
    QPushButton *Btn_qfdx;
    QLineEdit *Editor_theme;
    QTextEdit *textEdit;
    QPushButton *Btn_send_2;
    QPushButton *Btn_add;
    QToolButton *toolButton;
    QPushButton *Btn_cancel_2;
    QLabel *label_sender;
    QWidget *page_Recieverpage;
    QWidget *widget;
    QTableView *tableView;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_receive_selectall;
    QPushButton *pushButton_readall;
    QPushButton *btn_receive_delete;
    QPushButton *btn_receive_deleteall;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QWidget *page_Starletter;
    QWidget *widget_3;
    QTableView *tableView_star;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_star_selectall;
    QPushButton *btn_star_cancel;
    QSpacerItem *horizontalSpacer_6;
    QWidget *page_Draftletter;
    QWidget *widget_5;
    QTableView *tableView_draft;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_5;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton_f5;
    QWidget *page_Sendedpage;
    QTableView *tableView_sended;
    QWidget *page_Bin;
    QWidget *widget_7;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QSpacerItem *horizontalSpacer_8;
    QTableView *tableView_bin;
    QListWidget *listWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *mainwindow)
    {
        if (mainwindow->objectName().isEmpty())
            mainwindow->setObjectName(QString::fromUtf8("mainwindow"));
        mainwindow->resize(1068, 631);
        mainwindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(mainwindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(170, 10, 831, 591));
        page_Homepage = new QWidget();
        page_Homepage->setObjectName(QString::fromUtf8("page_Homepage"));
        label_2 = new QLabel(page_Homepage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 70, 731, 451));
        label_2->setStyleSheet(QString::fromUtf8("font: 80pt \"Edwardian Script ITC\";\n"
"\n"
""));
        stackedWidget->addWidget(page_Homepage);
        page_Writeletter = new QWidget();
        page_Writeletter->setObjectName(QString::fromUtf8("page_Writeletter"));
        Btn_preview = new QPushButton(page_Writeletter);
        Btn_preview->setObjectName(QString::fromUtf8("Btn_preview"));
        Btn_preview->setGeometry(QRect(90, 20, 51, 28));
        Btn_draft = new QPushButton(page_Writeletter);
        Btn_draft->setObjectName(QString::fromUtf8("Btn_draft"));
        Btn_draft->setGeometry(QRect(140, 20, 61, 28));
        Btn_cancel = new QPushButton(page_Writeletter);
        Btn_cancel->setObjectName(QString::fromUtf8("Btn_cancel"));
        Btn_cancel->setGeometry(QRect(200, 20, 51, 28));
        Btn_send = new QPushButton(page_Writeletter);
        Btn_send->setObjectName(QString::fromUtf8("Btn_send"));
        Btn_send->setGeometry(QRect(20, 20, 71, 28));
        label_reciever = new QLabel(page_Writeletter);
        label_reciever->setObjectName(QString::fromUtf8("label_reciever"));
        label_reciever->setGeometry(QRect(20, 80, 81, 31));
        label_theme = new QLabel(page_Writeletter);
        label_theme->setObjectName(QString::fromUtf8("label_theme"));
        label_theme->setGeometry(QRect(20, 140, 71, 21));
        Editor_reciever = new QLineEdit(page_Writeletter);
        Editor_reciever->setObjectName(QString::fromUtf8("Editor_reciever"));
        Editor_reciever->setGeometry(QRect(80, 80, 711, 31));
        Editor_reciever->setStyleSheet(QString::fromUtf8("background-color: rgb(254, 246, 233);"));
        Btn_resend = new QPushButton(page_Writeletter);
        Btn_resend->setObjectName(QString::fromUtf8("Btn_resend"));
        Btn_resend->setGeometry(QRect(590, 20, 61, 31));
        Btn_sendsecret = new QPushButton(page_Writeletter);
        Btn_sendsecret->setObjectName(QString::fromUtf8("Btn_sendsecret"));
        Btn_sendsecret->setGeometry(QRect(650, 20, 61, 31));
        Btn_qfdx = new QPushButton(page_Writeletter);
        Btn_qfdx->setObjectName(QString::fromUtf8("Btn_qfdx"));
        Btn_qfdx->setGeometry(QRect(710, 20, 81, 31));
        Editor_theme = new QLineEdit(page_Writeletter);
        Editor_theme->setObjectName(QString::fromUtf8("Editor_theme"));
        Editor_theme->setGeometry(QRect(80, 140, 711, 31));
        Editor_theme->setStyleSheet(QString::fromUtf8("background-color: rgb(254, 246, 233);"));
        textEdit = new QTextEdit(page_Writeletter);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(20, 220, 801, 331));
        textEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(254, 246, 233);"));
        Btn_send_2 = new QPushButton(page_Writeletter);
        Btn_send_2->setObjectName(QString::fromUtf8("Btn_send_2"));
        Btn_send_2->setGeometry(QRect(560, 510, 61, 31));
        Btn_add = new QPushButton(page_Writeletter);
        Btn_add->setObjectName(QString::fromUtf8("Btn_add"));
        Btn_add->setGeometry(QRect(20, 190, 93, 28));
        toolButton = new QToolButton(page_Writeletter);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(700, 190, 47, 21));
        Btn_cancel_2 = new QPushButton(page_Writeletter);
        Btn_cancel_2->setObjectName(QString::fromUtf8("Btn_cancel_2"));
        Btn_cancel_2->setGeometry(QRect(630, 510, 61, 31));
        label_sender = new QLabel(page_Writeletter);
        label_sender->setObjectName(QString::fromUtf8("label_sender"));
        label_sender->setGeometry(QRect(540, 480, 151, 16));
        stackedWidget->addWidget(page_Writeletter);
        page_Recieverpage = new QWidget();
        page_Recieverpage->setObjectName(QString::fromUtf8("page_Recieverpage"));
        widget = new QWidget(page_Recieverpage);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(1, 21, 831, 541));
        tableView = new QTableView(widget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 60, 811, 461));
        tableView->setStyleSheet(QString::fromUtf8("background-color: rgb(254, 246, 233);"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(0, 0, 580, 50));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_receive_selectall = new QPushButton(widget_2);
        btn_receive_selectall->setObjectName(QString::fromUtf8("btn_receive_selectall"));

        horizontalLayout->addWidget(btn_receive_selectall);

        pushButton_readall = new QPushButton(widget_2);
        pushButton_readall->setObjectName(QString::fromUtf8("pushButton_readall"));

        horizontalLayout->addWidget(pushButton_readall);

        btn_receive_delete = new QPushButton(widget_2);
        btn_receive_delete->setObjectName(QString::fromUtf8("btn_receive_delete"));

        horizontalLayout->addWidget(btn_receive_delete);

        btn_receive_deleteall = new QPushButton(widget_2);
        btn_receive_deleteall->setObjectName(QString::fromUtf8("btn_receive_deleteall"));

        horizontalLayout->addWidget(btn_receive_deleteall);

        horizontalSpacer_3 = new QSpacerItem(48, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        horizontalSpacer_4 = new QSpacerItem(48, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        horizontalSpacer_5 = new QSpacerItem(48, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        stackedWidget->addWidget(page_Recieverpage);
        page_Starletter = new QWidget();
        page_Starletter->setObjectName(QString::fromUtf8("page_Starletter"));
        widget_3 = new QWidget(page_Starletter);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(10, 20, 821, 531));
        tableView_star = new QTableView(widget_3);
        tableView_star->setObjectName(QString::fromUtf8("tableView_star"));
        tableView_star->setGeometry(QRect(0, 60, 811, 461));
        tableView_star->setStyleSheet(QString::fromUtf8("background-color: rgb(254, 246, 233);"));
        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(-10, 0, 621, 51));
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btn_star_selectall = new QPushButton(widget_4);
        btn_star_selectall->setObjectName(QString::fromUtf8("btn_star_selectall"));

        horizontalLayout_2->addWidget(btn_star_selectall);

        btn_star_cancel = new QPushButton(widget_4);
        btn_star_cancel->setObjectName(QString::fromUtf8("btn_star_cancel"));

        horizontalLayout_2->addWidget(btn_star_cancel);

        horizontalSpacer_6 = new QSpacerItem(398, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        stackedWidget->addWidget(page_Starletter);
        page_Draftletter = new QWidget();
        page_Draftletter->setObjectName(QString::fromUtf8("page_Draftletter"));
        widget_5 = new QWidget(page_Draftletter);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(0, 20, 831, 531));
        tableView_draft = new QTableView(widget_5);
        tableView_draft->setObjectName(QString::fromUtf8("tableView_draft"));
        tableView_draft->setGeometry(QRect(11, 58, 811, 461));
        tableView_draft->setStyleSheet(QString::fromUtf8("background-color: rgb(254, 246, 233);"));
        widget_6 = new QWidget(widget_5);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setGeometry(QRect(0, 0, 831, 50));
        horizontalLayout_3 = new QHBoxLayout(widget_6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_5 = new QPushButton(widget_6);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        horizontalLayout_3->addWidget(pushButton_5);

        horizontalSpacer_7 = new QSpacerItem(474, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        pushButton_f5 = new QPushButton(widget_6);
        pushButton_f5->setObjectName(QString::fromUtf8("pushButton_f5"));

        horizontalLayout_3->addWidget(pushButton_f5);

        stackedWidget->addWidget(page_Draftletter);
        page_Sendedpage = new QWidget();
        page_Sendedpage->setObjectName(QString::fromUtf8("page_Sendedpage"));
        tableView_sended = new QTableView(page_Sendedpage);
        tableView_sended->setObjectName(QString::fromUtf8("tableView_sended"));
        tableView_sended->setGeometry(QRect(10, 80, 811, 461));
        tableView_sended->setStyleSheet(QString::fromUtf8("background-color: rgb(254, 246, 233);"));
        stackedWidget->addWidget(page_Sendedpage);
        page_Bin = new QWidget();
        page_Bin->setObjectName(QString::fromUtf8("page_Bin"));
        widget_7 = new QWidget(page_Bin);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setGeometry(QRect(0, 20, 831, 531));
        widget_8 = new QWidget(widget_7);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        widget_8->setGeometry(QRect(0, 0, 606, 50));
        horizontalLayout_4 = new QHBoxLayout(widget_8);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton_6 = new QPushButton(widget_8);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        horizontalLayout_4->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(widget_8);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        horizontalLayout_4->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(widget_8);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        horizontalLayout_4->addWidget(pushButton_8);

        horizontalSpacer_8 = new QSpacerItem(284, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        tableView_bin = new QTableView(widget_7);
        tableView_bin->setObjectName(QString::fromUtf8("tableView_bin"));
        tableView_bin->setGeometry(QRect(11, 58, 811, 461));
        tableView_bin->setStyleSheet(QString::fromUtf8("background-color: rgb(254, 246, 233);"));
        stackedWidget->addWidget(page_Bin);
        listWidget = new QListWidget(centralwidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(0, 30, 171, 531));
        listWidget->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/back2.png);\n"
"font: 75 9pt \"Agency FB\";\n"
"font: 18pt \"\345\256\213\344\275\223\";\n"
""));
        mainwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mainwindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1068, 26));
        mainwindow->setMenuBar(menubar);
        statusbar = new QStatusBar(mainwindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        mainwindow->setStatusBar(statusbar);

        retranslateUi(mainwindow);

        stackedWidget->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(mainwindow);
    } // setupUi

    void retranslateUi(QMainWindow *mainwindow)
    {
        mainwindow->setWindowTitle(QApplication::translate("mainwindow", "MainWindow", nullptr));
        label_2->setText(QApplication::translate("mainwindow", "      FlowerMail", nullptr));
        Btn_preview->setText(QApplication::translate("mainwindow", "\351\242\204\350\247\210", nullptr));
        Btn_draft->setText(QApplication::translate("mainwindow", "\345\255\230\350\215\211\347\250\277", nullptr));
        Btn_cancel->setText(QApplication::translate("mainwindow", "\345\217\226\346\266\210", nullptr));
        Btn_send->setText(QApplication::translate("mainwindow", "\345\217\221\351\200\201", nullptr));
        label_reciever->setText(QApplication::translate("mainwindow", "\346\224\266\344\273\266\344\272\272\357\274\232", nullptr));
        label_theme->setText(QApplication::translate("mainwindow", "\344\270\273\351\242\230\357\274\232", nullptr));
        Btn_resend->setText(QApplication::translate("mainwindow", "\346\212\204\351\200\201", nullptr));
        Btn_sendsecret->setText(QApplication::translate("mainwindow", "\345\257\206\351\200\201", nullptr));
        Btn_qfdx->setText(QApplication::translate("mainwindow", "\347\276\244\345\217\221\345\215\225\346\230\276", nullptr));
        Btn_send_2->setText(QApplication::translate("mainwindow", "\345\217\221\351\200\201", nullptr));
        Btn_add->setText(QApplication::translate("mainwindow", "\346\267\273\345\212\240\351\231\204\344\273\266\357\274\232", nullptr));
        toolButton->setText(QApplication::translate("mainwindow", "...", nullptr));
        Btn_cancel_2->setText(QApplication::translate("mainwindow", "\345\217\226\346\266\210", nullptr));
        label_sender->setText(QString());
        btn_receive_selectall->setText(QApplication::translate("mainwindow", "\345\205\250\351\203\250\351\200\211\346\213\251", nullptr));
        pushButton_readall->setText(QApplication::translate("mainwindow", "\345\205\250\351\203\250\345\267\262\350\257\273", nullptr));
        btn_receive_delete->setText(QApplication::translate("mainwindow", "\345\210\240\351\231\244", nullptr));
        btn_receive_deleteall->setText(QApplication::translate("mainwindow", "\345\275\273\345\272\225\345\210\240\351\231\244", nullptr));
        btn_star_selectall->setText(QApplication::translate("mainwindow", "\345\205\250\351\203\250\351\200\211\346\213\251", nullptr));
        btn_star_cancel->setText(QApplication::translate("mainwindow", "\345\217\226\346\266\210\346\230\237\346\240\207", nullptr));
        pushButton_5->setText(QApplication::translate("mainwindow", "\345\210\240\351\231\244", nullptr));
        pushButton_f5->setText(QApplication::translate("mainwindow", "\345\210\267\346\226\260", nullptr));
        pushButton_6->setText(QApplication::translate("mainwindow", "\351\200\211\346\213\251\345\205\250\351\203\250", nullptr));
        pushButton_7->setText(QApplication::translate("mainwindow", "\346\201\242\345\244\215", nullptr));
        pushButton_8->setText(QApplication::translate("mainwindow", "\345\275\273\345\272\225\345\210\240\351\231\244", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("mainwindow", "\351\246\226\351\241\265", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("mainwindow", "\345\206\231\344\277\241", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("mainwindow", "\346\224\266\344\273\266\347\256\261", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("mainwindow", "\346\224\266\350\227\217\351\202\256\344\273\266", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = listWidget->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("mainwindow", "\350\215\211\347\250\277\347\256\261", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = listWidget->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("mainwindow", "\345\267\262\345\217\221\351\200\201", nullptr));
        QListWidgetItem *___qlistwidgetitem6 = listWidget->item(6);
        ___qlistwidgetitem6->setText(QApplication::translate("mainwindow", "\345\233\236\346\224\266\347\256\261", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class mainwindow: public Ui_mainwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
