/**
 * @file Available.cpp
 * @brief Implementation of the Available class
 * @author Chaos_Compilers
 * @date 2025
 */

#include "Available.h"

void Available::handle() {
	// TODO - implement Available::handle
	if(this->staff)
	{
		std::cout<< "This staff member is has no tasks to complete - Available."<<std::endl;
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
