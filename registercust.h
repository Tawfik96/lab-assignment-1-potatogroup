#ifndef REGISTERCUST_H
#define REGISTERCUST_H
#include <QDialog>

class mainwindow;
class customer;

namespace Ui {
class registercust;
}

class registercust : public QDialog
{
    Q_OBJECT

public:
    explicit registercust(QWidget *parent = nullptr);
    ~registercust();


private slots:
    void on_registerpb_clicked();

private:
    Ui::registercust *ui;
    customer *custwin;

};

#endif // REGISTERCUST_H
