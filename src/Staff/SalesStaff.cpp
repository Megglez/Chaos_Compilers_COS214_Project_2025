#include "SalesStaff.h"



SalesStaff::SalesStaff() {
	// TODO - implement SalesStaff::SalesStaff
workArea ="Sales Floor";
	
}

SalesStaff::~SalesStaff()
{
}

bool SalesStaff::canHandleEnquiry()
{
	return true;
}

void SalesStaff::performDuty()
{
if(getCurrentCustomer())//someone to help
{	
	string response;
	string enquiry;
	cout<<"What is your Enquiry?"<<endl;
	cin>>response;
	string pos1 = "Do you have"; //inventory 
	string pos2 = "Where are the"; //directions
	string pos3 = "What do I do"; //QnA
	if(enquiry.find(pos1)!=string::npos)
	{
		response = "Yes we do."
	}
	else if(enquiry.find(pos2)!=string::npos)
	{
		response = "Isle 3."
	}
	else if(enquiry.find(pos3)!=string::npos)
	{
		response = "Move it to the shade for 2 weeks.";
	}
	else{
		response = "Sure.";
	}
}

return response;
}

 void SalesStaff::setRole()
 {
	 this->role = "SalesStaff";
 }


