#include "menu.h"
#include <QApplication>
#include <QtWidgets>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    menu menu0;
    menu0.show();

    return a.exec();
}
