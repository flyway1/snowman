#include "obstacle.h"
#include "picture.h"
#include <qDebug>
#include <QTime>

Obstacle::Obstacle()
{
    //导入石头图片
    m_stonepixmap.load(STONE_PATH);

    //设立石头初始坐标与速度
    startnum=1;
    Stonenum=0;
    m_stone_speedX=0.0;

    //对图片进行等比例缩放
    m_stonepixmap = m_stonepixmap.scaled(80, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation);
}

void Obstacle::StonePosition()
{

}
