#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QMainWindow>
#include "mainwindow.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    MainWindow * main=nullptr;
    void paintEvent(QPaintEvent*);


signals:
    void backsignal();
    void selectSong();
    void exitGame();
private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
