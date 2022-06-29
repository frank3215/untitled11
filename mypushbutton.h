#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include<QPushButton>
#include<QDebug>
class Mypushbutton : public QPushButton
{
    Q_OBJECT
public:
    Mypushbutton(QString nomal,QString press="");//设置点击前后的图片（实现特效）
    QString nomalImg;
    QString pressImg;
    void zoom1();//向下跳跃
    void zoom2();//向上跳跃
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
signals:

};


#endif // MYPUSHBUTTON_H
