#include "Cashiers.h"



Cashiers::Cashiers(std::string& name,std::string& id):Staff(name,id) {
	// TODO - implement Cashiers::Cashiers
	workArea="Till";
	
}

Cashiers::~Cashiers()
{
}

std::string Cashiers::getStaffType() 
 {
return "Cashier";
}
 
bool Cashiers::canHandleEnquiry()
{
	return false;
 }