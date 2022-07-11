#ifndef COMMANDLEFT_H
#define COMMANDLEFT_H
#include "command_interface.h"

class CommandLeft: public command_interface
{
public:
    CommandLeft();
    static CommandLeft* alone_CommandLeft();
    void exec() override;
};

#endif // COMMANDLeft_H
