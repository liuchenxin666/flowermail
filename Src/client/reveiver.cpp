#include "reveiver.h"
#include "ui_reveiver.h"

Reveiver::Reveiver(QString s,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Reveiver)
{
    ui->setupUi(this);
    name=s;
    init();
}

Reveiver::~Reveiver()
{
    delete ui;
}

void Reveiver::init()
{

    qry.prepare( "select * from message where id = '"+name+"' " );
    if( !qry.exec() )
        qDebug() <<"display error"<<qry.lastError();
    else
        qDebug( "Select success!  display. " );

    qry.next();

    ui->label_Title->setText(qry.value(3).toString());
    ui->label_sender->setText(qry.value(1).toString());
    ui->label_reciever->setText(qry.value(2).toString());
    ui->label_time->setText(qry.value(6).toString());
    ui->textBrowser->setHtml(qry.value(4).toString());

}
