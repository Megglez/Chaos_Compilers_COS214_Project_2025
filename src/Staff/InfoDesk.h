#ifndef INFODESK_H
#define INFODESK_H
#include <iostream>
using namespace std;

class Staff;
class InfoDesk {
public:
	virtual void notify(Staff* staff);
	InfoDesk();
	virtual ~InfoDesk();
};

#endif
