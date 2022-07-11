#ifndef COMMANDDOWN_H
#define COMMANDDOWN_H
#include "command_interface.h"

class CommandDown: public command_interface
{
public:
    CommandDown();
    static CommandDown* alone_CommandDown();
    void exec() override;
};

#endif // COMMANDDown_H
