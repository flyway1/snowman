#ifndef OBSTACLE_H
#define OBSTACLE_H
#include <QPixmap>
#include <QLabel>

/**********  障碍物配置数据 **********/
#define STONE_PATH  "C:/Users/lywpc/Desktop/QT/snowpeople lyw/snowpeople lyw/snowpeople/picture/stone.png" //雪球图片路径
#define STONE_WIDTH 100  //宽度
#define STONE_HEIGHT 100  //高度
#define STONE_RATE  10   //刷新间隔，帧率 单位毫秒

class Obstacle
{
public:
    Obstacle();

    //更新石头的坐标
    void StonePosition();

    //导入石头对象的图片
    QPixmap m_stonepixmap;
    QLabel *label=new QLabel;

    //石头的数量
    int Stonenum;
    int startnum;

    //石头X轴坐标、Y轴坐标
    double m_stone_posX[2000];
    double m_stone_posY[2000];
    //地形的Y坐标
    double m_ground_posY;

    //石头在水平方向上的速度
    double m_stone_speedX;
};

#endif // OBSTACLE_H
