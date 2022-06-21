#include "shot.h"
#include "ui_shot.h"
#include<QScreen>
#include<QPainter>
#include<QPixmap>

Shot::Shot(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Shot)
{
    ui->setupUi(this);
    FullScreen();
}

void Shot::FullScreen()
{
//    QPixmap pixmap;
//    QScreen *screen=QApplication::primaryScreen();
//    pixmap=screen->grabWindow(0);

//    QImage img=pixmap.toImage();
//    img.save("/root/MyProject/1.jpg");
    QScreen *screen=QGuiApplication::primaryScreen();
    screen->grabWindow(0).save("/root/MyProject/1.jpg");
    //QWidget *newWidget=new QWidget(this);
}

void Shot::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(rect(),QPixmap("/root/MyProject/1.jpg"),QRect());
}

Shot::~Shot()
{
    delete ui;
}

