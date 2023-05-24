#ifndef MYGAME_H
#define MYGAME_H

#include <QWidget>

namespace Ui {
class myGame;
}

class myGame : public QWidget
{
    Q_OBJECT

public:
    explicit myGame(QWidget *parent = 0);
    ~myGame();

private slots:
    void on_back_button_clicked();

private:
    Ui::myGame *ui;
};

#endif // MYGAME_H
