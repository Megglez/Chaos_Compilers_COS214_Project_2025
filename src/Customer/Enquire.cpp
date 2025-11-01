#include "Enquire.h"

void Enquire::handle() {
	// TODO - implement Enquire::handle
	
}

Action* Enquire::getNextAction() {
	// TODO - implement Enquire::getNextAction
	//return Enquire();
	
}

Enquire::Enquire() {
	// TODO - implement Enquire::Enquire
	
}

Enquire::~Enquire()
{
}

std::string Enquire::getActionName() 
{
	return "Enquiring";
}

void Enquire::requestStaffAssistance(Customer *customer, InfoDesk& desk)
{
	std::cout<<"Customer is requesting assistance at infodesk."<<std::endl;
	// call staff at infodesk
	desk.handleCustomer(customer);
	
	


}