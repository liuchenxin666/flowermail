#ifndef REGISTER_H
#define REGISTER_H

#include <QMainWindow>

namespace Ui {
class rregister;
}

class rregister : public QMainWindow
{
    Q_OBJECT

public:
    explicit rregister(QWidget *parent = nullptr);
    ~rregister();

private:
    Ui::rregister *ui;
};

#endif // REGISTER_H
