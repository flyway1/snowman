#include "menu.h"
#include "ui_menu.h"
#include "picture.h"
#include "mygame.h"
#include "story.h"
#include <QtWidgets>
#include <QMessageBox>

menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
    //设置主窗口名字、大小、背景
    setWindowTitle("滑雪大冒险");
    setFixedSize(1000,600);
    ui->menu_back->resize(1000,600);
    //picture *mainbg=new picture("C:/Users/lywpc/Desktop/QT/snowpeople/picture/menubackground.jpeg",this);
    //mainbg->move(0,0);


}

menu::~menu()
{
    delete ui;
}

//退出游戏
void menu::on_cancelButton_clicked()
{
    int ret1=QMessageBox::question(this,tr("询问"),tr("你确定要退出游戏吗？"),QMessageBox::Yes,QMessageBox::No);
    if (ret1==QMessageBox::Yes)
        close();
}

//游戏介绍
void menu::on_information_button_clicked()
{
    story *widget=new story;
    widget->show();
}

//进入正式的游戏界面
void menu::on_begin_button_clicked()
{
    myGame* mygame0=new myGame;
    mygame0->show();
    close();
}
