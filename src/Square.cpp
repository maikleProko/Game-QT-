#include "Square.h"


Square::Square(bool pass, QImage img, short int tp)
{
    this->passibility=pass;
    this->image=img;
    this->type=tp;
    unit=0;


}
void Square::SetSquare(bool pass, QImage img, short int tp)
{
    this->passibility=pass;
    this->image=img;
    this->type=tp;

}


void Square::SetImage(QImage img)
{
    this->image=img;

}



QImage Square::GetSquare()
{
    return(this->image);
}

short int Square::GetTP()
{
    return(this->type);
}

bool Square::GetPass()
{
    return(this->passibility);
}

void Square::subscribe(bridge *My_bridge)
{
    subscribes.push_back(My_bridge);
}

void Square::unsubscribe(bridge *My_bridge)
{
    subscribes.remove(My_bridge);
}

std::ostream& operator << (std::ostream &flash, Square& my_Square)
{


     time_t seconds = time(NULL);
     tm* timeinfo = localtime(&seconds);
     if(my_Square.image==scoreup) flash << "the player picked up the item [score]. time: "<< asctime (timeinfo);
     if(my_Square.image==moneyup) flash << "the player picked up the item [money]. time: "<< asctime (timeinfo);
     if(my_Square.image==speedup) flash << "the player picked up the item [speed]. time: "<< asctime (timeinfo);
     return flash;
}


void Square::notify()
{
    std::list<bridge*>::iterator iter = subscribes.begin();
    while(iter!=subscribes.end())
    {
        (*iter)->upBridge(this);
        ++iter;
    }

}



