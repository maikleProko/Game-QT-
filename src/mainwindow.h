#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "scene.h"
#include "iter.h"
#include "player.h"
#include "score_adder.h"
#include "speed_adder.h"
#include "money_adder.h"
#include "subscriber_player.h"
#include "subscriber_square.h"



#include "modifiers.h"
#include "commandright.h"
#include "commandup.h"
#include "commandleft.h"
#include "commanddown.h"


#include "sh_enemy.h"
#include "enemy001.h"
#include "enemy002.h"
#include "enemy003.h"




#include "care_taker.h"
#include "correct_class.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    bool GameStarted;
    subscriber_player main_subscriber;
    subscriber_square main_subscriber_square;
    bridge* for_player;
    bridge* for_item;
    bridge** main_bridges;
    int xmax, ymax;
    int move_x, move_y;
    int time_x1, time_x2, time_y1, time_y2;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void printImage(int x,int y, QImage my_image);
    void printSprite(int x,int y, QImage my_image, int kadr);
    void testprintImage(int x,int y, QImage my_image);
    void SetLocationGraph();
    void moveGraph(int x_absolute_center, int y_absolute_center, QImage frame);
    void moveGraphSprite(int x_absolute_center, int y_absolute_center, QImage my_image, int kadr);
    void LoadGame();
    short int whichStep;

    QBoxLayout *Panel;
    QBoxLayout *Interface;
    QBoxLayout *Interface_stats;
    QScrollArea *PrintScene;
    QLabel *ControlPrintScene;
    QImage *AreaScene;
    QTimer *timer;
    int winxmax, winymax;
    speed_adder* obj1;
    score_adder* obj2;
    money_adder* obj3;
    int frames_player;
    enemy001* un1;
    enemy002* un2;
    enemy003* un3;
    QImage timeFrame;

    QPushButton* NewGameButton;
    QPushButton* LoadGameButton;
    QPushButton* SaveGameButton;

    QString lyr1;
    QString lyr2;
    QString lyr3;
    QString lyr1time;
    QString lyr2time;
    QString lyr3time;
    QLabel *kv1;
    QLabel *kv2;
    QLabel *kv3;
    int local_speed, local_score, local_money;




protected:
   virtual void keyPressEvent(QKeyEvent *event);
private slots:
    void updateSec();
    void NewGameMethod();
    void LoadGameMethod();
    void SaveGameMethod();



};
#endif // MAINWINDOW_H
