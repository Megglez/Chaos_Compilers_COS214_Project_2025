#include "Customer.h"

void Customer::request(InfoDesk& desk) {
	// TODO - implement Customer::request
	if(action)
	{
		action->requestStaffAssistance(this,desk); //delegates to state
	}
	
}

void Customer::setAction(std::string ss) {
	// TODO - implement Customer::setAction
	delete action;
	if(ss=="Enquiring")
	{
		
		this->action= new Enquire();
	}

	else if(ss=="Browsing")
	{
	
		this->action= new Browse();
	}

	else if(ss=="Purchasing")
	{
		
		this->action= new Purchasing();
	}

	else
	{
		std::cout<<"unknown State. Default to Browsing.";
		this->action = new Browse();
	}


	
}

Customer::Customer() {
	// TODO - implement Customer::Customer
	setAction("Browsing");
	
}

Customer::~Customer()
{
	delete action;
	delete basket;
}

bool Customer::addToBasket(Plant*plants,int quantity)
{

}
bool Customer::removeFromBasket(Plant* plants,int quantity)
{

}

int Customer::getId()
{
	return id;
}

Action* Customer::getAction()
{
	return this->action;
}

void Customer::setAssignedStaff(Staff*ss)
{

}