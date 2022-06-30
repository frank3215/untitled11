#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include "widget.h"
#include "mainwindow.h"
#include "game.h"
#include "settlement_interface.h"

class GameWindow : public QMainWindow
{
    Q_OBJECT
public:
    GameWindow(QWidget *parent = nullptr);

signals:

public slots:
    void startGame(QString songName, QString difficultyName, double songSpeed, int OD);
    void showResult();
    void restartGame();
    void selectSong();
    void exitGame();
    void startScreen();
    void songScreen();
private:
    Widget * widget;
    Game * game;
    MainWindow * mainwindow;
    Settlement_interface * settlement;
};

#endif // GAMEWINDOW_H
