#ifndef ITER_H
#define ITER_H
#include "scene.h"


class iter
{
private:
    int xiter;
    int yiter;
    int xmaxiter=Scene::getInstance()->xmaxscene;
    int ymaxiter=Scene::getInstance()->ymaxscene;

public:
    iter();
    void iterPlus();
    void iterMinus();
    bool iterEnds();
    const Square& gc();
    void operator++();
    void operator--();
    int iterSearchSceneX(int type);
    int iterSearchSceneY(int type);
};

#endif // ITER_H
