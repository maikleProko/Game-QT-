#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H
#include "publisher.h"
#include <fstream>
class publisher;

class subscriber
{
public:
    virtual void upfile(publisher* My_publisher) = 0;
    virtual ~subscriber(){}
};

#endif // SUBSCRIBER_H
