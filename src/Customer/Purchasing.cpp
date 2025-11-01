#include "Purchasing.h"

void Purchasing::handle() {
	// TODO - implement Purchasing::handle

	
}

Action* Purchasing::getNextAction() {
	// TODO - implement Purchasing::getNextAction
	return Action();
}

Purchasing::Purchasing() {
	// TODO - implement Purchasing::Purchasing
	
}

Purchasing::~Purchasing()
{
}

std::string Purchasing::getActionName() 
{
	return "Purchasing";
}

void Purchasing::requestStaffAssistance(Customer *customer,InfoDesk& desk)
{
	std::cout<< "Currently in the queue. You need to leave the queue for assistance.";
}
