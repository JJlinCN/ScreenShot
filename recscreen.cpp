#include"RecScreen.h"
#include<QApplication>
#include<QDesktopServices>
#include<QScreen>
#include<QPixmap>


CaptureScreen::CaptureScreen(QWidget *parent) :QWidget(parent),m_isMousePressed(false){
    initWindow();
    loadBackgroundPixmap();
    connect(this,&CaptureScreen::signalCompleteCapture,this,&CaptureScreen::show);
}

CaptureScreen::~CaptureScreen(){

}
void CaptureScreen::initWindow(){
    this->setMouseTracking(true);
    this->setWindowFlags(Qt::FramelessWindowHint);
    setWindowState(Qt::WindowActive|Qt::WindowFullScreen);
}

void CaptureScreen::loadBackgroundPixmap(){
    m_loadPixmap = QApplication::primaryScreen()->grabWindow(0); //截取的是当前屏幕的照片
    m_screenWidth = m_loadPixmap.width();
    m_screenHeight = m_loadPixmap.height();
}

void CaptureScreen::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        if(!m_isMousePressed){
            m_isMousePressed = true;
            m_beginPoint = event->pos();
        }
    }
}

void CaptureScreen::mouseMoveEvent(QMouseEvent *event){
    if(m_isMousePressed){
        m_endPoint = event->pos();
        update();   //move事件需要不断更新是以为鼠标在不断地移动，屏幕每次需要对鼠标的位置进行刷新更新
    }
}
void CaptureScreen::mouseReleaseEvent(QMouseEvent *event){
    m_endPoint = event->pos();
    m_isMousePressed = false;
}

void CaptureScreen::paintEvent(QPaintEvent *event){  //一旦鼠标进行移动，调用了update（），就会调用paintEvent（）处理绘画事件

    m_painter.begin(this);
    QColor shadowColor(0,0,0,100);  //这里是为截屏时，没有选取的区域设置的阴影颜色，不可见度很高
    m_painter.setPen(QPen(Qt::blue,1,Qt::SolidLine,Qt::FlatCap));
    m_painter.drawPixmap(0,0,m_loadPixmap);//将抓取到的像素图进行绘制
    m_painter.fillRect(m_loadPixmap.rect(),shadowColor);//对没有抓取的区域进行阴影填充

    if(m_isMousePressed){//如果此时鼠标是按下的，证明还在继续选取要截屏的区域

        QRect selectRect(m_beginPoint,m_endPoint);//设置现在选取矩形那个区域的位置和大小
        m_capturePixmap = m_loadPixmap.copy(selectRect);//？？
        m_painter.drawPixmap(selectRect.topLeft(),m_capturePixmap);//将这个捕捉到的像素图画从矩形框的左上角开始绘画
        m_painter.drawRect(selectRect);

    }
    m_painter.end();
}

void CaptureScreen::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Escape){
        close();
    }
    if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return){
        emit signalCompleteCapture(m_capturePixmap);
        close();
    }
}


QRect CaptureScreen::getRect(const QPoint &beginPoint,const QPoint &endPoint){

    int x,y,width,height;
    width = qAbs(beginPoint.x() - endPoint.x());
    height = qAbs(beginPoint.y() - endPoint.y());
    x = beginPoint.x() < endPoint.x() ? beginPoint.x() : endPoint.x();
    y = beginPoint.y() < endPoint.y() ? beginPoint.x() : endPoint.y();
    //当选择的矩形的宽和高是0,则手动要设置宽和高最小为1
    QRect selectRect(x,y,width,height);
    if(selectRect.width() == 0){
        selectRect.setWidth(1);
    }
    if(selectRect.height() == 0){
        selectRect.setHeight(1);
    }
    return selectRect;
}
