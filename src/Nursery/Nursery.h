#ifndef NURSERY_H
#define NURSERY_H
#include <iostream>
#include <vector>
#include "../Staff/Staff.h"
using namespace std;

class Nursery {
private:
    vector<Staff*> staff;
    int customerCount;
    int customerLimit;
public:
    Nursery();
    virtual ~Nursery();
};

#endif
