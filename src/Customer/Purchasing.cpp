#include "Purchasing.h"
#include "Customer.h"
#include "../Staff/InfoDesk.h"
#include <iostream>

void Purchasing::handle() {
    // TODO: Implement actual purchasing logic
    std::cout << "Customer is purchasing " << quantity << " plant(s)" << std::endl;
}

Action* Purchasing::getNextAction() {
    // After purchasing, the customer is done with their transaction
    // Return nullptr to indicate no further actions
    return nullptr;
}

void Purchasing::requestStaffAssistance(Customer *customer, InfoDesk& desk) {
    std::cout << "Customer needs assistance with purchase. Requesting staff help." << std::endl;
    desk.handleCustomer(customer);
}
