#ifndef PICTURE_H
#define PICTURE_H

#include<QWidget>
#include<QLabel>

class picture:public QLabel
{
    Q_OBJECT
    
public:
    picture(QString Img,QWidget *widget);
    picture(QWidget *widget);
    void changeImg(QString Img);
signals:

public slots:

};

#endif // PICTURE_H
