#include "Available.h"

void Available::handle() {
	// TODO - implement Available::handle
	if(this->staff)
	{
		cout<< "This staff member is has no tasks to complete - Available."<<endl;
	}

	
}

Available::Available() {
    // Initialize Available state
}

Available::~Available()
{
}

string Available::getStateName()const
{
	return "Available";
}

bool Available::canAcceptCustomer()
{
	return true;
}
