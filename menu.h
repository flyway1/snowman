#ifndef MENU_H
#define MENU_H

#include <QDialog>

namespace Ui {
class menu;
}

class menu : public QDialog
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = 0);
    ~menu();

private slots:
    void on_cancelButton_clicked();

    void on_information_button_clicked();

    void on_begin_button_clicked();

private:
    Ui::menu *ui;
};

#endif // MENU_H
