#ifndef INFODESK_H
#define INFODESK_H
#include <iostream>
using namespace std;

class InfoDesk {


public:
	virtual void notify(Staff* staff) = 0;

	InfoDesk();

	virtual ~InfoDesk();
};

#endif
