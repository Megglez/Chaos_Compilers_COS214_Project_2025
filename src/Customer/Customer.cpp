#include "Customer.h"

void Customer::request() {
	if(action)
	{
		action->requestStaffAssistance(this,desk); //delegates to state
	}
}

void Customer::setAction(string ss) {
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
		cout<<"unknown State. Default to Browsing.";
		this->action = new Browse();
	}


	
}

Customer::Customer(Action* action) {
	id = 0;
	this->action = action;
}

Customer::~Customer()
{
	delete action;
}

bool Customer::addToBasket(Plant*plants,int quantity)
{
	return false;
}

bool Customer::removeFromBasket(Plant* plants,int quantity)
{
	return true;
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