#include "memento_player.h"


memento_player::memento_player()
{
    mememto_money=player::one_player()->GetMoney();
    mememto_score=player::one_player()->GetScore();
    mememto_speed=player::one_player()->GetSpeed();
}


int memento_player::GetXmax()
{
    return 1;
}



int memento_player::GetYmax()
{
    return 1;
}


QImage memento_player::GetImage(int i, int j)
{
    return private_image[i][j];
}

int memento_player::GetSpeed()
{
    return mememto_speed;
}


int memento_player::GetScore()
{
    return mememto_score;
}

int memento_player::GetMoney()
{
    return mememto_money;
}



int memento_player::GetUnit(int i, int j)
{
}


void memento_player::SetUnit(int i, int j,int k)
{
}

void memento_player::SetImage(int i, int j, QImage k)
{
}

void memento_player::SetXmax(int k)
{
}

void memento_player::SetYmax(int k)
{
}

void memento_player::SetSpeed(int k)
{
    player::one_player()->AddSpeed(-1*player::one_player()->GetSpeed());
    player::one_player()->AddSpeed(k);
}


void memento_player::SetScore(int k)
{
    player::one_player()->AddScore(-1*player::one_player()->GetScore());
    player::one_player()->AddScore(k);
}

void memento_player::SetMoney(int k)
{
    player::one_player()->AddMoney(-1*player::one_player()->GetMoney());
    player::one_player()->AddMoney(k);
}
