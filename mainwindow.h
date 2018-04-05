#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ZorkUL.h"
#include <QMediaPlayer>
#include <QRadialGradient>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

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

private:
    Ui::MainWindow *ui;
    ZorkUL *zork;
    QMediaPlayer *breakWindow;
    QMediaPlayer *falling;
    QMediaPlayer *bell;
    int levelCount;
    int value;
    QGraphicsScene scene;
//    QMovie *movie;
};

#endif // MAINWINDOW_H
