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
    int questionType; // 0 = advice question, 1 = information question

public:
    Enquire(Plant *plant, const std::string &question = "", int qType = 0) : Action("Enquiring"), enquiryQuestion(question), questionType(qType)
    {
        if (plant)
            plantsOfInterest.push_back(plant);
    }
    Enquire(std::vector<Plant *> plants, const std::string &question = "", int qType = 0) : Action("Enquiring"), plantsOfInterest(plants), enquiryQuestion(question), questionType(qType) {}
    virtual ~Enquire() {}

    void handle() override;
    Action *getNextAction() override;
    void requestStaffAssistance(Customer *customer, InfoDesk &desk) override;
    std::string getEnquiryQuestion() const { return enquiryQuestion; }
    std::vector<Plant *> getPlantsOfInterest() const { return plantsOfInterest; }

    // Getter for question type: 0 = advice question, 1 = information question
    int getQuestionType() const { return questionType; }
};
#endif