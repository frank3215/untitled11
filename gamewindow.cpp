#include "gamewindow.h"

GameWindow::GameWindow(QWidget *parent)
    : QMainWindow(parent)
{
    widget = new Widget(this);
    widget->show();
    connect(widget, &Widget::selectSong, this, &GameWindow::songScreen);
    connect(widget, &Widget::exitGame, this, &GameWindow::exitGame);

    mainwindow = new MainWindow(this);
    mainwindow->hide();
    connect(mainwindow, &MainWindow::startGame, this, &GameWindow::startGame);
    connect(mainwindow, &MainWindow::backsignal, this, &GameWindow::startScreen);

    game = new Game(this);
    game->hide();
    connect(game, &Game::gameEnded, this, &GameWindow::showResult);

    settlement = new Settlement_interface(this);
    settlement->hide();
    connect(settlement, &Settlement_interface::restartGame, this, &GameWindow::restartGame);
    connect(settlement, &Settlement_interface::selectSong, this, &GameWindow::selectSong);
    connect(settlement, &Settlement_interface::exitGame, this, &GameWindow::exitGame);


    this->setFixedSize(widget->size());
}

void GameWindow::startGame(QString songName, QString difficultyName, double songSpeed, int OD, int scrollSpeed)
{
    qDebug() << songName << difficultyName << songSpeed << OD;
    mainwindow->hide();
    game->setSong(songName, difficultyName, songSpeed, OD, scrollSpeed);
    game->clear();
    game->show();
    setFixedSize(game->size());
    // game->start();
}

void GameWindow::showResult()
{
    qDebug() << "GameWindow::showResult";
    game->setResults(settlement);
    settlement->show();
}

void GameWindow::restartGame() {
    qDebug() << "GameWindow::restartGame";
    settlement->hide();
    game->clear();
    game->show();
    // game->start();
}

void GameWindow::selectSong() {
    qDebug() << "GameWindow::selectSong";
    settlement->hide();
    mainwindow->show();
    setFixedSize(mainwindow->size());
}

void GameWindow::exitGame() {
    qDebug() << "GameWindow::exitGame";
    delete this;
}

void GameWindow::startScreen() {
    qDebug() << "GameWindow::startScreen";
    settlement->hide();
    mainwindow->hide();
    widget->show();
    setFixedSize(widget->size());
}

void GameWindow::songScreen()
{
    qDebug() << "GameWindow::songScreen";
    widget->hide();
    mainwindow->show();
    setFixedSize(mainwindow->size());
}
