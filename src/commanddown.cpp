#include "commanddown.h"

CommandDown::CommandDown()
{

}


void CommandDown::exec()
{
    modifiers::static_modifiers()->move_x=0;
    modifiers::static_modifiers()->move_y=player::one_player()->GetSpeed();

    if((player::one_player()->GetX()+modifiers::static_modifiers()->move_x>=0)
     &&(player::one_player()->GetY()+modifiers::static_modifiers()->move_y>=0)
     &&(player::one_player()->GetY()+modifiers::static_modifiers()->move_y<=Scene::getInstance()->ymaxscene)
     &&(player::one_player()->GetX()+modifiers::static_modifiers()->move_x<=Scene::getInstance()->xmaxscene))
    {

        Scene::getInstance()->a[player::one_player()->GetX()][player::one_player()->GetY()].unit=0;
        Scene::getInstance()->a[player::one_player()->GetX()+modifiers::static_modifiers()->move_x][player::one_player()->GetY()+modifiers::static_modifiers()->move_y].unit=1;

        modifiers::static_modifiers()->time_x1=player::one_player()->GetX();
        modifiers::static_modifiers()->time_x2=player::one_player()->GetX()+modifiers::static_modifiers()->move_x;
        modifiers::static_modifiers()->time_y1=player::one_player()->GetY();
        modifiers::static_modifiers()->time_y2=player::one_player()->GetY()+modifiers::static_modifiers()->move_y;
        player::one_player()->SetLocation(modifiers::static_modifiers()->move_x,modifiers::static_modifiers()->move_y);
    }
}


CommandDown* CommandDown::alone_CommandDown()
{
    static CommandDown instance;
            return &instance;
}
