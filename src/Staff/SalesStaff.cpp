#include "SalesStaff.h"
#include "../Customer/Customer.h"
#include "../Customer/Enquire.h"

SalesStaff::SalesStaff(string &name, string &id, InfoDesk *infodesk) : Staff(name, id, infodesk)
{
	// TODO - implement SalesStaff::SalesStaff
	setRole();
}

SalesStaff::~SalesStaff()
{
}

bool SalesStaff::canHandleEnquiry()
{
	return true;
}

void SalesStaff::performDuty() // 1 job
{
	// already checked question type=0;
	Enquire *enquiry = dynamic_cast<Enquire *>(getCurrentCustomer()->getAction());
	if (!enquiry)
		return;

	string question = enquiry->getEnquiryQuestion();
	if (question == "What summer flowers are available")
	{
		cout << "Listing summer plants from inventory:" << endl;
		vector<Plant *> summerPlants = subject->FlowerBySeason("Summer");
		for (const auto &item : summerPlants)
		{
			if (item)
			{
				std::cout << item->getName() << std::endl;
			}
		}
	}
	else if (question == "What winter plants are available?")
	{
		cout << "Listing winter plants from inventory:" << endl;
		vector<Plant *> winterPlants = subject->FlowerBySeason("Winter");
		for (const auto &item : winterPlants)
		{
			if (item)
			{
				std::cout << item->getName() << std::endl;
			}
		}
	}
	else if (question == "What is the best time of day to water my plants?")
	{
		cout << "The best time to water plants is early in the morning or late in the afternoon." << endl;
	}
	else if (question == "How many categories of plants do you sell?")
	{
		cout << "We sell 4 categories: Succulents,Flowers,Trees and Herbs." << endl;
	}
	else
	{
		cout << "General Sales Enquiry response." << endl;
	}
}

void SalesStaff::setRole()
{
	role = "SalesStaff";
}
