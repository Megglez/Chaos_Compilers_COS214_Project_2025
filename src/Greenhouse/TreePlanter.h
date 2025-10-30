#ifndef TREEPLANTER_H
#define TREEPLANTER_H
#include <iostream>
#include "Planter.h"
#include "Seed.h"
using namespace std;

class TreePlanter : public Planter 
{
public:
	virtual Plant* planterMethod(std::string name) override;
	TreePlanter();
	virtual ~TreePlanter();
};

#endif
