#ifndef TREEPLANTER_H
#define TREEPLANTER_H
#include <iostream>
#include "Planter.h"
#include "Seed.h"
using namespace std;

class TreePlanter : public Planter 
{
public:
	Plant* planterMethod();
	TreePlanter();
	virtual ~TreePlanter();
};

#endif
