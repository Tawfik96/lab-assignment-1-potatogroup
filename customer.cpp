#include "customer.h"
#include "ui_customer.h"
#include"home.h"
#include<QMessageBox>  //added
#include "CartExceptions.h"
customer::customer(QWidget *parent) :
       QDialog(parent)
     ,ui(new Ui::customer)

{
    ui->setupUi(this);
}

customer::~customer()
{
    delete ui;
}

void customer::on_pushButton_5_clicked()
{
   homewin = new home();
   homewin->show();
   this->close();
}


 void customer::on_Sname_clicked()
{


    for (int i=0; i< 10; i++) //10 is the preset size for the marketplace products array
     if(ui->name->text()==cm.products[i].name)
         ui->Name_List->setText("Product Name: "+cm.products[i].name+"\n "+ "Price: "+cm.products[i].price+"\n "+ "Quantity: "+cm.products[i].quantity+"\n "+ "Category: "+cm.products[i].category);

}


void customer::on_Scategory_clicked()
{

reset();
      for (int i=0; i< 10; i++)
          if(ui->category->text()==cm.products[i].category)
          {
              ui->Category_List->setText(ui->Category_List->text()+"\n"+cm.products[i].name);
          }

}


void customer::on_add_clicked()
{
    for(int i=0;i<ccart.size();i++)
    {

        if(ui->product->text()==ccart[i].name)
        {
          QMessageBox::warning(this,"Error","product already exists");
        return;
        }
   }
    for (int i=0; i< 10; i++){
     if((ui->product->text()==cm.products[i].name) && ui->quantity->text().toInt()>0 && ui->quantity->text()!="")
     {
         try{
             if(ui->quantity->text().toDouble()>cm.products[i].quantity.toDouble())
                {
                     throw NoAvailableQuantity();
                }
             else
                {
             ui->cart->setText(ui->cart->text()+"\n"+cm.products[i].name+"("+ui->quantity->text()+")"+"                                             "+cm.products[i].price);
              total+=(cm.products[i].price.toDouble() * ui->quantity->text().toDouble());
              ui->price->setText(QString::number(total));
                p.name=ui->product->text();
                p.quantity=ui->quantity->text();
              ccart.push_back(p);
                  }
             }
         catch(NoAvailableQuantity &x)
         {
            QMessageBox::warning(this,"Erorr",x.what());
         }
     }

    }


    ui->quantity->setText("");
    ui->product->setText("");

}

void customer::reset()
{
    ui->Category_List->setText("");
}

void customer::on_confirm_clicked()
{
    try{

        if(ccart.empty())
        {
         throw EmptyCart_exception();
        }



        }
    catch (EmptyCart_exception& e) {
        QMessageBox::warning(this,"Error",e.what());
        return;
    }
    QMessageBox::StandardButton check;
    check = QMessageBox::question(this, "Test", "Are you sure?\n\nTotal price: "+QString::number(total)+" $",
                                  QMessageBox::Yes|QMessageBox::No);
    if(check==QMessageBox::Yes)
    {
        for(int p=0; p<ccart.size();p++)
        for(int i=0;i<10;i++)
        {

            if(cm.products[i].name==ccart[p].name)
            {
                   cm.products[i].quantity=QString::number(cm.products[i].quantity.toDouble()-ccart[p].quantity.toDouble());
                        cm.update();
             }

        }
        on_pushButton_5_clicked();
    }else
    {
        on_pushButton_5_clicked();

    }



}




