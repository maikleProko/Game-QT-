#include "memento_scene.h"


memento_scene::memento_scene(int Xmax_private, int Ymax_private)
{
  Xmax=Xmax_private;
  Ymax=Ymax_private;

    private_image=new QImage*[Xmax];
    for(int x=0; x<Xmax; x++)
        private_image[x] = new QImage[Ymax];

    for(int i=0; i< Xmax; i++)
        for(int j=0; j<Ymax; j++)
            private_image[i][j]=Scene::getInstance()->a[i][j].GetSquare();
}


int memento_scene::GetXmax()
{
    return Xmax;
}



int memento_scene::GetYmax()
{
    return Ymax;
}


QImage memento_scene::GetImage(int i, int j)
{
    return private_image[i][j];
}

int memento_scene::GetSpeed()
{
    return 1;
}


int memento_scene::GetScore()
{
    return 1;
}

int memento_scene::GetMoney()
{
    return 1;
}


int memento_scene::GetUnit(int i, int j)
{
    return Scene::getInstance()->a[i][j].unit;
}


void memento_scene::SetUnit(int i, int j,int k)
{
    if(k==1)
    {
        player::one_player()->SetX(i);
        player::one_player()->SetY(j);
    }
    Scene::getInstance()->a[i][j].unit=k;
}

void memento_scene::SetImage(int i, int j, QImage k)
{
    Scene::getInstance()->a[i][j].SetImage(k);
}

void memento_scene::SetXmax(int k)
{
    Ymax=k;
    Scene::getInstance()->xmaxscene=k;
}

void memento_scene::SetYmax(int k)
{
    Xmax=k;
    Scene::getInstance()->ymaxscene=k;
}

void memento_scene::SetSpeed(int k)
{
}


void memento_scene::SetScore(int k)
{
}

void memento_scene::SetMoney(int k)
{
}

