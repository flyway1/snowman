#ifndef BACKGROUND_H
#define BACKGROUND_H
#include<QPixmap>

/**********  背景配置数据 **********/
#define BackGround_PATH  ":/new/image/picture/SnowMountain.jpg" //背景图片路径
#define GAME_WIDTH 1000  //宽度
#define GAME_HEIGHT 600  //高度
#define GAME_RATE  5   //刷新间隔，帧率 单位毫秒


class BackGround
{
public:
    //构造函数
    BackGround();

    //背景滚动坐标计算
    void BackgroundPosition(double addernum);

public:
    //背景图片对象
    QPixmap m_map1;
    QPixmap m_map2;

    //地图X轴坐标
    double m_map1_posX;
    double m_map2_posX;

    //背景滚动幅度
    double m_scroll_speed;

    double BackGround_SCROLL_SPEED=7.0;  //背景滚动速度

};

#endif // BACKGROUND_H
