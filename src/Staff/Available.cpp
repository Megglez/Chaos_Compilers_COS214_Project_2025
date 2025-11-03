#include "Available.h"

void Available::handle() {
	// TODO - implement Available::handle
	if(this->staff)
	{
		std::cout<< "This staff member is has no tasks to complete - Available."<<std::endl;
		return;
	}

	
}

Available::Available() {
    // Initialize Available state
}

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
