#include "Cashiers.h"

Cashiers::Cashiers(std::string& name, std::string& id) : Staff(name, id) {
    currentCustomer = nullptr;
    subject = nullptr;
}

Cashiers::~Cashiers() {
    if (subject) {
        delete subject;
    }
}

std::string Cashiers::getStaffType() {
    return "Cashier";
}

bool Cashiers::canHandleEnquiry() {
    return false;
}

void Cashiers::performDuty() {
    if (currentCustomer != nullptr) {
        makeTransaction();
    }
}

void Cashiers::makeTransaction() {
    if (currentCustomer != nullptr) {
        emptyBasket();
    }
}

void Cashiers::emptyBasket() {
    // Implementation for emptying the customer's basket
    // This will be implemented when basket functionality is added
}