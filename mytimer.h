#ifndef MYTIMER_H
#define MYTIMER_H
#include <QWidget>
#include <QTimer>

class myTimer: public QWidget
{
    Q_OBJECT
    public:
        myTimer();
        myTimer(QWidget * parent = 0);
        ~mTimer();
        void beginTimer();
        QTimer *aTimer;

    public slots:
        void TimerEvent();
};

#endif // MYTIMER_H
