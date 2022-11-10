#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <QDialog>
#include <vector>
#include "Market.h"
class home;
using namespace std;
namespace Ui {class customer;}

class customer :public QDialog
{
    Q_OBJECT

public:
    explicit customer(QWidget *parent = nullptr);
    ~customer();
    void addtocart();
    QString name, address, phone_number, email;
    double total=0;
    vector<product> ccart;
      product p;
private slots:
    void on_pushButton_5_clicked();

   void on_Sname_clicked();
   void reset();

   void on_Scategory_clicked();

   void on_add_clicked();

   void on_confirm_clicked();

private:
   Market cm;
    Ui::customer *ui;
    home *homewin;
};

#endif // CUSTOMER_H
