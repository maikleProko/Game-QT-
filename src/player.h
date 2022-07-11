#ifndef PLAYER_H
#define PLAYER_H
#include "scene.h"
#include "publisher.h"
class player: public publisher
{
private:
    QImage position;
    int speed;
    int score;
    int money;
    int x_public;
    int y_public;
    int animation;

    std::list<bridge*> subscribes;
public:
    bool death=0;
    player(int x_public=0, int y_public=1, int speed_public=1, QImage position=main_player);
    static player* one_player();
    void operator+= (char k);
    void SetLocation(int x, int y);
    void SetLocationFin(int x, int y);
    void AddScore(int k);
    void AddSpeed(int k);
    void AddMoney(int k);
    void SetAnimation(int k);
    int GetScore();
    int GetSpeed();
    int GetMoney();
    int GetAnimation();
    int GetX();
    int GetY();
    void SetX(int k);
    void SetY(int k);

    void SetScore(int k);
    void SetSpeed(int k);
    void SetMoney(int k);


    void subscribe(bridge* My_bridge) override;
    void unsubscribe(bridge* My_bridge) override;
    void notify()  override;
    friend std::ostream& operator<<(std::ostream &flash, player& my_player);

};

#endif // PLAYER_H
