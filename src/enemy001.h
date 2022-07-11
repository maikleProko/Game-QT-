#ifndef enemy001_H
#define enemy001_H
#include "sh_enemy.h"
#include "scene.h"
#include "player.h"
class abstract_enemy;

class enemy001
{
private:
    int animation_behavior;
    int x_public;
    int y_public;
    int local_frame;
public:
    void operator*= (char k);
    void variant();
    enemy001(int local_animation_behavior=0);
    ~enemy001();
    void LocalSetLocation(int x, int y);
    void Stop();
    void Defense();
    void StartedSetPosition(int x_local, int y_local);
    void nullFrame();
    void iterFrame();
    void SetAnimationBehavior(int local_animation_behavior);
    int GetX();
    int GetY();
    int GetAnimationBehavior();
    int GetFrame();
};

#endif // enemy001_H
