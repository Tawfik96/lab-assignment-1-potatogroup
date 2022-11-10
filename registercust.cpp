#include "registercust.h"
#include "ui_registercust.h"
#include "customer.h"
#include<QMessageBox>  //added
registercust::registercust(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registercust)
{
    ui->setupUi(this);

}

registercust::~registercust()
{
    delete ui;
}

void registercust::on_registerpb_clicked()
{
    if(ui->name->text()=="" ||ui->email->text()=="" )
    {
        QMessageBox::warning(this,"ERROR","Hey sneaky, Where is your info?");
    }else
    {
    custwin = new customer();
    custwin->name = ui->name->text();
    custwin->address = ui->address->text();
    custwin->email = ui->email->text();
    custwin->phone_number = ui->num->text();
    custwin->show();
    this->close();
    }



}

