#include "Staff.h"


void Staff::changeState()
{
	// TODO - implement Staff ::changeState
	if(this->state)
	{
		if(this->state->getStateName()=="Busy")
		{
			delete this->state;
			this->state=new Available();
			this->state->setContext(this);
		}
		else
		{	delete this->state;
			this->state=new Busy();
			this->state->setContext(this);
		}
	
	}
}

void Staff::update(const std::string &update)
{
	std::cout << "New Notification: " << update << std::endl;
}

Staff::Staff()
{
	// TODO - implement Staff ::Staff
	this->state = new Available();

}

Staff::~Staff()
{
	delete this->state;
}

void Staff::setAvailability(bool isAvailable)
{
	available=isAvailable;
}

Staff* Staff::getNextInChain()
{
    return nextInChain;
}

void Staff::setNextInChain(Staff* ss)
{
    nextInChain = ss;
}

std::string Staff::getName()
{
return name;
}

std::string Staff::getID()
{
 return staffID;
}

std::string Staff::getStaffType()
{
	
	return state->getStateName();

}
void Staff::getAvailability(){
	
}
