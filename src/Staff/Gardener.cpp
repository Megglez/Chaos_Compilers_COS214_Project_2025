#include "Gardener.h"


Gardener::Gardener(std::string &name, std::string &id,InfoDesk& infodesk) {

	workArea ="Garden Area";
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

}
}

void Gardener::setRole(){
		this->role = "Gardener";
	}