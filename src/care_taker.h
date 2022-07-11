#ifndef CARE_TAKER_H
#define CARE_TAKER_H
#include "memento_scene.h"
#include "memento_player.h"
#include "fstream"
#include "correct_class.h"

class care_taker
{
   memento_scene* my_scene;
   memento_player* my_player;
   std::fstream SceneSave;

public:
    care_taker(memento_scene* my_scene_public, memento_player* my_player_public);
    ~care_taker();
    void load();
    void save();
};

#endif // CARE_TAKER_H
