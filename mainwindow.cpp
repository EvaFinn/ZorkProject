#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "item.h"
#include "axe.h"
#include "extinguisher.h"
#include <vector>
#include "decrease.h"

using namespace std;

class Marks{
public:
  int val;
  Marks(){
      val = 0;
  }
  Marks(int v){
    val = v;
  }
  Marks operator--(int){
      Marks d(*this);
      val = val - 1;
      return d;
  }

  friend Marks operator++(Marks&, int);
};

Marks operator++(Marks &m, int){
    Marks d(m);
    m.val = m.val + 5;
    return d;
}


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

    cough = new QMediaPlayer();
    cough->setMedia(QUrl("qrc:/sounds/cough.mp3"));
}

void MainWindow::makeTimer(){
    this->ui->healthBar->setTextVisible(false);
    this->ui->healthBar->setValue(100);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(TimerEvent()));
    timer->start(1000);
}

void MainWindow::TimerEvent(){
  int value = this->ui->healthBar->value();
  Marks aValue(value);
  aValue--;
  value = aValue.val;
  this->ui->healthBar->setValue(value);

  if(value == 0){
      ui->stackedWidget->setCurrentIndex(1);
  }
}

void MainWindow::on_pickAxeBtn_clicked()
{
    this->ui->invBox->addItem(axe.getName());
}

void MainWindow::on_pickExting_clicked()
{
    this->ui->invBox->addItem(extinguisher.getName());
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
        ui->stackedWidget->setCurrentIndex(10);
        timer->stop();
        this->ui->healthBar->setValue(0);
        cough->play();
    }
    else{
        ui->stackedWidget->setCurrentIndex(4);
    }
}

void MainWindow::on_downStairsBtn_clicked(){
    ui->stackedWidget->setCurrentIndex(7);
    ui->pushButton->setVisible(false);
    this->value=0;
    ui->progressBar->setValue(value);
    ui->goBtn_2->setEnabled(false);
    if(ui->invBox->findText(extinguisher.getName()) != -1){
        ui->pushButton->setVisible(true);
    }
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
    int newValue = this->ui->progressBar->value();
    Marks aValue(newValue);
    aValue++;
    newValue = aValue.val;
    this->ui->progressBar->setValue(newValue);

    if(newValue == 100){
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
    timer->stop();
}
