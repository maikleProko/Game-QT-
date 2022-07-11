#include "enemy001.h"

enemy001::enemy001(int local_animation_behavior)
{
    this->animation_behavior=local_animation_behavior;
    this->local_frame=0;
}


enemy001::~enemy001()
{

}

void enemy001::Stop()
{

}

void enemy001::StartedSetPosition(int x_local, int y_local)
{
    this->x_public=x_local;
    this->y_public=y_local;
    Scene::getInstance()->a[x_public][y_public].unit=2;
}



void enemy001::LocalSetLocation(int x, int y)
{
    Scene::getInstance()->a[x_public][y_public].unit=0;
    this->x_public+=x;
    this->y_public+=y;
    Scene::getInstance()->a[x_public][y_public].unit=2;
}

void enemy001::Defense()
{

}

void enemy001::variant()
{
    srand(time(0));
    int random = (rand() % 3);

    if(random==0) this->animation_behavior=1;
    if(random==1) this->animation_behavior=2;
    if(random==2) this->animation_behavior=3;
}

void enemy001::nullFrame()
{
    this->local_frame=0;
}

void enemy001::iterFrame()
{
    this->local_frame++;
}


int enemy001::GetX()
{
    return x_public;
}


int enemy001::GetY()
{
    return y_public;
}

int enemy001::GetAnimationBehavior()
{
    return this->animation_behavior;
}

int enemy001::GetFrame()
{
    return this->local_frame;
}


void enemy001::SetAnimationBehavior(int local_animation_behavior)
{
    this->animation_behavior=local_animation_behavior;
}

void enemy001::operator*=(char k)
{
    if((k=='d')&&(player::one_player()->GetX()==x_public)&&(player::one_player()->GetY()==y_public))
    {
        player::one_player()->death=1;
    }

}
