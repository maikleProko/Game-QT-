#ifndef subscriber_square_H
#define subscriber_square_H
#include "subscriber.h"
#include <fstream>

class subscriber_square: public subscriber
{
public:
    subscriber_square();
    ~subscriber_square();
    void upfile(publisher* My_publisher) override;

};

#endif // subscriber_square_H
