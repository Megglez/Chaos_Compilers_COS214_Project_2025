#ifndef CLOCK_H
#define CLOCK_H

#include <QObject>
#include <QTimer> 

class Clock : public QObject
{
    Q_OBJECT 

public:
    explicit Clock(QObject *parent = nullptr);
    virtual ~Clock() = default; // Important for base classes
    
    // Starts the internal timer with the given interval (reusable function)
    void startClock(int intervalMs); 

signals:
    // A generic signal all derived classes can connect to internally
    void ticked(); 

private slots:
    // Catches the internal QTimer's signal and emits the custom 'ticked' signal
    void onInternalTimeout(); 

private:
    QTimer *internalTimer;
};

#endif