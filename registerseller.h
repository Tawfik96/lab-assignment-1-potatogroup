#ifndef REGISTERSELLER_H
#define REGISTERSELLER_H

#include <QDialog>

class mainwindow;
class seller;

namespace Ui {
class registerseller;
}

class registerseller : public QDialog
{
    Q_OBJECT

public:
    explicit registerseller(QWidget *parent = nullptr);
    ~registerseller();


private slots:
    void on_register_2_clicked();

private:
    Ui::registerseller *ui;
    seller * sellwin;
};

#endif // REGISTERSELLER_H
