#ifndef CORRECT_CLASS_H
#define CORRECT_CLASS_H
#include "fstream"
#include "string.h"
#include "memento_scene.h"
#include "memento_player.h"

class correct_class
{
    std::fstream SceneSave;
public:
    correct_class();
    ~correct_class();
    bool check_correct();
    bool check_char(char* check);
    bool check_int(char* check);

};

#endif // CORRECT_CLASS_H
