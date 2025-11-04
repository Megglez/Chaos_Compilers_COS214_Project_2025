#include "Staff.h"
#include "../Customer/Customer.h"
#include "InfoDesk.h"


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

Staff::Staff(const string& name, const string& id){
	this->name=name;
	this->staffID=id;
	available= true;
	infoDesk=nullptr;
	nextInChain=nullptr;
	currentCustomer=nullptr;
	state=new Available();
	state->setContext(this);
}

void Staff::update(const string &update)
{
	cout << "New Notification: " << update << endl;
}

Staff::Staff()
{
    name = "";
    staffID = "";
    available = true;
    infoDesk = nullptr;
    nextInChain = nullptr;
    currentCustomer = nullptr;
    state = new Available();
    state->setContext(this);

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
    return nextInChain;return nextInChain;
}

void Staff::setNextInChain(Staff* ss)
{
    nextInChain = ss;nextInChain=ss;
}

string Staff::getName()
{
return name;
}

string Staff::getID()
{
 return staffID;
}

string Staff::getStaffType()
{
	
	return state->getStateName();

}
bool Staff::getAvailability(){
return available;	
}

InfoDesk * Staff::getInfodesk()
{
	return this->infoDesk;
}

void Staff::completeTask()
{
	state->handle();
 }

  void Staff::assistCustomer(Customer *cc)
 {
	if(!cc)
	{
		cout<<"Staff "<< name<< "cannot assist null Customer"<<endl;
		return;
	}
	if(!getAvailability())
	{
	cout<<"Staff "<< name<< "is not Available."<<endl;
		return;
	}

	cout<<"Staff "<<name<< " is assisting Customer "<<cc->getId();
	currentCustomer=cc;
	this->changeState();
	available=false;
	performDuty();
	cc->setAssignedStaff(this);

 }

 Staff* Staff::handleEnquiryRequest()
 {
if(canHandleEnquiry()&& getAvailability())
{
	cout<< getStaffType()<<" "<<name<< "can handle enquiry."<<endl;
}
return this;

if(nextInChain)
{
cout<< getStaffType()<<" "<<name<< "can't handle enquiry.Passing on to.."<<endl;
	cout<<nextInChain->getStaffType();
	return nextInChain->handleEnquiryRequest();
}

//otherwise
cout<<"No staff avaialable to handle enquiry."<<endl;
return nullptr;
 }

void Staff::registerToAllStaff(InfoDesk *desk)
{
	if(!desk)
	{
		cout<<"cannot register. Null Infodesk."<<endl;
		return;
	}

	if(infoDesk)
	{
		cout<<"Staff already registered in AllStaff."<<endl;
		return;
	}

	infoDesk=desk;
	desk->addStaff(this);
	cout<<name<< " registered from AllStaff."<<endl;

 }

void Staff ::unregisterFromAllStaff()
 {
if(!infoDesk)
{
	cout<<"Staff not registered!"<<endl;
	return;
}

this->infoDesk->removeStaff(this);
infoDesk=nullptr;
cout<<name<< " unregistered from AllStaff."<<endl;

}

string Staff::getStateName()
{
 if(state)
 {
	return state->getStateName();
 }
 return "Unknown";
}

Customer* Staff::getCurrentCustomer()
{
	return currentCustomer;

}

void Staff::setCurrentCustomer(Customer* cc)
{
currentCustomer=cc;
}