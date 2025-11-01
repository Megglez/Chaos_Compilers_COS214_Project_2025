#include "Browse.h"
#include "Purchasing.h" // Needed for getNextAction()
#include "Customer.h"   // Need full Customer definition
#include "Enquire.h"    // Need Enquire definition for new Enquire()
#include "../Staff/InfoDesk.h"

void Browse::handle()
{
    std::cout << "Customer is browsing. They are considering buying " 
              << quantity << " of " << (plantToBuy ? plantToBuy->getName() : "a generic plant") << std::endl;
}

Action* Browse::getNextAction() {
    // FIX: Correctly instantiate a pointer to the next state, e.g., Purchasing.
    // Assuming Purchasing uses the same constructor parameters.
    return new Purchasing(plantToBuy, quantity); 
}

void Browse::requestStaffAssistance(Customer* customer, InfoDesk& desk)
{
    // Browsing customer decides to Enquire. Transition to the Enquire state.
    std::cout << "Customer wants to Enquire while browsing. Transitioning to Enquire state." << std::endl;
    customer->setAction(new Enquire(plantToBuy)); 
}