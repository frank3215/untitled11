#include "score.h"
#include <QFont>

void Score::clear()
{
    score = 0;
    redraw();
}

Score::Score()
{
    score = 0;
    setPlainText(QString::number(score));
    setDefaultTextColor(Qt::black);
    setFont(QFont("times", 60));
}

void Score::increaseScore(int delta)
{
    score += delta;
    redraw();
}

void Score::redraw() {
    setPlainText(QString::number(score));
}
