#include "money_adder.h"
#include "scene.h"

money_adder::money_adder(int x, int y, int k_public, QImage position)
{
    this->k_private=k_public;
    this->x_private=x;
    this->y_private=y;
    this->position=position;
    Scene::getInstance()->a[this->x_private][this->y_private].SetSquare(1, this->position, 4);
}

void money_adder::set_item_object(int x, int y, int k)
{
    Scene::getInstance()->a[this->x_private][this->y_private].SetSquare(0, standard, 1);
    this->k_private=k;
    this->x_private=x;
    this->y_private=y;
    Scene::getInstance()->a[this->x_private][this->y_private].SetSquare(1, this->position, 4);

}
money_adder::~money_adder()
{

}

int money_adder::getX()
{
    return this->x_private;
}

int money_adder::getY()
{
    return this->y_private;
}

int money_adder::getK()
{
    return this->k_private;
}

QImage money_adder::getPosition()
{
    return this->position;
}

void money_adder::setX(int k)
{
    this->x_private=k;
}

void money_adder::setY(int k)
{
    this->y_private=k;
}


