#ifndef ENQUIRE_H
#define ENQUIRE_H

#include "Action.h"
#include "../Greenhouse/Plant.h"
#include <string>
#include <vector>

class Customer;
class InfoDesk;

class Enquire : public Action
{
private:
    std::vector<Plant *> plantsOfInterest;
    std::string enquiryQuestion;

public:
    Enquire(Plant *plant, const std::string &question = "") : Action("Enquiring"), enquiryQuestion(question)
    {
        if (plant)
            plantsOfInterest.push_back(plant);
    }
    Enquire(std::vector<Plant *> plants, const std::string &question = "") : Action("Enquiring"), plantsOfInterest(plants), enquiryQuestion(question) {}
    virtual ~Enquire() {}

    void handle() override;
    Action *getNextAction() override;
    void requestStaffAssistance(Customer *customer, InfoDesk &desk) override;
    std::string getEnquiryQuestion() const { return enquiryQuestion; }
    std::vector<Plant *> getPlantsOfInterest() const { return plantsOfInterest; }
};
#endif