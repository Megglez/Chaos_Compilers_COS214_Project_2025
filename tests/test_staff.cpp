#include "gtest/gtest.h"
#include "../src/Customer/Customer.h"
#include "../src/Customer/Action.h"
#include "../src/Staff/Staff.h"
#include "../src/Staff/Manager.h"
#include "../src/Staff/SalesStaff.h"
#include "../src/Staff/InfoDesk.h"
#include "../src/Staff/Cashiers.h"
#include "../src/Staff/Busy.h"
#include "../src/Staff/Available.h"
#include "../src/Staff/StaffState.h"
#include "../src/Staff/Gardener.h"

#include <queue>
#include <vector>

// Minimal stub for Action
class DummyAction : public Action
{
public:
    DummyAction(const std::string &actionName = "Enquiring", int type = 0) : Action(actionName), type_(type) {}
    void handle() override {}
    Action *getNextAction() override { return nullptr; }
    void requestStaffAssistance(Customer *customer, InfoDesk &desk) override {}
    int getQuestionType() const { return type_; }

private:
    int type_;
};

class DummyCustomer2 : public Customer
{
public:
    DummyCustomer2(const std::string &id = "C1", Action *action = nullptr) : Customer(action, nullptr) {}
};

// Minimal stubs for Staff and Customer for InfoDesk tests
class DummyStaff : public Staff
{
public:
    DummyStaff(const std::string &name = "Test", const std::string &id = "1") : Staff(name, id, nullptr)
    {
        role = "SalesStaff"; // Set role directly
    }
    void performDuty() override {}
    bool canHandleEnquiry() override { return true; }
    void setRole() override
    {
        role = "SalesStaff";
    }
};

class DummyCustomer : public Customer
{
public:
    DummyCustomer() : Customer(nullptr, nullptr) {}
};

TEST(InfoDeskTest, NotifyCallsStaffGetID)
{
    InfoDesk desk;
    DummyStaff staff;
    testing::internal::CaptureStdout();
    desk.notify(&staff);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Customer needs your assistance"), std::string::npos);
}

TEST(InfoDeskTest, HandleCustomerNull)
{
    InfoDesk desk;
    testing::internal::CaptureStdout();
    desk.handleCustomer(nullptr);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Customer is null"), std::string::npos);
}

TEST(InfoDeskTest, HandleCustomerNotEnquiring)
{
    InfoDesk desk;
    DummyAction *notEnquiring = new DummyAction("NotEnquiring", 0);
    DummyCustomer2 cust("C2", notEnquiring);
    testing::internal::CaptureStdout();
    desk.handleCustomer(&cust);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Customer is not in Enquiring state"), std::string::npos);
}

TEST(InfoDeskTest, FindQnAStaffReturnsNullIfNone)
{
    InfoDesk desk;
    DummyCustomer2 cust;
    Staff *result = desk.findQnAStaff(&cust);
    EXPECT_EQ(result, nullptr);
}

TEST(InfoDeskTest, FindInventoryStaffReturnsNullIfNone)
{
    InfoDesk desk;
    DummyCustomer2 cust;
    Staff *result = desk.findInventoryStaff(&cust);
    EXPECT_EQ(result, nullptr);
}

TEST(InfoDeskTest, FindAvailableStaffReturnsFalseIfNone)
{
    InfoDesk desk;
    DummyCustomer2 cust;
    bool found = desk.FindAvailableStaff(&cust);
    EXPECT_FALSE(found);
}

TEST(InfoDeskTest, AssignStaffToCustomerNull)
{
    InfoDesk desk;
    testing::internal::CaptureStdout();
    desk.AssignStaffToCustomer(nullptr);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Customer is Null"), std::string::npos);
}

TEST(InfoDeskTest, ProcessWaitingCustomersNoCustomers)
{
    InfoDesk desk;
    testing::internal::CaptureStdout();
    desk.processWaitingCustomers();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("No customers waiting in queue"), std::string::npos);
}

// Example: Test Staff base class
TEST(StaffTest, SetAndGetRole)
{
    class DummyStaff : public Staff
    {
    public:
        DummyStaff() : Staff("TestName", "TestID", nullptr) {}
        void performDuty() override {}
        bool canHandleEnquiry() override { return false; }
        void setRole() override { role = "TestRole"; }
    };
    DummyStaff staff;
    staff.setRole();
    EXPECT_EQ(staff.getStaffType(), "TestRole");
}

// Example: Test Manager
TEST(ManagerTest, RoleIsManager)
{
    Manager manager("Alice", "001", nullptr, nullptr);
    manager.setRole();
    EXPECT_EQ(manager.getStaffType(), "Manager");
}

// Example: Test SalesStaff
TEST(SalesStaffTest, RoleIsSalesStaff)
{
    std::string name = "TestSales";
    std::string id = "S001";
    SalesStaff sales(name, id, nullptr);
    sales.setRole();
    EXPECT_EQ(sales.getStaffType(), "SalesStaff");
}

// Add more tests for InfoDesk, Cashiers, Busy, Available, StaffState, Gardener as needed

// Example: Test InfoDesk creation
TEST(InfoDeskTest, CanCreateInfoDesk)
{
    InfoDesk info;
    EXPECT_TRUE(true); // Just checks construction for now
}

// Example: Test Cashiers creation
TEST(CashiersTest, CanCreateCashiers)
{
    std::string name = "TestCashier";
    std::string id = "C001";
    Cashiers cashier(name, id, nullptr);
    EXPECT_TRUE(true); // Just checks construction for now
}

// Example: Test Busy creation
TEST(BusyTest, CanCreateBusy)
{
    Busy busy;
    EXPECT_TRUE(true); // Just checks construction for now
}

// Example: Test Available creation
TEST(AvailableTest, CanCreateAvailable)
{
    Available available;
    EXPECT_TRUE(true); // Just checks construction for now
}

// Example: Test StaffState creation
TEST(StaffStateTest, CanCreateStaffState)
{
    StaffState *state = nullptr;
    EXPECT_EQ(state, nullptr); // Just a placeholder
}

// Example: Test Gardener creation
TEST(GardenerTest, CanCreateGardener)
{
    std::string name = "TestGardener";
    std::string id = "G001";
    Gardener gardener(name, id, nullptr);
    EXPECT_TRUE(true); // Just checks construction for now
}

// InfoDesk tests
TEST(InfoDeskTest, ConstructionAndDestruction)
{
    InfoDesk *desk = new InfoDesk();
    EXPECT_NE(desk, nullptr);
    delete desk;
}

TEST(InfoDeskTest, AddAndRemoveStaff)
{
    InfoDesk desk;
    DummyStaff *staff = new DummyStaff("Sally", "2");
    EXPECT_TRUE(desk.addStaff(staff));
    EXPECT_FALSE(desk.addStaff(staff)); // Already added
    EXPECT_TRUE(desk.removeStaff(staff));
    EXPECT_FALSE(desk.removeStaff(staff)); // Already removed
    delete staff;
}

TEST(InfoDeskTest, GetAllStaff)
{
    InfoDesk desk;
    DummyStaff *staff1 = new DummyStaff("A", "1");
    DummyStaff *staff2 = new DummyStaff("B", "2");
    desk.addStaff(staff1);
    desk.addStaff(staff2);
    auto all = desk.getAllStaff();
    EXPECT_EQ(all.size(), 2);
    delete staff1;
    delete staff2;
}

TEST(InfoDeskTest, NotifyStaffAvailable)
{
    InfoDesk desk;
    DummyStaff staff;
    desk.notifyStaffAvailable(&staff);
    desk.notifyStaffAvailable(nullptr); // Should handle null
}

TEST(InfoDeskTest, GetInfodeskReturnsSelf)
{
    InfoDesk desk;
    EXPECT_EQ(desk.getInfodesk(), &desk);
}

TEST(InfoDeskTest, BuildAndClearChain)
{
    InfoDesk desk;
    DummyStaff *staff1 = new DummyStaff("A", "1");
    desk.addStaff(staff1);
    desk.buildChain();
    desk.clearChain();
    delete staff1;
}

// Skipping test for private method findAvailableStaffThroughChain
// TEST(InfoDeskTest, FindAvailableStaffThroughChainEmpty) {
//     InfoDesk desk;
//     EXPECT_EQ(desk.findAvailableStaffThroughChain(), nullptr);
// }

TEST(InfoDeskTest, GetStaffByType)
{
    InfoDesk desk;
    DummyStaff *staff1 = new DummyStaff("A", "1");
    desk.addStaff(staff1);
    auto result = desk.getStaffByType("SalesStaff");
    EXPECT_EQ(result.size(), 1);
    delete staff1;
}

// The following tests require more complex stubs/mocks for Customer and Action
// and are provided as structure/examples for further expansion.

// TEST(InfoDeskTest, HandleCustomerNull) { ... }
// TEST(InfoDeskTest, HandleCustomerNotEnquiring) { ... }
// TEST(InfoDeskTest, HandleCustomerAssignsStaff) { ... }
// TEST(InfoDeskTest, ProcessWaitingCustomers) { ... }
