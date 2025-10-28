#include "Busy.h"

void Busy::handle() {
	// TODO - implement Busy::handle

	if(staff)
	{

		/*if(customer.request=)
		*/
		
		
		this->staff->changeState();
		this->staff->setAvailability(true);
		std::cout<< "Staff has assisted customer. Staff is now Available."<<std::endl;
		/*if(staff.getInfodesk())
		{

		}*/
	}
	
	
}


//constructor uneccessary
/*
Busy::Busy() {
	// TODO - implement Busy::Busy
	
}*/

Busy::~Busy()
{
}


std::string Busy::getStateName()const
{
	return "Busy";
}

bool Busy::canAcceptCustomer()
{
	return false;
}
