#ifndef TREEPLANTER_H
#define TREEPLANTER_H
#include <iostream>
using namespace std;

class TreePlanter : public Planter {


public:
	Plant* planterMethod();

	TreePlanter();

	virtual ~TreePlanter();
};

#endif
