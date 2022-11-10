#ifndef HOME_H
#define HOME_H
#include <QMainWindow>
#include"product.h"
class registercust;
class registerseller;
QT_BEGIN_NAMESPACE
namespace Ui { class home; }
QT_END_NAMESPACE

class home : public QMainWindow
{
    Q_OBJECT

public:
    home(QWidget *parent = nullptr);
    ~home();
       product *home_p;
private slots:
    void on_sellpb_clicked();

    void on_buypb_clicked();

private:
    Ui::home *ui;
    registercust * custwin;
    registerseller * sellerwin;

};
#endif // HOME_H
