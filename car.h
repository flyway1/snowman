#ifndef CAR_H
#define CAR_H
#include <QPixmap>
#include <QLabel>

/**********  人物配置数据 **********/
#define CAR_PATH  "C:/Users/lywpc/Desktop/QT/snowpeople lyw/snowpeople lyw/snowpeople/picture/car.png" //人物图片路径
#define MAN_WIDTH 100  //宽度
#define MAN_HEIGHT 60  //高度
#define MAN_RATE  10   //刷新间隔，帧率 单位毫秒

class Car
{
public:
    Car();

    //更新石头的坐标
    void CarPosition();

    //导入石头对象的图片
    QPixmap m_carpixmap;
    QLabel *label=new QLabel;

    //石头的数量
    int Stonenum;
    int startnum;

    //石头X轴坐标、Y轴坐标
    double m_car_posX[2000];
    double m_car_posY[2000];
    //地形的Y坐标
    double m_ground_posY;

    //石头在水平方向上的速度
    double m_car_speedX;
};

#endif // CAR_H
