#include "enemy003.h"

enemy003::enemy003(int local_animation_behavior)
{
    this->animation_behavior=local_animation_behavior;
    this->local_frame=0;
}


enemy003::~enemy003()
{

}

void enemy003::Stop()
{

}

void enemy003::StartedSetPosition(int x_local, int y_local)
{
    this->x_public=x_local;
    this->y_public=y_local;
    Scene::getInstance()->a[x_public][y_public].unit=4;
}



void enemy003::LocalSetLocation(int x, int y)
{
    Scene::getInstance()->a[x_public][y_public].unit=0;
    this->x_public+=x;
    this->y_public+=y;
    Scene::getInstance()->a[x_public][y_public].unit=4;
}

void enemy003::Defense()
{

}

void enemy003::variant()
{
    srand(time(0));
    int random = (rand() % 3);

    if(random==0) this->animation_behavior=1;
    if(random==1) this->animation_behavior=2;
    if(random==2) this->animation_behavior=3;
}

void enemy003::nullFrame()
{
    this->local_frame=0;
}

void enemy003::iterFrame()
{
    this->local_frame++;
}


int enemy003::GetX()
{
    return x_public;
}


int enemy003::GetY()
{
    return y_public;
}

int enemy003::GetAnimationBehavior()
{
    return this->animation_behavior;
}

int enemy003::GetFrame()
{
    return this->local_frame;
}


void enemy003::SetAnimationBehavior(int local_animation_behavior)
{
    this->animation_behavior=local_animation_behavior;
}

void enemy003::operator*=(char k)
{
    if((k=='d')&&(player::one_player()->GetX()==x_public)&&(player::one_player()->GetY()==y_public))
    {
        player::one_player()->death=1;
    }

}
