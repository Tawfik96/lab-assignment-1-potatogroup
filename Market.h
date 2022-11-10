#ifndef MARKET_H
#define MARKET_H
#include<fstream>
#include"product.h"
class Market
{
    std::string temp;

    int end;
public:
      product products[10];
    Market() {
       end= download();

    }

    int download()

    {

        std::ifstream read;
        read.open("PRODUCTS.txt");
        int i=0;
        while(!read.eof())//name - category - price - quantity
        {
            read>>temp;
            products[i].name=QString::fromStdString(temp);
            read>>temp;
            products[i].category=QString::fromStdString(temp);
            read>>temp;
            products[i].price=QString::fromStdString(temp);
            read>>temp;
            products[i].quantity=QString::fromStdString(temp);

            i++;
        }
        return i;

    }

    void add_product(product p)
    {
        products[end]=p;
        update();
        end++;
    }

    void update()
    {
        std::ofstream write;
        write.open("PRODUCTS.txt");
        for(int i=0;i<=end;i++)
        {

             write<<"\n"<<products[i].name.toStdString()<<"\t"<<products[i].category.toStdString()<<"\t"<<products[i].price.toStdString()<<"\t"<<products[i].quantity.toStdString();
        }
        write.close();
    }

};
#endif // MARKET_H
