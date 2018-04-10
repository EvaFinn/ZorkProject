#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "item.h"
#include "axe.h"
#include "extinguisher.h"
#include "inventory.h"
#include <vector>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    setSounds();
    makeTimer();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::setSounds(){
    breakWindow = new QMediaPlayer();
    breakWindow->setMedia(QUrl("qrc:/sounds/impact_glass_window_smash_005.mp3"));

    falling = new QMediaPlayer();
    falling->setMedia(QUrl("qrc:/sounds/falling.mp3"));

    bell = new QMediaPlayer();
    bell->setMedia(QUrl("qrc:/sounds/bell.mp3"));
}

void MainWindow::makeTimer(){
    this->ui->healthBar->setTextVisible(false);
    this->ui->healthBar->setValue(100);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(TimerEvent()));
    timer->start(1000);
}

void MainWindow::TimerEvent(){
  int value = this->ui->healthBar->value();
  this->ui->healthBar->setValue(value-1);//ony decreases by 1% at the minute
  //maybe put destructor in here??

  if(value == 0){
      ui->stackedWidget->setCurrentIndex(1);
  }
}

void MainWindow::on_pickAxeBtn_clicked()
{
    this->ui->inventory->setText(axe.getName());
}

void MainWindow::on_pickExting_clicked()
{
    this->ui->inventory2->setText(extinguisher.getName());
}

void MainWindow::on_windowBtn_clicked(){
    ui->stackedWidget->setCurrentIndex(1);
    breakWindow->play();
    falling->play();
}

void MainWindow::on_elevatorBtn_clicked(){
    ui->stackedWidget->setCurrentIndex(2);
    ui->enterLiftBtn->setDisabled(true);
}

void MainWindow::on_stairsBtn_clicked(){
    ui->label->setText("Stair door is blocked, try find something to clear it with");
}

void MainWindow::on_radioButton_clicked(){
   bell->play();
   ui->enterLiftBtn->setEnabled(true);
}

void MainWindow::on_enterLiftBtn_clicked(){
    ui->stackedWidget->setCurrentIndex(3);
    ui->radioButton->setChecked(false);
    this->levelCount=6;
    ui->floorNumber->display(levelCount);
}

void MainWindow::on_restart_clicked(){
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_upBtn_clicked(){
    levelCount++;
    ui->floorNumber->display(levelCount);
    ui->downBtn->setEnabled(true);

    if(levelCount == 10){
        ui->upBtn->setEnabled(false);
    }
}

void MainWindow::on_downBtn_clicked(){
    levelCount--;
    ui->floorNumber->display(levelCount);
    ui->upBtn->setEnabled(true);

    if(levelCount == 0){
        ui->downBtn->setEnabled(false);
    }
}

void MainWindow::on_goBtn_clicked(){
    if(levelCount < 6){
        ui->stackedWidget->setCurrentIndex(1);
        ui->windowDeathLabel->setText("Elevator filled with smoke \n\tYou Died");
    }
    else{
        ui->stackedWidget->setCurrentIndex(4);
    }
}

void MainWindow::on_downStairsBtn_clicked(){
    ui->stackedWidget->setCurrentIndex(7);
    this->value=0;
    ui->progressBar->setValue(value);
    ui->goBtn_2->setEnabled(false);
}

void MainWindow::on_leftBtn_clicked(){
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_rightBtn2_clicked(){
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_rightBtn_clicked(){
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_clicked(){
    ui->progressBar->setValue(value);
    value++;
    if(value == 100){
        ui->goBtn_2->setEnabled(true);
    }
}

void MainWindow::on_pushButton_2_clicked(){
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_goBtn_2_clicked(){
    ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_pushButton_4_clicked(){
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_5_clicked(){
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_3_clicked(){
    ui->stackedWidget->setCurrentIndex(9);
}
