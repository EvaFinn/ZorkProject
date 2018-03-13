#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ZorkUL.h"
#include <QMediaPlayer>

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

private:
    Ui::MainWindow *ui;
    ZorkUL *zork;
    QMediaPlayer *breakWindow;
    QMediaPlayer *falling;
    QMediaPlayer *bell;
};

#endif // MAINWINDOW_H
