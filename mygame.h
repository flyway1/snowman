#ifndef MYGAME_H
#define MYGAME_H

#include <QWidget>
#include <QPaintEvent>
#include <QTimer>
#include "Background.h"
#include "people.h"
#include "snowball.h"
#include "warning.h"
#include "obstacle.h"
#include "car.h"

namespace Ui {
class myGame;
}

class myGame : public QWidget
{
    Q_OBJECT

public:
    explicit myGame(QWidget *parent = 0);
    ~myGame();

    //启动游戏  用于启动定时器对象
    void playGame();
    //更新坐标
    void updatePosition();
    //绘图事件
    //void paintEvent(QPaintEvent *event);

    //地图对象
    BackGround m_map;

    //定时器对象
     QTimer m_Timer;

     //人物对象
     people m_people;

     //雪球对象
     snowball m_snowball;

     //警示牌对象
     warning m_warning;

     //障碍物对象
     Obstacle m_stone;

     //车辆对象
     Car m_car;

protected:
    void paintEvent(QPaintEvent *event);

private slots:
    void on_back_button_clicked();

    void on_jumpbutton_clicked();

private:
    Ui::myGame *ui;

};


#endif // MYGAME_H
