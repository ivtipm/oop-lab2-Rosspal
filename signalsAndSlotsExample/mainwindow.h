#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QTimer>
#include <QSet>
#include "secondaryfunctions.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    int hero = 1;   //боец игрока
    int enemy = 1;  //боец оппонента
    int heroPoint = 0,enemyPoint = 0; //очки
    QTimer *timerOne;
    QTimer *timerTwo;   //таймеры
    QTimer *timerTree;
    QSet<int> numWin = {-1, 2}; //разница между значениями при победе 1 игрока всегда равна этим значения
    QSet<int> numLose = {-2, 1};//разница между значениями при поражение 1 игрока всегда равна этим значения при ничье = 0
    Ui::MainWindow *ui;
    void loseOrWin(); //определение победителя
    void result(int res);

private slots:
    void selection();//выбор игроком бойца
    void fight();//начало боя
    void changeImage();//случайные бойцы на экране
    void timerOneStop();//случайный выбор бойца оппонента и остановка первого таймера а так же запуск выбора победителя
    void visibleRes();//прячет label победа/поражение/ничья

};
#endif // MAINWINDOW_H
