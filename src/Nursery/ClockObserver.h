#ifndef CLOCKOBSERVER_H
#define CLOCKOBDERVER_H

class ClockObserver 
{
private:
public:
    ClockObserver();
    virtual ~ClockObserver();
    virtual void update();
};

#endif