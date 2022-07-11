#ifndef COMMANDUP_H
#define COMMANDUP_H
#include "command_interface.h"

class CommandUp: public command_interface
{
public:
    CommandUp();
    static CommandUp* alone_CommandUp();
    void exec() override;
};

#endif // COMMANDUp_H
