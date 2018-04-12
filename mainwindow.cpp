#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "item.h"
#include "axe.h"
#include "extinguisher.h"
#include "inventory.h"
#include <vector>

using namespace std;

class Marks{
public:
  double val;
  Marks(){
      val = 0.0;
  }
  Marks(double v){
    val = v;
  }
  Marks operator--(int){
      Marks d(*this);
      val = val - 1.0;
      return d;
  }

  friend Marks operator++(Marks&, int);
};

Marks operator++(Marks &m, int){
    Marks d(m);
    m.val = m.val + 5.0;
    return d;
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Escape!");
    ui->stackedWidget->setCurrentIndex(0);
    ui->label_2->setVisible(false);

    setSounds();
    makeTimer();
    fire->play();
}

MainWindow::~MainWindow(){
    delete ui;
    delete timer;
    delete breakWindow;
    delete falling;
    delete bell;
    delete fire;
    delete cough;
}

void MainWindow::setSounds(){
    ui->volumeSlider->setRange(0, 100);
    ui->volumeSlider->setFixedWidth(100);
    ui->volumeSlider->setValue(100);
    fire = new QMediaPlayer();
    fire->setMedia(QUrl("qrc:/sounds/firesound.mp3"));

    connect(ui->volumeSlider, SIGNAL(valueChanged(int)), this, SIGNAL(volumeChanged(int)));
    connect(ui->volumeSlider, SIGNAL(valueChanged(int)), fire, SLOT(setVolume(int)));

    breakWindow = new QMediaPlayer();
    breakWindow->setMedia(QUrl("qrc:/sounds/impact_glass_window_smash_005.mp3"));

    falling = new QMediaPlayer();
    falling->setMedia(QUrl("qrc:/sounds/falling.mp3"));

    bell = new QMediaPlayer();
    bell->setMedia(QUrl("qrc:/sounds/bell.mp3"));

    cough = new QMediaPlayer();
    cough->setMedia(QUrl("qrc:/sounds/cough.mp3"));

    win = new QMediaPlayer();
    win->setMedia(QUrl("qrc:/sounds/winSound.mp3"));
}

int MainWindow::volume() const{
    return ui->volumeSlider->value();
}

void MainWindow::setVolume(int volume){
    if(ui->checkBox->isChecked() == false){
        fire->setVolume(volume);
    }else{
        fire->setVolume(0);
    }
}

void MainWindow::on_checkBox_toggled(bool checked){
    if(checked){
        fire->setVolume(0);
    }
    else{
        fire->setVolume(100);
    }
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
      timer->stop();
  }
}

void MainWindow::on_pickAxeBtn_clicked(){
    Inventory<Axe> inv;
    Axe test;
    test = inv.addItem(axe);
    this->ui->invBox->addItem(test.getName());
}

void MainWindow::on_pickExting_clicked(){
    Inventory<Extinguisher> inv;
    Extinguisher test;
    test = inv.addItem(extinguisher);
    this->ui->invBox->addItem(test.getName());
}

void MainWindow::on_windowBtn_clicked(){
    ui->stackedWidget->setCurrentIndex(1);
    breakWindow->play();
    falling->play();
    timer->stop();
    this->ui->healthBar->setValue(0);
}

void MainWindow::on_elevatorBtn_clicked(){
    ui->stackedWidget->setCurrentIndex(2);
    ui->enterLiftBtn->setDisabled(true);
}

void MainWindow::on_stairsBtn_clicked(){
    if(ui->invBox->findText(axe.getName()) != -1){
        ui->stackedWidget->setCurrentIndex(8);
        ui->pickAxeBtn->setVisible(false);
        ui->label_9->setVisible(false);
    }
    else{
        ui->label->setVisible(false);
        ui->label_2->setVisible(true);
    }
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
    this->ui->healthBar->setValue(100);
    ui->label->setVisible(true);
    ui->label_2->setVisible(false);
    ui->invBox->clear();
    timer->start();
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
    else if(levelCount == 6){
        ui->stackedWidget->setCurrentIndex(0);
    }
    else{
        ui->stackedWidget->setCurrentIndex(4);
    }
}

void MainWindow::on_downStairsBtn_clicked(){
    ui->stackedWidget->setCurrentIndex(7);
    this->ui->exLabel->setVisible(true);
    this->ui->pushButton->setVisible(false);
    this->value=0;
    ui->progressBar->setValue(value);
    ui->goBtn_2->setEnabled(false);
    if(ui->invBox->findText(extinguisher.getName()) != -1){
        this->ui->pushButton->setVisible(true);
        this->ui->exLabel->setVisible(false);
    }
    ui->progressBar->setTextVisible(false);
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
    win->play();
}

void MainWindow::on_pushButton_6_clicked(){
    ui->stackedWidget->setCurrentIndex(0);
    this->ui->healthBar->setValue(100);
    ui->label->setVisible(true);
    ui->label_2->setVisible(false);
    ui->invBox->clear();
    timer->start();
}

void MainWindow::on_pushButton_7_clicked(){
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_8_clicked(){
    ui->stackedWidget->setCurrentIndex(0);
    this->ui->healthBar->setValue(100);
    ui->label->setVisible(true);
    ui->label_2->setVisible(false);
    ui->invBox->clear();
    timer->start();
}
