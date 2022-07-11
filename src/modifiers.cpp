#include "modifiers.h"

modifiers::modifiers()
{
    this->move_x = 0;
    this->move_y = 0;
    this->time_x1 = 0;
    this->time_x2 = 0;
    this->time_y1 = 0;
    this->time_y2 = 0;

}
modifiers::~modifiers()
{

}


modifiers* modifiers::static_modifiers()
{
    static modifiers instance;
            return &instance;
}
