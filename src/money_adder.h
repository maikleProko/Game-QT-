#ifndef MONEY_ADDER_H
#define MONEY_ADDER_H
#include "item_object.h"

class money_adder: public item_object
{
private:
    int k_private;
    int x_private, y_private;
    QImage position;
public:
    money_adder(int x=1, int y=1, int k_public=1, QImage position=moneyup);
    ~money_adder();
    void set_item_object(int x_public, int y_public, int k_public);
    int getX();
    int getY();
    int getK();
    QImage getPosition();
    void setX(int k);
    void setY(int k);
};
#endif // money_ADDER_H
