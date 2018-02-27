#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    zork = new ZorkUL();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->label->setText("You died");
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->label->setText(QString::fromStdString(zork->elevatorDeath()));
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->label->setText("Stair door is blocked, try find something to clear it with");
}
