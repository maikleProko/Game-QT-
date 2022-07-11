#include "bridge.h"
#include "libs.h"

bridge::bridge(subscriber *local_subscriber): my_subscriber(local_subscriber){}

void bridge::upBridge(publisher *my_publisher)
{
    my_subscriber->upfile(my_publisher);
}
