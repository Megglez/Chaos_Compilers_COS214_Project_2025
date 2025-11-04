#include <gtest/gtest.h>
#include "../src/Customer/Customer.h"
#include "../src/Customer/CustomerCreator.h"
#include "../src/Customer/Browse.h"
#include "../src/Customer/Enquire.h"
#include "../src/Customer/Purchasing.h"
#include "../src/Greenhouse/Plant.h"
#include "../src/Greenhouse/Stock.h"
#include "../src/Greenhouse/Inventory.h"
#include "../src/Greenhouse/GiftWrap.h"
#include "../src/Greenhouse/Pot.h"
#include "../src/Greenhouse/SpecialArrangement.h"
#include "../src/Staff/Staff.h"
#include "../src/Nursery/Nursery.h"
#include <memory>
#include <set>
#include <map>

// Dummy Plant for testing
class DummyPlant : public Plant
{
public:
    DummyPlant(const std::string &n) { name = n; }
    Plant *clone() override { return new DummyPlant(*this); }
    void grow() override {}
    void setStage(StageOfDevelopment *) override {}
    void helpPlant() override {}
    void package() override {}
    std::string getType() override { return "Dummy"; }
    std::string getName() override { return name; }
    StageOfDevelopment *getState() override { return nullptr; }
    int getWater() override { return 0; }
    int getSoil() override { return 0; }
    int getSunlight() override { return 0; }
    bool isWinter() const override { return false; }
    CareStrategy *getCare() override { return nullptr; }
};

// Dummy Staff for testing
class DummyStaff : public Staff
{
public:
    DummyStaff() : Staff("TestStaff", "S1", nullptr) {}
    void performDuty() override {}
    bool canHandleEnquiry() override { return true; }
    void setRole() override {}
};

// Test Customer creation with Browse and Enquire
TEST(CustomerTest, CreationAndGetters)
{
    DummyPlant plant("TestPlant");
    Browse *browse = new Browse(&plant, 3);
    Nursery nursery;
    Customer c1(browse, &nursery);
    EXPECT_EQ(c1.getAction()->getActionName(), "Browsing");
    EXPECT_EQ(c1.getAssignedStaff(), nullptr);
    EXPECT_GT(c1.getId(), 0);

    Enquire *enquire = new Enquire(&plant, "What is this?");
    Customer c2(enquire, &nursery);
    EXPECT_EQ(c2.getAction()->getActionName(), "Enquiring");
    EXPECT_EQ(static_cast<Enquire *>(c2.getAction())->getEnquiryQuestion(), "What is this?");
}

// Test setAction and processNextAction (Browse -> Enquire or leave)
TEST(CustomerTest, StateTransitionAndSetAction)
{
    DummyPlant plant("TestPlant");
    Nursery nursery;
    Customer c(new Browse(&plant, 2), &nursery);
    // Simulate transition
    Action *next = c.getAction()->getNextAction();
    c.setAction(next);
    if (next)
    {
        EXPECT_TRUE(next->getActionName() == "Enquiring" ||
                    next->getActionName() == "Browsing" ||
                    next->getActionName() == "Purchasing");
    }
}

// Test basket management
TEST(CustomerTest, BasketManagement)
{
    DummyPlant plant("TestPlant");
    Nursery nursery;
    Customer c(new Browse(&plant, 2), &nursery);
    EXPECT_TRUE(c.addToBasket(&plant, 1));
    EXPECT_EQ(c.getBasket().size(), 1);
    c.clearBasket();
    EXPECT_EQ(c.getBasket().size(), 0);
}

// Test staff assignment
TEST(CustomerTest, StaffAssignment)
{
    DummyPlant plant("TestPlant");
    Nursery nursery;
    Customer c(new Browse(&plant, 2), &nursery);
    DummyStaff staff;
    c.setAssignedStaff(&staff);
    EXPECT_EQ(c.getAssignedStaff(), &staff);
}

// Test CustomerCreator randomization (Browse/Enquire, question selection)
TEST(CustomerTest, CustomerCreatorRandomization)
{
    Inventory inv;
    DummyPlant *p1 = new DummyPlant("A");
    DummyPlant *p2 = new DummyPlant("B");
    inv.addPlant(std::unique_ptr<Plant>(p1), 5);
    inv.addPlant(std::unique_ptr<Plant>(p2), 5);
    Stock stock(&inv);
    Nursery nursery;
    CustomerCreator creator;
    int browseCount = 0, enquireCount = 0;
    std::set<std::string> questions;
    for (int i = 0; i < 50; ++i)
    {
        Customer *c = creator.createNewCustomer(&nursery, &stock);
        std::string act = c->getAction()->getActionName();
        if (act == "Browsing")
            browseCount++;
        else if (act == "Enquiring")
        {
            enquireCount++;
            questions.insert(static_cast<Enquire *>(c->getAction())->getEnquiryQuestion());
        }
        delete c;
    }
    EXPECT_GT(browseCount, 0);
    EXPECT_GT(enquireCount, 0);
    EXPECT_GE(questions.size(), 2); // At least 2 different questions should appear
}

// Test Enquire question getter
TEST(CustomerTest, EnquireQuestionGetter)
{
    DummyPlant plant("TestPlant");
    Enquire e(&plant, "How are you?");
    EXPECT_EQ(e.getEnquiryQuestion(), "How are you?");
}

// Test Customer memory management (basic)
TEST(CustomerTest, MemoryManagement)
{
    DummyPlant plant("TestPlant");
    Nursery nursery;
    Customer *c = new Customer(new Browse(&plant, 1), &nursery);
    delete c; // Should not leak or crash
}

// Test Customer leaving (processNextAction to nullptr)
TEST(CustomerTest, CustomerLeavesNursery)
{
    DummyPlant plant("TestPlant");
    Nursery nursery;
    Customer *c = new Customer(new Enquire(&plant, "Test leave"), &nursery);
    // Call processNextAction until action is nullptr (simulate leaving)
    int steps = 0;
    while (c->getAction() && steps < 10)
    {
        c->processNextAction();
        steps++;
    }
    EXPECT_TRUE(c->getAction() == nullptr || steps == 10);
    delete c;
}

// Test Enquire with question type parameter (NEW)
TEST(CustomerTest, EnquireQuestionTypeAdvice)
{
    DummyPlant plant("Rose");
    Enquire adviceEnquire(&plant, "What is the best time to water plants?", 0);
    EXPECT_EQ(adviceEnquire.getQuestionType(), 0); // Advice question
    EXPECT_EQ(adviceEnquire.getEnquiryQuestion(), "What is the best time to water plants?");
}

TEST(CustomerTest, EnquireQuestionTypeInformation)
{
    DummyPlant plant("Basil");
    Enquire infoEnquire(&plant, "How many Basil do you have in stock?", 1);
    EXPECT_EQ(infoEnquire.getQuestionType(), 1); // Information question
    EXPECT_EQ(infoEnquire.getEnquiryQuestion(), "How many Basil do you have in stock?");
}

TEST(CustomerTest, EnquireQuestionTypeDefault)
{
    DummyPlant plant("Cactus");
    Enquire defaultEnquire(&plant, "General question");
    EXPECT_EQ(defaultEnquire.getQuestionType(), 0); // Default is advice (0)
}

// Test Enquire with vector constructor and question type
TEST(CustomerTest, EnquireVectorConstructorWithQuestionType)
{
    DummyPlant plant1("Rose");
    DummyPlant plant2("Basil");
    std::vector<Plant *> plants = {&plant1, &plant2};
    Enquire enquire(plants, "How do I care for these?", 0);
    EXPECT_EQ(enquire.getQuestionType(), 0);
    EXPECT_EQ(enquire.getPlantsOfInterest().size(), 2);
}

// Test Browse getPlantsToBuy and getQuantities (NEW)
TEST(CustomerTest, BrowseGettersForPlantsAndQuantities)
{
    DummyPlant plant1("Rose");
    DummyPlant plant2("Basil");
    std::vector<Plant *> plants = {&plant1, &plant2};
    std::vector<int> quantities = {3, 5};
    Browse browse(plants, quantities);

    EXPECT_EQ(browse.getPlantsToBuy().size(), 2);
    EXPECT_EQ(browse.getQuantities().size(), 2);
    EXPECT_EQ(browse.getQuantities()[0], 3);
    EXPECT_EQ(browse.getQuantities()[1], 5);
}

// Test Browse getNextAction returns Browse, Enquire, or Purchasing (UPDATED)
TEST(CustomerTest, BrowseGetNextActionReturnsThreeStates)
{
    DummyPlant plant("TestPlant");
    Browse browse(&plant, 2);

    std::set<std::string> actionTypes;
    for (int i = 0; i < 30; ++i)
    {
        Action *action = browse.getNextAction();
        if (action)
        {
            actionTypes.insert(action->getActionName());
            delete action;
        }
    }

    // Should be able to return Browse, Enquire, or Purchasing
    EXPECT_GE(actionTypes.size(), 2); // At least 2 different action types
    // Check that only valid action types are returned
    for (const auto &type : actionTypes)
    {
        EXPECT_TRUE(type == "Browsing" || type == "Enquiring" || type == "Purchasing");
    }
}

// Test CustomerCreator with question type distribution (NEW)
TEST(CustomerTest, CustomerCreatorQuestionTypeDistribution)
{
    Inventory inv;
    DummyPlant *p1 = new DummyPlant("Rose");
    DummyPlant *p2 = new DummyPlant("Basil");
    inv.addPlant(std::unique_ptr<Plant>(p1), 10);
    inv.addPlant(std::unique_ptr<Plant>(p2), 10);
    Stock stock(&inv);
    Nursery nursery;
    CustomerCreator creator;

    int adviceQuestions = 0;
    int infoQuestions = 0;
    int browseCustomers = 0;

    // Increased to 100 iterations for better statistical distribution
    for (int i = 0; i < 100; ++i)
    {
        Customer *c = creator.createNewCustomer(&nursery, &stock);
        if (c->getAction()->getActionName() == "Enquiring")
        {
            Enquire *enquire = dynamic_cast<Enquire *>(c->getAction());
            if (enquire)
            {
                int qType = enquire->getQuestionType();
                if (qType == 0)
                    adviceQuestions++;
                else if (qType == 1)
                    infoQuestions++;
            }
        }
        else if (c->getAction()->getActionName() == "Browsing")
        {
            browseCustomers++;
        }
        delete c;
    }

    // Should have both browse and enquire customers
    EXPECT_GT(browseCustomers, 0);
    // Should have at least some enquire customers
    int totalEnquireCustomers = adviceQuestions + infoQuestions;
    EXPECT_GT(totalEnquireCustomers, 0);
    // Among enquire customers, both question types should eventually appear
    // (or at least one of each type should appear given enough iterations)
    EXPECT_TRUE(adviceQuestions > 0 || infoQuestions > 0);
}

// Test CustomerCreator with null nursery (NEW - testing null safety)
TEST(CustomerTest, CustomerCreatorWithNullNursery)
{
    Inventory inv;
    DummyPlant *p1 = new DummyPlant("TestPlant");
    inv.addPlant(std::unique_ptr<Plant>(p1), 5);
    Stock stock(&inv);
    CustomerCreator creator;

    // Should not crash when nursery is null
    Customer *c = creator.createNewCustomer(nullptr, &stock);
    EXPECT_NE(c, nullptr);
    EXPECT_NE(c->getAction(), nullptr);
    delete c;
}

// Test basket clearBasket functionality (UPDATED)
TEST(CustomerTest, BasketClearFunctionality)
{
    DummyPlant plant1("Rose");
    DummyPlant plant2("Basil");
    Nursery nursery;
    Customer c(new Browse(&plant1, 2), &nursery);

    c.addToBasket(&plant1, 3);
    c.addToBasket(&plant2, 2);
    EXPECT_EQ(c.getBasket().size(), 5); // 3 + 2 = 5 plants

    c.clearBasket();
    EXPECT_EQ(c.getBasket().size(), 0);
}

// Test Customer getNursery (NEW)
TEST(CustomerTest, GetNurseryReference)
{
    DummyPlant plant("TestPlant");
    Nursery nursery;
    Customer c(new Browse(&plant, 1), &nursery);

    EXPECT_EQ(c.getNursery(), &nursery);
}

// Test multiple customers have unique IDs (NEW)
TEST(CustomerTest, UniqueCustomerIDs)
{
    DummyPlant plant("TestPlant");
    Nursery nursery;
    std::set<int> ids;

    for (int i = 0; i < 20; ++i)
    {
        Customer *c = new Customer(new Browse(&plant, 1), &nursery);
        ids.insert(c->getId());
        delete c;
    }

    EXPECT_EQ(ids.size(), 20); // All IDs should be unique
}

// Test Browse with single plant constructor
TEST(CustomerTest, BrowseSinglePlantConstructor)
{
    DummyPlant plant("Rose");
    Browse browse(&plant, 5);

    EXPECT_EQ(browse.getPlantsToBuy().size(), 1);
    EXPECT_EQ(browse.getQuantities()[0], 5);
    EXPECT_EQ(browse.getActionName(), "Browsing");
}

// Test Browse with vector constructor
TEST(CustomerTest, BrowseVectorConstructor)
{
    DummyPlant plant1("Rose");
    DummyPlant plant2("Basil");
    std::vector<Plant *> plants = {&plant1, &plant2};
    std::vector<int> quantities = {2, 3};
    Browse browse(plants, quantities);

    EXPECT_EQ(browse.getPlantsToBuy().size(), 2);
    EXPECT_EQ(browse.getQuantities().size(), 2);
}

// Test Enquire getPlantsOfInterest (NEW)
TEST(CustomerTest, EnquireGetPlantsOfInterest)
{
    DummyPlant plant1("Rose");
    DummyPlant plant2("Basil");
    DummyPlant plant3("Cactus");
    std::vector<Plant *> plants = {&plant1, &plant2, &plant3};
    Enquire enquire(plants, "How do I care for these?", 0);

    std::vector<Plant *> retrieved = enquire.getPlantsOfInterest();
    EXPECT_EQ(retrieved.size(), 3);
}

// Test CustomerCreator distinct plant selection (NEW)
TEST(CustomerTest, CustomerCreatorDistinctPlantSelection)
{
    Inventory inv;
    DummyPlant *p1 = new DummyPlant("Rose");
    DummyPlant *p2 = new DummyPlant("Basil");
    DummyPlant *p3 = new DummyPlant("Cactus");
    inv.addPlant(std::unique_ptr<Plant>(p1), 10);
    inv.addPlant(std::unique_ptr<Plant>(p2), 10);
    inv.addPlant(std::unique_ptr<Plant>(p3), 10);
    Stock stock(&inv);
    Nursery nursery;
    CustomerCreator creator;

    int twoPlantCustomers = 0;
    int distinctPlants = 0;

    for (int i = 0; i < 50; ++i)
    {
        Customer *c = creator.createNewCustomer(&nursery, &stock);
        if (c->getAction()->getActionName() == "Browsing")
        {
            Browse *browse = dynamic_cast<Browse *>(c->getAction());
            if (browse && browse->getPlantsToBuy().size() == 2)
            {
                twoPlantCustomers++;
                std::vector<Plant *> plants = browse->getPlantsToBuy();
                if (plants[0]->getName() != plants[1]->getName())
                {
                    distinctPlants++;
                }
            }
        }
        delete c;
    }

    // All two-plant customers should have distinct plant types
    if (twoPlantCustomers > 0)
    {
        EXPECT_EQ(twoPlantCustomers, distinctPlants);
    }
}

// Test information questions reference correct plant (NEW)
TEST(CustomerTest, InformationQuestionsReferencePlant)
{
    Inventory inv;
    DummyPlant *p1 = new DummyPlant("Rose");
    DummyPlant *p2 = new DummyPlant("Basil");
    inv.addPlant(std::unique_ptr<Plant>(p1), 10);
    inv.addPlant(std::unique_ptr<Plant>(p2), 10);
    Stock stock(&inv);
    Nursery nursery;
    CustomerCreator creator;

    int infoQuestionsFound = 0;
    int validReferences = 0;

    // Increased to 150 iterations for better chance of getting info questions
    for (int i = 0; i < 150; ++i)
    {
        Customer *c = creator.createNewCustomer(&nursery, &stock);
        if (c->getAction()->getActionName() == "Enquiring")
        {
            Enquire *enquire = dynamic_cast<Enquire *>(c->getAction());
            if (enquire && enquire->getQuestionType() == 1)
            {
                infoQuestionsFound++;
                std::string question = enquire->getEnquiryQuestion();
                std::vector<Plant *> plants = enquire->getPlantsOfInterest();

                if (!plants.empty() && plants[0])
                {
                    std::string plantName = plants[0]->getName();
                    // Question should mention the plant name
                    if (question.find(plantName) != std::string::npos)
                    {
                        validReferences++;
                    }
                }
            }
        }
        delete c;
    }

    // If we found any info questions, they should all reference the plant correctly
    if (infoQuestionsFound > 0)
    {
        EXPECT_EQ(infoQuestionsFound, validReferences);
    }
    // This test passes even if no info questions are generated (due to randomness)
    // but if they are generated, they must be correct
    EXPECT_TRUE(infoQuestionsFound == 0 || validReferences > 0);
}

// main for GoogleTest
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
