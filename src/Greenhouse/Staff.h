#ifndef STAFF_H
#define STAFF_H
#include <iostream>
#include "../Greenhouse/Plant.h"

class Inventory;

using namespace std;

class Staff
{
private:
	string name;
	string staffID;
	string workArea;

public:
	void update(const std::string &update);
};

#endif
