#include "people.h"
#include "picture.h"
#include <qDebug>

people::people()
{
    //导入人物图片
    m_man.load(People_PATH);

    //设立人物初始坐标与速度
    m_man_posX = 200;
    m_man_posY=100;
    m_man_speedY=0.0;
    JumpBool=2;

    //对图片进行等比例缩放
    m_man = m_man.scaled(150, 75, Qt::KeepAspectRatio, Qt::SmoothTransformation);
}

void people::PeoplePosition()
{
    //设重力加速度大小为以下值
    m_man_speedY-=0.2;

    //当人物落地时，即人物纵坐标不小于地形纵坐标
    if (m_man_posY+272>=m_ground_posY&&JumpBool!=1)
    {
        m_man_speedY=0;
        JumpBool=0;
    }
    //当人物开始下落时，修改JumpBool的状态
    if (JumpBool==1&&m_man_speedY<=0)
    {
        JumpBool=2;
    }
}
