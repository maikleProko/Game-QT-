#ifndef SUBSCRIBER_PLAYER_H
#define SUBSCRIBER_PLAYER_H
#include "subscriber.h"
#include <fstream>

class subscriber_player: public subscriber
{
public:
    subscriber_player();
    ~subscriber_player();
    void upfile(publisher* My_publisher) override;

};

#endif // SUBSCRIBER_PLAYER_H
