#include "register.h"
#include "ui_register.h"

rregister::rregister(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::rregister)
{
    ui->setupUi(this);
}

rregister::~rregister()
{
delete ui;
}
