#ifndef SUCCULENTPLANTER_H
#define SUCCULENTPLANTER_H
#include <iostream>
#include "Planter.h"
#include "Seed.h"
using namespace std;

class SucculentPlanter : public Planter 
{
private: 
	Seed seed;
public:
	virtual Plant* planterMethod(std::string name) override;
	SucculentPlanter();
	virtual ~SucculentPlanter();
};

#endif
