#ifndef SNOWBALL_H
#define SNOWBALL_H
#include <QPixmap>
#include <QLabel>

/**********  雪球配置数据 **********/
#define BALL_PATH  "C:/Users/lywpc/Desktop/QT/snowpeople lyw/snowpeople lyw/snowpeople/picture/snowball.png" //雪球图片路径
#define BALL_WIDTH 100  //宽度
#define BALL_HEIGHT 100  //高度
#define BALL_RATE  10   //刷新间隔，帧率 单位毫秒
class snowball
{
public:
    snowball();

    //更新雪球的坐标
    void SnowBallPosition();

    //导入雪球对象的图片
    QPixmap m_ball;
    QLabel *label=new QLabel;

    //雪球X轴坐标、Y轴坐标
    double m_ball_posX;
    double m_ball_posY;
    //地形的Y坐标
    double m_ground_posY;

    //雪球在水平方向上的速度
    double m_ball_speedX;

    //雪球是否处于画面左方
    bool FallBool;
};

#endif // SNOWBALL_H
