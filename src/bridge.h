#ifndef BRIDGE_H
#define BRIDGE_H
#include "subscriber.h"
#include "publisher.h"
class subscriber;
class publisher;

class bridge
{
private:
    subscriber* my_subscriber;
public:
    bridge(subscriber* local_subscriber);
    void upBridge(publisher* my_publisher);
    ~bridge()
    {
       delete my_subscriber;

    }
};

#endif // BRIDGE_H
