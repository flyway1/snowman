#ifndef COLOR_H
#define COLOR_H
#include <QString>
#include <QColor>
#include <QScreen>
#include <QPixmap>
#include <QDesktopWidget>
#include <QApplication>

class color
{
public:
    color();
public:enum ColorType { RGB, RGBA, HEX };

    /**
     * @brief 传入颜色和模式即可得到字符串
     */
    public: static QString ColorToString(QColor &color, ColorType type);

    /**
    * @brief 传入xy坐标获取设备上该像素点的颜色
    */
    public: static QColor DesktopXYColor(int x,int y);

};

#endif // COLOR_H
