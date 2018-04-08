#include "mytimer.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QTimer>

using namespace std;

myTimer::myTimer()
{

}

myTimer::myTimer(QWidget *parent): QWidget(parent)
{
    aTimer = new QTimer;
}

MyTimer::~MyTimer(){

}
void myTimer::beginTimer()
{
        connect(aTimer, SIGNAL(timeout()), this, SLOT(TimerEvent()));
        aTimer->start(10000);
}
