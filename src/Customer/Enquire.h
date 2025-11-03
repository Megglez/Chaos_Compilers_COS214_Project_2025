#ifndef ENQUIRE_H
#define ENQUIRE_H

#include "Action.h"
#include "../Greenhouse/Plant.h"
#include <string>
#include <iostream>
using namespace std;

class Customer;
class InfoDesk;

class Enquire : public Action
{
private:
    Plant *plantOfInterest;
    string enquiryQuestion;

public:
    Enquire(Plant *plant, const string &question = "") : Action("Enquiring"), plantOfInterest(plant), enquiryQuestion(question) {}
    virtual ~Enquire() {}

    void handle() override;
    Action *getNextAction() override;
    void requestStaffAssistance(Customer *customer, InfoDesk &desk) override;
    string getEnquiryQuestion() const { return enquiryQuestion; }
};
#endif