#include "correct_class.h"

correct_class::correct_class()
{
    SceneSave.open("SceneSave.txt");
}

bool correct_class::check_correct()
{
    if(SceneSave)
    {
        char charecteristic[512];
        char timeImage[4];
        int abstractX;
        int abstractY;

        SceneSave >> charecteristic;
        if(!this->check_int(charecteristic)) return 0;
        abstractX=atoi(charecteristic);
        SceneSave >> charecteristic;
        if(!this->check_int(charecteristic)) return 0;
        abstractY=atoi(charecteristic);
        SceneSave >> charecteristic;
        if(!this->check_int(charecteristic)) return 0;
        SceneSave >> charecteristic;
        if(!this->check_int(charecteristic)) return 0;
        SceneSave >> charecteristic;
        if(!this->check_int(charecteristic)) return 0;
        for(int i = 0; i<abstractX; i++)
            for(int j = 0; j<abstractY; j++)
            {
                SceneSave >> timeImage;
                if(!this->check_char(timeImage)) return 0;
            }
    }
    else return 0;

    char endfile;
    SceneSave >> endfile;
    if (!SceneSave.eof()) return 0;

  return 1;
}

bool correct_class::check_char(char *check)
{
    if(strlen(check)==2)
    {
        if((check[0]=='l')&&(check[1]=='n')) return 1;
        if((check[0]=='r')&&(check[1]=='c')) return 1;
        if((check[0]=='e')&&(check[1]=='n')) return 1;
        if((check[0]=='e')&&(check[1]=='x')) return 1;
        if((check[0]=='s')&&(check[1]=='c')) return 1;
        if((check[0]=='s')&&(check[1]=='p')) return 1;
        if((check[0]=='m')&&(check[1]=='n')) return 1;
        if((check[0]=='u')&&(check[1]=='g')) return 1;
        if((check[0]=='u')&&(check[1]=='1')) return 1;
        if((check[0]=='u')&&(check[1]=='2')) return 1;
        if((check[0]=='u')&&(check[1]=='3')) return 1;
    }

    if(strlen(check)==4)
    {
        bool check_1=0;
        if((check[0]=='l')&&(check[1]=='n')) check_1=1;
        if((check[0]=='r')&&(check[1]=='c')) check_1=1;
        if((check[0]=='e')&&(check[1]=='n')) check_1=1;
        if((check[0]=='e')&&(check[1]=='x')) check_1=1;
        if((check[0]=='s')&&(check[1]=='c')) check_1=1;
        if((check[0]=='s')&&(check[1]=='p')) check_1=1;
        if((check[0]=='m')&&(check[1]=='n')) check_1=1;
        if(check_1)
        {
        if((check[2]=='u')&&(check[3]=='g')) return 1;
        if((check[2]=='u')&&(check[3]=='1')) return 1;
        if((check[2]=='u')&&(check[3]=='2')) return 1;
        if((check[2]=='u')&&(check[3]=='3')) return 1;
        }
    }
    return 0;
}

bool correct_class::check_int(char *check)
{
    for(int i=0; check[i]; i++) if((check[i]<'0')||(check[i]>'9')) return 0;
    return 1;
}

correct_class::~correct_class()
{
    SceneSave.close();
}

