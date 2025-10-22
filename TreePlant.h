#ifndef TREEPLANT_H
#define TREEPLANT_H
#include <iostream>
using namespace std;

class TreePlant : Plant {


public:
	virtual Plant* clone() = 0;

	void package();

	TreePlant();

	virtual ~TreePlant();
};

#endif
