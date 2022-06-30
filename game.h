#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include <QGraphicsRectItem>
#include <deque>
#include <QMainWindow>
#include <QMediaPlayer>
#include <QFileInfo>
#include "QtMultimedia/qaudiooutput.h"
#include "note.h"
#include "playfield.h"
#include "score.h"
#include "judge.h"
#include "accuracy.h"
#include "settlement_interface.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class Form;
}
QT_END_NAMESPACE

const int columnCount = 4;
const int noteWidth = 100, noteHeight = 82 * 100 / 256;
const int marginUp = 100, marginDown = 100, marginLeft = 100, marginRight = 100;
const int playFieldWidth = columnCount * noteWidth, playFieldHeight = 400;

class Game : public QWidget
{
    Q_OBJECT
public:
    // directly change these!
    double musicSpeed;
    int visualScrollSpeed; // 400 ~ 600
    int musicVolume; // 0 ~ 100
    QString musicURL, osuURL;
    Game(QWidget * parent = nullptr);
    void setResults(Settlement_interface *settlement);
public slots:
    void timerAlert();
    void start();
    void keyPress(int key);
    void pauseGame();
    void continueGame();
    int endGame();
    void setSong(QString songName, QString difficultyName, double songSpeed, int OD);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

private:
    int scrollSpeed;
    Ui::Form *ui;
    int lastPosition;
    QList<Note *> notes[4];
    int st[4], ed[4];
    QGraphicsView * view;
    QGraphicsScene * scene;
    QMediaPlayer * player;
    QAudioOutput * audio;
    QTimer * timer;
    QFile * file;
    PlayField * playField;
    Score * score;
    Judge * judgement;
    Accuracy * accuracy;
    void redraw(int cur = -1);
    Settlement_interface * settlement;
    ~Game();

signals:
    void gameEnded();
    void gameExit();
};

#endif // GAME_H
