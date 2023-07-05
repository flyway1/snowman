#ifndef STORY_H
#define STORY_H

#include <QWidget>

namespace Ui {
class story;
}

class story : public QWidget
{
    Q_OBJECT

public:
    explicit story(QWidget *parent = 0);
    ~story();

private slots:
    void on_pushButton_clicked();

private:
    Ui::story *ui;
};

#endif // STORY_H
