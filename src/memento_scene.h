#ifndef memento_scene_H
#define memento_scene_H
#include "memento.h"
#include "scene.h"
#include "player.h"
class memento_scene: public memento
{
    int Xmax, Ymax;
    QImage** private_image;
public:
    memento_scene(int Xmax_private, int Ymax_private);
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
#endif // memento_scene_H
