#ifndef REVEIVER_H
#define REVEIVER_H


#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlRecord>
#include <QPainter>

namespace Ui {
class Reveiver;
}

class Reveiver : public QMainWindow
{
    Q_OBJECT

public:
    explicit Reveiver(QString s,QWidget *parent = nullptr);
    ~Reveiver();

    void init();

private:
    Ui::Reveiver *ui;
    QSqlQuery qry;
    QPixmap outImg;
    QString name;
};

#endif // REVEIVER_H
