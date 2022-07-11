#ifndef COMMANDRIGHT_H
#define COMMANDRIGHT_H
#include "command_interface.h"

class CommandRight: public command_interface
{
public:
    CommandRight();
    static CommandRight* alone_CommandRight();
    void exec() override;
};

#endif // COMMANDRIGHT_H
