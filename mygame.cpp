#include "mygame.h"
#include "menu.h"
#include "ui_mygame.h"

myGame::myGame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myGame)
{
    ui->setupUi(this);
    setWindowTitle("滑雪大冒险");
    setFixedSize(1920,1200);
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
