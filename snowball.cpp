#include "snowball.h"
#include "picture.h"
#include <qDebug>

snowball::snowball()
{
    //导入雪球图片
    m_ball.load(BALL_PATH);

    //设立雪球初始坐标与速度
    m_ball_posX = 100;
    m_ball_posY=200;
    m_ball_speedX=0.0;

    FallBool=0;
    //对图片进行等比例缩放
    m_ball = m_ball.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation);
}

void snowball::SnowBallPosition()
{
    const double leftside=-50.0;

    if(m_ball_posX<=leftside&&!FallBool)
    {
        FallBool=1;
    }
    if(m_ball_posX>leftside&&FallBool)
    {
        FallBool=0;
    }
}
