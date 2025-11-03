#include "Gardener.h"

void Gardener::helpPlant() {
	// TODO - implement Gardener::helpPlant
	
}

void Gardener::getCareStrategy() {
	// TODO - implement Gardener::getCareStrategy
	
}

}

Gardener::Gardener(std::string &name, std::string &id,InfoDesk& infodesk) {

	
}

Gardener::~Gardener()
{
	delete role;
}

void Gardener::performDuty()
{
//care for plants
// attend to customers
if(getCurrentCustomer())
{
    return true;
}
}
void Gardener::setRole(){
		this->role = "Gardener";
	}