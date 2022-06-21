#ifndef SHOT_H
#define SHOT_H

#include <QMainWindow>
#include<QPaintEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class Shot; }
QT_END_NAMESPACE

class Shot : public QMainWindow
{
    Q_OBJECT

protected:
    void paintEvent(QPaintEvent *event);
public:
    Shot(QWidget *parent = nullptr);
    void FullScreen();
    ~Shot();

private:
    Ui::Shot *ui;
};
#endif // SHOT_H
