#include "subscriber_player.h"
#include "player.h"
#include "openlog.h"
#include "libs.h"

subscriber_player::subscriber_player()
{

}

subscriber_player::~subscriber_player()
{

}

void subscriber_player::upfile(publisher *My_publisher)
{
    OpenLog::My_OpenLog()->my_file << *(dynamic_cast<player*>(My_publisher));

}
