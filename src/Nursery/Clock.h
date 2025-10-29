#ifndef CLOCK_H
#define CLOCK_H

#include <./Nursery/QObject>
#include <QTimer>

class Clock : public QObject
{
    // Required macro for signal/slot system
    Q_OBJECT 

public:
    explicit Clock(QObject *parent = nullptr);

public slots:
    // A slot is a function that can be connected to a signal
    void onTimerTimeout(); 

private:
    QTimer *timer;
};

#endif