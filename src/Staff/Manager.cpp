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

bool Manager::canHandleEnquiry()
{
	return true;
}

void Manager::performDuty()
{
	if(getCurrentCustomer())//someone to help
	{
		if(getCurrentCustomer()->getQuestionType()==0) //sales advice
		{
			switch (/*selectedQuestion*/)
			{
			case 0: //"What summer plants are available?"
				/* code */
				//get all summer plants from inventory where type 
				break;
			case 1: //"What winter plants are available?"
			//get all winter plants from inventory
				/* code */

			case 2:   //"What is the best time of day to water my plants?"
				/* code */ 
				break;

			case 3:  //"How many categories of plants do you sell?"

				/* code *// 
				break;	
			
			default:
				break;
			}
		}
		else //garden advice
		{
			cout<<"General Enquiry response."<<endl;
		}
	}
	else
{cout<< trackInventory()<<endl;}
	}


void Manager::setRole()
{
	this->role = "Manager";
}
