#include "Browse.h"

void Browse::handle() {
	// TODO - implement Browse::handle
	
}

Action* Browse::getNextAction() {
	// TODO - implement Browse::getNextAction
	//random - either go to enquiry or purchase if basket<1
}

Browse::Browse() {
	// TODO - implement Browse::Browse
	
}

Browse::~Browse()
{
}

void Browse::requestStaffAssistance()
{
	
}

string Browse::getActionName() 
{
 return "Browsing";
}

void Browse::requestStaffAssistance(Customer *customer,InfoDesk& desk)
{
	std::cout<<"Please go to the InfoDesk to receive assistance."<<std::endl;
}
