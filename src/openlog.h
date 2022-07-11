#ifndef OPENLOG_H
#define OPENLOG_H
#include "fstream"
class OpenLog
{
public:
    std::ofstream my_file;
    OpenLog();
    ~OpenLog();
    static OpenLog* My_OpenLog();
};

#endif // OPENLOG_H
