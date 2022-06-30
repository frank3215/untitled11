#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QWidget>
#include "game.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
     Game* game=NULL;
     QString musictitle;
    void paintEvent(QPaintEvent*);
public slots:
    void showAgain();
private:
    Ui::MainWindow *ui;
signals:
    void backsignal();
    void startGame(QString songName, QString difficultyName, double songSpeed, int OD);
};
#endif // MAINWINDOW_H
