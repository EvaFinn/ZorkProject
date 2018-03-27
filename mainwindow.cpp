#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);
    zork = new ZorkUL();

    breakWindow = new QMediaPlayer();
    breakWindow->setMedia(QUrl("qrc:/sounds/impact_glass_window_smash_005.mp3"));

    falling = new QMediaPlayer();
    falling->setMedia(QUrl("qrc:/sounds/falling.mp3"));

    bell = new QMediaPlayer();
    bell->setMedia(QUrl("qrc:/sounds/bell.mp3"));

//    this->connect(this->ui->upBtn, SIGNAL(clicked()), this,SLOT(on_upBtn_click()));
//    this->connect(this->ui->downBtn, SIGNAL(clicked()), this,SLOT(on_downBtn_click()));
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
    ui->enterLiftBtn->setDisabled(true);
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
    this->levelCount=6;
    ui->floorNumber->display(levelCount);
}

void MainWindow::on_restart_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_upBtn_clicked()
{
    levelCount++;
    ui->floorNumber->display(levelCount);
    ui->downBtn->setEnabled(true);

    if(levelCount == 10){
        ui->upBtn->setEnabled(false);
    }
}

void MainWindow::on_downBtn_clicked()
{
    levelCount--;
    ui->floorNumber->display(levelCount);
    ui->upBtn->setEnabled(true);

    if(levelCount == 0){
        ui->downBtn->setEnabled(false);
    }
}

void MainWindow::on_goBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}
void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_leftBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_rightBtn2_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}
