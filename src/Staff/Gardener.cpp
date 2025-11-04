#include "Gardener.h"



void Gardener::careForPlants(Plant* plant)
{
	cout << "Gardener " << getName() << " is caring for "<<plant->getName() << endl;
	plant->helpPlant();
}



Gardener::Gardener(std::string &name, std::string &id,InfoDesk& infodesk) {

	
}

Gardener::~Gardener()
{

}

void Gardener::performDuty()//customer
{

if(getCurrentCustomer())
{
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
void Gardener::setRole(){
		this->role = "Gardener";
	}