#ifndef SELLER_H
#define SELLER_H
#include"product.h"
#include <QDialog>
#include<fstream>
#include"Market.h"
class home;
namespace Ui {
class seller;
}

class seller : public QDialog
{
    Q_OBJECT

public:
    explicit seller(QWidget *parent = nullptr);
    ~seller();
        QString name, email;
           product new_prod;


private slots:
    void on_pushButton_2_clicked();

    void on_addpro_clicked();

    void reset();

private:
    Ui::seller *ui;

    home *homewin;
    Market MS;
};

#endif // SELLER_H
