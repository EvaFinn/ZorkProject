#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);     //creates main object that controls program
    MainWindow w;
    w.show();

    return a.exec();                //should return zero if program ran without errors
}
