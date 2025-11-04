#ifndef CUSTOMERCLOCK_H
#define CUSTOMERCLOCK_H
#include "Clock.h"
#include <QRandomGenerator> // For generating random numbers

class CustomerClock : public Clock
{
    Q_OBJECT
public:
    explicit CustomerClock(QObject *parent = nullptr);
    void startCustomerClock(); 

signals:
    // Signal to notify the Nursery/MainWindow to spawn a new customer
    void customerArrived(); 

private slots:
    void onBaseTick(); 
};

#endif