#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->enter,&QPushButton::clicked,this,&MainWindow::clearAndEnterClickHandler);
    connect(ui->clear,&QPushButton::clicked,this,&MainWindow::resetLineEdits);

    connect(ui->add,&QPushButton::clicked,this,&MainWindow::addSubMulDivClickHandler);
    connect(ui->sub,&QPushButton::clicked,this,&MainWindow::addSubMulDivClickHandler);
    connect(ui->mul,&QPushButton::clicked,this,&MainWindow::addSubMulDivClickHandler);
    connect(ui->div,&QPushButton::clicked,this,&MainWindow::addSubMulDivClickHandler);

    connect(ui->N0,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->N1,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->N2,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->N3,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->N4,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->N5,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->N6,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->N7,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->N8,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->N9,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberClickedHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    if (state == 2){
        number2 = ui->num2->text() + button->text();
        ui->num2->setText(number2);
        qDebug() << "number2: " << number2;
    }
    else{
        number1 = ui->num1->text() + button->text();
        ui->num1->setText(number1);
        qDebug() << "number1: " << number1;
    }
}

void MainWindow::clearAndEnterClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    float n1 = number1.toFloat();
    float n2 = number2.toFloat();

    qDebug() << "n1: " << n1;
    qDebug() << "n2: " << n2;

    if (operand == 1) {
        result = n1 + n2;
    }
    else if (operand == 2) {
        result = n1 - n2;
    }
    else if (operand == 3) {
        result = n1 * n2;
    }
    else if (operand == 4) {
        result = n1 / n2;
    }
    ui->result->setText(QString::number(result));
    ui->num1->setText("");
    ui->num2->setText("");
    number1 = "";
    number2 = "";
    state = 1;
}

void MainWindow::addSubMulDivClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString a = button->text();
    if (a == "+") operand = 1;
    else if (a == "-") operand = 2;
    else if (a == "*") operand = 3;
    else if (a == "/") operand = 4;

    state = 2;
}

void MainWindow::resetLineEdits()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    state = 1;
    ui->num1->setText("");
    ui->num2->setText("");
    ui->result->setText("");
}
