#include "openlog.h"

OpenLog::OpenLog()
{
    my_file.open("log.txt", std::ios::in | std::ios::out);
}


OpenLog::~OpenLog()
{
    my_file.close();
}


OpenLog* OpenLog::My_OpenLog()
{
    static OpenLog instance;
            return &instance;
}
