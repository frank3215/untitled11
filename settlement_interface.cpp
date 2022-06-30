#include "settlement_interface.h"
#include "ui_settlement_interface.h"
#include <QString>

Settlement_interface::Settlement_interface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Settlement_interface)
{
    ui->setupUi(this);
}

Settlement_interface::~Settlement_interface()
{
    delete ui;
}

void Settlement_interface::setResult(int perfectNum, int greatNum, int goodNum, int missNum, int totalScore, QString ranking)
{
    ui->lineEdit->setText(QString::number(greatNum)); // wtf: what shitty naming convention is this...are you fucking kidding me???
    ui->lineEdit_2->setText(QString::number(perfectNum));
    ui->lineEdit_3->setText(QString::number(goodNum));
    ui->lineEdit_4->setText(QString::number(missNum));
    ui->lineEdit_5->setText(QString::number(totalScore));
    ui->lineEdit_6->setText(ranking);
}

void Settlement_interface::on_pushButton_clicked()
{
    emit this->restartGame();
}


void Settlement_interface::on_pushButton_2_clicked()
{
    emit this->selectSong();
}


void Settlement_interface::on_pushButton_3_clicked()
{
    emit this->exitGame();
}

