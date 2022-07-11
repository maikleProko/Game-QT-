#ifndef ABSTRACT_ENEMY_H
#define ABSTRACT_ENEMY_H

class abstract_enemy{
public:
    virtual ~abstract_enemy(){}
    virtual void action() = 0;
};

#endif // ABSTRACT_ENEMY_H
