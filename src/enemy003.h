#ifndef enemy003_H
#define enemy003_H
#include "sh_enemy.h"
#include "scene.h"
#include "player.h"
class abstract_enemy;

class enemy003
{
private:
    int animation_behavior;
    int x_public;
    int y_public;
    int local_frame;
public:
    void operator*= (char k);
    void variant();
    enemy003(int local_animation_behavior=0);
    ~enemy003();
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

#endif // enemy003_H
