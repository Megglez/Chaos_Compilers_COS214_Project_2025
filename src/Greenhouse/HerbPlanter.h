#ifndef HERBPLANTER_H
#define HERBPLANTER_H
#include <iostream>
#include "Planter.h"
#include "Seed.h"
using namespace std;

class HerbPlanter : public Planter 
{
public:
	virtual Plant* planterMethod(std::string name) override;
	HerbPlanter();
	virtual ~HerbPlanter();
	CareStrategy* clone();
};

#endif
