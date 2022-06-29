#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "game.h"
#include<mypushbutton.h>
#include<QTimer>
#include<QDebug>
#include<QFile>
#include<QPainter>
#include<QPropertyAnimation>
#include<QPushButton>
#include"buttonevent.h"
#include<QListView>
#include <QStandardItemModel>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //放音乐
    //QSound* music=new QSound("",this);
    //music->play();
    qDebug() << "mainwindow init";
    this->setFixedSize(400,600);//设置固定大小 后期跟进背景图片设置 这里是随便写的

    this->setWindowIcon(QPixmap(":/back.png"));
    //显示文件消息框来进行选歌
    //connect(ui->pushButton,&QPushButton::clicked,[=](){
    //QString path = QFileDialog::getOpenFileName(this,"打开文件");（第五个参数是默认路径）
    //ui->lineEdit->setText(path);

    //尝试从文件读取名字放在按钮上
    //QPushButton* btn=new QPushButton;
    //btn->setParent(this);
    //btn->setFixedSize(50,50);
    //btn->move(this->width()*0.2,this->height()*0.8);
    //QFile file(事先设计的路径);
    //file.open(QIODevice::ReadOnly);
    //QByteArray array ;
    //array= file.readLine();
    //btn->setText(QString(array));

    //创建我的按钮(目前无法加载出图片)
    //Mypushbutton* backbtn=new Mypushbutton(":/playbtn.png");
    //backbtn->setParent(this);

   //backbtn->move(this->width()*0.2,this->height()*0.8);
    //connect(backbtn,&QPushButton::clicked,[=](){
        //qDebug()<<"enter";
        //backbtn->zoom1();
        //backbtn->zoom2();
        //QTimer::singleShot(500,this,[=](){
            //emit this->backsignal();
            //emit 叫开始界面监听（.h 加signal）
            //begin->show();
            //在.h里写 beginscene* begin=new beginscene;
       // });
    //});

   ui->btn->setStyleSheet("font-size:25px;color:white");
   ui->pushButton->setStyleSheet("font-size:25px;color:white");
    connect(ui->btn,&QPushButton::clicked,[=](){
        QPropertyAnimation* animation=new QPropertyAnimation(ui->btn,"geometry");
         animation->setDuration(200);
        animation->setStartValue(QRect(ui->btn->x(),ui->btn->y(),ui->btn->width(),ui->btn->height()));
        animation->setEndValue(QRect(ui->btn->x(),ui->btn->y()+10,ui->btn->width(),ui->btn->height()));
        animation->setEasingCurve(QEasingCurve::OutCurve);
        qDebug()<<"zoom1";
        animation->start();

        qDebug()<<"zoom2r";
        QPropertyAnimation* animation2=new QPropertyAnimation(ui->btn,"geometry");
        animation2->setDuration(200);
        animation2->setStartValue(QRect(ui->btn->x(),ui->btn->y()+10,ui->btn->width(),ui->btn->height()));
        animation2->setEndValue(QRect(ui->btn->x(),ui->btn->y(),ui->btn->width(),ui->btn->height()));
        animation2->setEasingCurve(QEasingCurve::OutCurve);
        animation2->start();
        qDebug() << ui->comboBox_2->currentIndex();
        QTimer::singleShot(500,this,[=](){
            game = new Game(this->musictitle, ui->comboBox_2->currentText());
            connect(game, &Game::gameEnded, this, &MainWindow::showAgain);
            this->hide();
            game->show();
           });
       });




    //设置scroll透明背景
    QPalette pa = ui->scrollArea->palette();
    pa.setBrush(QPalette::Window, Qt::transparent);
    ui->scrollArea->setPalette(pa);



    //ui->comboBox->addItem("MOD");
    ui->comboBox_2->addItem("Easy");
    ui->comboBox_2->addItem("Difficult");
    //ui->comboBox->addItem("No Fail");
    ui->comboBox_2->addItem("Challenging");
   // ui->comboBox->addItem("Half Time");
    //ui->comboBox->addItem("Double Time");




    connect(ui->btn1,&buttonEvent::readyplay,[=](){
        qDebug() << ui->btn1->text();
        qDebug() << ui->comboBox_2->currentIndex();
        this->musictitle=ui->btn1->text();
    });
    connect(ui->btn2,&buttonEvent::readyplay,[=](){
        qDebug() << ui->btn2->text();
        this->musictitle=ui->btn2->text();
    });
    connect(ui->btn3,&buttonEvent::readyplay,[=](){
        qDebug() << ui->btn3->text();
        this->musictitle=ui->btn3->text();
    });
    connect(ui->btn4,&buttonEvent::readyplay,[=](){

        this->musictitle=ui->btn4->text();
    });
    connect(ui->btn5,&buttonEvent::readyplay,[=](){

       this->musictitle=ui->btn5->text();
    });
    connect(ui->btn6,&buttonEvent::readyplay,[=](){

        this->musictitle=ui->btn6->text();
    });
    connect(ui->btn7,&buttonEvent::readyplay,[=](){

       this->musictitle=ui->btn7->text();
    });
    connect(ui->btn8,&buttonEvent::readyplay,[=](){

       this->musictitle=ui->btn8->text();
    });
    connect(ui->btn9,&buttonEvent::readyplay,[=](){

        this->musictitle=ui->btn9->text();
    });
    ui->comboBox_2->setStyleSheet("QComboBox{background:rgba(0,0,0,0);font-size:15px;color:white}");
    ui->widget->setStyleSheet("background-color:rgba(0,0,0,0);color:white");
    connect(ui->pushButton,&QPushButton::clicked,[=](){

        emit this->backsignal();
        this->hide();

       //emit 叫开始界面监听（.h 加signal）
      //begin->show();
       //在.h里写 beginscene* begin=new beginscene;
    });
}




void MainWindow::paintEvent(QPaintEvent* e)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load((":/background.png"));
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

}

void MainWindow::showAgain()
{
    show();
}
MainWindow::~MainWindow()
{
    delete ui;
}

