#include <gtest/gtest.h>
#include <QCoreApplication>
#include "../src/Nursery/Nursery.h"
#include "../src/Customer/Customer.h"
#include "../src/Customer/Browse.h"
#include "../src/Staff/InfoDesk.h"
#include "../src/Staff/Staff.h"
#include "../src/Staff/SalesStaff.h"
#include "../src/Staff/Cashiers.h"
#include "../src/Staff/Manager.h"
#include "../src/Staff/Gardener.h"
#include "../src/Greenhouse/Inventory.h"
#include "../src/Greenhouse/Stock.h"
#include "../src/Greenhouse/Spring.h"

/**
 * @brief Test fixture for Nursery tests
 *
 * Sets up a QCoreApplication for Qt-based tests and provides
 * common setup/teardown for Nursery tests.
 */
class NurseryTest : public ::testing::Test
{
protected:
    static QCoreApplication *app;
    Nursery *nursery;

    static void SetUpTestSuite()
    {
        // Initialize QCoreApplication once for all tests
        if (!QCoreApplication::instance())
        {
            int argc = 0;
            char **argv = nullptr;
            app = new QCoreApplication(argc, argv);
        }
    }

    void SetUp() override
    {
        // Create a new Nursery for each test
        nursery = new Nursery();
    }

    void TearDown() override
    {
        // Clean up after each test
        delete nursery;
        nursery = nullptr;
    }

    static void TearDownTestSuite()
    {
        // Clean up QCoreApplication after all tests
        delete app;
        app = nullptr;
    }
};

QCoreApplication *NurseryTest::app = nullptr;

// ==================== Nursery Initialization Tests ====================

TEST_F(NurseryTest, NurseryInitialization)
{
    ASSERT_NE(nursery, nullptr) << "Nursery should be created successfully";
}

TEST_F(NurseryTest, InventoryInitialization)
{
    ASSERT_NE(nursery->getInventory(), nullptr) << "Inventory should be initialized";
}

TEST_F(NurseryTest, StockInitialization)
{
    ASSERT_NE(nursery->getStock(), nullptr) << "Stock should be initialized";
}

TEST_F(NurseryTest, InfoDeskInitialization)
{
    ASSERT_NE(nursery->getInfoDesk(), nullptr) << "InfoDesk should be initialized";
}

// ==================== Customer Management Tests ====================

TEST_F(NurseryTest, InitialCustomerCount)
{
    EXPECT_EQ(nursery->getActiveCustomers().size(), 0)
        << "Initial customer count should be 0";
}

TEST_F(NurseryTest, AddCustomer)
{
    Action *browseAction = new Browse(nullptr, 1); // Pass nullptr for plant in test
    Customer *customer = new Customer(browseAction, nursery);
    nursery->addCustomer(customer);

    EXPECT_EQ(nursery->getActiveCustomers().size(), 1)
        << "Customer count should be 1 after adding";
}

TEST_F(NurseryTest, AddMultipleCustomers)
{
    for (int i = 0; i < 5; i++)
    {
        Action *browseAction = new Browse(nullptr, 1); // Pass nullptr for plant in test
        Customer *customer = new Customer(browseAction, nursery);
        nursery->addCustomer(customer);
    }

    EXPECT_EQ(nursery->getActiveCustomers().size(), 5)
        << "Should have 5 customers after adding 5";
}

TEST_F(NurseryTest, RemoveCustomer)
{
    Action *browseAction = new Browse(nullptr, 1); // Pass nullptr for plant in test
    Customer *customer = new Customer(browseAction, nursery);
    nursery->addCustomer(customer);
    EXPECT_EQ(nursery->getActiveCustomers().size(), 1);

    nursery->removeCustomer(customer);
    EXPECT_EQ(nursery->getActiveCustomers().size(), 0)
        << "Customer count should be 0 after removal";
}

TEST_F(NurseryTest, CustomerCapacityLimit)
{
    // Add customers up to the limit (assuming limit is 20)
    for (int i = 0; i < 25; i++)
    {
        nursery->handleCustomerArrivalSignal();
    }

    // Should not exceed the limit
    EXPECT_LE(nursery->getActiveCustomers().size(), 20)
        << "Customer count should not exceed capacity limit";
}

TEST_F(NurseryTest, AddNullCustomer)
{
    nursery->addCustomer(nullptr);
    EXPECT_EQ(nursery->getActiveCustomers().size(), 0)
        << "Null customer should not be added";
}

// ==================== Inventory Tests ====================

TEST_F(NurseryTest, InventoryGetCatalogue)
{
    ASSERT_NO_THROW({
        nursery->getInventory()->getCatalogue();
    }) << "getCatalogue should not throw";
}

TEST_F(NurseryTest, InventoryStaffAttachment)
{
    std::string staffName = "TestStaff";
    std::string staffId = "S001";
    SalesStaff *staff = new SalesStaff(staffName, staffId, nullptr);

    ASSERT_NO_THROW({
        nursery->getInventory()->attach(staff);
    }) << "Attaching staff should not throw";

    delete staff;
}

// ==================== Stock Tests ====================

TEST_F(NurseryTest, StockPrintCatalogue)
{
    ASSERT_NO_THROW({
        nursery->getStock()->printStock();
    }) << "printStock should not throw";
}

TEST_F(NurseryTest, StockGetTotalPlants)
{
    int totalPlants = nursery->getStock()->getTotalPlants();
    EXPECT_GE(totalPlants, 0) << "Total plants should be non-negative";
}

// ==================== Season Tests ====================

TEST_F(NurseryTest, SeasonGetCurrent)
{
    std::string season = nursery->getCurrentSeason()->getSeason();
    EXPECT_FALSE(season.empty()) << "Season name should not be empty";
}

TEST_F(NurseryTest, SeasonHandleChange)
{
    ASSERT_NO_THROW({
        nursery->getCurrentSeason()->handleChange(nursery);
    }) << "handleChange should not throw";
}

// ==================== InfoDesk Tests ====================

TEST_F(NurseryTest, InfoDeskBuildChain)
{
    ASSERT_NO_THROW({
        nursery->getInfoDesk()->buildChain();
    }) << "buildChain should not throw";
}

TEST_F(NurseryTest, InfoDeskHandleNullCustomer)
{
    ASSERT_NO_THROW({
        nursery->getInfoDesk()->handleCustomer(nullptr);
    }) << "Handling null customer should not crash";
}

TEST_F(NurseryTest, InfoDeskAddStaff)
{
    std::string staffName = "TestSales";
    std::string staffId = "S002";
    SalesStaff *staff = new SalesStaff(staffName, staffId, nullptr);

    bool result = nursery->getInfoDesk()->addStaff(staff);
    EXPECT_TRUE(result) << "Adding staff should succeed";

    // Clean up
    nursery->getInfoDesk()->removeStaff(staff);
    delete staff;
}

TEST_F(NurseryTest, InfoDeskRemoveStaff)
{
    std::string staffName = "TestManager";
    std::string staffId = "M001";
    Manager *staff = new Manager(staffName, staffId, nullptr, nullptr);

    nursery->getInfoDesk()->addStaff(staff);
    bool result = nursery->getInfoDesk()->removeStaff(staff);

    EXPECT_TRUE(result) << "Removing staff should succeed";
    delete staff;
}

TEST_F(NurseryTest, InfoDeskAddNullStaff)
{
    bool result = nursery->getInfoDesk()->addStaff(nullptr);
    EXPECT_FALSE(result) << "Adding null staff should fail";
}

// ==================== Plant Factory Tests ====================

// Factories are no longer part of Nursery - tests removed

// ==================== Integration Tests ====================

TEST_F(NurseryTest, CustomerArrivalSignal)
{
    size_t initialCount = nursery->getActiveCustomers().size();

    nursery->handleCustomerArrivalSignal();

    EXPECT_GT(nursery->getActiveCustomers().size(), initialCount)
        << "Customer count should increase after arrival signal";
}

TEST_F(NurseryTest, MultipleCustomerArrivals)
{
    for (int i = 0; i < 3; i++)
    {
        nursery->handleCustomerArrivalSignal();
    }

    EXPECT_EQ(nursery->getActiveCustomers().size(), 3)
        << "Should have 3 customers after 3 arrival signals";
}

TEST_F(NurseryTest, CustomerStaffAssignment)
{
    // Add staff to InfoDesk
    std::string staffName = "TestSales";
    std::string staffId = "S003";
    SalesStaff *staff = new SalesStaff(staffName, staffId, nullptr);
    nursery->getInfoDesk()->addStaff(staff);

    // Create and handle customer
    nursery->handleCustomerArrivalSignal();

    EXPECT_EQ(nursery->getActiveCustomers().size(), 1)
        << "Customer should be created and added";

    // Clean up
    nursery->getInfoDesk()->removeStaff(staff);
    delete staff;
}

TEST_F(NurseryTest, StaffChainBuilding)
{
    // Add different types of staff
    std::string name1 = "Sales1", id1 = "S001";
    std::string name2 = "Manager1", id2 = "M001";
    std::string name3 = "Gardener1", id3 = "G001";

    SalesStaff *sales = new SalesStaff(name1, id1, nullptr);
    Manager *manager = new Manager(name2, id2, nullptr, nullptr);
    Gardener *gardener = new Gardener(name3, id3, nullptr);

    nursery->getInfoDesk()->addStaff(sales);
    nursery->getInfoDesk()->addStaff(manager);
    nursery->getInfoDesk()->addStaff(gardener);

    ASSERT_NO_THROW({
        nursery->getInfoDesk()->buildChain();
    }) << "Building chain with multiple staff should not throw";

    // Clean up
    nursery->getInfoDesk()->removeStaff(sales);
    nursery->getInfoDesk()->removeStaff(manager);
    nursery->getInfoDesk()->removeStaff(gardener);
    delete sales;
    delete manager;
    delete gardener;
}

// ==================== Edge Case Tests ====================

TEST_F(NurseryTest, RemoveNonExistentCustomer)
{
    Action *browseAction = new Browse(nullptr, 1); // Pass nullptr for plant in test
    Customer *customer = new Customer(browseAction, nursery);
    // Don't add the customer

    ASSERT_NO_THROW({
        nursery->removeCustomer(customer);
    }) << "Removing non-existent customer should not crash";

    delete customer; // Customer destructor will delete the action
    // Do NOT delete browseAction - it's owned by customer and already deleted
}

TEST_F(NurseryTest, GettersReturnValidPointers)
{
    EXPECT_NE(nursery->getStock(), nullptr);
    EXPECT_NE(nursery->getInventory(), nullptr);
    EXPECT_NE(nursery->getInfoDesk(), nullptr);
    EXPECT_NE(nursery->getCurrentSeason(), nullptr);
}

TEST_F(NurseryTest, ActiveCustomersVectorIsValid)
{
    const auto &customers = nursery->getActiveCustomers();
    EXPECT_NO_THROW({
        size_t size = customers.size();
        (void)size; // Suppress unused variable warning
    }) << "Getting active customers should not throw";
}

// ==================== Memory Management Tests ====================

TEST_F(NurseryTest, NurseryDeletionCleansUp)
{
    Nursery *tempNursery = new Nursery();

    // Add some customers
    for (int i = 0; i < 3; i++)
    {
        tempNursery->handleCustomerArrivalSignal();
    }

    ASSERT_NO_THROW({
        delete tempNursery;
    }) << "Nursery deletion should clean up all resources without crashing";
}

TEST_F(NurseryTest, MultipleNurseryInstances)
{
    Nursery *nursery1 = new Nursery();
    Nursery *nursery2 = new Nursery();

    EXPECT_NE(nursery1, nursery2) << "Different nursery instances should be distinct";
    EXPECT_NE(nursery1->getInventory(), nursery2->getInventory())
        << "Each nursery should have its own inventory";

    delete nursery1;
    delete nursery2;
}