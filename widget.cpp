#include "widget.h"
#include "./ui_widget.h"
#include "mainwindow.h"
#include<QTimer>
#include<QDebug>
#include<QFile>
#include<QPainter>
#include<QPropertyAnimation>
#include<QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //QSound* music=new QSound("",this);
    //music->play();

    this->setFixedSize(400,600);//鐠佸墽鐤嗛崶鍝勭暰婢堆冪毈 閸氬孩婀＄捄鐔荤箻閼冲本娅欓崶鍓у鐠佸墽鐤?鏉╂瑩鍣烽弰顖炴娓氬灝鍟撻惃?



     ui->btn->setStyleSheet("font-size:25px;color:white");
     ui->pushButton->setStyleSheet("font-size:25px;color:white");
     connect(ui->btn,&QPushButton::clicked,[=](){
            QPropertyAnimation* animation=new QPropertyAnimation(ui->btn,"geometry");
            animation->setDuration(200);
            animation->setStartValue(QRect(ui->btn->x(),ui->btn->y(),ui->btn->width(),ui->btn->height()));
            animation->setEndValue(QRect(ui->btn->x(),ui->btn->y()+10,ui->btn->width(),ui->btn->height()));
            animation->setEasingCurve(QEasingCurve::OutCurve);
            qDebug()<<"zoom1";
            animation->start();

            qDebug()<<"zoom2r";
            QPropertyAnimation* animation2=new QPropertyAnimation(ui->btn,"geometry");
            animation2->setDuration(200);
            animation2->setStartValue(QRect(ui->btn->x(),ui->btn->y()+10,ui->btn->width(),ui->btn->height()));
            animation2->setEndValue(QRect(ui->btn->x(),ui->btn->y(),ui->btn->width(),ui->btn->height()));
            animation2->setEasingCurve(QEasingCurve::OutCurve);
            animation2->start();
            QTimer::singleShot(500,this,[=](){

                    emit this->exitGame();
               });
           });
     connect(ui->pushButton,&QPushButton::clicked,[=](){
         emit this->selectSong();
     });
}
void Widget::paintEvent(QPaintEvent* e)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load((":/background.png"));
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

}
Widget::~Widget()
{
    delete ui;
}

