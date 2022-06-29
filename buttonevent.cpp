#include "buttonevent.h"
#include<QPushButton>
#include<QMouseEvent>
#include<QDebug>
buttonEvent::buttonEvent(QWidget *parent)
    : QPushButton{parent}
{
    this->setStyleSheet("font-size:15px;color:white");

}
void buttonEvent::enterEvent(QEnterEvent* e)
{
    this->resize(200,40);

    return;
}
void buttonEvent::leaveEvent(QEvent* e)
{
    this->resize(160,40);

    return;
}
void buttonEvent::mousePressEvent(QMouseEvent *e)
{

    emit this->readyplay();
    return;
}
