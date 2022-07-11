#include "mainwindow.h"

int const const1=1;
int const const2=1;
int const const3=1;
int const const_enemies001=1;
int const const_enemies002=0;
int const const_enemies003=0;


void MainWindow::LoadGame()
{
    for(int x=0; x<xmax; x++)
        for(int y=0;y<ymax;y++)
        {
            for(int z=0; z<const_enemies001; z++)
                if(Scene::getInstance()->a[x][y].unit==2)
                {
                    Scene::getInstance()->a[un1[z].GetX()][un1[z].GetY()].unit=0;
                    un1[z].StartedSetPosition(x,y);
                    break;
                }
            for(int z=0; z<const_enemies002; z++)
                if(Scene::getInstance()->a[x][y].unit==3)
                {
                    Scene::getInstance()->a[un2[z].GetX()][un2[z].GetY()].unit=0;
                    un2[z].StartedSetPosition(x,y);
                    break;
                }
            for(int z=0; z<const_enemies003; z++)
                if(Scene::getInstance()->a[x][y].unit==4)
                {
                    Scene::getInstance()->a[un3[z].GetX()][un3[z].GetY()].unit=0;
                    un3[z].StartedSetPosition(x,y);
                    break;
                }
        }
    for(int x=0; x<xmax; x++)
        for(int y=0;y<ymax;y++)
            printImage(x,y, Scene::getInstance()->a[x][y].image);

}

void MainWindow::moveGraph(int x_absolute_center, int y_absolute_center, QImage frame)
{
    for(int i = 0; i < 128; i++){
            for(int j = 0; j < 128; j++ ){
            QRgb pixColor;
            pixColor = frame.pixel(j, i);
            if((qRed(pixColor)!=0)&&(qGreen(pixColor)!=0)&&(qBlue(pixColor)!=0)&&(qRed(pixColor)!=63)&&(qGreen(pixColor)!=63)&&(qBlue(pixColor)!=63)) AreaScene->setPixel( x_absolute_center-64+i, y_absolute_center-64+j, pixColor);
            }
    }
    ControlPrintScene->resize(winxmax, winymax);
    ControlPrintScene->setPixmap(QPixmap::fromImage(*AreaScene));
}



void MainWindow::SetLocationGraph()
{
    printImage(player::one_player()->GetX(),player::one_player()->GetY(), Scene::getInstance()->a[player::one_player()->GetX()][player::one_player()->GetY()].image);
}
void MainWindow::printImage(int x,int y, QImage my_image)
{
    for(int i = 0; i < 128; i++){
            for(int j = 0; j < 128; j++ ){
            QRgb pixColor;
            pixColor = my_image.pixel(j, i);
            if((qRed(pixColor)!=0)&&(qGreen(pixColor)!=0)&&(qBlue(pixColor)!=0)) AreaScene->setPixel( i+128*x, j+128*y, pixColor);
            }
    }
    ControlPrintScene->resize(winxmax, winymax);
    ControlPrintScene->setPixmap(QPixmap::fromImage(*AreaScene));
}

void MainWindow::printSprite(int x,int y, QImage my_image, int kadr)
{
    for(int i = 0; i < 128; i++){
            for(int j = 0+kadr*128; j < 128+kadr*128; j++ ){
            QRgb pixColor;
            pixColor = my_image.pixel(j, i);
            if((qRed(pixColor)!=0)&&(qGreen(pixColor)!=0)&&(qBlue(pixColor)!=0)&&(qRed(pixColor)!=63)&&(qGreen(pixColor)!=63)&&(qBlue(pixColor)!=63)) AreaScene->setPixel( i+128*x, j+128*y-kadr*128, pixColor);
            }
    }
    ControlPrintScene->resize(winxmax, winymax);
    ControlPrintScene->setPixmap(QPixmap::fromImage(*AreaScene));
}

void MainWindow::moveGraphSprite(int x_absolute_center, int y_absolute_center, QImage my_image, int kadr)
{
    for(int i = 0; i < 128; i++){
            for(int j = 0+kadr*128; j < 128+kadr*128; j++ ){
            QRgb pixColor;
            pixColor = my_image.pixel(j, i);
            if((qRed(pixColor)!=0)&&(qGreen(pixColor)!=0)&&(qBlue(pixColor)!=0)&&(qRed(pixColor)!=63)&&(qGreen(pixColor)!=63)&&(qBlue(pixColor)!=63)) AreaScene->setPixel( x_absolute_center-64+i, y_absolute_center-64+j-kadr*128, pixColor);
            }
    }
    ControlPrintScene->resize(winxmax, winymax);
    ControlPrintScene->setPixmap(QPixmap::fromImage(*AreaScene));
}


void MainWindow::testprintImage(int x,int y, QImage my_image)
{
    for(int i = 0; i < 115; i++){
            for(int j = 0; j < 128; j++ ){
            QRgb pixColor;
            pixColor = my_image.pixel(j, i);
            if((qRed(pixColor)!=63)&&(qGreen(pixColor)!=63)&&(qBlue(pixColor)!=63)) AreaScene->setPixel( i+128*x, j+128*y, pixColor);
            }
    }
    ControlPrintScene->resize(winxmax, winymax);
    ControlPrintScene->setPixmap(QPixmap::fromImage(*AreaScene));
}


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{

    kv1 = new QLabel(this);
    kv2 = new QLabel(this);
    kv3 = new QLabel(this);

    //lyr1.setNum(1234);
   // lyr2.setNum(1234);
   // lyr3.setNum(1234);

    lyr1="            Скорость: ";
    lyr2="            Очки: ";
    lyr3="            Монеты: ";
    lyr1time.setNum(0);
    lyr2time.setNum(0);
    lyr3time.setNum(0);
    kv1->setText(lyr1+lyr1time);
    kv2->setText(lyr2+lyr2time);
    kv3->setText(lyr3+lyr3time);

    frames_player=1;
    whichStep=0;
    GameStarted=0;

    xmax=5;
    ymax=5;
    winxmax=10*65;
    winymax=11*64;
    QWidget *cw = new QWidget(this);
    Panel = new QVBoxLayout(cw);
    Interface = new QHBoxLayout(cw);
    Interface_stats = new QVBoxLayout(cw);
    PrintScene = new QScrollArea();
    NewGameButton = new QPushButton("Новая игра", cw);
    LoadGameButton = new QPushButton("Загрузить игру", cw);
    SaveGameButton = new QPushButton("Сохранить игру", cw);


    ControlPrintScene = new QLabel(PrintScene);
    ControlPrintScene->setMouseTracking(true);
    ControlPrintScene->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);


    Panel->addWidget(PrintScene);
    Panel->addItem(Interface);
    Interface->addWidget(NewGameButton);
    Interface->addWidget(LoadGameButton);
    Interface->addWidget(SaveGameButton);
    Interface->addItem(Interface_stats);
    Interface_stats->addWidget(kv1);
    Interface_stats->addWidget(kv2);
    Interface_stats->addWidget(kv3);


    setMinimumSize(winxmax, winymax);
    setCentralWidget(cw);

    connect(NewGameButton, SIGNAL(clicked()), this, SLOT(NewGameMethod()));
    connect(LoadGameButton, SIGNAL(clicked()), this, SLOT(LoadGameMethod()));
    connect(SaveGameButton, SIGNAL(clicked()), this, SLOT(SaveGameMethod()));

}
   /*
*/

void MainWindow::keyPressEvent(QKeyEvent *event) {

    int key=event->key();
    if((player::one_player()->GetAnimation()==0)&&(whichStep==0)&&(player::one_player()->death==0))
    {
    frames_player=1;
    if (key==Qt::Key_W)   CommandUp::alone_CommandUp()->exec();
    if (key==Qt::Key_D)   CommandRight::alone_CommandRight()->exec();
    if (key==Qt::Key_A)   CommandLeft::alone_CommandLeft()->exec();
    if (key==Qt::Key_S)   CommandDown::alone_CommandDown()->exec();
    SetLocationGraph();
    }

}
/**/


void MainWindow::updateSec()
{

    local_speed=player::one_player()->GetSpeed();
    local_score=player::one_player()->GetScore();
    local_money=player::one_player()->GetMoney();
    lyr1time.setNum(local_speed);
    lyr2time.setNum(local_score);
    lyr3time.setNum(local_money);

    kv1->setText(lyr1+lyr1time);
    kv2->setText(lyr2+lyr2time);
    kv3->setText(lyr3+lyr3time);
    if(player::one_player()->death==0)
    {
    //ANIMATION FOR PLAYER:
    printImage(player::one_player()->GetX(),player::one_player()->GetY(),
                                    Scene::getInstance()->a[player::one_player()->GetX()][player::one_player()->GetY()].image);
    if(player::one_player()->GetAnimation()==0)
    {
        timeFrame.load(QDir::currentPath() + "/st.png");
        printSprite(player::one_player()->GetX(),player::one_player()->GetY(), timeFrame, frames_player);
        if(frames_player<60) frames_player++; else frames_player=0;
    }

    if((player::one_player()->GetAnimation()>=1)&&(player::one_player()->GetAnimation()<=4))
    {

        printImage(modifiers::static_modifiers()->time_x1,modifiers::static_modifiers()->time_y1, Scene::getInstance()->a[modifiers::static_modifiers()->time_x1][modifiers::static_modifiers()->time_y1].image);
        printImage(modifiers::static_modifiers()->time_x2,modifiers::static_modifiers()->time_y2, Scene::getInstance()->a[modifiers::static_modifiers()->time_x2][modifiers::static_modifiers()->time_y2].image);
        if(player::one_player()->GetAnimation()==1) timeFrame.load(QDir::currentPath() + "/w_rel.png");
        if(player::one_player()->GetAnimation()==2) timeFrame.load(QDir::currentPath() + "/w_left.png");
        if(player::one_player()->GetAnimation()==3) timeFrame.load(QDir::currentPath() + "/w_right.png");
        if(player::one_player()->GetAnimation()==4) timeFrame.load(QDir::currentPath() + "/w_back.png");
        moveGraphSprite(modifiers::static_modifiers()->time_x1*128+64+frames_player*modifiers::static_modifiers()->move_x*2, modifiers::static_modifiers()->time_y1*128+64+frames_player*modifiers::static_modifiers()->move_y*2, timeFrame, frames_player);
        if(frames_player<70) frames_player++; else
        {
            frames_player=0;

            printImage(modifiers::static_modifiers()->time_x1,modifiers::static_modifiers()->time_y1, Scene::getInstance()->a[modifiers::static_modifiers()->time_x1][modifiers::static_modifiers()->time_y1].image);
            printImage(modifiers::static_modifiers()->time_x2,modifiers::static_modifiers()->time_y2, Scene::getInstance()->a[modifiers::static_modifiers()->time_x2][modifiers::static_modifiers()->time_y2].image);

            player::one_player()->SetLocationFin(modifiers::static_modifiers()->move_x, modifiers::static_modifiers()->move_y);
            whichStep=1; // ПЕРЕХОД ХОДА
            qDebug() << "X = " << player::one_player()->GetX() << " Y = " << player::one_player()->GetY();
            qDebug() << "speed:";
            qDebug() << player::one_player()->GetSpeed();
            qDebug() << "scores:";
            qDebug() << player::one_player()->GetScore();
            qDebug() << "money:";
            qDebug() << player::one_player()->GetMoney();

            if((Scene::getInstance()->a[player::one_player()->GetX()][player::one_player()->GetY()].GetTP()==3)
                    &&(player::one_player()->GetScore()==1))
                QMessageBox::about(this, "Message", "You are win!");
        }
    }
    //END ANIMATION FOR PLAYER
    }

    //ANIMATION FOR ENEMIES:

    //ENEMY 001:
    for(int i=0; i<const_enemies001; i++)
    {
    printImage(un1[i].GetX(),un1[i].GetY(), Scene::getInstance()->a[un1[i].GetX()][un1[i].GetY()].image);

    if(un1[i].GetAnimationBehavior()==0)
    {
        timeFrame.load(QDir::currentPath() + "/enemy1_st.png");
        printSprite(un1[i].GetX(),un1[i].GetY(), timeFrame, un1[i].GetFrame());
        if(un1[i].GetFrame()<60) un1[i].iterFrame(); else un1[i].nullFrame();
    }

    if((un1[i].GetAnimationBehavior()==1)&&(whichStep==2))
    {
        int modX_enemy=0;
        int modY_enemy=1;
        printImage(un1[i].GetX(),un1[i].GetY(), Scene::getInstance()->a[un1[i].GetX()][un1[i].GetY()].image);
        printImage(un1[i].GetX()+modX_enemy,un1[i].GetY()+modY_enemy, Scene::getInstance()->a[un1[i].GetX()+modX_enemy][un1[i].GetY()+modY_enemy].image);
        timeFrame.load(QDir::currentPath() + "/enemy1_rel.png");
        moveGraphSprite(un1[i].GetX()*128+64+un1[i].GetFrame()*modX_enemy*2, un1[i].GetY()*128+64+un1[i].GetFrame()*modY_enemy*2, timeFrame, un1[i].GetFrame());
        if(un1[i].GetFrame()<70) un1[i].iterFrame(); else
        {
            un1[i].nullFrame();
            printImage(un1[i].GetX(),un1[i].GetY(), Scene::getInstance()->a[un1[i].GetX()][un1[i].GetY()].image);
            printImage(un1[i].GetX()+modX_enemy,un1[i].GetY()+modY_enemy, Scene::getInstance()->a[un1[i].GetX()+modX_enemy][un1[i].GetY()+modY_enemy].image);
            un1[i].LocalSetLocation(modX_enemy,modY_enemy);
            un1[i].SetAnimationBehavior(0);
            whichStep=0; // ПЕРЕХОД ХОДА ИГРОКУ
        }
    }

    if((un1[i].GetAnimationBehavior()==2)&&(whichStep==2))
    {
        timeFrame.load(QDir::currentPath() + "/enemy1_defense.png");
        printSprite(un1[i].GetX(),un1[i].GetY(), timeFrame, un1[i].GetFrame());
        if(un1[i].GetFrame()<60) un1[i].iterFrame(); else
        {
            un1[i].Defense();
            un1[i].nullFrame();
            un1[i].SetAnimationBehavior(0);
            whichStep=0; // ПЕРЕХОД ХОДА ИГРОКУ
        }
    }

    if((un1[i].GetAnimationBehavior()==3)&&(whichStep==2))
    {
        timeFrame.load(QDir::currentPath() + "/enemy1_st.png");
        printSprite(un1[i].GetX(),un1[i].GetY(), timeFrame, un1[i].GetFrame());
        if(un1[i].GetFrame()<60) un1[i].iterFrame(); else
        {
            un1[i].Stop();
            un1[i].nullFrame();
            un1[i].SetAnimationBehavior(0);
            whichStep=0; // ПЕРЕХОД ХОДА ИГРОКУ
        }
    }

    }
    //ENEMY 001 END;


    //ENEMY 002:
    for(int i=0; i<const_enemies002; i++)
    {
    printImage(un2[i].GetX(),un2[i].GetY(), Scene::getInstance()->a[un2[i].GetX()][un2[i].GetY()].image);

    if(un2[i].GetAnimationBehavior()==0)
    {
        timeFrame.load(QDir::currentPath() + "/enemy1_st.png");
        printSprite(un2[i].GetX(),un2[i].GetY(), timeFrame, un2[i].GetFrame());
        if(un2[i].GetFrame()<60) un2[i].iterFrame(); else un2[i].nullFrame();
    }

    if((un2[i].GetAnimationBehavior()==1)&&(whichStep==2))
    {
        int modX_enemy=-1;
        int modY_enemy=0;
        printImage(un2[i].GetX(),un2[i].GetY(), Scene::getInstance()->a[un2[i].GetX()][un2[i].GetY()].image);
        printImage(un2[i].GetX()+modX_enemy,un2[i].GetY()+modY_enemy, Scene::getInstance()->a[un2[i].GetX()+modX_enemy][un2[i].GetY()+modY_enemy].image);
        timeFrame.load(QDir::currentPath() + "/enemy1_right.png");
        moveGraphSprite(un2[i].GetX()*128+64+un2[i].GetFrame()*modX_enemy*2, un2[i].GetY()*128+64+un2[i].GetFrame()*modY_enemy*2, timeFrame, un2[i].GetFrame());
        if(un2[i].GetFrame()<70) un2[i].iterFrame(); else
        {
            un2[i].nullFrame();
            printImage(un2[i].GetX(),un2[i].GetY(), Scene::getInstance()->a[un2[i].GetX()][un2[i].GetY()].image);
            printImage(un2[i].GetX()+modX_enemy,un2[i].GetY()+modY_enemy, Scene::getInstance()->a[un2[i].GetX()+modX_enemy][un2[i].GetY()+modY_enemy].image);
            un2[i].LocalSetLocation(modX_enemy,modY_enemy);
            un2[i].SetAnimationBehavior(0);
            whichStep=0; // ПЕРЕХОД ХОДА ИГРОКУ
        }
    }

    if((un2[i].GetAnimationBehavior()==2)&&(whichStep==2))
    {
        timeFrame.load(QDir::currentPath() + "/enemy1_defense.png");
        printSprite(un2[i].GetX(),un2[i].GetY(), timeFrame, un2[i].GetFrame());
        if(un2[i].GetFrame()<60) un2[i].iterFrame(); else
        {
            un2[i].Defense();
            un2[i].nullFrame();
            un2[i].SetAnimationBehavior(0);
            whichStep=0; // ПЕРЕХОД ХОДА ИГРОКУ
        }
    }

    if((un2[i].GetAnimationBehavior()==3)&&(whichStep==2))
    {
        timeFrame.load(QDir::currentPath() + "/enemy1_st.png");
        printSprite(un2[i].GetX(),un2[i].GetY(), timeFrame, un2[i].GetFrame());
        if(un2[i].GetFrame()<60) un2[i].iterFrame(); else
        {
            un2[i].Stop();
            un2[i].nullFrame();
            un2[i].SetAnimationBehavior(0);
            whichStep=0; // ПЕРЕХОД ХОДА ИГРОКУ
        }
    }

    }
    //ENEMY 002 END;


    //ENEMY 003:
    for(int i=0; i<const_enemies003; i++)
    {
    printImage(un3[i].GetX(),un3[i].GetY(), Scene::getInstance()->a[un3[i].GetX()][un3[i].GetY()].image);

    if(un3[i].GetAnimationBehavior()==0)
    {
        timeFrame.load(QDir::currentPath() + "/enemy1_st.png");
        printSprite(un3[i].GetX(),un3[i].GetY(), timeFrame, un3[i].GetFrame());
        if(un3[i].GetFrame()<60) un3[i].iterFrame(); else un3[i].nullFrame();
    }

    if((un3[i].GetAnimationBehavior()==1)&&(whichStep==2))
    {
        int modX_enemy=1;
        int modY_enemy=0;
        printImage(un3[i].GetX(),un3[i].GetY(), Scene::getInstance()->a[un3[i].GetX()][un3[i].GetY()].image);
        printImage(un3[i].GetX()+modX_enemy,un3[i].GetY()+modY_enemy, Scene::getInstance()->a[un3[i].GetX()+modX_enemy][un3[i].GetY()+modY_enemy].image);
        timeFrame.load(QDir::currentPath() + "/enemy1_left.png");
        moveGraphSprite(un3[i].GetX()*128+64+un3[i].GetFrame()*modX_enemy*2, un3[i].GetY()*128+64+un3[i].GetFrame()*modY_enemy*2, timeFrame, un3[i].GetFrame());
        if(un3[i].GetFrame()<70) un3[i].iterFrame(); else
        {
            un3[i].nullFrame();
            printImage(un3[i].GetX(),un3[i].GetY(), Scene::getInstance()->a[un3[i].GetX()][un3[i].GetY()].image);
            printImage(un3[i].GetX()+modX_enemy,un3[i].GetY()+modY_enemy, Scene::getInstance()->a[un3[i].GetX()+modX_enemy][un3[i].GetY()+modY_enemy].image);
            un3[i].LocalSetLocation(modX_enemy,modY_enemy);
            un3[i].SetAnimationBehavior(0);
            whichStep=0; // ПЕРЕХОД ХОДА ИГРОКУ
        }
    }

    if((un3[i].GetAnimationBehavior()==2)&&(whichStep==2))
    {
        timeFrame.load(QDir::currentPath() + "/enemy1_defense.png");
        printSprite(un3[i].GetX(),un3[i].GetY(), timeFrame, un3[i].GetFrame());
        if(un3[i].GetFrame()<60) un3[i].iterFrame(); else
        {
            un3[i].Defense();
            un3[i].nullFrame();
            un3[i].SetAnimationBehavior(0);
            whichStep=0; // ПЕРЕХОД ХОДА ИГРОКУ
        }
    }

    if((un3[i].GetAnimationBehavior()==3)&&(whichStep==2))
    {
        timeFrame.load(QDir::currentPath() + "/enemy1_st.png");
        printSprite(un3[i].GetX(),un3[i].GetY(), timeFrame, un3[i].GetFrame());
        if(un3[i].GetFrame()<60) un3[i].iterFrame(); else
        {
            un3[i].Stop();
            un3[i].nullFrame();
            un3[i].SetAnimationBehavior(0);
            whichStep=0; // ПЕРЕХОД ХОДА ИГРОКУ
        }
    }

    }
    //ENEMY 003 END;



    //END ANIMATION FOR ENEMIES

    //BEHAVIORS OF ENEMIES:

    if(whichStep==1)
    {
        whichStep=2;
        for(int i=0; i<const_enemies001; i++)
        {
            un1[i].nullFrame();
            un1[i].variant();
        }
        for(int i=0; i<const_enemies002; i++)
        {
            un2[i].nullFrame();
            un2[i].variant();
        }
        for(int i=0; i<const_enemies003; i++)
        {
            un3[i].nullFrame();
            un3[i].variant();
        }
    }
    for(int i=0; i<const_enemies001; i++)
    {
        un1[i]*='d';
    }
    for(int i=0; i<const_enemies002; i++)
    {
        un2[i]*='d';
    }
    for(int i=0; i<const_enemies003; i++)
    {
        un3[i]*='d';
    }

    //BEHAVIORS OF ENEMIES END

}

void MainWindow::NewGameMethod()
{
    if(GameStarted==0)
    {

    bool bOk;
    GameStarted=1;
    xmax = QInputDialog::getInt(0,"Параметры поля","Размеры поля(x):", 2, 2, 10, 1, &bOk); if (!bOk) {}
    ymax = QInputDialog::getInt(0,"Параметры поля","Размеры поля(y):", 2, 2, 10, 1, &bOk); if (!bOk) {}
    // // // // Настройка поля
    Scene::getInstance()->xmaxscene=xmax;
    Scene::getInstance()->ymaxscene=ymax;
    Scene::getInstance()->initScene();
    Scene::getInstance()->GenerateRandomLandscapeOfScene();
    // // // //Проверка итератора, например, найдём выход
    // // // // Работа с окном
    winxmax=xmax*128;
    winymax=ymax*128;

    AreaScene = new QImage(winxmax, winymax,  QImage::Format_RGB888 );
    for(int i = 0; i < winxmax; i++){
        for(int j = 0; j < winymax; j++ ){
            AreaScene->setPixel( i, j, qRgb(0, 0, 0 ) );
            }
        }
    player::one_player();

    for_player = new bridge(&main_subscriber);
    player::one_player()->subscribe(for_player);


    // ITEMS
    MainWindow::obj2=new score_adder[const1];
    obj2[0].set_item_object(2,2,1);
    for_item = new bridge(&main_subscriber_square);
    Scene::getInstance()->a[2][2].subscribe(for_item);

    // ENEMIES
    MainWindow::un1=new enemy001[const_enemies001];
    un1[0].StartedSetPosition(2,1);



    // // // // Рисуем само поле
    for(int x=0; x<xmax; x++)
        for(int y=0;y<ymax;y++)
            printImage(x,y, Scene::getInstance()->a[x][y].image);


    ControlPrintScene->resize(winxmax, winymax);
    ControlPrintScene->setPixmap(QPixmap::fromImage(*AreaScene));

    timer = new QTimer(this);
    timer->setInterval(16);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateSec()));
    timer->start();

}

}

void MainWindow::LoadGameMethod()
{

    correct_class checking;
    if(checking.check_correct())
    {
    delete &checking;
    if(GameStarted==0)
    {
        GameStarted=1;
        Scene::getInstance()->xmaxscene=xmax;
        Scene::getInstance()->ymaxscene=ymax;
        Scene::getInstance()->initScene();
        winxmax=xmax*128;
        winymax=ymax*128;

        AreaScene = new QImage(winxmax, winymax,  QImage::Format_RGB888 );
        for(int i = 0; i < winxmax; i++){
            for(int j = 0; j < winymax; j++ ){
                AreaScene->setPixel( i, j, qRgb(0, 0, 0 ) );
                }
            }
        player::one_player();

        for_player = new bridge(&main_subscriber);
        player::one_player()->subscribe(for_player);


        // ITEMS
        MainWindow::obj2=new score_adder[const1];
        obj2[0].set_item_object(2,2,1);
        for_item = new bridge(&main_subscriber_square);
        Scene::getInstance()->a[2][2].subscribe(for_item);

        // ENEMIES
        MainWindow::un1=new enemy001[const_enemies001];
        un1[0].StartedSetPosition(2,1);



        // // // // Рисуем само поле
        for(int x=0; x<xmax; x++)
            for(int y=0;y<ymax;y++)
                printImage(x,y, Scene::getInstance()->a[x][y].image);


        ControlPrintScene->resize(winxmax, winymax);
        ControlPrintScene->setPixmap(QPixmap::fromImage(*AreaScene));

        timer = new QTimer(this);
        timer->setInterval(16);
        connect(timer, SIGNAL(timeout()), this, SLOT(updateSec()));
        timer->start();

    }
    qDebug() << "Load" << xmax << " " << ymax << " ";
    memento_scene save_scene(xmax, ymax);
    memento_player save_player;
    care_taker taker(&save_scene, &save_player);
    taker.load();
    LoadGame();
    ControlPrintScene->resize(winxmax, winymax);
    ControlPrintScene->setPixmap(QPixmap::fromImage(*AreaScene));
    }
    else
    {
        delete &checking;
        QMessageBox::about(this, "Message", "The save file cannot be loaded because it is damaged.");

    }
}

void MainWindow::SaveGameMethod()
{
    if(GameStarted==1)
    {
    qDebug() << "Save" << xmax << " " << ymax << " ";
    memento_scene save_scene(xmax, ymax);
    memento_player save_player;
    care_taker taker(&save_scene, &save_player);
    taker.save();
    QMessageBox::about(this, "Message", "Game saved.");
    }
}
MainWindow::~MainWindow()
{
}



