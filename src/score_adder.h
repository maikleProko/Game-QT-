#ifndef SCORE_ADDER_H
#define SCORE_ADDER_H
#include "item_object.h"

class score_adder: public item_object
{
private:
    int k_private;
    int x_private, y_private;
    QImage position;
public:
    score_adder(int x=1, int y=1, int k_public=1, QImage position=scoreup);
    ~score_adder();
    void set_item_object(int x_public, int y_public, int k_public);
    int getX();
    int getY();
    int getK();
    QImage getPosition();
    void setX(int k);
    void setY(int k);
};
#endif // SCORE_ADDER_H
