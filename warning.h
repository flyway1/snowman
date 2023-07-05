#ifndef WARNING_H
#define WARNING_H
#include <QPixmap>
#include <QLabel>

#define W_PATH  "C:/Users/lywpc/Desktop/QT/snowpeople lyw/snowpeople lyw/snowpeople/picture/warning.png" //雪球图片路径

class warning
{
public:
    warning();
    QPixmap m_warn;
    QLabel *label=new QLabel;
};

#endif // WARNING_H
