#include "player.h"



player::player(int x_public, int y_public, int speed_public, QImage position)
{
    this->x_public=x_public;
    this->y_public=y_public;
    this->position=position;

    this->animation=0;
    this->score=0;
    this->money=0;
    this->speed=speed_public;
    this->death=0;
    Scene::getInstance()->a[0][1].unit=1;
}

player* player::one_player()
{
    static player instance;
            return &instance;

}
void player::SetLocation(int x, int y)
{
    Scene::getInstance()->a[x_public+x][y_public+y].notify();
    if(Scene::getInstance()->a[this->x_public+x][this->y_public+y].GetSquare()!=rock)
    {
        if(Scene::getInstance()->a[this->x_public][this->y_public].GetTP()==2) Scene::getInstance()->a[this->x_public][this->y_public].SetImage(entry);
        else if(Scene::getInstance()->a[this->x_public][this->y_public].GetTP()==3) Scene::getInstance()->a[this->x_public][this->y_public].SetImage(exite);
        else if(Scene::getInstance()->a[this->x_public][this->y_public].GetTP()==6) Scene::getInstance()->a[this->x_public][this->y_public].SetImage(teleporter1);
        else if(Scene::getInstance()->a[this->x_public][this->y_public].GetTP()==7) Scene::getInstance()->a[this->x_public][this->y_public].SetImage(teleporter2);
        else Scene::getInstance()->a[this->x_public][this->y_public].SetImage(standard);


    if(y>0) animation=1;
    else
    if(y<0) animation=4;
    else
    if(x>0) animation=2;
    else
    if(x<0) animation=3;



    }
    notify();
}

void player::SetLocationFin(int x, int y)
{

    player& my_player= *player::one_player();
    if(Scene::getInstance()->a[this->x_public+x][this->y_public+y].GetSquare()==scoreup)
    {
        my_player+='c';
        Scene::getInstance()->a[this->x_public+x][this->y_public+y].SetImage(standard);
    }
    if(Scene::getInstance()->a[this->x_public+x][this->y_public+y].GetSquare()==speedup)
    {
        my_player+='s';
        Scene::getInstance()->a[this->x_public+x][this->y_public+y].SetImage(standard);
    }
    if(Scene::getInstance()->a[this->x_public+x][this->y_public+y].GetSquare()==moneyup)
    {
        my_player+='m';
        Scene::getInstance()->a[this->x_public+x][this->y_public+y].SetImage(standard);
    }


    this->x_public+=x;
    this->y_public+=y;
   // Scene::getInstance()->a[this->x_public][this->y_public].SetImage(this->position);
    animation=0;
}
void player::operator+=(char k)
{
    if(k=='c') player::one_player()->AddScore(1);
    if(k=='s') player::one_player()->AddSpeed(1);
    if(k=='m') player::one_player()->AddMoney(1);

}


void player::AddScore(int k)
{
    this->score+=k;
}

void player::AddMoney(int k)
{
    this->money+=k;
}

void player::AddSpeed(int k)
{
    this->speed+=k;
}

void player::SetAnimation(int k)
{
    this->animation=k;
}

int player::GetScore()
{
    return this->score;
}

int player::GetSpeed()
{
    return this->speed;
}
int player::GetMoney()
{
    return this->money;
}

int player::GetX()
{
    return this->x_public;
}

int player::GetY()
{
    return this->y_public;
}

int player::GetAnimation()
{
    return this->animation;
}

void player::SetScore(int k)
{
    this->score=k;
}

void player::SetSpeed(int k)
{
    this->speed=k;
}
void player::SetMoney(int k)
{
    this->money=k;
}











void player::subscribe(bridge *My_bridge)
{
    subscribes.push_back(My_bridge);
}

void player::unsubscribe(bridge *My_bridge)
{
    subscribes.remove(My_bridge);
}

void player::notify()
{
    std::list<bridge*>::iterator iter = subscribes.begin();
    while(iter!=subscribes.end())
    {
        (*iter)->upBridge(this);
        ++iter;
    }

}



std::ostream& operator << (std::ostream &flash, player& my_player)
{

    time_t seconds = time(NULL);
    tm* timeinfo = localtime(&seconds);
    flash << "the player went to the point: [" << my_player.GetX() << "," << my_player.GetY() << "]. time: " << asctime (timeinfo);
    return flash;
}


void player::SetX(int k)
{
    this->x_public=k;
}

void player::SetY(int k)
{
    this->y_public=k;
}
