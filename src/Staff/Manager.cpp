#include "Manager.h"

string Manager::trackInventory() {
	// TODO - implement Manager::trackInventory
	stringstream ss;
	
	ss<<"Here is the current Inventory status: "<<endl;

	for(const auto& item : inventory->getInventory()) {
		const auto& plantPtr = item.second.first;
		const auto& quantity = item.second.second;
		if(plantPtr)
		{
			ss << "Plant: " << plantPtr->getName() << ", Quantity: " << quantity << std::endl;
		}
		
	}
	
	return ss.str();
}



Manager::Manager(Inventory* inventory):Staff("Manager","MGR001","")
{
	// TODO - implement Manager::Manager
	subject=inventory;

}

Manager::~Manager()
{
}

bool SalesStaff::canHandleEnquiry()
{
	return true;
}

void SalesStaff::performDuty()
{
	
}

void Manager::setRole()
{
	this->role = "Manager";
}
