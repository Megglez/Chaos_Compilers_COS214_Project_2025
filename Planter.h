#ifndef PLANTER_H
#define PLANTER_H
#include <iostream>
using namespace std;

class Planter {


public:
	virtual Plant* planterMethod() = 0;

	Planter();

	virtual ~Planter();
};

#endif
