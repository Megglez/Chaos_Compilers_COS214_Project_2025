#ifndef INFODESK_H
#define INFODESK_H

class InfoDesk {


public:
	virtual void notify(Staff* staff) = 0;

	InfoDesk();

	virtual void ~InfoDesk() = 0;
};

#endif
