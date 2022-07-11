#include "speed_adder.h"
#include "scene.h"


speed_adder::speed_adder(int x, int y, int k_public, QImage position)
{
    this->k_private=k_public;
    this->x_private=x;
    this->y_private=y;
    this->position=position;
    Scene::getInstance()->a[this->x_private][this->y_private].SetSquare(1, this->position, 4);
}

void speed_adder::set_item_object(int x, int y, int k)
{
    Scene::getInstance()->a[this->x_private][this->y_private].SetSquare(0, standard, 1);
    this->k_private=k;
    this->x_private=x;
    this->y_private=y;
    Scene::getInstance()->a[this->x_private][this->y_private].SetSquare(1, this->position, 4);

}
speed_adder::~speed_adder()
{

}

int speed_adder::getX()
{
    return this->x_private;
}

int speed_adder::getY()
{
    return this->y_private;
}

int speed_adder::getK()
{
    return this->k_private;
}

QImage speed_adder::getPosition()
{
    return this->position;
}

void speed_adder::setX(int k)
{
    this->x_private=k;
}

void speed_adder::setY(int k)
{
    this->y_private=k;
}

