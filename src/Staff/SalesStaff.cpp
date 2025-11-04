#include "SalesStaff.h"


SalesStaff::SalesStaff(string& name,string& id,InfoDesk*infodesk) : Staff(name,id,infodesk){
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

void SalesStaff::performDuty()  //1 job
{
//aleady checked question type=0;

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
	


 void SalesStaff::setRole()
 {
	role="SalesStaff";
 }


