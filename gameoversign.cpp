#include "gameoversign.h"
#include "mygame.h"
#include "menu.h"
#include "ui_gameoversign.h"
#include <QLabel>
#include <QPainter>

GameOverSign::GameOverSign(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameOverSign)
{
    ui->setupUi(this);

}

GameOverSign::~GameOverSign()
{
    delete ui;
}

void GameOverSign::on_pushButton_clicked()
{
    close();

    menu* menu0=new menu;
    menu0->show();
}

void GameOverSign::showgrade(int numx)
{
    QString stnumm=QString::number(numx,10);
    ui->labelnum->setText(stnumm);
    QFont ft;
    ft.setPointSize(50);
    ui->labelnum->setFont(ft);
}

