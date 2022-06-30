#ifndef SETTLEMENT_INTERFACE_H
#define SETTLEMENT_INTERFACE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Settlement_interface; }
QT_END_NAMESPACE

class Settlement_interface : public QWidget
{
    Q_OBJECT

public:
    Settlement_interface(QWidget *parent = nullptr);
    ~Settlement_interface();
    void setResult(int perfectNum, int greatNum, int goodNum, int missNum, int totalScore, QString ranking);

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

signals:
    void restartGame();
    void exitGame();
    void selectSong();

private:
    Ui::Settlement_interface *ui;
};
#endif // SETTLEMENT_INTERFACE_H
