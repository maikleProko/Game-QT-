#include "iter.h"

iter::iter()
{
}


void iter::iterPlus()
{
    if(yiter != ymaxiter-1)
    {
        if(xiter==xmaxiter-1) { xiter=0; yiter++;}
        else xiter++;
    }
}

void iter::iterMinus()
{
    if(yiter != 0)
    {
        if(xiter==xmaxiter-1) { xiter=0; yiter--;}
        else xiter--;
    }
}

bool iter::iterEnds()
{
    return(yiter == ymaxiter);
}

const Square& iter::gc()
{
    return Scene::getInstance()->a[xiter][yiter];
}
void iter::operator++()
{
    iterPlus();
}

void iter::operator--()
{
    iterMinus();
}
int iter::iterSearchSceneX(int type)
{
    while(Scene::getInstance()->a[xiter][yiter].type!=type) iterPlus();
    return xiter;
}
int iter::iterSearchSceneY(int type)
{
    while(Scene::getInstance()->a[xiter][yiter].type!=type) iterPlus();
    return yiter;
}




