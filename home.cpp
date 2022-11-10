#include "home.h"
#include "ui_home.h"
#include "registerseller.h"
#include "registercust.h"
home::home(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::home)
{
    ui->setupUi(this);
    home_p=new product();
    home_p->name="home";  // ADDED
}

home::~home()
{
    delete ui;
}

void home::on_sellpb_clicked()
{
    sellerwin = new registerseller();
    sellerwin->show();
    this->close();

}


void home::on_buypb_clicked()
{
    custwin = new registercust();
   custwin->show();
   this->close();

}

