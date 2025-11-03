#include "Cashiers.h"



Cashiers::Cashiers(std::string& name,std::string& id,):Staff(name,id) {
	// TODO - implement Cashiers::Cashiers
	workArea="Till";

}

Cashiers::~Cashiers() {

    
}

std::string Cashiers::getStaffType() {
    return "Cashier";
}
 
bool Cashiers::canHandleEnquiry()
{
	return false;
}

void Cashiers::performDuty()
{
	if(currentCustomer)
	{
		cout<<"Now Serving Customer "<<currentCustomer->getId()<<"..."<<endl;
		
		if(currentCustomer->basket.empty())
		cout<<"Customer Basket is empty."<<endl;
		

		else
		{
			emptyBasket();
			//dequeue customer;
	}
	}

	else
	{
		"Cashier "<<getID()<< " waiting to serve the next customer.";
	}

}

void Cashiers::emptyBasket()
{
	if(currentCustomer)
	{
		if(currentCustomer->basket.empty())
		cout<<"Customer Basket is empty."<<endl;
		
		else
		{
			printSlip(currentCustomer->basket);
			while(!currentCustomer->basket.empty())
			{
				currentCustomer->basket.pop_back();
			}
		}
	}

}

string Cashiers::printSlip(vector<Plant*> basket)
{

	stringstream ss;
ss<< "-----Customer "<<currentCustomer->getId()<<" full purchase------ "<<endl;

for(const auto & p: basket)
{
	ss<< p.first.getName() <<" -- "<<p.second<<endl;
}


return ss.str();
}