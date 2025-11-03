#include "SalesStaff.h"

void SalesStaff::interact() {
	// TODO - implement SalesStaff::interact
	
}

void SalesStaff::QnA() {
	// TODO - implement SalesStaff::QnA
	
}

void SalesStaff::findPlant() {
	// TODO - implement SalesStaff::findPlant
	
}

bool SalesStaff::getAvailability() {
    return Staff::getAvailability();
}

void SalesStaff::setAvailability(bool isAvailable) {
    Staff::setAvailability(isAvailable);
	
}

SalesStaff::SalesStaff() {
	// TODO - implement SalesStaff::SalesStaff
	
}

SalesStaff::~SalesStaff()
{
}

void SalesStaff::performDuty()
{
    interact();
    QnA();
    findPlant();
}

bool SalesStaff::canHandleEnquiry()
{
    return true;
}
