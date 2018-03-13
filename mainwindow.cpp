#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->enterLiftBtn->setDisabled(true);
    zork = new ZorkUL();
    breakWindow = new QMediaPlayer();
    breakWindow->setMedia(QUrl("qrc:/sounds/impact_glass_window_smash_005.mp3"));

    falling = new QMediaPlayer();
    falling->setMedia(QUrl("qrc:/sounds/falling.mp3"));

    bell = new QMediaPlayer();
    bell->setMedia(QUrl("qrc:/sounds/bell.mp3"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_windowBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    breakWindow->play();
    falling->play();
}

void MainWindow::on_elevatorBtn_clicked()
{
    //ui->label->setText(QString::fromStdString(zork->elevatorDeath()));
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_stairsBtn_clicked()
{
    ui->label->setText("Stair door is blocked, try find something to clear it with");
}

void MainWindow::on_radioButton_clicked()
{
   bell->play();
   ui->enterLiftBtn->setEnabled(true);
}

void MainWindow::on_enterLiftBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}
