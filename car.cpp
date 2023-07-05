#include "car.h"
#include "picture.h"
#include <qDebug>
#include <QTime>

Car::Car()
{
    //导入石头图片
    m_carpixmap.load(CAR_PATH);

    //设立石头初始坐标与速度
    startnum=1;
    Stonenum=0;
    m_car_speedX=0.0;

    //对图片进行等比例缩放
    m_carpixmap = m_carpixmap.scaled(100, 125, Qt::KeepAspectRatio, Qt::SmoothTransformation);
}

void Car::CarPosition()
{

}
