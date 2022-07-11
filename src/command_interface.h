#ifndef COMMAND_INTERFACE_H
#define COMMAND_INTERFACE_H

#include "player.h"
#include "modifiers.h"
class command_interface
{ 
public:
 virtual ~command_interface() {
 }
 virtual void exec() = 0;
};

#endif // COMMAND_INTERFACE_H
