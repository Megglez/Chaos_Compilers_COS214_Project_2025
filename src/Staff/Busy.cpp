#include "Busy.h"
#include "Staff.h"
#include "InfoDesk.h"
void Busy::handle() {
	// TODO - implement Busy::handle

	if(staff)
	{
		cout<<staff->getName()<< " is completing this task."<<endl;
 
		
		staff->setCurrentCustomer(nullptr);
 		this->staff->changeState();
 		this->staff->setAvailability(true);
		InfoDesk* infod = staff->getInfodesk();
		if(infod)
		{
			infod->notifyStaffAvailable(staff);
		}
 		cout<< "Staff has assisted customer. Staff is now Available."<<endl;
		//remove staff from Infodesk::AvailableStaff

	}
	
	
}


Busy::Busy() {
    // Initialize Busy state
}

Busy::~Busy()
{
}


string Busy::getStateName()const
{
	return "Busy";
}

bool Busy::canAcceptCustomer()
{
	return false;
}
