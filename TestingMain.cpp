#include "src/Greenhouse/Planter.h"
#include "src/Greenhouse/HerbPlanter.h"
#include "src/Greenhouse/SucculentPlanter.h"
#include "src/Greenhouse/TreePlanter.h"
#include "src/Greenhouse/FlowerPlanter.h"
#include "src/Greenhouse/Plant.h"
#include "src/Greenhouse/TreePlant.h"
#include "src/Greenhouse/SucculentPlant.h"
#include "src/Greenhouse/FlowerPlant.h"
#include "src/Greenhouse/HerbPlant.h"
#include "src/Greenhouse/Stock.h"
#include "src/Greenhouse/Inventory.h"
#include "src/Greenhouse/Seasons.h"
#include "src/Greenhouse/AutumnCommand.h"
#include "src/Greenhouse/SummerCommand.h"
#include "src/Greenhouse/WinterCommand.h"
#include "src/Greenhouse/SpringCommand.h"
#include "src/Greenhouse/StateCommand.h"
#include "src/Greenhouse/PlantDecorator.h"
#include "src/Greenhouse/GiftWrap.h"
#include "src/Greenhouse/Pot.h"
#include "src/Greenhouse/SpecialArrangement.h"
#include "src/Customer/CustomerCreator.h"
#include "src/Customer/Customer.h"
#include "src/Customer/Browse.h"
#include "src/Customer/Enquire.h"

#include <memory>
#include <iostream>
#include <vector>

// Function declarations
void testGreenhouse();
void testCustomer();

int main()
{
    testGreenhouse();
    testCustomer();

    return 0;
}

void testGreenhouse()
{

    Planter *FlowerP = new FlowerPlanter();
    Planter *HerbP = new HerbPlanter();
    Planter *SuccP = new SucculentPlanter();
    Planter *TreeP = new TreePlanter();
    Planter *FlowerW = new FlowerPlanter(true);

    /*Plant* Flower = FlowerP->planterMethod("Rose");
    Plant* Herb = HerbP->planterMethod("Basil");
    Plant* Succ = SuccP->planterMethod("Cactus");
    Plant* Tree = TreeP->planterMethod("Willow");

    std::cout << Flower->getName() << std::endl;
    std::cout << Herb->getName() <<std::endl;
    std::cout << Succ->getName()<< std::endl;
    std::cout <<Tree->getName() <<std::endl;*/

    std::unique_ptr<Plant> Flower(FlowerP->planterMethod("Rose"));
    std::unique_ptr<Plant> Herb(HerbP->planterMethod("Basil"));
    std::unique_ptr<Plant> Succ(SuccP->planterMethod("Cactus"));
    std::unique_ptr<Plant> Tree(TreeP->planterMethod("Willow"));
    std::unique_ptr<Plant> FlowerWinter(FlowerW->planterMethod("Snowdrops"));

    Plant *Flower2 = FlowerP->planterMethod("Rose Bush");
    GiftWrap *gift = new GiftWrap(Flower2);
    // Pot* pot = new Pot(gift);
    gift->package();
    // pot->package();
    delete gift;

    // testing the different strategies
    cout << "\n=====Plants Help Strategies=====" << endl;
    std::unique_ptr<Plant> Flower1(FlowerP->planterMethod("Agapanthus"));
    std::unique_ptr<Plant> Herb1(HerbP->planterMethod("Thym"));
    std::unique_ptr<Plant> Succ1(SuccP->planterMethod("Aloe Vera"));
    std::unique_ptr<Plant> Tree1(TreeP->planterMethod("Acaccia"));

    Plant *Flower3 = FlowerP->planterMethod("Thym");
    Plant *Herb4 = HerbP->planterMethod("Agapanthus Bush");
    Plant *Succ5 = SuccP->planterMethod("Aloe Vera");
    Plant *Tree6 = TreeP->planterMethod("Acaccia");

    Flower3->helpPlant();
    Herb4->helpPlant();
    Succ5->helpPlant();
    Tree6->helpPlant();
    Flower3->helpPlant();
    Flower3->helpPlant();

    Inventory *test_inv = new Inventory();
    // test_inv->attach(staff1);
    Stock *test_st = new Stock(test_inv);
    test_st->Add(std::move(Flower), 30);
    test_st->Add(std::move(Herb), 50);
    test_st->Add(std::move(Succ), 60);
    test_st->Add(std::move(FlowerWinter), 60);
    test_st->Remove(nullptr);
    // test_st->Remove(std::unique_ptr<Plant>(FlowerP->planterMethod("Rose")));
    test_st->printStock();
    test_inv->getCatalogue();
    test_inv->getCatalogue();

    StateCommand *command = new SpringCommand(test_inv);
    command->execute();
    test_inv->getCatalogue();

    StateCommand *command2 = new SummerCommand(test_inv);
    command2->execute();
    test_inv->getCatalogue();

    StateCommand *command3 = new AutumnCommand(test_inv);
    command3->execute();
    test_inv->getCatalogue();

    StateCommand *command4 = new WinterCommand(test_inv);
    command4->execute();
    test_inv->getCatalogue();
    std::cout << test_st->getTotalPlants();
    const auto &inv = test_inv->getInventory();
    for (const auto &entry : inv)
    {
        std::cout << "- " << entry.second.first.get()->getState()->getStageName();
    }

    delete test_st;
    delete test_inv;
    delete FlowerP;
    delete SuccP;
    delete HerbP;
    delete TreeP;
    // delete pot;
    delete FlowerW;
    delete Flower3;
    delete Herb4;
    delete Succ5;
    delete Tree6;

    /*delete command;
    delete command2;
    delete command3;
    delete command4;*/
}

void testCustomer()
{
    std::cout << "\n=====Testing Customer Creation=====" << std::endl;

    // Create test inventory and stock for customer creation
    Inventory *testInventory = new Inventory();
    Stock *testStock = new Stock(testInventory);

    // Add some plants to the stock for testing
    Planter *flowerPlanter = new FlowerPlanter();
    Planter *herbPlanter = new HerbPlanter();

    std::unique_ptr<Plant> rose(flowerPlanter->planterMethod("Rose"));
    std::unique_ptr<Plant> basil(herbPlanter->planterMethod("Basil"));

    testStock->Add(std::move(rose), 10);
    testStock->Add(std::move(basil), 15);

    std::cout << "Created test stock with plants for customer testing" << std::endl;
    testStock->printStock();

    // Create CustomerCreator
    CustomerCreator *customerFactory = new CustomerCreator();

    // Test creating multiple customers to see random behavior
    std::cout << "\n=====Creating 10 Test Customers=====" << std::endl;
    std::vector<Customer *> testCustomers;

    int browseCount = 0;
    int enquireCount = 0;

    for (int i = 0; i < 10; i++)
    {
        Customer *newCustomer = customerFactory->createNewCustomer(nullptr, testStock);
        testCustomers.push_back(newCustomer);

        std::cout << "\nCustomer " << (i + 1) << " (ID: " << newCustomer->getId() << "):" << std::endl;
        std::cout << "Action: " << newCustomer->getAction()->getActionName() << std::endl;

        // Check if it's Browse or Enquire and count them
        if (newCustomer->getAction()->getActionName() == "Browsing")
        {
            browseCount++;
            std::cout << "Customer is browsing plants" << std::endl;
        }
        else if (newCustomer->getAction()->getActionName() == "Enquiring")
        {
            enquireCount++;
            // Try to cast to Enquire to get the question
            Enquire *enquireAction = dynamic_cast<Enquire *>(newCustomer->getAction());
            if (enquireAction)
            {
                std::cout << "Customer's enquiry question: " << enquireAction->getEnquiryQuestion() << std::endl;
            }
        }

        // Test the customer's handle method
        newCustomer->getAction()->handle();
    }

    // Display statistics
    std::cout << "\n=====Customer Creation Statistics=====" << std::endl;
    std::cout << "Total customers created: " << testCustomers.size() << std::endl;
    std::cout << "Browse customers: " << browseCount << std::endl;
    std::cout << "Enquire customers: " << enquireCount << std::endl;
    std::cout << "Browse percentage: " << (browseCount * 100.0 / testCustomers.size()) << "%" << std::endl;
    std::cout << "Enquire percentage: " << (enquireCount * 100.0 / testCustomers.size()) << "%" << std::endl;

    // Test customer creation with empty stock
    std::cout << "\n=====Testing Customer Creation with Empty Stock=====" << std::endl;
    Inventory *emptyInventory = new Inventory();
    Stock *emptyStock = new Stock(emptyInventory);

    Customer *customerWithEmptyStock = customerFactory->createNewCustomer(nullptr, emptyStock);
    std::cout << "Customer created with empty stock - ID: " << customerWithEmptyStock->getId() << std::endl;
    std::cout << "Action: " << customerWithEmptyStock->getAction()->getActionName() << std::endl;
    customerWithEmptyStock->getAction()->handle();

    // Clean up
    for (Customer *customer : testCustomers)
    {
        delete customer;
    }
    delete customerWithEmptyStock;
    delete customerFactory;
    delete testStock;
    delete testInventory;
    delete emptyStock;
    delete emptyInventory;
    delete flowerPlanter;
    delete herbPlanter;

    std::cout << "\nCustomer testing completed successfully!" << std::endl;
}