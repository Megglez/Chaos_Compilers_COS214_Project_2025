#include "Manager.h"

void Manager::trackInventory() {
	// TODO - implement Manager::trackInventory
	
}

bool Manager::getAvailability() {
    return Staff::getAvailability();
}

void Manager::setAvailability(bool isAvailable) {
    Staff::setAvailability(isAvailable);
	
}

Manager::Manager() {
	// TODO - implement Manager::Manager
	
}

Manager::~Manager()
{
}

void Manager::performDuty()
{
    trackInventory();
}

bool Manager::canHandleEnquiry()
{
    return true;
}
