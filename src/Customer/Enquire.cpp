#include "Enquire.h"
#include "Customer.h"
#include "../Staff/InfoDesk.h"
#include <iostream>
using namespace std;

void Enquire::handle() {
    // TODO - implement Enquire::handle
    cout << "Customer is handling the Enquire action" << endl;
}

Action* Enquire::getNextAction() {
    // For now, return nullptr as there is no next action after enquiring
    return nullptr;
}

void Enquire::requestStaffAssistance(Customer* customer, InfoDesk& desk) {
    cout << "Customer is requesting assistance at infodesk." << endl;
    desk.handleCustomer(customer);
}