#include "care_taker.h"
#include <QDebug>
care_taker::care_taker(memento_scene* my_scene_public, memento_player* my_player_public)
{
    SceneSave.open("SceneSave.txt");
    this->my_player=my_player_public;
    this->my_scene=my_scene_public;


}

void care_taker::save()
{
    SceneSave.clear();
    SceneSave << my_scene->GetXmax() << endl;
    SceneSave << my_scene->GetYmax() << endl;

    SceneSave << my_player->GetMoney() << endl;
    SceneSave << my_player->GetSpeed() << endl;
    SceneSave << my_player->GetScore() << endl;

    for(int i = 0; i<my_scene->GetXmax(); i++)
        for(int j = 0; j<my_scene->GetYmax(); j++)
        {
            if(my_scene->GetImage(i, j) == standard)
                SceneSave << "ln";
            if(my_scene->GetImage(i, j) == rock)
                SceneSave << "rc";
            if(my_scene->GetImage(i, j) == entry)
                SceneSave << "en";
            if(my_scene->GetImage(i, j) == exite)
                SceneSave << "ex";
            if(my_scene->GetImage(i, j) == scoreup)
                SceneSave << "sc";
            if(my_scene->GetImage(i, j) == speedup)
                SceneSave << "sp";
            if(my_scene->GetImage(i, j) == moneyup)
                SceneSave << "mn";
            if(my_scene->GetUnit(i,j)==1)
                SceneSave << "ug";
            if(my_scene->GetUnit(i,j)==2)
                SceneSave << "u1";
            if(my_scene->GetUnit(i,j)==3)
                SceneSave << "u2";
            if(my_scene->GetUnit(i,j)==4)
                SceneSave << "u3";
            SceneSave << endl;
         }

}

void care_taker::load()
{

    int charecteristic;
    char timeImage[4];
    SceneSave >> charecteristic;
    my_scene->SetXmax(charecteristic);
    SceneSave >> charecteristic;
    my_scene->SetYmax(charecteristic);
    SceneSave >> charecteristic;
    my_player->SetMoney(charecteristic);
    SceneSave >> charecteristic;
    my_player->SetSpeed(charecteristic);
    SceneSave >> charecteristic;
    my_player->SetScore(charecteristic);
    for(int i = 0; i<my_scene->GetXmax(); i++)
        for(int j = 0; j<my_scene->GetYmax(); j++)
        {
            SceneSave >> timeImage;
            if((timeImage[0]=='l')&&(timeImage[1]=='n'))
                my_scene->SetImage(i,j,standard);
            if((timeImage[0]=='r')&&(timeImage[1]=='c'))
                my_scene->SetImage(i,j,rock);
            if((timeImage[0]=='e')&&(timeImage[1]=='n'))
                my_scene->SetImage(i,j,entry);
            if((timeImage[0]=='e')&&(timeImage[1]=='x'))
                my_scene->SetImage(i,j,exite);
            if((timeImage[0]=='s')&&(timeImage[1]=='c'))
                my_scene->SetImage(i,j,scoreup);
            if((timeImage[0]=='s')&&(timeImage[1]=='r'))
                my_scene->SetImage(i,j,speedup);
            if((timeImage[0]=='m')&&(timeImage[1]=='n'))
                my_scene->SetImage(i,j,moneyup);
            if((timeImage[2]=='u')&&(timeImage[3]=='g'))
                my_scene->SetUnit(i,j,1);
            if((timeImage[2]=='u')&&(timeImage[3]=='1'))
                my_scene->SetUnit(i,j,2);
            if((timeImage[2]=='u')&&(timeImage[3]=='2'))
                my_scene->SetUnit(i,j,3);
            if((timeImage[0]=='u')&&(timeImage[1]=='3'))
                my_scene->SetUnit(i,j,4);
        }
}


care_taker::~care_taker()
{

    SceneSave.close();

}
