#include "Cashiers.h"



Cashiers::Cashiers(std::string& name,std::string& id):Staff(name,id) {
	// TODO - implement Cashiers::Cashiers
	workArea="Till";
	
}

Cashiers::~Cashiers()
{
}


std::string getName()
{
    return "Cashier";
std::string Cashiers::getStaffType() 
 {
return "Cashier";
}

std::string getID()
{
    return "C001"; // Default ID for now
}

std::string getStaffType() 
 
bool Cashiers::canHandleEnquiry()
{
    return "Cashier";
}
	return false;
 }