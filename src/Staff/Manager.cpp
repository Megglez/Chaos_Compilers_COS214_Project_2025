//#include "Enquire.h"
#include "Manager.h"



string Manager::trackInventory() {
	// TODO - implement Manager::trackInventory
	stringstream ss;
	
	ss<<"Here is the current Inventory status: "<<endl;

	for(const auto& item : subject->getInventory()) {
		const auto& plantPtr = item.second.first;
		const auto& quantity = item.second.second;
		if(plantPtr)
		{
			ss << "Plant: " << plantPtr->getName() << ", Quantity: " << quantity << std::endl;
		}
		
	}
	
	return ss.str();
}


Manager::Manager(string name,string id,InfoDesk *info,Inventory *inventory): Staff(name,id,infoDesk), subject(inventory)
{
	// TODO - implement Manager::Manager
	
setRole();

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
			switch (getCurrentCustomer()->getAction()->getEnquiryQuestion())
			{
			case "What summer flowers are available": 
				cout<<"Listing summer plants from inventory:"<<endl;
				vector<Plant*> summerPlants;
				summerPlants = subject->getInventory()->FlowerBySeason("Summer");
				for (const auto& item : summerPlants) {
					if (item) {
						std::cout << item->getName() << std::endl;
					}
				}

				break;

			case "What winter plants are available?":
			cout<<"Listing winter plants from inventory:"<<endl;
				vector<Plant*> winterPlants;
				winterPlants = subject->getInventory()->FlowerBySeason("Winter");
				for (const auto& item : winterPlants) {
					if (item) {
						std::cout << item->getName() << std::endl;
					}
				}
				
			case "What is the best time of day to water my plants?":
				cout<<"The best time to water plants is early in the morning or late in the afternoon."<<endl;
				break;

			case "How many categories of plants do you sell?":

				cout<<"We sell 4 categories: Succulents,Flowers,Trees and Herbs."<<endl;
				break;
				
			
			default:
			cout<<"General Sales Enquiry response."<<endl;
				break;
			}
		}
		if(getCurrentCustomer()->getAction()->getEnquiryQuestion()) //garden advice: how many of plant X in stock
		{
			string ss=getCurrentCustomer()->getAction()->getEnquiryQuestion();
			std::istringstream iss(yourString);
			std::string word;
			int count = 0;
			while(iss >> word) {
			++count;
			if (count == 3) {
			// word is the 3rd word
			break;}


			}
		for(const auto& item : subject->getInventory()) {
		const auto& plantName= item.first; 
		const auto& quantity = item.second.second;
		if(plantName==word)
		{
			cout << "Plant: " << plantName << ", Quantity: " << quantity << std::endl;
			break;
		}
		
	}
			
		
		}
	}
	
	}


void Manager::setRole()
{
	this->role = "Manager";
}
