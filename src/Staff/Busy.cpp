#include "Busy.h"

void Busy::handle() {
	// TODO - implement Busy::handle

	if(staff)
	{

		
		this->staff->changeState();
		this->staff->setAvailability(true);
		std::cout<< "Staff has assisted customer. Staff is now Available."<<std::endl;
		
		this->staff->changeState();
		this->staff->setAvailability(true);	
		
		

		//remove staff from Infodesk::AvailableStaff

	}
	
	
}


Busy::Busy() {
    // Initialize Busy state
}

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
