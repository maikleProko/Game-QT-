#ifndef POINT_H
#define POINT_H
#include "libs.h"
#include "publisher.h"

using namespace std;
const QImage standard(QDir::currentPath() + "/block01.png");
const QImage rock(QDir::currentPath() + "/block02.png");
const QImage entry(QDir::currentPath() + "/block03.png");
const QImage exite(QDir::currentPath() + "/block04.png");
const QImage main_player(QDir::currentPath() + "/block05.png");
const QImage teleporter1(QDir::currentPath() + "/block08.png");
const QImage teleporter2(QDir::currentPath() + "/block09.png");
const QImage scoreup(QDir::currentPath() + "/block06.png");
const QImage speedup(QDir::currentPath() + "/block07.png");
const QImage moneyup(QDir::currentPath() + "/block10.png");

class Square: public publisher
{

private:
    bool passibility;
    std::list<bridge*> subscribes;

public:

    QImage image;
    short int type; // 0 - свободная, 1 - стена, 2 - вход, 3 - выход
    short int unit;
    void SetSquare(bool pass, QImage img, short int tp);
    void SetImage(QImage img);
    QImage GetSquare();
    short int GetTP();
    bool GetPass();
    Square(bool pass=false, QImage img=rock, short int tp=1);




    void subscribe(bridge* My_bridge) override;
    void unsubscribe(bridge* My_bridge) override;
    void notify()  override;
    friend std::ostream& operator<<(std::ostream &flash, Square& Square);


};

#endif // POINT_H
