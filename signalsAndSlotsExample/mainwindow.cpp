#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    timerOne = new QTimer();
    timerTwo = new QTimer();
    timerTree = new QTimer();

    connect(ui->paper,SIGNAL(clicked()),this,SLOT(selection()));
    connect(ui->stone,SIGNAL(clicked()),this,SLOT(selection()));
    connect(ui->scissors,SIGNAL(clicked()),this,SLOT(selection()));
    connect(ui->fight,SIGNAL(clicked()),this,SLOT(fight()));
    connect(timerOne,SIGNAL(timeout()),this,SLOT(changeImage()));
    connect(timerTwo,SIGNAL(timeout()),this,SLOT(timerOneStop()));
    connect(timerTree,SIGNAL(timeout()),this,SLOT(visibleRes()));

    ui->win->setVisible(false);
    ui->lose->setVisible(false);
    ui->draw->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::result(int res)
{
    switch (res) {
    case 1:
        ui->win->setVisible(true);
        heroPoint += 1;
        ui->heroPoint->setNum(heroPoint);
        break;
    case 2:
        ui->lose->setVisible(true);
        enemyPoint += 1;
        ui->enemyPoint->setNum(enemyPoint);
        break;
    case 3:
        ui->draw->setVisible(true);
        break;
    }
    timerTree->start(1500);
}

void MainWindow::selection()
{
    QPushButton *button = (QPushButton *)sender();
    if (button->text() == "Мистер \"Ножницы\""){
        hero = 2;
        ui->hero->setPixmap(QPixmap(":/image/scissors.jpg"));
    }
    if (button->text() == "Мистер \"Бумага\""){
        hero = 3;
        ui->hero->setPixmap(QPixmap(":/image/paper.jpg"));
    }
    if (button->text() == "Мистер \"Камень\""){
        hero = 1;
        ui->hero->setPixmap(QPixmap(":/image/stone.jpg"));
    }
}

void MainWindow::fight()
{
    timerOne->start(100);
    timerTwo->start(3000);
    ui->stone->setEnabled(false);
    ui->scissors->setEnabled(false);
    ui->paper->setEnabled(false);
}

void MainWindow::changeImage()
{
    int k = random(1,3);
    switch (k) {
    case 1:
        ui->enemy->setPixmap(QPixmap(":/image/stone.jpg"));
        break;
    case 2:
        ui->enemy->setPixmap(QPixmap(":/image/scissors.jpg"));
        break;
    case 3:
        ui->enemy->setPixmap(QPixmap(":/image/paper.jpg"));
        break;
    }

}

void MainWindow::timerOneStop()
{
    timerOne->stop();
    timerTwo->stop();

    enemy = random(1,3);
    switch (enemy) {
    case 1:
        ui->enemy->setPixmap(QPixmap(":/image/stone.jpg"));
        break;
    case 2:
        ui->enemy->setPixmap(QPixmap(":/image/scissors.jpg"));
        break;
    case 3:
        ui->enemy->setPixmap(QPixmap(":/image/paper.jpg"));
        break;
    }
    ui->stone->setEnabled(true);
    ui->scissors->setEnabled(true);
    ui->paper->setEnabled(true);
    loseOrWin();
}

void MainWindow::visibleRes()
{
    ui->win->setVisible(false);
    ui->lose->setVisible(false);
    ui->draw->setVisible(false);
}

void MainWindow::loseOrWin()
{
    if(numWin.contains(hero - enemy)){
        result(1);
    } else {
        if(numLose.contains(hero - enemy)){
            result(2);
        }else{
            result(3);
        }
    }

}


