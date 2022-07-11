#ifndef SH_ENEMY_H
#define SH_ENEMY_H



#include "abstract_enemy.h"
#include "scene.h"

class player;

template<typename Kind>
class sh_enemy:public abstract_enemy{
    Kind* kind;
    int animation_behavior;
    int x_public;
    int y_public;
    int local_frame;
public:
    sh_enemy(Kind* variant, int i, int j);
    ~sh_enemy();
    void action() override;
    void LocalSetLocation();
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

template<typename Kind>
sh_enemy<Kind>::sh_enemy(Kind* variant, int i, int j): kind(variant), x_public(j), y_public(i){}

template<typename Kind>
sh_enemy<Kind>::~sh_enemy() {
    delete kind;
}
template<typename Kind>
void sh_enemy<Kind>::action() {
    kind->variant();
}

template<typename Kind>
void sh_enemy<Kind>::StartedSetPosition(int x_local, int y_local) {
    kind->StartedSetPosition(x_local, y_local);
}

template<typename Kind>
void sh_enemy<Kind>::nullFrame() {
    kind->nullFrame();
}

template<typename Kind>
void sh_enemy<Kind>::iterFrame() {
    kind->iterFrame();
}

template<typename Kind>
void sh_enemy<Kind>::SetAnimationBehavior(int local_animation_behavior) {
    kind->SetAnimationBehavior(local_animation_behavior);
}


template<typename Kind>
int sh_enemy<Kind>::GetX() {
    return kind->GetX();
}


template<typename Kind>
int sh_enemy<Kind>::GetY() {
    return kind->GetY();

}


template<typename Kind>
int sh_enemy<Kind>::GetAnimationBehavior() {
    return kind->GetAnimationBehavior();

}

template<typename Kind>
int sh_enemy<Kind>::GetFrame() {
    return kind->GetFrame();
}

#endif // SH_ENEMY_H
