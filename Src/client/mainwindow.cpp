#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "user.h"
#include "buttondelegate.h"
#include <QButtonGroup>
#include <QFontDialog>
#include <unistd.h>
#include <QtNetwork>
#include <QGraphicsOpacityEffect>

#define QIP "192.168.118.137"

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

struct st_mail{
    char operation[4];
    char frid[16];
    char toid[16];
    char title[64];
    char datetime[32];
    char content[892];

};

struct st_mail_list{
    int sum;
    struct st_mail list[10];
};

mainwindow::mainwindow(QString name,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainwindow)
{
    ui->setupUi(this);
    ui->centralwidget->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(":/new/prefix1/back.png");
    palette.setBrush(QPalette::Window,QBrush(pixmap.scaled(this->size())));
    ui->centralwidget->setPalette(palette);
    ui->centralwidget->show();


    QFont fontt("Microsoft YaHei",50,25);
    ui->label_2->setFont(fontt);

//    QGraphicsOpacityEffect* opacityEffect2 = new QGraphicsOpacityEffect;
//    opacityEffect2->setOpacity(1);
//    ui->textEdit->setGraphicsEffect(opacityEffect2);

    setWindowTitle("FlowerMail");

    //把QListWidget和stackedWidget对应起来
    connect(ui->listWidget,SIGNAL(currentRowChanged(int)),ui->stackedWidget,SLOT(setCurrentIndex(int)));

    user = new User(name);

    //写信页面的布局
    init_sendLetter();

    //tableWidget的布局
    init_tableWidget();

    timer = new QTimer();
    timer->start(10000);
    connect(timer, SIGNAL(timeout()),this, SLOT(updateTime()));



    //添加表内信息
    display(user->username);



}

mainwindow::~mainwindow()
{
    delete ui;
}

void mainwindow::init_sendLetter()  //写信页面
{
    MainLayout = new QVBoxLayout(this);
    toplayout = new QHBoxLayout();
    toplayout->addWidget(ui->Btn_send);
    toplayout->addWidget(ui->Btn_preview);
    toplayout->addWidget(ui->Btn_draft);
    toplayout->addWidget(ui->Btn_cancel);
    toplayout->addStretch();
    toplayout->addWidget(ui->Btn_resend);
    toplayout->addWidget(ui->Btn_sendsecret);
    toplayout->addWidget(ui->Btn_qfdx);
    //toplayout->addWidget(ui->Btn_invite);

    middlelayout = new QGridLayout;
    middlelayout->addWidget(ui->label_reciever,0,0);
    middlelayout->addWidget(ui->Editor_reciever,0,1);
    middlelayout->addWidget(ui->label_theme,1,0);
    middlelayout->addWidget(ui->Editor_theme,1,1);

    Buttonlayout = new QHBoxLayout();

    fontLabel1 = new QLabel(tr("字体:"));
    fontComboBox = new QFontComboBox;
    fontComboBox->setFontFilters(QFontComboBox::ScalableFonts);

    fontLabel2 = new QLabel(tr("字号:"));
    sizeComboBox = new QComboBox;
    QFontDatabase db;
    foreach(int size, db.standardSizes())
    {
        sizeComboBox->addItem(QString::number(size));
    }

    QSize size(24,24);

    boldBtn = new QToolButton;
    boldBtn->setIcon(QIcon(":/new/prefix1/b.PNG"));
    boldBtn->setCheckable(true);
    boldBtn->setIconSize(size);
    boldBtn->setAutoRaise(true);

    italicBtn = new QToolButton;
    italicBtn->setIcon(QIcon(":/new/prefix1/i.PNG"));
    italicBtn->setCheckable(true);
    italicBtn->setIconSize(size);
    italicBtn->setAutoRaise(true);

    underlineBtn = new QToolButton;
    underlineBtn->setIcon(QIcon(":/new/prefix1/u.PNG"));
    underlineBtn->setCheckable(true);
    underlineBtn->setIconSize(size);
    underlineBtn->setAutoRaise(true);

    colorBtn = new QToolButton;
    colorBtn->setIcon(QIcon(":/new/prefix1/a.PNG"));
    colorBtn->setIconSize(size);
    colorBtn->setAutoRaise(true);

    Btgrp2 = new QButtonGroup;
    //undo/redo Action
    undoAction = new QToolButton;
    undoAction->setIcon(QIcon(":/new/prefix1/time.JPG"));
    undoAction->setIconSize(size);
    undoAction->setAutoRaise(true);
    Btgrp2->addButton(undoAction,1);

    redoAction= new QToolButton;
    redoAction->setIcon(QIcon(":/new/prefix1/add.png"));
    redoAction->setIconSize(size);
    redoAction->setAutoRaise(true);
    Btgrp2->addButton(redoAction,2);
    connect(Btgrp2,SIGNAL(buttonClicked(int)),this,SLOT(unredo(int)));

     //排版
     Btgrp = new QButtonGroup;
     leftAction= new QToolButton;
     leftAction->setIcon(QIcon(":/new/prefix1/left.PNG"));
     leftAction->setCheckable(true);
     leftAction->setIconSize(size);
     leftAction->setAutoRaise(true);
     Btgrp->addButton(leftAction,1);

     rightAction= new QToolButton;
     rightAction->setIcon(QIcon(":/new/prefix1/right.PNG"));
     rightAction->setCheckable(true);
     rightAction->setIconSize(size);
     rightAction->setAutoRaise(true);
     Btgrp->addButton(rightAction,2);

     centerAction= new QToolButton;
     centerAction->setIcon(QIcon(":/new/prefix1/center.PNG"));
     centerAction->setCheckable(true);
     centerAction->setIconSize(size);
     centerAction->setAutoRaise(true);
     Btgrp->addButton(centerAction,3);

     justifyAction= new QToolButton;
     justifyAction->setIcon(QIcon(":/new/prefix1/justify.PNG"));
     justifyAction->setCheckable(true);
     justifyAction->setIconSize(size);
     justifyAction->setAutoRaise(true);
     Btgrp->addButton(justifyAction,4);
     connect(Btgrp,SIGNAL(buttonClicked(int)),this,SLOT(ShowAlignment(int)));

     Buttonlayout->addWidget(boldBtn);
     Buttonlayout->addWidget(italicBtn);
     Buttonlayout->addWidget(underlineBtn);
     Buttonlayout->addWidget(colorBtn);

     Buttonlayout->addWidget(leftAction);
     Buttonlayout->addWidget(centerAction);
     Buttonlayout->addWidget(rightAction);
     Buttonlayout->addWidget(justifyAction);

     Buttonlayout->addWidget(fontLabel2);
     Buttonlayout->addWidget(sizeComboBox);
     Buttonlayout->addWidget(fontLabel1);
     Buttonlayout->addWidget(fontComboBox);

//    Buttonlayout->addWidget(action);
     Buttonlayout->addWidget(undoAction);
     Buttonlayout->addWidget(redoAction);
     Buttonlayout->addWidget(ui->toolButton);

     Buttonlayout->addWidget(ui->Btn_add);
     Buttonlayout->addStretch();

     buttomlayout = new QHBoxLayout();
     buttomlayout->addWidget(ui->Btn_send_2);
     buttomlayout->addWidget(ui->Btn_cancel_2);
     buttomlayout->addStretch();

     MainLayout->addLayout(toplayout);
     MainLayout->addLayout(middlelayout);
     MainLayout->addLayout(Buttonlayout);
     MainLayout->addWidget(ui->textEdit);
     MainLayout->addWidget(ui->label_sender);
     MainLayout->addLayout(buttomlayout);

     ui->page_Writeletter->setLayout(MainLayout);

     connect(fontComboBox,SIGNAL(activated(QString)),this,SLOT(ShowFontComboBox(QString)));
     connect(sizeComboBox,SIGNAL(activated(QString)),this,SLOT(ShowSizeSpinBox(QString)));
     connect(boldBtn,SIGNAL(clicked()),this,SLOT(ShowBoldBtn()));
     connect(italicBtn,SIGNAL(clicked()),this,SLOT(ShowItalicBtn()));
     connect(underlineBtn,SIGNAL(clicked()),this,SLOT(showUnderlineButton()));
     connect(colorBtn,SIGNAL(clicked()),this,SLOT(ShowColorBtn()));
     connect( ui->textEdit, SIGNAL( currentCharFormatChanged( const QTextCharFormat & ) ), this, SLOT( ShowCurrentFormatChanged(const QTextCharFormat&)));

     connect(ui->Btn_send,SIGNAL(clicked()),this,SLOT(button_send()));
     connect(ui->Btn_send_2,SIGNAL(clicked()),this,SLOT(button_send()));
}

void mainwindow::ShowBoldBtn()
{
    QTextCharFormat fmt;
    fmt.setFontWeight(boldBtn->isChecked()?QFont::Bold:QFont::Normal);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}

void mainwindow::ShowItalicBtn()
{
    QTextCharFormat fmt;
    fmt.setFontItalic(italicBtn->isChecked());
    ui->textEdit->mergeCurrentCharFormat(fmt);
}

void mainwindow::showUnderlineButton()
{
    QTextCharFormat fmt;
    fmt.setFontUnderline(underlineBtn->isChecked());
    ui->textEdit->mergeCurrentCharFormat(fmt);
    qDebug()<<"underline!!!";
}

void mainwindow::ShowColorBtn()
{
    QColor color = QColorDialog::getColor(Qt::red,this);

    if(color.isValid()){
        QTextCharFormat fmt;
        fmt.setForeground(color);
        ui->textEdit->mergeCurrentCharFormat(fmt);
    }
}

void mainwindow::ShowAlignment(int id)
{
    qDebug()<<"id:"<<id;
    if(id==1){
        ui->textEdit->setAlignment(Qt::AlignLeft);
    }
    if(id==2){
        ui->textEdit->setAlignment(Qt::AlignRight);
    }
    if(id==3){
        ui->textEdit->setAlignment(Qt::AlignCenter);
    }
    if(id==4){
        ui->textEdit->setAlignment(Qt::AlignJustify);
    }
}

void mainwindow::unredo(int id)
{
    if(id==1){
        ui->textEdit->undo();
    }
    if(id==2){
        ui->textEdit->redo();
    }
}

void mainwindow::ShowCurrentFormatChanged(const QTextCharFormat &fmt)
{
    fontComboBox->setCurrentIndex(fontComboBox->findText(fmt.fontFamily()));
    sizeComboBox->setCurrentIndex(sizeComboBox->findText(QString::number(fmt.fontPointSize())));
    boldBtn->setChecked(fmt.font().bold());
    italicBtn->setChecked(fmt.fontItalic());
    underlineBtn->setChecked(fmt.fontUnderline());
}

void mainwindow::ShowFontComboBox(QString comboStr)
{
    QTextCharFormat fmt;
    fmt.setFontFamily(comboStr);
    mergeFormat(fmt);
}

void mainwindow::mergeFormat(QTextCharFormat format)
{
    QTextCursor cursor = ui->textEdit->textCursor();
    if(!cursor.hasSelection()){
        cursor.select(QTextCursor::WordUnderCursor);
    }
    cursor.mergeCharFormat(format);
    ui->textEdit->mergeCurrentCharFormat(format);
}

void mainwindow::ShowSizeSpinBox(QString spinValue)
{
    QTextCharFormat fmt;
    fmt.setFontPointSize(spinValue.toDouble());
    ui->textEdit->mergeCurrentCharFormat(fmt);
}


void mainwindow::ShowCursorPositionChanged()
{
    if(ui->textEdit->alignment()==Qt::AlignLeft)
        leftAction->setChecked(true);
    if(ui->textEdit->alignment()==Qt::AlignRight)
        rightAction->setChecked(true);
    if(ui->textEdit->alignment()==Qt::AlignCenter)
        centerAction->setChecked(true);
    if(ui->textEdit->alignment()==Qt::AlignJustify)
        justifyAction->setChecked(true);
}


void mainwindow::saveImg(const QString &imgFileName,QString sn)
{
    QFile inImg(save_filename);
    QImage img;
    if(!inImg.open(QIODevice::ReadOnly)){
        QMessageBox::warning(0,"Error","Open Image File Failed");
        return;
    }
    else{
        if(!(img.load(save_filename)))
        {
            QMessageBox::information(this,tr("Open failed!"),tr("Failed!"));
            return;
        }
    }
    QDir *file = new QDir;
    bool exist = file->exists("./File");
    if(exist)
        qDebug()<<"File exits!";
    else {
        bool ok = file->mkdir("./File");
        if(ok){
            qDebug()<<"file success!";
        }
    }
    QString savename="./File/"+sn;
    img.save(savename);
}

void mainwindow::init_tableWidget()
{
    //收件箱的布局--------------------------------------------------------------

    model = new QStandardItemModel();

    //添加表头信息
    model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("选择")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("阅读")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("发件人")));
    model->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("星标")));
    model->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("标题")));
    model->setHorizontalHeaderItem(5, new QStandardItem(QObject::tr("内容")));
    model->setHorizontalHeaderItem(6, new QStandardItem(QObject::tr("日期")));

    //连接model和tableView
    ui->tableView->setModel(model);

    //设置列的宽度
    ui->tableView->setColumnWidth(0,30);
    ui->tableView->setColumnWidth(1,30);
    ui->tableView->setColumnWidth(2,130);
    ui->tableView->setColumnWidth(3,30);
    ui->tableView->setColumnWidth(4,150);
    ui->tableView->setColumnWidth(5,400);
    ui->tableView->setColumnWidth(6,150);

    //可隐藏grid
    ui->tableView->setShowGrid(false);

    //默认显示行头，也可以将隐藏
    ui->tableView->verticalHeader()->hide();

    //设置选中时为整行选中
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    //设置表格的单元为只读属性，即不能编辑
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //ui->tableView->setEditTriggers(QAbstractItemView::QAbstractItemView::CurrentChanged);



    //星际邮箱的布局--------------------------------------------------------------

    model_star = new QStandardItemModel();

    //添加表头信息
    model_star->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("选择")));
    model_star->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("阅读")));
    model_star->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("发件人")));
    model_star->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("星标")));
    model_star->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("标题")));
    model_star->setHorizontalHeaderItem(5, new QStandardItem(QObject::tr("内容")));
    model_star->setHorizontalHeaderItem(6, new QStandardItem(QObject::tr("日期")));

    //连接model和tableView
    ui->tableView_star->setModel(model_star);

    //设置列的宽度
    ui->tableView_star->setColumnWidth(0,30);
    ui->tableView_star->setColumnWidth(1,30);
    ui->tableView_star->setColumnWidth(2,130);
    ui->tableView_star->setColumnWidth(3,30);
    ui->tableView_star->setColumnWidth(4,150);
    ui->tableView_star->setColumnWidth(5,400);
    ui->tableView_star->setColumnWidth(6,150);

    //可隐藏grid
    ui->tableView_star->setShowGrid(false);

    //默认显示行头，也可以将隐藏
    ui->tableView_star->verticalHeader()->hide();

    //设置选中时为整行选中
    ui->tableView_star->setSelectionBehavior(QAbstractItemView::SelectRows);

    //设置表格的单元为只读属性，即不能编辑
    ui->tableView_star->setEditTriggers(QAbstractItemView::NoEditTriggers);



    //草稿邮箱的布局--------------------------------------------------------------

    model_draft = new QStandardItemModel();

    //添加表头信息
    model_draft->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("选择")));
    model_draft->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("阅读")));
    model_draft->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("收件人")));
    model_draft->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("星标")));
    model_draft->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("标题")));
    model_draft->setHorizontalHeaderItem(5, new QStandardItem(QObject::tr("内容")));
    model_draft->setHorizontalHeaderItem(6, new QStandardItem(QObject::tr("日期")));

    //连接model和tableView
    ui->tableView_draft->setModel(model_draft);

    //设置列的宽度
    ui->tableView_draft->setColumnWidth(0,30);
    ui->tableView_draft->setColumnWidth(1,30);
    ui->tableView_draft->setColumnWidth(2,130);
    ui->tableView_draft->setColumnWidth(3,30);
    ui->tableView_draft->setColumnWidth(4,150);
    ui->tableView_draft->setColumnWidth(5,400);
    ui->tableView_draft->setColumnWidth(6,150);

    //可隐藏grid
    ui->tableView_draft->setShowGrid(false);

    //默认显示行头，也可以将隐藏
    ui->tableView_draft->verticalHeader()->hide();

    //设置选中时为整行选中
    ui->tableView_draft->setSelectionBehavior(QAbstractItemView::SelectRows);

    //设置表格的单元为只读属性，即不能编辑
    ui->tableView_draft->setEditTriggers(QAbstractItemView::NoEditTriggers);


    //已发送的布局--------------------------------------------------------------
    model_sended = new QStandardItemModel();

    //添加表头信息
    model_sended->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("选择")));
    model_sended->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("阅读")));
    model_sended->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("收件人")));
    model_sended->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("星标")));
    model_sended->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("标题")));
    model_sended->setHorizontalHeaderItem(5, new QStandardItem(QObject::tr("内容")));
    model_sended->setHorizontalHeaderItem(6, new QStandardItem(QObject::tr("日期")));

    //连接model和tableView
    ui->tableView_sended->setModel(model_sended);

    //设置列的宽度
    ui->tableView_sended->setColumnWidth(0,30);
    ui->tableView_sended->setColumnWidth(1,30);
    ui->tableView_sended->setColumnWidth(2,130);
    ui->tableView_sended->setColumnWidth(3,30);
    ui->tableView_sended->setColumnWidth(4,150);
    ui->tableView_sended->setColumnWidth(5,400);
    ui->tableView_sended->setColumnWidth(6,150);

    //可隐藏grid
    ui->tableView_sended->setShowGrid(false);

    //默认显示行头，也可以将隐藏
    ui->tableView_sended->verticalHeader()->hide();

    //设置选中时为整行选中
    ui->tableView_sended->setSelectionBehavior(QAbstractItemView::SelectRows);

    //设置表格的单元为只读属性，即不能编辑
    ui->tableView_sended->setEditTriggers(QAbstractItemView::NoEditTriggers);



    //回收站的布局--------------------------------------------------------------
    model_bin = new QStandardItemModel();

    //添加表头信息
    model_bin->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("选择")));
    model_bin->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("阅读")));
    model_bin->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("发件人")));
    model_bin->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("星标")));
    model_bin->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("标题")));
    model_bin->setHorizontalHeaderItem(5, new QStandardItem(QObject::tr("内容")));
    model_bin->setHorizontalHeaderItem(6, new QStandardItem(QObject::tr("日期")));

    //连接model和tableView
    ui->tableView_bin->setModel(model_bin);

    //设置列的宽度
    ui->tableView_bin->setColumnWidth(0,30);
    ui->tableView_bin->setColumnWidth(1,30);
    ui->tableView_bin->setColumnWidth(2,130);
    ui->tableView_bin->setColumnWidth(3,30);
    ui->tableView_bin->setColumnWidth(4,150);
    ui->tableView_bin->setColumnWidth(5,400);
    ui->tableView_bin->setColumnWidth(6,150);

    //可隐藏grid
    ui->tableView_bin->setShowGrid(false);

    //默认显示行头，也可以将隐藏
    ui->tableView_bin->verticalHeader()->hide();

    //设置选中时为整行选中
    ui->tableView_bin->setSelectionBehavior(QAbstractItemView::SelectRows);

    //设置表格的单元为只读属性，即不能编辑
    ui->tableView_bin->setEditTriggers(QAbstractItemView::NoEditTriggers);



}





void mainwindow::display(QString name)
{
    QSqlQuery qry;

    //清空model
    model->clear();
    model_bin->clear();
    model_star->clear();
    model_sended->clear();
    //model_rubbish->clear();

    //初始化布局
    init_tableWidget();

    QTcpSocket *client; // socket 句柄
    char sip[64];   // IP 地址字符串
    struct st_mail mail; // mail结构体
    memset(&mail, 0, sizeof(mail));

    // 获取IP、端口号、收件人ID、邮件标题、邮件内容
    QString qip =QIP;
    QString qport ="8808";

    // 连接到服务器
    strcpy(sip, qip.toStdString().data());
    client = new QTcpSocket(this);
    client->connectToHost(QHostAddress(sip), qport.toInt());

    //显示收件箱--------------------------------------------------------------

    // 发送邮件到服务器
    strncpy(mail.operation, RECEIVE, 4);
    strncpy(mail.toid, user->username.toStdString().data(), 16);

    client->write((char *)&mail, 1024);

    // 获取服务器处理结果
    connect(client, &QTcpSocket::readyRead, [=]()
    {
        // 获取对方发送的内容
        char buff[10244];
        memset(buff, 0, 10244);
        client->read(buff, 10244);
        struct st_mail_list lcx;
        memset(&lcx, 0, sizeof(st_mail_list));
        memcpy(&lcx, buff, sizeof(struct st_mail_list));
        for(int i=0; i < lcx.sum ;i++)
        {
              model->setItem(i, 1, new QStandardItem("no"));
              model->setItem(i, 2, new QStandardItem(lcx.list[i].frid));
              //星标没填
              model->setItem(i, 4, new QStandardItem(lcx.list[i].title));

//              QTextEdit te;
//              te.setHtml(qry.value(4).toString());
              model->setItem(i, 5, new QStandardItem(lcx.list[i].content));
              model->setItem(i, 6, new QStandardItem(lcx.list[i].datetime));
              ui->tableView->setItemDelegate(new ButtonDelegate());

        }

        // 发送退出电文到服务器，由服务器关闭连接
        client->write(QUIT);
    });




    //显示星际邮箱--------------------------------------------------------------

    //qry.prepare( "select * from message where sender = '"+name+"' or receiver = '"+ name+" '  and important = 'yes';  " );
    //qry.prepare( "select * from message where receiver = '"+ name+" '  " );
    qry.prepare( "select * from message where receiver = '"+name+"' and important = 'yes' " );
    if( !qry.exec() )
        qDebug() <<"display star error"<<qry.lastError();
    else
        qDebug( "Select success!  display star. " );

    for(int i=0;qry.next();i++){
        model_star->setItem(i, 1, new QStandardItem(qry.value(8).toString()));
        model_star->setItem(i, 2, new QStandardItem(qry.value(1).toString()));
        model_star->setItem(i, 3, new QStandardItem(qry.value(9).toString()));
        model_star->setItem(i, 4, new QStandardItem(qry.value(3).toString()));
        QTextEdit te;
        te.setHtml(qry.value(4).toString());
        model_star->setItem(i, 5, new QStandardItem(te.toPlainText()));
        //model->setItem(i, 5, new QStandardItem(qry.value(4).toString()));
        model_star->setItem(i, 6, new QStandardItem(qry.value(6).toString()));
        ui->tableView_star->setItemDelegate(new ButtonDelegate());
    }



    //显示草稿邮箱--------------------------------------------------------------





    //显示已发件邮箱--------------------------------------------------------------

    qry.prepare( "select * from message where sender = '"+name+"' and state = 'sended';  " );
    if( !qry.exec() )
        qDebug() <<"display sended error"<<qry.lastError();
    else
        qDebug( "Select success!  display sended. " );

    for(int i=0;qry.next();i++){
        //model_sended->setItem(i, 1, new QStandardItem(qry.value(8).toString()));
        model_sended->setItem(i, 2, new QStandardItem(qry.value(2).toString()));//收件人
        //model_sended->setItem(i, 3, new QStandardItem(qry.value(9).toString()));
        model_sended->setItem(i, 4, new QStandardItem(qry.value(3).toString()));
        QTextEdit te;
        te.setHtml(qry.value(4).toString());
        model_sended->setItem(i, 5, new QStandardItem(te.toPlainText()));
        //model->setItem(i, 5, new QStandardItem(qry.value(4).toString()));
        model_sended->setItem(i, 6, new QStandardItem(qry.value(6).toString()));
        ui->tableView_sended->setItemDelegate(new ButtonDelegate());

    }



    //显示回收站邮箱--------------------------------------------------------------

    qry.prepare( "select * from message where receiver = '"+name+"' and state = 'bin';  " );
    if( !qry.exec() )
        qDebug() <<"display bin error"<<qry.lastError();
    else
        qDebug( "Select success!  display bin. " );

    for(int i=0;qry.next();i++){
        model_bin->setItem(i, 1, new QStandardItem(qry.value(8).toString()));
        model_bin->setItem(i, 2, new QStandardItem(qry.value(1).toString()));
        model_bin->setItem(i, 3, new QStandardItem(qry.value(9).toString()));
        model_bin->setItem(i, 4, new QStandardItem(qry.value(3).toString()));
        QTextEdit te;
        te.setHtml(qry.value(4).toString());
        model_bin->setItem(i, 5, new QStandardItem(te.toPlainText()));
        //model->setItem(i, 5, new QStandardItem(qry.value(4).toString()));
        model_bin->setItem(i, 6, new QStandardItem(qry.value(6).toString()));
        ui->tableView_bin->setItemDelegate(new ButtonDelegate());

    }

}

void mainwindow::button_send()
{
    if(save_filename!="") saveImg(save_filename,save_name);

    QDateTime time = QDateTime::currentDateTime();

    if(ui->Editor_reciever->text()==""){
        QMessageBox::information(this,"提示","请输入收件人！");
        return;
    }
    if(ui->Editor_theme->text()==""){
        QMessageBox::information(this,"提示","请输入邮件的主题！");
        return;
    }
    if(ui->textEdit->toPlainText()==""){
        QMessageBox::information(this,"提示","请输入内容！");
        return;
    }

    QString nname;
    if(save_filename=="") nname="null";
    else nname = save_filename;

    QString InsertStr = QString("INSERT INTO message("
                                "id, "
                                "sender, "
                                "receiver, "
                                "title, "
                                "content, "
                                "accessory, "
                                "senddate, "
                                "state, "
                                "read,"
                                "important)"

                                "VALUES("
                                "'"+user->username+time.toString("yyyyMMddhhmmss")+"', "
                                "'"+user->username+"', "
                                "'"+ui->Editor_reciever->text()+"', "
                                "'"+ui->Editor_theme->text()+"', "
                                "'"+ui->textEdit->toHtml().replace("'","\"") +"', "
                                "'"+nname+"', "
                                "'"+time.toString("yyyy-MM-dd hh:mm:ss")+"', "
                                "'sended', "
                                "'no', "
                                "'no' "
                                    " ); "
                                );

    query.prepare(InsertStr);
    qDebug()<<InsertStr;

    if(!query.exec()){
        qDebug()<<"Send Button Insert error :"<<query.lastError();
    }
    else{
        qDebug()<<"Send Button  insert data success!";
    }



    QTcpSocket *client; // socket 句柄
    char sip[64];   // IP 地址字符串
    struct st_mail mail; // mail结构体
    memset(&mail, 0, sizeof(mail));

    // 获取IP、端口号、收件人ID、邮件标题、邮件内容
    QString qip =QIP;
    QString qport ="8808";
    QString qmailto = ui->Editor_reciever->text();
    QString qtitle = ui->Editor_theme->text();
    QString qcontent = ui->textEdit->toPlainText();

    // 连接到服务器
    strcpy(sip, qip.toStdString().data());
    client = new QTcpSocket(this);
    client->connectToHost(QHostAddress(sip), qport.toInt());

    // 发送邮件到服务器
    strncpy(mail.operation, SEND, 4);
    strncpy(mail.frid, user->username.toStdString().data(),16);
    strncpy(mail.toid, qmailto.toStdString().data(), 16);
    strncpy(mail.title, qtitle.toStdString().data(), 64);
    strncpy(mail.datetime,time.toString("yyyy-MM-dd hh:mm:ss").toStdString().data(),32);
    strncpy(mail.content, qcontent.toStdString().data(), 892);

    client->write((char *)&mail, 1024);

    // 获取服务器处理结果
    connect(client, &QTcpSocket::readyRead, [=]()
    {
        // 获取对方发送的内容
        QByteArray array = client->readAll();
        QMessageBox::information(this, "Server Message", array);
        // 关闭连接
        client->write(QUIT);
    });


    display(user->username);
    ui->Editor_reciever->clear();
    ui->Editor_theme->clear();
    ui->textEdit->clear();

}


void mainwindow::on_tableView_clicked(const QModelIndex &index)
{
    qDebug()<<index.row();
    qDebug()<<index.column();
    qDebug()<<index.data().toString();


    QString id = model->data(QModelIndex(model->index( index.row(),2))).toString();
    QString time = model->data(QModelIndex(model->index( index.row(),6))).toString();
    QString ttime = time.mid(0,4)+time.mid(5,2)+time.mid(8,2)+time.mid(11,2)+time.mid(14,2)+time.mid(17,2);
    id += ttime;
    qDebug()<<id;

    QSqlQuery qry;
    if(index.column()==3){
        if(index.data().toString()=="no"){
            qry.prepare( "UPDATE message SET important = 'yes' WHERE id = '"+id+"' " );
              if( !qry.exec() )
                qDebug() << qry.lastError();
              else
                qDebug( "Updated!" );
        }
        else if(index.data().toString()=="yes"){
            qry.prepare( "UPDATE message SET important = 'no' WHERE id = '"+id+"' " );
              if( !qry.exec() )
                qDebug() << qry.lastError();
              else
                qDebug( "Updated!" );
        }
        display(user->username);
        return;
    }
    if(index.column()!=3&&index.column()!=0){//打开邮件，显示详细信息

        qry.prepare( "UPDATE message SET read = 'yes' WHERE id = '"+id+"' " );//设置已读
        if( !qry.exec() )
           qDebug() << qry.lastError();
        else
           qDebug( "Updated!" );
        display(user->username);

        Reveiver *r = new Reveiver(id);
        r->show();
    }
}

void mainwindow::on_tableView_star_clicked(const QModelIndex &index)
{
    qDebug()<<index.row();
    qDebug()<<index.column();
    qDebug()<<index.data().toString();

    QString id = model_star->data(QModelIndex(model_star->index( index.row(),2))).toString();
    QString time = model_star->data(QModelIndex(model_star->index( index.row(),6))).toString();
    QString ttime = time.mid(0,4)+time.mid(5,2)+time.mid(8,2)+time.mid(11,2)+time.mid(14,2)+time.mid(17,2);
    id += ttime;
    qDebug()<<id;

    QSqlQuery qry;
    if(index.column()==3){
        if(index.data().toString()=="no"){
            qry.prepare( "UPDATE message SET important = 'yes' WHERE id = '"+id+"' " );
              if( !qry.exec() )
                qDebug() << qry.lastError();
              else
                qDebug( "Updated!" );
        }
        else if(index.data().toString()=="yes"){
            qry.prepare( "UPDATE message SET important = 'no' WHERE id = '"+id+"' " );
              if( !qry.exec() )
                qDebug() << qry.lastError();
              else
                qDebug( "Updated!" );
        }
        display(user->username);
        return;
    }
    if(index.column()!=3&&index.column()!=0){//打开邮件，显示详细信息

        qry.prepare( "UPDATE message SET read = 'yes' WHERE id = '"+id+"' " );//设置已读
        if( !qry.exec() )
           qDebug() << qry.lastError();
        else
           qDebug( "Updated!" );
        display(user->username);

        Reveiver *r = new Reveiver(id);
        r->show();
    }
}


void mainwindow::on_tableView_draft_clicked(const QModelIndex &index)
{
    qDebug()<<index.row();
    qDebug()<<index.column();
    qDebug()<<index.data().toString();

    QString id = user->username;
    QString time = model_draft->data(QModelIndex(model_draft->index( index.row(),6))).toString();
    QString ttime = time.mid(0,4)+time.mid(5,2)+time.mid(8,2)+time.mid(11,2)+time.mid(14,2)+time.mid(17,2);
    id += ttime;
    qDebug()<<id;

    QSqlQuery qry;
    if(index.column()==3){
        if(index.data().toString()=="no"){
            qry.prepare( "UPDATE message SET important = 'yes' WHERE id = '"+id+"' " );
              if( !qry.exec() )
                qDebug() << qry.lastError();
              else
                qDebug( "Updated!" );
        }
        else if(index.data().toString()=="yes"){
            qry.prepare( "UPDATE message SET important = 'no' WHERE id = '"+id+"' " );
              if( !qry.exec() )
                qDebug() << qry.lastError();
              else
                qDebug( "Updated!" );
        }
        display(user->username);
        return;
    }
    if(index.column()!=3&&index.column()!=0){//打开邮件，显示详细信息

    }

}



void mainwindow::on_tableView_sended_clicked(const QModelIndex &index)
{
    qDebug()<<index.row();
    qDebug()<<index.column();
    qDebug()<<index.data().toString();

    QString id = user->username;
    QString time = model_sended->data(QModelIndex(model_sended->index( index.row(),6))).toString();
    QString ttime = time.mid(0,4)+time.mid(5,2)+time.mid(8,2)+time.mid(11,2)+time.mid(14,2)+time.mid(17,2);
    id += ttime;
    qDebug()<<id;


    QSqlQuery qry;
    if(index.column()==3){
        if(index.data().toString()=="no"){
            qry.prepare( "UPDATE message SET important = 'yes' WHERE id = '"+id+"' " );
              if( !qry.exec() )
                qDebug() << qry.lastError();
              else
                qDebug( "Updated!" );
        }
        else if(index.data().toString()=="yes"){
            qry.prepare( "UPDATE message SET important = 'no' WHERE id = '"+id+"' " );
              if( !qry.exec() )
                qDebug() << qry.lastError();
              else
                qDebug( "Updated!" );
        }
        display(user->username);
        return;
    }
    if(index.column()!=3&&index.column()!=0){//打开邮件，显示详细信息
        Reveiver *r = new Reveiver(id);
        qDebug()<<id<<"         !!!!!!!";
        r->show();
    }
}

void mainwindow::on_tableView_bin_clicked(const QModelIndex &index)
{
    qDebug()<<index.row();
    qDebug()<<index.column();
    qDebug()<<index.data().toString();

    QString id = model_bin->data(QModelIndex(model_bin->index( index.row(),2))).toString();
    QString time = model_bin->data(QModelIndex(model_bin->index( index.row(),6))).toString();
    QString ttime = time.mid(0,4)+time.mid(5,2)+time.mid(8,2)+time.mid(11,2)+time.mid(14,2)+time.mid(17,2);
    id += ttime;
    qDebug()<<id;

    QSqlQuery qry;
    if(index.column()==3){
        if(index.data().toString()=="no"){
            qry.prepare( "UPDATE message SET important = 'yes' WHERE id = '"+id+"' " );
              if( !qry.exec() )
                qDebug() << qry.lastError();
              else
                qDebug( "Updated!" );
        }
        else if(index.data().toString()=="yes"){
            qry.prepare( "UPDATE message SET important = 'no' WHERE id = '"+id+"' " );
              if( !qry.exec() )
                qDebug() << qry.lastError();
              else
                qDebug( "Updated!" );
        }
        display(user->username);
        return;
    }
    if(index.column()!=3&&index.column()!=0){//打开邮件，显示详细信息

        qry.prepare( "UPDATE message SET read = 'yes' WHERE id = '"+id+"' " );//设置已读
        if( !qry.exec() )
           qDebug() << qry.lastError();
        else
           qDebug( "Updated!" );
        display(user->username);

        Reveiver *r = new Reveiver(id);
        r->show();
    }
}


void mainwindow::on_btn_receive_selectall_clicked()
{
    for(int i=0;i<model->rowCount();i++){
        QVariant  ok;
        QModelIndex index= ui->tableView->model()->index(i,0, QModelIndex());

        model->setData(index, true, Qt::DisplayRole);
    }
}



void mainwindow::on_pushButton_readall_clicked()
{
    QTcpSocket *client; // socket 句柄
        char sip[64];   // IP 地址字符串
        struct st_mail mail; // mail结构体
        memset(&mail, 0, sizeof(mail));

        // 获取IP、端口号、收件人ID、邮件标题、邮件内容
        QString qip = QIP;
        QString qport ="8808";

        // 连接到服务器
        strcpy(sip, qip.toStdString().data());
        client = new QTcpSocket(this);
        client->connectToHost(QHostAddress(sip), qport.toInt());

        QSqlQuery qry;
        qry.prepare( "update  message set  read = 'yes'  where receiver = '"+user->username+"' and state = 'sended' " );
        if( !qry.exec() )
            qDebug() <<"read all error"<<qry.lastError();
        else
            qDebug( "read all correct " );

        // 发送邮件到服务器
        strncpy(mail.operation, READALL, 4);
        strncpy(mail.toid, user->username.toStdString().data(), 16);

        client->write((char *)&mail, 1024);
        // 获取服务器处理结果
        connect(client, &QTcpSocket::readyRead, [=]()
        {
            // 获取对方发送的内容
            QByteArray array = client->readAll();
            QMessageBox::information(this, "Server Message", array);
            // 关闭连接
            client->write(QUIT);
        });

        display(user->username);

}




void mainwindow::on_btn_receive_delete_clicked()
{
    QTcpSocket *client; // socket 句柄
    char sip[64];   // IP 地址字符串
    struct st_mail mail; // mail结构体
    memset(&mail, 0, sizeof(mail));

    // 获取IP、端口号、收件人ID、邮件标题、邮件内容
    QString qip = QIP;
    QString qport ="8808";

    // 连接到服务器
    strcpy(sip, qip.toStdString().data());
    client = new QTcpSocket(this);
    client->connectToHost(QHostAddress(sip), qport.toInt());


    for(int i=0;i<model->rowCount();i++){
        QVariant  ok;
        QModelIndex index= ui->tableView->model()->index(i,0, QModelIndex());

        bool data = model->data(index, Qt::DisplayRole).toBool();

        if(data==true){
            QString id = model->data(QModelIndex(model->index( index.row(),2))).toString();
            QString time = model->data(QModelIndex(model->index( index.row(),6))).toString();
            QString ttime = time.mid(0,4)+time.mid(5,2)+time.mid(8,2)+time.mid(11,2)+time.mid(14,2)+time.mid(17,2);
            id += ttime;

            QSqlQuery qry;
            qry.prepare( "update  message  set state = 'bin'  where id = '"+id+"' " );
            if( !qry.exec() )
                qDebug() <<"delete  error"<<qry.lastError();
            else
                qDebug( "delete correct " );

            // 发送邮件到服务器
            strncpy(mail.operation, BIN, 4);
            strncpy(mail.toid, user->username.toStdString().data(), 16);
            strncpy(mail.datetime, time.toStdString().data(), 32);

            client->write((char *)&mail, 1024);

        }
    }
    // 获取服务器处理结果
    connect(client, &QTcpSocket::readyRead, [=]()
    {
        // 获取对方发送的内容
        QByteArray array = client->readAll();
        QMessageBox::information(this, "Server Message", array);
        // 关闭连接
        client->write(QUIT);
    });

    display(user->username);
}




void mainwindow::on_btn_receive_deleteall_clicked()//还要修改
{
    QTcpSocket *client; // socket 句柄
    char sip[64];   // IP 地址字符串
    struct st_mail mail; // mail结构体
    memset(&mail, 0, sizeof(mail));

    // 获取IP、端口号、收件人ID、邮件标题、邮件内容
    QString qip = QIP;
    QString qport ="8808";

    // 连接到服务器
    strcpy(sip, qip.toStdString().data());
    client = new QTcpSocket(this);
    client->connectToHost(QHostAddress(sip), qport.toInt());


    for(int i=0;i<model->rowCount();i++){
        QVariant  ok;
        QModelIndex index= ui->tableView->model()->index(i,0, QModelIndex());

        bool data = model->data(index, Qt::DisplayRole).toBool();

        if(data==true){
            QString id = model->data(QModelIndex(model->index( index.row(),2))).toString();
            QString ttime = model->data(QModelIndex(model->index( index.row(),6))).toString();
            QString tttime = ttime.mid(0,4)+ttime.mid(5,2)+ttime.mid(8,2)+ttime.mid(11,2)+ttime.mid(14,2)+ttime.mid(17,2);
            id += tttime;

            QSqlQuery qry;
            qry.prepare( "delete from message   where id = '"+id+"' " );
            if( !qry.exec() )
                qDebug() <<"delete  error"<<qry.lastError();
            else
                qDebug( "delete correct " );

            // 发送邮件到服务器
            strncpy(mail.operation, DELETE, 4);
            strncpy(mail.toid, user->username.toStdString().data(), 16);
            strncpy(mail.datetime, ttime.toStdString().data(), 32);

            client->write((char *)&mail, 1024);
        }
    }
    // 获取服务器处理结果
    connect(client, &QTcpSocket::readyRead, [=]()
    {
        // 获取对方发送的内容
        QByteArray array = client->readAll();
        QMessageBox::information(this, "Server Message", array);
        // 关闭连接
        client->write(QUIT);
    });
    display(user->username);
}




void mainwindow::on_btn_star_selectall_clicked()
{
    for(int i=0;i<model_star->rowCount();i++){
        QVariant  ok;
        QModelIndex index= ui->tableView_star->model()->index(i,0, QModelIndex());

        model_star->setData(index, true, Qt::DisplayRole);
    }
}


void mainwindow::on_btn_star_cancel_clicked()
{
    QTcpSocket *client; // socket 句柄
    char sip[64];   // IP 地址字符串
    struct st_mail mail; // mail结构体
    memset(&mail, 0, sizeof(mail));

    // 获取IP、端口号、收件人ID、邮件标题、邮件内容
    QString qip = QIP;
    QString qport ="8808";

    // 连接到服务器
    strcpy(sip, qip.toStdString().data());
    client = new QTcpSocket(this);
    client->connectToHost(QHostAddress(sip), qport.toInt());

    for(int i=0;i<model_star->rowCount();i++){
        QVariant  ok;
        QModelIndex index= ui->tableView_star->model()->index(i,0, QModelIndex());

        bool data = model_star->data(index, Qt::DisplayRole).toBool();

        if(data==true){
            QString id = model_star->data(QModelIndex(model_star->index( index.row(),2))).toString();
            QString time = model_star->data(QModelIndex(model_star->index( index.row(),6))).toString();
            QString ttime = time.mid(0,4)+time.mid(5,2)+time.mid(8,2)+time.mid(11,2)+time.mid(14,2)+time.mid(17,2);
            id += ttime;
            QSqlQuery qry;
            qry.prepare( "UPDATE message SET important = 'no' WHERE id = '"+id+"' " );
            if( !qry.exec() )
                qDebug() <<"update  error"<<qry.lastError();
            else
                qDebug()<< "update correct " ;

            // 发送邮件到服务器
            strncpy(mail.operation, IMPORTANT, 4);
            strncpy(mail.toid, user->username.toStdString().data(), 16);
            strncpy(mail.datetime, time.toStdString().data(), 32);

            client->write((char *)&mail, 1024);

        }
    }
    // 获取服务器处理结果
    connect(client, &QTcpSocket::readyRead, [=]()
    {
        // 获取对方发送的内容
        QByteArray array = client->readAll();
        QMessageBox::information(this, "Server Message", array);
        // 关闭连接
        client->write(QUIT);
    });
    display(user->username);
}




void mainwindow::on_pushButton_5_clicked()
{
    QTcpSocket *client; // socket 句柄
    char sip[64];   // IP 地址字符串
    struct st_mail mail; // mail结构体
    memset(&mail, 0, sizeof(mail));

    // 获取IP、端口号、收件人ID、邮件标题、邮件内容
    QString qip = QIP;
    QString qport ="8808";

    // 连接到服务器
    strcpy(sip, qip.toStdString().data());
    client = new QTcpSocket(this);
    client->connectToHost(QHostAddress(sip), qport.toInt());

    for(int i=0;i<model_draft->rowCount();i++){
        QVariant  ok;
        QModelIndex index= ui->tableView_draft->model()->index(i,0, QModelIndex());

        bool data = model_draft->data(index, Qt::DisplayRole).toBool();

        if(data==true){
            QString id = model_draft->data(QModelIndex(model_draft->index( index.row(),2))).toString();
            strncpy(mail.toid, id.toStdString().data(), 16);
            QString time = model_draft->data(QModelIndex(model_draft->index( index.row(),6))).toString();
            QString ttime = time.mid(0,4)+time.mid(5,2)+time.mid(8,2)+time.mid(11,2)+time.mid(14,2)+time.mid(17,2);
            id += ttime;

            QSqlQuery qry;
            qry.prepare( "delete from message   where id = '"+id+"' " );
            if( !qry.exec() )
                qDebug() <<"delete  error"<<qry.lastError();
            else
                qDebug( "delete correct " );

            // 发送邮件到服务器
            strncpy(mail.operation, DELETE, 4);

            strncpy(mail.datetime, time.toStdString().data(), 32);

            client->write((char *)&mail, 1024);
            //没问题

        }
    }
    // 获取服务器处理结果
    connect(client, &QTcpSocket::readyRead, [=]()
    {
        // 获取对方发送的内容
        QByteArray array = client->readAll();
        QMessageBox::information(this, "Server Message", array);
        // 关闭连接
        client->write(QUIT);
    });

    display(user->username);
}



void mainwindow::on_pushButton_6_clicked()
{
    for(int i=0;i<model_bin->rowCount();i++){
        QVariant  ok;
        QModelIndex index= ui->tableView_bin->model()->index(i,0, QModelIndex());

        model_bin->setData(index, true, Qt::DisplayRole);
    }
}

void mainwindow::on_pushButton_7_clicked()
{
    QTcpSocket *client; // socket 句柄
    char sip[64];   // IP 地址字符串
    struct st_mail mail; // mail结构体
    memset(&mail, 0, sizeof(mail));

    // 获取IP、端口号、收件人ID、邮件标题、邮件内容
    QString qip = QIP;
    QString qport ="8808";

    // 连接到服务器
    strcpy(sip, qip.toStdString().data());
    client = new QTcpSocket(this);
    client->connectToHost(QHostAddress(sip), qport.toInt());


    for(int i=0;i<model_bin->rowCount();i++){
        QVariant  ok;
        QModelIndex index= ui->tableView_bin->model()->index(i,0, QModelIndex());

        bool data = model_bin->data(index, Qt::DisplayRole).toBool();

        if(data==true){
            QString id = model_bin->data(QModelIndex(model_bin->index( index.row(),2))).toString();
            QString time = model_bin->data(QModelIndex(model_bin->index( index.row(),6))).toString();
            QString ttime = time.mid(0,4)+time.mid(5,2)+time.mid(8,2)+time.mid(11,2)+time.mid(14,2)+time.mid(17,2);
            id += ttime;
            QSqlQuery qry;
            qry.prepare( "UPDATE message SET state = 'sended' WHERE id = '"+id+"' " );
            if( !qry.exec() )
                qDebug() <<"update  error"<<qry.lastError();
            else
                qDebug()<< "update correct " ;

            // 发送邮件到服务器
            strncpy(mail.operation, RECOVER, 4);
            strncpy(mail.toid, user->username.toStdString().data(), 16);
            strncpy(mail.datetime, time.toStdString().data(), 32);

            client->write((char *)&mail, 1024);

        }
    }
    // 获取服务器处理结果
    connect(client, &QTcpSocket::readyRead, [=]()
    {
        // 获取对方发送的内容
        QByteArray array = client->readAll();
        QMessageBox::information(this, "Server Message", array);
        // 关闭连接
        client->write(QUIT);
    });
    display(user->username);
}



void mainwindow::on_pushButton_8_clicked()
{
    QTcpSocket *client; // socket 句柄
    char sip[64];   // IP 地址字符串
    struct st_mail mail; // mail结构体
    memset(&mail, 0, sizeof(mail));

    // 获取IP、端口号、收件人ID、邮件标题、邮件内容
    QString qip = QIP;
    QString qport ="8808";

    // 连接到服务器
    strcpy(sip, qip.toStdString().data());
    client = new QTcpSocket(this);
    client->connectToHost(QHostAddress(sip), qport.toInt());


    for(int i=0;i<model->rowCount();i++){
        QVariant  ok;
        QModelIndex index= ui->tableView->model()->index(i,0, QModelIndex());

        bool data = model->data(index, Qt::DisplayRole).toBool();

        if(data==true){
            QString id = model->data(QModelIndex(model->index( index.row(),2))).toString();
            QString ttime = model->data(QModelIndex(model->index( index.row(),6))).toString();
            QString tttime = ttime.mid(0,4)+ttime.mid(5,2)+ttime.mid(8,2)+ttime.mid(11,2)+ttime.mid(14,2)+ttime.mid(17,2);
            id += tttime;

            QSqlQuery qry;
            qry.prepare( "delete from message   where id = '"+id+"' " );
            if( !qry.exec() )
                qDebug() <<"delete  error"<<qry.lastError();
            else
                qDebug( "delete correct " );

            // 发送邮件到服务器
            strncpy(mail.operation, DELETE, 4);
            strncpy(mail.toid, user->username.toStdString().data(), 16);
            strncpy(mail.datetime, ttime.toStdString().data(), 32);

            client->write((char *)&mail, 1024);
        }
    }
    // 获取服务器处理结果
    connect(client, &QTcpSocket::readyRead, [=]()
    {
        // 获取对方发送的内容
        QByteArray array = client->readAll();
        QMessageBox::information(this, "Server Message", array);
        // 关闭连接
        client->write(QUIT);
    });
    display(user->username);
}





void mainwindow::on_Btn_draft_clicked()
{
    if(save_filename!="") saveImg(save_filename,save_name);

           QDateTime time = QDateTime::currentDateTime();

           if(ui->Editor_reciever->text()==""){
               QMessageBox::information(this,"提示","请输入收件人！");
               return;
           }
           if(ui->Editor_theme->text()==""){
               QMessageBox::information(this,"提示","请输入邮件的主题！");
               return;
           }
           if(ui->textEdit->toPlainText()==""){
               QMessageBox::information(this,"提示","请输入内容！");
               return;
           }

           QString InsertStr = QString("INSERT INTO message("
                                       "id, "
                                       "sender, "
                                       "receiver, "
                                       "title, "
                                       "content, "
                                       "senddate, "
                                       "state, "
                                       "read,"
                                       "important)"

                                       "VALUES("
                                       "'"+user->username+time.toString("yyyyMMddhhmmss")+"', "
                                       "'"+user->username+"', "
                                       "'"+ui->Editor_reciever->text()+"', "
                                       "'"+ui->Editor_theme->text()+"', "
                                       "'"+ui->textEdit->toHtml().replace("'","\"")+"', "
                                       "'"+time.toString("yyyy-MM-dd hh:mm:ss")+"', "
                                       "'draft', "
                                       "'no', "
                                       "'no' "
                                           " ); "
                                       );

           query.prepare(InsertStr);
           qDebug()<<InsertStr;
           QMessageBox::information(this,"提示","储存成功");

           if(!query.exec()){
               qDebug()<<"Send Button Insert error :"<<query.lastError();
           }
           else{
               qDebug()<<"Send Button  insert data success!";
           }


           QTcpSocket *client; // socket 句柄
           char sip[64];   // IP 地址字符串
           struct st_mail mail; // mail结构体
           memset(&mail, 0, sizeof(mail));

           // 获取IP、端口号、收件人ID、邮件标题、邮件内容
           QString qip = QIP;
           QString qport ="8808";
           QString qmailto = ui->Editor_reciever->text();
           QString qtitle = ui->Editor_theme->text();
           QString qcontent = ui->textEdit->toPlainText();

           // 连接到服务器
           strcpy(sip, qip.toStdString().data());
           client = new QTcpSocket(this);
           client->connectToHost(QHostAddress(sip), qport.toInt());

           // 发送邮件到服务器
           strncpy(mail.operation, DRAFT, 4);
           strncpy(mail.frid,user->username.toStdString().data(),16);
           strncpy(mail.toid, qmailto.toStdString().data(), 16);
           strncpy(mail.title, qtitle.toStdString().data(), 64);
           strncpy(mail.datetime,time.toString("yyyy-MM-dd hh:mm:ss").toStdString().data(),32);
           strncpy(mail.content, qcontent.toStdString().data(), 892);

           client->write((char *)&mail, 1024);

           // 获取服务器处理结果
           connect(client, &QTcpSocket::readyRead, [=]()
           {
               // 获取对方发送的内容
               QByteArray array = client->readAll();
               QMessageBox::information(this, "Server Message", array);
               // 关闭连接
               client->write(QUIT);
           });
           display(user->username);
}


void mainwindow::on_Btn_cancel_clicked()
{
    ui->Editor_reciever->clear();
    ui->Editor_theme->clear();
    ui->textEdit->clear();

    ui->stackedWidget->setCurrentIndex(0);
}

void mainwindow::on_Btn_cancel_2_clicked()
{
    ui->textEdit->clear();
}

void mainwindow::on_pushButton_f5_clicked()
{
    model_draft->clear();

    //草稿邮箱的布局--------------------------------------------------------------

    model_draft = new QStandardItemModel();

    //添加表头信息
    model_draft->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("选择")));
    model_draft->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("阅读")));
    model_draft->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("收件人")));
    model_draft->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("星标")));
    model_draft->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("标题")));
    model_draft->setHorizontalHeaderItem(5, new QStandardItem(QObject::tr("内容")));
    model_draft->setHorizontalHeaderItem(6, new QStandardItem(QObject::tr("日期")));

    //连接model和tableView
    ui->tableView_draft->setModel(model_draft);

    //设置列的宽度
    ui->tableView_draft->setColumnWidth(0,30);
    ui->tableView_draft->setColumnWidth(1,30);
    ui->tableView_draft->setColumnWidth(2,130);
    ui->tableView_draft->setColumnWidth(3,30);
    ui->tableView_draft->setColumnWidth(4,150);
    ui->tableView_draft->setColumnWidth(5,400);
    ui->tableView_draft->setColumnWidth(6,150);

    //可隐藏grid
    ui->tableView_draft->setShowGrid(false);

    //默认显示行头，也可以将隐藏
    ui->tableView_draft->verticalHeader()->hide();

    //设置选中时为整行选中
    ui->tableView_draft->setSelectionBehavior(QAbstractItemView::SelectRows);

    //设置表格的单元为只读属性，即不能编辑
    ui->tableView_draft->setEditTriggers(QAbstractItemView::NoEditTriggers);


    QTcpSocket *client; // socket 句柄
    char sip[64];   // IP 地址字符串
    struct st_mail mail; // mail结构体
    memset(&mail, 0, sizeof(mail));

    // 获取IP、端口号、收件人ID、邮件标题、邮件内容
    QString qip =QIP;
    QString qport ="8808";

    // 连接到服务器
    strcpy(sip, qip.toStdString().data());
    client = new QTcpSocket(this);
    client->connectToHost(QHostAddress(sip), qport.toInt());


    // 发送邮件到服务器
    strncpy(mail.operation, DISPLAY, 4);
    strncpy(mail.frid, user->username.toStdString().data(), 16);

    client->write((char *)&mail, 1024);

    // 获取服务器处理结果
    connect(client, &QTcpSocket::readyRead, [=]()
    {
        // 获取对方发送的内容
        char buff[10244];
        memset(buff, 0, 10244);
        client->read(buff, 10244);
        struct st_mail_list lcx;
        memset(&lcx, 0, sizeof(st_mail_list));
        memcpy(&lcx, buff, sizeof(struct st_mail_list));
        for(int i=0; i < lcx.sum ;i++)
        {
              model_draft->setItem(i, 1, new QStandardItem("no"));
              model_draft->setItem(i, 2, new QStandardItem(lcx.list[i].frid));
              //星标没填
              model_draft->setItem(i, 4, new QStandardItem(lcx.list[i].title));

              model_draft->setItem(i, 5, new QStandardItem(lcx.list[i].content));
              model_draft->setItem(i, 6, new QStandardItem(lcx.list[i].datetime));
              ui->tableView_draft->setItemDelegate(new ButtonDelegate());

        }

        // 发送退出电文到服务器，由服务器关闭连接
        client->write(QUIT);
    });
}
