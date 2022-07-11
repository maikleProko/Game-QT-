#pragma once
#ifndef ITEM_OBJECT_H
#define ITEM_OBJECT_H
#include "scene.h"
#include <iostream>
#include "libs.h"
#include "publisher.h"

class item_object
{
public:
    virtual ~item_object() {};
    virtual void set_item_object(int x_public, int y_public, int k_public) = 0;
    virtual int getX() = 0;
    virtual int getY() = 0;
    virtual int getK() = 0;
    virtual QImage getPosition() = 0;
    virtual void setX(int k) = 0;
    virtual void setY(int k) = 0;


};

#endif // ITEM_OBJECT_H
