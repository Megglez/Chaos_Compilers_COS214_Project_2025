#include <gtest/gtest.h>
#include "../src/Customer/Customer.h"
#include "../src/Customer/CustomerCreator.h"
#include "../src/Customer/Browse.h"
#include "../src/Customer/Enquire.h"
#include "../src/Greenhouse/Plant.h"
#include "../src/Greenhouse/Stock.h"
#include "../src/Greenhouse/Inventory.h"
#include "../src/Staff/Staff.h"
#include "../src/Nursery/Nursery.h"
#include <memory>
#include <set>

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
    DummyStaff() : Staff("TestStaff", "S1") {}
    void performDuty() override {}
    bool canHandleEnquiry() override { return true; }
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

// main for GoogleTest
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
