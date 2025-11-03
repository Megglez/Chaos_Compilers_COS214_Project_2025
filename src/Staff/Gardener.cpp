#include "Gardener.h"

void Gardener::helpPlant() {
	// TODO - implement Gardener::helpPlant
	
}

void Gardener::getCareStrategy() {
	// TODO - implement Gardener::getCareStrategy
	
}

bool Gardener::getAvailability() {
    return Staff::getAvailability();
}

void Gardener::setAvailability(bool isAvailable) {
    Staff::setAvailability(isAvailable);
	
}

Gardener::Gardener() {
	// TODO - implement Gardener::Gardener
	
}

Gardener::~Gardener()
{
}

void Gardener::performDuty()
{
    helpPlant();
    getCareStrategy();
}

bool Gardener::canHandleEnquiry()
{
    return true;
}
