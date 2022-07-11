#include "enemy002.h"

enemy002::enemy002(int local_animation_behavior)
{
    this->animation_behavior=local_animation_behavior;
    this->local_frame=0;
}


enemy002::~enemy002()
{

}

void enemy002::Stop()
{

}

void enemy002::StartedSetPosition(int x_local, int y_local)
{
    this->x_public=x_local;
    this->y_public=y_local;
    Scene::getInstance()->a[x_public][y_public].unit=3;
}



void enemy002::LocalSetLocation(int x, int y)
{
    Scene::getInstance()->a[x_public][y_public].unit=0;
    this->x_public+=x;
    this->y_public+=y;
    Scene::getInstance()->a[x_public][y_public].unit=3;
}

void enemy002::Defense()
{

}

void enemy002::variant()
{
    srand(time(0));
    int random = (rand() % 3);

    if(random==0) this->animation_behavior=1;
    if(random==1) this->animation_behavior=2;
    if(random==2) this->animation_behavior=3;
}

void enemy002::nullFrame()
{
    this->local_frame=0;
}

void enemy002::iterFrame()
{
    this->local_frame++;
}


int enemy002::GetX()
{
    return x_public;
}


int enemy002::GetY()
{
    return y_public;
}

int enemy002::GetAnimationBehavior()
{
    return this->animation_behavior;
}

int enemy002::GetFrame()
{
    return this->local_frame;
}


void enemy002::SetAnimationBehavior(int local_animation_behavior)
{
    this->animation_behavior=local_animation_behavior;
}

void enemy002::operator*=(char k)
{
    if((k=='d')&&(player::one_player()->GetX()==x_public)&&(player::one_player()->GetY()==y_public))
    {
        player::one_player()->death=1;
    }

}
