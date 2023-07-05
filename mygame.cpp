#include "mygame.h"
#include "people.h"
#include "menu.h"
#include "snowball.h"
#include "obstacle.h"
#include "car.h"
#include "warning.h"
#include "ui_mygame.h"
#include "qpainter.h"
#include "qpaintdevice.h"
#include "qpaintengine.h"
#include "qpainterpath.h"
#include "iomanip"
#include "random"
#include "ctime"
#include "background.h"
#include "gameoversign.h"
#include <qDebug>
#include <QString>
#include <QPixmap>
#include <QCursor>
#include <QScreen>
#include <iostream>
#include <QApplication>
#include <QLabel>
#include <QTime>

 static double diff1 = 0;// 设置一个偏移量，每次触发时改变绘制位置
 static double diff2 = 0;// 设置一个偏移量，每次触发时改变绘制位置
 static double groundSpeed = 5.0;
 int StartBlack=0;// 标志量，求开始黑色线段的坐标
 int StartBlack1=0;
 int StartBlack2=0;
 static double BallSpeed=5.0;//雪球的游戏速度固定
 int stonex=0;
 int yy=800;// 屏幕最下方的纵坐标
 double adder=0.0;// 判断人物速度变化量的记录量
 double totgrade=0.0;//记录游戏总得分
 bool OverBool=0;//游戏是否结束

myGame::myGame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myGame)
{
    ui->setupUi(this);
    setWindowTitle("滑雪大冒险");
    setFixedSize(1000,600);

    //定时器间隔设置
    m_Timer.setInterval(GAME_RATE);
    //调用启动游戏的接口
    playGame();
}

myGame::~myGame()
{
    delete ui;
}

void myGame::on_back_button_clicked()
{
    menu *menu0=new menu;
    menu0->show();
    close();
}

QPointF sp1, ep1, c11, c21;
QPointF sp2, ep2, c12, c22;

double myx1,myy1,myx2,myy2;//初始坐标点sp1,ep1
double myx3,myy3,myx4,myy4;//初始坐标点sp2,ep2
double real_ballspeed;//雪球在屏幕上的速度

void myGame::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    //显示各项积分
    totgrade+=BallSpeed;
    int numy=(int)(totgrade);
    QString stnumy=QString::number(numy,10);
    ui->grade->setText(stnumy);
    QFont ft1;
    ft1.setPointSize(30);
    ui->grade->setFont(ft1);

    int numz=(int)(m_people.m_man_posX-m_snowball.m_ball_posX-50);
    QString stnumz=QString::number(numz,10);
    ui->distance->setText(stnumz);
    QFont ft2;
    ft2.setPointSize(30);
    ui->distance->setFont(ft2);


    QPainter mPainter(this);// 创建painter并指定paintEngine
    mPainter.setRenderHint(QPainter::Antialiasing,true);//抗锯齿
    QPen pen;
    pen.setWidth(20);
    pen.setColor(Qt::black);
    pen.setJoinStyle(Qt::RoundJoin);
    mPainter.setPen(pen);// 设定画笔

    //绘制背景
    mPainter.drawPixmap(m_map.m_map1_posX , 0,m_map.m_map1);
    mPainter.drawPixmap(m_map.m_map2_posX , 0,m_map.m_map2);

    //绘制人物
    m_people.m_man_posY-=m_people.m_man_speedY;
    mPainter.drawPixmap(m_people.m_man_posX ,m_people.m_man_posY,m_people.m_man);

    //绘制雪球
    m_snowball.m_ball_posX+=m_snowball.m_ball_speedX;

    //如果雪球在画面中
    //if(!m_snowball.FallBool)
        mPainter.drawPixmap(100 ,m_snowball.m_ball_posY,m_snowball.m_ball);

    //如果雪球将要追上人：绘制“危险”图标
    if(m_people.m_man_posX-m_snowball.m_ball_posX<250)
        mPainter.drawPixmap(800 ,50,m_warning.m_warn);

    //绘制障碍物模型
    for (int j=m_stone.startnum;j<=m_stone.Stonenum;j++)
        mPainter.drawPixmap(m_stone.m_stone_posX[j] ,m_stone.m_stone_posY[j],m_stone.m_stonepixmap);

    //绘制车辆模型
    for (int j=m_car.startnum;j<=m_car.Stonenum;j++)
        mPainter.drawPixmap(m_car.m_car_posX[j] ,m_car.m_car_posY[j],m_car.m_carpixmap);

    if(diff1==0)
    {
        sp1.setX(0);sp1.setY(300);
        ep1.setX(1000);ep1.setY(900);
        myx1=0,myy1=300,myx2=1000,myy2=900;

        sp2.setX(5000);sp2.setY(3000);
        ep2.setX(8000);ep2.setY(9000);
        myx3=5000,myy3=3000,myx4=8000,myy4=9000;

    }
    if((ep1.y()==600&&ep1.x()>=0&&ep1.x()<=1000)||(ep1.x()==1000&&ep1.y()>=0&&ep1.y()<=600))//第一段曲线的末端到达窗口下边界或者右边界
    {
        srand(time(0));
        int k = rand() % 7;
        sp2.setX(ep1.x());
        sp2.setY(ep1.y());//sp2=ep1
        ep2.setX(sp2.x()+250*(k+2));
        ep2.setY(sp2.y()+150*(k+2));

        myx3=sp2.x();
        myy3=sp2.y();
        myx4=ep2.x();
        myy4=ep2.y();

        diff2=0;
        //qDebug()<<"1"<<sp1<<" "<<ep1<<" "<<sp2<<" "<<ep2<<'\n';
    }
     if((sp2.x()==0&&sp2.y()>=0&&sp2.y()<=600)||(sp2.y()==0&&sp2.x()>=0&&sp2.x()<=1000))//第二段曲线的前端到达窗口左边界或者上边界
    {
        sp1.setX(sp2.x());
        sp1.setY(sp2.y());//sp1=sp2

        ep1.setX(ep2.x());
        ep1.setY(ep2.y());//ep1=ep2

        myx1=sp1.x();
        myy1=sp1.y();
        myx2=ep1.x();
        myy2=ep1.y();

        diff1=0;
        //qDebug()<<"2"<<sp1<<" "<<ep1<<" "<<sp2<<" "<<ep2<<'\n';
    }

    sp1.setX(myx1-0.5*diff1);sp1.setY(myy1-0.3*diff1);
    ep1.setX(myx2-0.5*diff1);ep1.setY(myy2-0.3*diff1);//第一段坐标设置

    sp2.setX(myx3-0.5*diff2);sp2.setY(myy3-0.3*diff2);
    ep2.setX(myx4-0.5*diff2);ep2.setY(myy4-0.3*diff2);//第二段坐标设置

    c11.setX((sp1.x()+ep1.x())/2);c11.setY(sp1.y());
    c21.setX((sp1.x()+ep1.x())/2);c21.setY(ep1.y());//第一段中间点设置

    c12.setX((sp2.x()+ep2.x())/2);c12.setY(sp2.y());
    c22.setX((sp2.x()+ep2.x())/2);c22.setY(ep2.y());//第二段中间点设置

    QPainterPath path;
    path.moveTo(sp1);
    path.cubicTo(c11, c21, ep1);
    mPainter.drawPath(path);

    QPainterPath path2;
    path2.moveTo(sp2);
    path2.cubicTo(c12,c22,ep2);
    mPainter.drawPath(path2);

    //qDebug()<<sp1<<" "<<ep1<<" "<<sp2<<" "<<ep2<<'\n';
    mPainter.end();

    diff1+=groundSpeed;
    diff2+=groundSpeed;

    update();



    //障碍物与道具会改变groundSpeed
    //之后改变雪球速度
    real_ballspeed = BallSpeed-groundSpeed;

    m_snowball.m_ball_speedX=real_ballspeed;

    //获取屏幕上某点的颜色
    int x = 685; //该坐标代表人物的横坐标，是定值
    int y;//该坐标代表人物的纵坐标

    int ballx;
    ballx= m_snowball.m_ball_posX + 520;
    int bally;
    //雪球的横纵坐标

    //int mouse=QCursor::pos().x();
    //std::cout<<mouse<<" "<<std::endl;
    // QPixmap pixmap = QPixmap::grabWindow(QApplication::desktop()->winId(), x, y, 1, 1);

    //求出初始状态时黑色线段的坐标
    if (StartBlack==0)
    {
        QList<QScreen *> list_screen =  QGuiApplication::screens(); //可能电脑接了多个屏幕
        //人物
        for (y=355;y<=770;y+=20)
        {
        QPixmap pixmap = list_screen.at(0)->grabWindow(0,x,y,1,1);
        if (!pixmap.isNull()) //如果像素图不为NULL
        {
            QImage image = pixmap.toImage();//将像素图转换为QImage
            if (!image.isNull()) //如果image不为空
            {
                if (image.valid(0, 0)) //坐标位置有效
                {
                    QColor color = image.pixel(0, 0);
                    int mousedPressed_R = color.red();
                    int mousedPressed_G = color.green();
                    int mousedPressed_B = color.blue();
                    //QString text = QString("RGB: %1, %2, %3").arg(mousedPressed_R).arg(mousedPressed_G).arg(mousedPressed_B);
                    //qDebug() << text;
                    //qDebug()<<y<<" "<<mousedPressed_R<<" "<<mousedPressed_G<<" "<<mousedPressed_B<<endl;
                    if ((mousedPressed_R==0)&&(mousedPressed_G==0)&&(mousedPressed_B==0))
                    {
                        StartBlack=y;
                        m_people.m_ground_posY=StartBlack;
                        //qDebug()<<"初始状态："<<y<<std::endl;
                        break;
                    }
                }
            }
        }
        }

    }

    else//改变黑色线段的坐标
    {
        //人物
        QList<QScreen *> list_screen =  QGuiApplication::screens(); //可能电脑接了多个屏幕
        StartBlack-=3;
        y=StartBlack; m_people.m_ground_posY=StartBlack;
        if (m_people.JumpBool==0)// 若人物在地面上，修改人物的坐标与地形坐标相同
        {
            m_people.m_man_posY-=3;
        }
        //qDebug()<<m_people.m_man_posY<<" "<<m_people.m_ground_posY<<std::endl;
        QPixmap pixmap = list_screen.at(0)->grabWindow(0,x,y,1,1);
        if (!pixmap.isNull()) //如果像素图不为NULL
        {
            QImage image = pixmap.toImage();//将像素图转换为QImage
            if (!image.isNull()) //如果image不为空
            {
                if (image.valid(0, 0)) //坐标位置有效
                {
                    QColor color = image.pixel(0, 0);
                    int mousedPressed_R = color.red();
                    int mousedPressed_G = color.green();
                    int mousedPressed_B = color.blue();
                    //QString text = QString("RGB: %1, %2, %3").arg(mousedPressed_R).arg(mousedPressed_G).arg(mousedPressed_B);
                    //qDebug() << text;
                    //qDebug()<<color.red()<<" "<<color.green()<<" "<<color.blue()<<endl;
                    if ((mousedPressed_R!=0)||(mousedPressed_G!=0)||(mousedPressed_B!=0))
                    {
                        StartBlack+=6;
                        m_people.m_ground_posY=StartBlack;
                        if (m_people.JumpBool==0)// 若人物在地面上，修改人物的坐标与地形坐标相同
                        {
                            m_people.m_man_posY+=6;
                        }
                    }
                }
            }
        }


    }

    if(StartBlack1==0)
    {
        QList<QScreen *> list_screen =  QGuiApplication::screens(); //可能电脑接了多个屏幕
        //雪球
        for (bally=355;bally<=770;bally+=20)
        {
            QPixmap pixmap = list_screen.at(0)->grabWindow(0,ballx,bally,1,1);
            if (!pixmap.isNull()) //如果像素图不为NULL
            {
                QImage image = pixmap.toImage();//将像素图转换为QImage
                if (!image.isNull()) //如果image不为空
                {
                    if (image.valid(0, 0)) //坐标位置有效
                    {
                        QColor color = image.pixel(0, 0);
                        int mousedPressed_R = color.red();
                        int mousedPressed_G = color.green();
                        int mousedPressed_B = color.blue();
                        //QString text = QString("RGB: %1, %2, %3").arg(mousedPressed_R).arg(mousedPressed_G).arg(mousedPressed_B);
                        //qDebug() << text;
                        //qDebug()<<y<<" "<<mousedPressed_R<<" "<<mousedPressed_G<<" "<<mousedPressed_B<<endl;
                        if ((mousedPressed_R==0)&&(mousedPressed_G==0)&&(mousedPressed_B==0))
                        {
                            StartBlack1=bally;
                            m_snowball.m_ground_posY=StartBlack1;
                            //qDebug()<<"初始状态："<<y<<std::endl;
                            break;
                        }
                    }
                }
            }
        }
    }
    else
    {
        QList<QScreen *> list_screen =  QGuiApplication::screens(); //可能电脑接了多个屏幕
        //雪球
        StartBlack1-=3;
        bally=StartBlack1;
        m_snowball.m_ground_posY=StartBlack1;
        m_snowball.m_ball_posY-=3;

        QPixmap pixmap = list_screen.at(0)->grabWindow(0,ballx,bally,1,1);
        if (!pixmap.isNull()) //如果像素图不为NULL
        {
            QImage image = pixmap.toImage();//将像素图转换为QImage
            if (!image.isNull()) //如果image不为空
            {
                if (image.valid(0, 0)) //坐标位置有效
                {
                    QColor color = image.pixel(0, 0);
                    int mousedPressed_R = color.red();
                    int mousedPressed_G = color.green();
                    int mousedPressed_B = color.blue();

                    if ((mousedPressed_R!=0)||(mousedPressed_G!=0)||(mousedPressed_B!=0))
                    {
                        StartBlack1+=6;
                        m_snowball.m_ground_posY=StartBlack1;
                        m_snowball.m_ball_posY+=6;
                    }
                }
            }
        }
    }

    //std::cout<<m_people.m_man_posX-m_snowball.m_ball_posX-50<<std::endl;
    //如果雪球追上人
    if(m_people.m_man_posX<=m_snowball.m_ball_posX+50&&!OverBool)
    {
        GameOverSign* GameOver0=new GameOverSign;
        GameOver0->show();
        int numm=(int)(totgrade);
        GameOver0->showgrade(numm);
        groundSpeed = 5.0;
        StartBlack=0;
        StartBlack1=0;
        StartBlack2=0;
        BallSpeed=5.0;
        stonex=0;
        yy=800;
        adder=0.0;
        totgrade=0.0;
        //OverBool=1;
        close();
    }


    /*
     * 下面的部分是对道具、障碍物等一系列组件进行操作
     */

    //判断是否生成障碍物
    qsrand(QTime::currentTime().msec());
    int randnum0;
    randnum0=qrand() % 1200;
    if (randnum0%100<=3)
    {
        m_stone.Stonenum++;

        //依据人物的坐标生成随机数
        int randnum;

            randnum=randnum0/3-100+m_people.m_man_posY;

        m_stone.m_stone_posY[m_stone.Stonenum]=randnum;
        m_stone.m_stone_posX[m_stone.Stonenum]=1000;
    }
    else for (int j=m_stone.startnum;j<=m_stone.Stonenum;j++)
        if (m_stone.m_stone_posX[j]>-150)
    {
       m_stone.m_stone_posX[j]-=groundSpeed*2;
       if (m_stone.m_stone_posY[j]-m_people.m_man_posY>100)
           m_stone.m_stone_posY[j]-=0;
       else if (m_stone.m_stone_posY[j]-m_people.m_man_posY<0)
           m_stone.m_stone_posY[j]+=0;
    }


    //判断是否生成车辆
    if (randnum0%100>=97)
    {
        m_car.Stonenum++;

        //依据人物的坐标生成随机数
        int randnum;

            randnum=randnum0/3-100+m_people.m_man_posY;

        m_car.m_car_posY[m_car.Stonenum]=randnum;
        m_car.m_car_posX[m_car.Stonenum]=1000;
    }
    else for (int j=m_car.startnum;j<=m_car.Stonenum;j++)
        if (m_car.m_car_posX[j]>-150)
    {
       m_car.m_car_posX[j]-=groundSpeed*2;
       if (m_car.m_car_posY[j]-m_people.m_man_posY>100)
           m_car.m_car_posY[j]-=0;
       else if (m_car.m_car_posY[j]-m_people.m_man_posY<0)
           m_car.m_car_posY[j]+=0;
    }

    //std::cout<<m_stone.m_stone_posX<<" "<<m_stone.m_stone_posY<<" "<<m_people.m_man_posX<<" "<<m_people.m_man_posY<<std::endl;
    //当人物与障碍物相碰时
    for (int j=m_stone.startnum;j<=m_stone.Stonenum;j++)
        if ((m_stone.m_stone_posX[j]>=130&&m_stone.m_stone_posX[j]<=230)&&
            (abs(m_stone.m_stone_posY[j]-m_people.m_man_posY)<30))
                {
                    BallSpeed+=0.15;
                    adder+=0.15;
                    m_stone.m_stone_posX[j]=-200;
                }

    //清除已经碰撞的或到达屏幕左侧的障碍物
    for (int j=m_stone.startnum;j<=m_stone.Stonenum;j++)
        if (m_stone.m_stone_posX[j]<0)
        {
            //std::cout<<j<<" "<<m_stone.m_stone_posX[j]<<std::endl;
            m_stone.startnum++;
        }


    //当人物与车辆相碰时
    for (int j=m_car.startnum;j<=m_car.Stonenum;j++)
        if ((m_car.m_car_posX[j]>=130&&m_car.m_car_posX[j]<=230)&&
            (abs(m_car.m_car_posY[j]-m_people.m_man_posY)<30))
                {
                    BallSpeed-=0.15;
                    adder-=0.15;
                    m_car.m_car_posX[j]=-200;
                }

    //清除已经碰撞的或到达屏幕左侧的车辆
    for (int j=m_car.startnum;j<=m_car.Stonenum;j++)
        if (m_car.m_car_posX[j]<0)
        {
            //std::cout<<j<<" "<<m_stone.m_stone_posX[j]<<std::endl;
            m_car.startnum++;
        }

}

void myGame::playGame()
{
    //开始游戏，启动定时器
    m_Timer.start();

    //监听定时器
    connect(&m_Timer,&QTimer::timeout,[=](){
        //更新游戏中元素的坐标
        updatePosition();
        //重新绘制图片
        update();
    });
}

void myGame::updatePosition()
{
    //更新地图坐标
    m_map.BackgroundPosition(adder);
    //更新人物坐标
    m_people.PeoplePosition();
    //更新雪球坐标
    m_snowball.SnowBallPosition();
    //更新障碍物坐标
    m_stone.StonePosition();
    //更新车辆坐标
    m_car.CarPosition();

}

//按下弹跳按钮后，人物起跳
void myGame::on_jumpbutton_clicked()
{
    //设人起跳的初速度为以下值（向上）
    if (m_people.JumpBool==0)// 人物不是在空中
    {
        m_people.m_man_speedY=8.0;
        m_people.JumpBool=1;
    }
}
