#ifndef BUTTONEVENT_H
#define BUTTONEVENT_H
#include<QMouseEvent>
#include<QPushButton>
#include <QWidget>
#include<QComboBox>
class buttonEvent : public QPushButton
{
    Q_OBJECT
public:
    explicit buttonEvent(QWidget *parent = nullptr);
    void enterEvent(QEnterEvent*);
    void leaveEvent(QEvent*);
     void mousePressEvent(QMouseEvent *e);

signals:
     void readyplay();

};

#endif // BUTTONEVENT_H
