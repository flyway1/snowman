#include "background.h"
BackGround::BackGround()
{
    //初始化加载背景对象
    m_map1.load(BackGround_PATH);
    m_map2.load(BackGround_PATH);

    //设置地图实时x轴坐标
    m_map1_posX = -GAME_WIDTH;
    m_map2_posX = 0;

    //设置地图滚动速度
    m_scroll_speed = BackGround_SCROLL_SPEED;
}

void BackGround::BackgroundPosition(double addernum)
{
    //处理第一张图片滚动
    m_map1_posX -= BackGround_SCROLL_SPEED-addernum*3;
    if(m_map1_posX <= -GAME_WIDTH)
    {
        m_map1_posX =0;
    }

    //处理第二张图片滚动
    m_map2_posX -= BackGround_SCROLL_SPEED-addernum*3;
    if(m_map2_posX <= 0 )
    {
        m_map2_posX =GAME_WIDTH;
    }
}
