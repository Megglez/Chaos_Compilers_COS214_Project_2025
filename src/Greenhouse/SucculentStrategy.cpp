#include "SucculentStrategy.h"

void SucculentStrategy::helpPlant(std::string& care) 
{
	cout << "Succulent currently being cared for by: " << care << std::endl;
	
}

SucculentStrategy::SucculentStrategy() 
{
	// TODO - implement SucculentStrategy::SucculentStrategy
	
}

SucculentStrategy::~SucculentStrategy()
{
}


CareStrategy* SucculentStrategy::clone(){
	return new SucculentStrategy();
}