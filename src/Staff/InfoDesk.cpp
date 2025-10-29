#include "InfoDesk.h"
#include "Staff.h"

void InfoDesk::notify(Staff *staff)
{
    staff->getAvailability(); //remove immediately
}

InfoDesk::InfoDesk()
{
    // TODO - implement InfoDesk::InfoDesk
	
}

InfoDesk::~InfoDesk()
{
}
