#include "Available.h"

void Available::handle() {
	// TODO - implement Available::handle
	if(this->staff)
	{
		std::cout<< "This staff member is has no tasks to complete - Available."<<std::endl;
		return;
	}

	
}

//constructor uneccessary
/*Available::Available() {
	// TODO - implement Available::Available
	
}*/

Available::~Available()
{
}

std::string Available::getStateName()const
{
	return "Available";
}

bool Available::canAcceptCustomer()
{
	return true;
}
