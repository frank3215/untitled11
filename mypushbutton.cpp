#include "mypushbutton.h"
#include<QPushButton>
#include<QDebug>
#include<QPropertyAnimation>
#include<QMouseEvent>
Mypushbutton::Mypushbutton(QString nomal,QString press)//如果传入press 点击时就更换图片 没传就执行弹跳效果
{

    nomalImg=nomal;
    pressImg=press;
    if(nomal!="")
    {
        QPixmap pixmap;
        bool ret=pixmap.load(nomalImg);
        if(!ret)
        {
            qDebug()<<"加载图片失败";//会自动换行
        }
        //设置图片固定尺寸
        this->setFixedSize(pixmap.width()*0.2,pixmap.height()*0.2);
        //设置样式
        this->setStyleSheet("QPushButton{border:0px}");
        //设置图案
        this->setIcon(pixmap);
        //设置大小
        this->setIconSize(QSize(pixmap.width()*0.2,pixmap.height()*0.2));
    }

}
void Mypushbutton::zoom1()
{
    qDebug()<<"zoom1";
    //创建动画对象
    QPropertyAnimation* animation=new QPropertyAnimation(this,"gometry");
    //设置时间间隔
    animation->setDuration(200);//毫秒单位
    //起始位置
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //结束位置
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //设置跳跳效果 有很多 可以查函数
    animation->setEasingCurve(QEasingCurve::OutCurve);
    //执行动画
    animation->start();

}
void Mypushbutton::zoom2()
{
    qDebug()<<"zoom2r";
    QPropertyAnimation* animation=new QPropertyAnimation(this,"gometry");
    animation->setDuration(200);
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation->setEasingCurve(QEasingCurve::OutCurve);
    animation->start();

}
void Mypushbutton::mousePressEvent(QMouseEvent *e)
{

    if(pressImg!="")
    {
        QPixmap pixmap;
        bool ret=pixmap.load(pressImg);
        if(!ret)
        {
             qDebug()<<"加载图片失败";//会自动换行
        }
        this->setFixedSize(pixmap.width(),pixmap.height());
        this->setStyleSheet("QPushButton{border:0px}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(),pixmap.height()));
    }
}
void Mypushbutton::mouseReleaseEvent(QMouseEvent *e)
{
      if(nomalImg!="")
       {

            QPixmap pixmap;
             bool ret=pixmap.load(nomalImg);
             if(!ret)
             {
                 qDebug()<<"加载图片失败";//会自动换行
             }
             this->setFixedSize(pixmap.width()*0.2,pixmap.height()*0.2);
             this->setStyleSheet("QPushButton{border:0px}");
             this->setIcon(pixmap);
            this->setIconSize(QSize(pixmap.width()*0.2,pixmap.height()*0.2));

    }

}
