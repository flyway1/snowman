#include "picture.h"

picture::picture (QString Img,QWidget *parent){
    QImage image(Img);
    setPixmap(QPixmap::fromImage(image));
    setGeometry(0,0,image.width(),image.height());
    setParent(parent);
}

picture::picture (QWidget *parent){
    setParent(parent);
}

void picture::changeImg(QString Img){
    QImage image(Img);
    setPixmap(QPixmap::fromImage(image));
}
