#include "Busy.h"
#include "InfoDesk.h"
void Busy::handle() {
	// TODO - implement Busy::handle

	if(staff)
	{
		cout<<staff->getName()<< " is completing this task."<<std::endl;
 
		
		staff->setCurrentCustomer(nullptr);
 		this->staff->changeState();
 		this->staff->setAvailability(true);
		InfoDesk* infod = staff->getInfodesk();
		if(infod)
		{
			infod->notifyStaffAvailable(staff);
		}
 		std::cout<< "Staff has assisted customer. Staff is now Available."<<std::endl;
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
