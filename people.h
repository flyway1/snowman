#ifndef PEOPLE_H
#define PEOPLE_H
#include <QPixmap>
#include <QLabel>

/**********  人物配置数据 **********/
#define People_PATH  "C:/Users/lywpc/Desktop/QT/snowpeople lyw/snowpeople lyw/snowpeople/picture/man.png" //人物图片路径
#define MAN_WIDTH 100  //宽度
#define MAN_HEIGHT 60  //高度
#define MAN_RATE  10   //刷新间隔，帧率 单位毫秒

class people
{
public:
    //构造函数
    people();

    //更新人物的坐标
    void PeoplePosition();

    //导入人物对象的图片
    QPixmap m_man;
    QLabel *label=new QLabel;

    //人物X轴坐标、Y轴坐标
    double m_man_posX;
    double m_man_posY;
    //地形的Y坐标
    double m_ground_posY;

    //人物在竖直方向上的速度
    double m_man_speedY;

    //判断人物是否跳起：1代表跳起，0代表未跳起在地面上，2代表落下
    int JumpBool;
};

#endif // PEOPLE_H
