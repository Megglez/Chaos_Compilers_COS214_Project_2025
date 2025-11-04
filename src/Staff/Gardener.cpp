#include "Gardener.h"
#include "../Customer/Customer.h"
#include "../Customer/Enquire.h"
#include <sstream>

void Gardener::careForPlants(Plant *plant)
{
	cout << "Gardener " << getName() << " is caring for " << plant->getName() << endl;
	plant->helpPlant();
}

Gardener::Gardener(std::string &name, std::string &id, InfoDesk *infodesk) : Staff(name, id, infodesk)
{
	setRole();
}

Gardener::~Gardener()
{
}

void Gardener::careForPlants()
{
	// Implementation for careForPlants without parameters
}

void Gardener::performDuty() // customer
{

	if (getCurrentCustomer())
	{
		Enquire *enquiry = dynamic_cast<Enquire *>(getCurrentCustomer()->getAction());
		if (enquiry && !enquiry->getEnquiryQuestion().empty()) // garden advice: how many of plant X in stock
		{
			string ss = enquiry->getEnquiryQuestion();
			std::istringstream iss(ss);
			std::string word;
			int count = 0;
			while (iss >> word)
			{
				++count;
				if (count == 3)
				{
					// word is the 3rd word
					break;
				}
			}
			for (const auto &item : subject->getInventory())
			{
				const auto &plantName = item.first;
				const auto &quantity = item.second.second;
				if (plantName == word)
				{
					cout << "Plant: " << plantName << ", Quantity: " << quantity << std::endl;
					break;
				}
			}
		}
	}
}

bool Gardener::canHandleEnquiry()
{
	return true;
}

void Gardener::setRole()
{
	this->role = "Gardener";
}
