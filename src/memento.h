#ifndef MEMENTO_H
#define MEMENTO_H
#include <QImage>
class memento
{
public:
    //save
    //for player
    //for player
    virtual int GetSpeed() = 0;
    virtual int GetScore() = 0;
    virtual int GetMoney() = 0;
    //for scene
    virtual int GetXmax() = 0;
    virtual int GetYmax() = 0;
    virtual QImage GetImage(int i, int j) = 0;
    //for item
    virtual int GetUnit(int i, int j) = 0;
    //load

    //for player
    virtual void SetSpeed(int k) = 0;
    virtual void SetScore(int k) = 0;
    virtual void SetMoney(int k) = 0;
    //for scene
    virtual void SetXmax(int k) = 0;
    virtual void SetYmax(int k) = 0;
    virtual void SetImage(int i, int j, QImage k) = 0;
    //for item
    virtual void SetUnit(int i, int j, int k) = 0;



};
#endif // MEMENTO_H
