#include "accuracy.h"
#include "game.h"
#include <QFont>

Accuracy::Accuracy()
{
    setPos(marginLeft + playFieldWidth, 0);
    setFont(QFont("times", 60));
    setDefaultTextColor(Qt::black);
    clear();
}

void Accuracy::addPercent(int percent) {
    count++;
    total += percent;
    setPlainText(QString::number(getAccuracy()) + QString("%"));
}

double Accuracy::getAccuracy()
{
    return double(total) / (3*count);
}

QString Accuracy::getRanking()
{
    double acc = getAccuracy();
    if (acc >= 95.0) return "S";
    else if (acc >= 90.0) return "A";
    else if (acc >= 80.0) return "B";
    else if (acc >= 70.0) return "C";
    else if (acc >= 60.0) return "D";
    else return "F";
}

void Accuracy::clear()
{
    total = 0;
    count = 0;
    setPlainText(QString("--.--%"));
}
