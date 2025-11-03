#include "SalesStaff.h"



SalesStaff::SalesStaff() {
	// TODO - implement SalesStaff::SalesStaff
workArea ="Sales Floor";
	
}

SalesStaff::~SalesStaff()
{
	delete role;
}

bool SalesStaff::canHandleEnquiry()
{
	return true;
}

void SalesStaff::performDuty()  //1 job
{
switch (/*getSelectedQuestion*/)
			{
			case 0: //"What summer plants are available?"
				cout<<"Listing summer plants from inventory:"<<endl;
				vector<Plant*> summerPlants;
				summerPlants = subject->getInventory()->:FlowerBySeason("Summer");
				for (const auto& item : summerPlants) {
					if (item) {
						std::cout << item->getName() << std::endl;
					}
				}

				break;
			case 1: //"What winter plants are available?"
			cout<<"Listing winter plants from inventory:"<<endl;
				vector<Plant*> winterPlants;
				summerPlants = subject->getInventory()->:FlowerBySeason("Winter");
				for (const auto& item : winterPlants) {
					if (item) {
						std::cout << item->getName() << std::endl;
					}
				}
				
			case 2:   //"What is the best time of day to water my plants?"
				cout<<"The best time to water plants is early in the morning or late in the afternoon."<<endl;
				break;

			case 3:  //"How many categories of plants do you sell?"

				cout<<"We sell 4 categories: Succulents,Flowers,Trees and Herbs."<<endl;
				break;	
			
			default:
			cout<<"General Sales Enquiry response."<<endl;
				break;
			}
		}
	


 void SalesStaff::setRole()
 {
	 this->role = "SalesStaff";
 }


