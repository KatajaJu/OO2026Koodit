#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pQTimer = new QTimer(this);
    connect(pQTimer, &QTimer::timeout, this, &MainWindow::updateProgressBar);

    connect(ui->sec120Button,&QPushButton::clicked,this,&MainWindow::selectTime);
    connect(ui->min5Button,&QPushButton::clicked,this,&MainWindow::selectTime);

    connect(ui->startButton,&QPushButton::clicked,this,&MainWindow::startGame);
    connect(ui->stopButton,&QPushButton::clicked,this,&MainWindow::stopGame);

    connect(ui->swichButton1,&QPushButton::clicked,this,&MainWindow::swichPlayer);
    connect(ui->swichButton2,&QPushButton::clicked,this,&MainWindow::swichPlayer);
    setGameInfoText("Select playtime and press start game!", 10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timeout()
{
    if(player1Time == 0){
        pQTimer->stop();
        setGameInfoText("Player 2 WON!", 10);
    }
    else if (player2Time == 0){
        pQTimer->stop();
        setGameInfoText("Player 1 WON!", 10);
    }
}

void MainWindow::updateProgressBar()
{
    if (currentPlayer == 1){
        player1Time--;
        ui->progressBar1->setValue(player1Time);
        timeout();
    }
    else if (currentPlayer == 2){
        player2Time--;
        ui->progressBar2->setValue(player2Time);
        timeout();
    }
}

void MainWindow::selectTime()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    if (button == ui->sec120Button){
        player1Time = 120;
        player2Time = 120;
        gameTime = 120;
        ui->progressBar1->setMaximum(gameTime);
        ui->progressBar2->setMaximum(gameTime);
        setGameInfoText("120 sec selected. Ready to play!", 10);
    }
    else if (button == ui->min5Button){
        player1Time = 300;
        player2Time = 300;
        gameTime = 300;
        ui->progressBar1->setMaximum(gameTime);
        ui->progressBar2->setMaximum(gameTime);
        setGameInfoText("5 min selected. Ready to play!", 10);
    }
}

void MainWindow::startGame()
{
    currentPlayer = 1;
    pQTimer->start(1000);
    setGameInfoText("Game ongoing", 10);
}

void MainWindow::stopGame()
{
    pQTimer->stop();
    ui->progressBar1->setValue(gameTime);
    ui->progressBar2->setValue(gameTime);
    setGameInfoText("New game via start button", 10);
}

void MainWindow::swichPlayer()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    if (button == ui->swichButton1){
        currentPlayer = 2;
        setGameInfoText("Player 2 turn", 10);
    }
    else if (button == ui->swichButton2){
        currentPlayer = 1;
        setGameInfoText("Player 1 turn", 10);
    }
}

void MainWindow::setGameInfoText(QString text, short size)
{
    ui->label->setText(text);
    QFont font = ui->label->font();
    font.setPointSize(size);
    ui->label->setFont(font);
    ui->label->adjustSize();
}


