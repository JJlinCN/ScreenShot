#ifndef RECSCREEN_H
#define RECSCREEN_H

#include<QtWidgets>
#include<QPainter>

class CaptureScreen:public QWidget{

    Q_OBJECT

public:
    CaptureScreen(QWidget *parent = nullptr);
    ~CaptureScreen();
signals:
    void signalCompleteCapture(QPixmap captureImage);  //完成截图信号
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent*event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
private:
    void loadBackgroundPixmap();
    void initWindow();
    QRect getRect(const QPoint &beginPoint,const QPoint &endPoint);
private:
    bool m_isMousePressed;  //用来判断事件发生时按键是否是按下的，鼠标的按键是否按下，有不同的处理方法
    QPixmap m_loadPixmap;
    QPixmap m_capturePixmap;
    QPoint m_beginPoint;
    QPoint m_endPoint;
    QPainter m_painter;
    int m_screenWidth;
    int m_screenHeight;
};

#endif // RECSCREEN_H
