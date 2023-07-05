#ifndef GAMEOVERSIGN_H
#define GAMEOVERSIGN_H

#include <QWidget>

namespace Ui {
class GameOverSign;
}

class GameOverSign : public QWidget
{
    Q_OBJECT

public:
    explicit GameOverSign(QWidget *parent = nullptr);
    ~GameOverSign();
    void showgrade(int numx);

private slots:
    void on_pushButton_clicked();

private:
    Ui::GameOverSign *ui;
};

#endif // GAMEOVERSIGN_H
