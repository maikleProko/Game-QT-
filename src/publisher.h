#ifndef PUBLISHER_H
#define PUBLISHER_H
#include "bridge.h"
#include "subscriber.h"


class subscriber;

class bridge;

class publisher
{
public:
    virtual void subscribe(bridge* My_bridge) = 0;
    virtual void unsubscribe(bridge* My_bridge) = 0;
    virtual void notify() = 0;
    virtual ~publisher(){}


};

#endif // PUBLISHER_H
