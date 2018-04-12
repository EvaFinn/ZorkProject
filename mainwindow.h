#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QRadialGradient>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <vector>
#include "item.h"
#include "inventory.h"
#include "axe.h"
#include "extinguisher.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Axe axe;
    Extinguisher extinguisher;
    QTimer *timer;
    void makeTimer();
    void setSounds();
    int volume() const;
    void setVolume(int);

private:
    Ui::MainWindow *ui;
    QMediaPlayer *breakWindow;
    QMediaPlayer *falling;
    QMediaPlayer *bell;
    QMediaPlayer *cough;
    QMediaPlayer *fire;
    QMediaPlayer *win;
    int levelCount;
    int value;
    QGraphicsScene scene;

public slots:
    void TimerEvent();

private slots:
    void on_windowBtn_clicked();
    void on_elevatorBtn_clicked();
    void on_stairsBtn_clicked();
    void on_radioButton_clicked();
    void on_enterLiftBtn_clicked();
    void on_restart_clicked();
    void on_upBtn_clicked();
    void on_downBtn_clicked();
    void on_goBtn_clicked();
    void on_downStairsBtn_clicked();
    void on_leftBtn_clicked();
    void on_rightBtn2_clicked();
    void on_rightBtn_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_goBtn_2_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_3_clicked();
    void on_pickAxeBtn_clicked();
    void on_pickExting_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_checkBox_toggled(bool checked);
    void on_pushButton_8_clicked();
};

#endif // MAINWINDOW_H
