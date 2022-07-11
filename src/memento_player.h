#ifndef memento_player_H
#define memento_player_H
#include "memento.h"
#include "scene.h"
#include "player.h"
class memento_player: public memento
{
    int mememto_money, mememto_score, mememto_speed;
    QImage** private_image;
public:
    memento_player();
    //load
    //for player
    void SetImage(int i, int j, QImage k) override;
    void SetSpeed( int k) override;
    void SetScore( int k) override;
    void SetMoney( int k) override;
    //for scene
    void SetXmax( int k) override;
    void SetYmax( int k) override;
    void SetUnit(int i, int j,  int k) override;

    //save
    //for player
    QImage GetImage(int i, int j) override;
    int GetSpeed() override;
    int GetScore() override;
    int GetMoney() override;
    //for scene
    int GetXmax() override;
    int GetYmax() override;
    int GetUnit(int i, int j) override;



};
#endif // memento_player_H
