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
#include "src/Nursery/Nursery.h"

#include <memory>
#include <iostream>
#include <vector>
#include <map>

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
    
    Plant* Flower2 = FlowerP->planterMethod("Rose Bush");
    GiftWrap* gift = new GiftWrap(Flower2);
    Pot* pot = new Pot(gift);
    gift->package();
    pot->package();
    delete pot;

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

    Nursery nursery;

    for (int i = 0; i < 10; i++) {
        std::cout << "\n--- Cycle " << (i + 1) << " ---" << std::endl;
        nursery.handleChange();
        
        // You can add some debugging output here
        // For example, check what season it is now:
        Seasons* currentSeason = nursery.getCurrentSeason();
        if (currentSeason) {
            std::cout << "Season changed!" << std::endl;
        }
    }

    /*StateCommand* command = new SpringCommand(test_inv);
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
    }*/
    
    
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
}

/*void testCustomer()
{
    std::cout << "\n=====Testing Customer Creation=====" << std::endl;

    // Create test inventory and stock for customer creation
    Inventory *testInventory = new Inventory();
    Stock *testStock = new Stock(testInventory);

    // Add multiple plants to the stock for testing random index selection
    Planter *flowerPlanter = new FlowerPlanter();
    Planter *herbPlanter = new HerbPlanter();
    Planter *succulentPlanter = new SucculentPlanter();
    Planter *treePlanter = new TreePlanter();

    std::unique_ptr<Plant> rose(flowerPlanter->planterMethod("Rose"));
    std::unique_ptr<Plant> basil(herbPlanter->planterMethod("Basil"));
    std::unique_ptr<Plant> cactus(succulentPlanter->planterMethod("Cactus"));
    std::unique_ptr<Plant> oak(treePlanter->planterMethod("Oak"));

    testStock->Add(std::move(rose), 10);
    testStock->Add(std::move(basil), 15);
    testStock->Add(std::move(cactus), 20);
    testStock->Add(std::move(oak), 8);

    std::cout << "Created test stock with plants for customer testing" << std::endl;
    std::cout << "Stock contains " << testStock->getStockListSize() << " plant types (indices 0-"
              << (testStock->getStockListSize() - 1) << "):" << std::endl;

    // Display stock with indices
    for (size_t idx = 0; idx < testStock->getStockListSize(); idx++)
    {
        Plant *p = testStock->getPlantByIndex(idx);
        if (p)
        {
            std::cout << "  Index " << idx << ": " << p->getName() << " (" << p->getType() << ")" << std::endl;
        }
    }

    std::cout << "Note: Customers are randomly assigned either 1 or 2 plants" << std::endl;
    std::cout << "Plant selection uses random indices from 0 to " << (testStock->getStockListSize() - 1) << std::endl;
    std::cout << "Customers wanting 2 plants will get 2 DIFFERENT types (e.g., Rose AND Basil)" << std::endl;

    // Create CustomerCreator
    CustomerCreator *customerFactory = new CustomerCreator();

    // Test creating multiple customers to see random behavior
    std::cout << "\n=====Creating 10 Test Customers=====" << std::endl;
    std::cout << "(Random integer 0-1 determines if customer wants 1 or 2 plants)" << std::endl;
    std::cout << "(Random indices 0-" << (testStock->getStockListSize() - 1) << " select which plants)" << std::endl;
    std::cout << "(If 2 plants: must be different types, not same type)" << std::endl;
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

            // Show which distinct plants they want
            Browse *browseAction = dynamic_cast<Browse *>(newCustomer->getAction());
            if (browseAction)
            {
                std::vector<Plant *> plants = browseAction->getPlantsToBuy();
                std::vector<int> quantities = browseAction->getQuantities();

                std::cout << "  Wants " << plants.size() << " distinct plant type(s): ";
                for (size_t j = 0; j < plants.size(); j++)
                {
                    if (plants[j])
                    {
                        std::cout << plants[j]->getName() << " (qty: " << quantities[j] << ")";
                        if (j < plants.size() - 1)
                            std::cout << ", ";
                    }
                }
                std::cout << std::endl;
            }
        }
        else if (newCustomer->getAction()->getActionName() == "Enquiring")
        {
            enquireCount++;
            // Try to cast to Enquire to get the question
            Enquire *enquireAction = dynamic_cast<Enquire *>(newCustomer->getAction());
            if (enquireAction)
            {
                std::cout << "Customer's enquiry question: " << enquireAction->getEnquiryQuestion() << std::endl;

                // Show which plants they're interested in
                std::vector<Plant *> plants = enquireAction->getPlantsOfInterest();
                if (!plants.empty())
                {
                    std::cout << "  Interested in " << plants.size() << " distinct plant type(s): ";
                    for (size_t j = 0; j < plants.size(); j++)
                    {
                        if (plants[j])
                        {
                            std::cout << plants[j]->getName();
                            if (j < plants.size() - 1)
                                std::cout << ", ";
                        }
                    }
                    std::cout << std::endl;
                }
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

    // Verify distinct plant selection
    std::cout << "\n=====Verifying Distinct Plant Types=====" << std::endl;
    int singlePlantCount = 0;
    int doublePlantCount = 0;
    int duplicateTypeIssues = 0;

    for (Customer *customer : testCustomers)
    {
        if (customer->getAction()->getActionName() == "Browsing")
        {
            Browse *browseAction = dynamic_cast<Browse *>(customer->getAction());
            if (browseAction)
            {
                std::vector<Plant *> plants = browseAction->getPlantsToBuy();

                if (plants.size() == 1)
                {
                    singlePlantCount++;
                }
                else if (plants.size() == 2)
                {
                    doublePlantCount++;
                    // Check if both plants have the same name (not allowed)
                    if (plants[0] && plants[1] && plants[0]->getName() == plants[1]->getName())
                    {
                        std::cout << "  ERROR: Customer " << customer->getId()
                                  << " has duplicate plant types: " << plants[0]->getName() << std::endl;
                        duplicateTypeIssues++;
                    }
                    else if (plants[0] && plants[1])
                    {
                        std::cout << "  Customer " << customer->getId()
                                  << " wants: " << plants[0]->getName() << " and " << plants[1]->getName()
                                  << " (different types)" << std::endl;
                    }
                }
            }
        }
    }

    std::cout << "Browsing customers with 1 plant: " << singlePlantCount << std::endl;
    std::cout << "Browsing customers with 2 plants: " << doublePlantCount << std::endl;
    std::cout << "Duplicate plant type errors: " << duplicateTypeIssues << std::endl;
    std::cout << (duplicateTypeIssues == 0 ? "✓ All customers have distinct plant types!" : "✗ Some duplicate types found!") << std::endl;

    // Test explicit demonstration of customers wanting 2 different plants
    std::cout << "\n=====Demonstrating Customers Wanting 2 Different Plant Types=====" << std::endl;
    std::cout << "Creating 5 customers with 2 distinct plant types each..." << std::endl;
    std::cout << "Note: Plants must have different names (e.g., Rose and Basil, not Rose and Rose)" << std::endl;

    std::vector<Customer *> twoPlantCustomers;
    for (int i = 0; i < 5; i++)
    {
        Customer *newCustomer = customerFactory->createNewCustomer(nullptr, testStock);

        // Check if customer is in Browse state and wants 2 plants
        if (newCustomer->getAction()->getActionName() == "Browsing")
        {
            Browse *browseAction = dynamic_cast<Browse *>(newCustomer->getAction());
            if (browseAction)
            {
                std::vector<Plant *> plants = browseAction->getPlantsToBuy();
                std::vector<int> quantities = browseAction->getQuantities();

                if (plants.size() == 2 && plants[0] && plants[1])
                {
                    std::cout << "\n  Customer " << newCustomer->getId() << ":" << std::endl;
                    std::cout << "    - Wants " << quantities[0] << " of " << plants[0]->getName()
                              << " (Type: " << plants[0]->getType() << ")" << std::endl;
                    std::cout << "    - Wants " << quantities[1] << " of " << plants[1]->getName()
                              << " (Type: " << plants[1]->getType() << ")" << std::endl;

                    // Verify they are different plant types
                    if (plants[0]->getName() != plants[1]->getName())
                    {
                        std::cout << "    ✓ Plants have DISTINCT types" << std::endl;
                    }
                    else
                    {
                        std::cout << "    ✗ ERROR: Plants have SAME type: " << plants[0]->getName() << std::endl;
                    }
                    twoPlantCustomers.push_back(newCustomer);
                }
                else
                {
                    // Keep trying until we get a customer with 2 plants
                    delete newCustomer;
                    i--;
                }
            }
            else
            {
                delete newCustomer;
                i--;
            }
        }
        else
        {
            delete newCustomer;
            i--;
        }
    }

    std::cout << "\n=====Summary of Two-Plant Customers=====" << std::endl;
    std::cout << "Successfully created " << twoPlantCustomers.size() << " customers wanting 2 distinct plant types" << std::endl;

    // Demonstrate basket operations with 2 different plant types
    if (!twoPlantCustomers.empty())
    {
        std::cout << "\n=====Demonstrating Basket Operations with 2 Plant Types=====" << std::endl;
        Customer *demoCustomer = twoPlantCustomers[0];
        Browse *demoAction = dynamic_cast<Browse *>(demoCustomer->getAction());

        if (demoAction)
        {
            std::vector<Plant *> demoPlants = demoAction->getPlantsToBuy();
            std::vector<int> demoQuantities = demoAction->getQuantities();

            std::cout << "Customer " << demoCustomer->getId() << " adding plants to basket:" << std::endl;

            // Add first plant type
            if (demoPlants[0])
            {
                bool success1 = demoCustomer->addToBasket(demoPlants[0], demoQuantities[0]);
                std::cout << "  - Added " << demoQuantities[0] << " of " << demoPlants[0]->getName()
                          << ": " << (success1 ? "Success" : "Failed") << std::endl;
            }

            // Add second plant type
            if (demoPlants[1])
            {
                bool success2 = demoCustomer->addToBasket(demoPlants[1], demoQuantities[1]);
                std::cout << "  - Added " << demoQuantities[1] << " of " << demoPlants[1]->getName()
                          << ": " << (success2 ? "Success" : "Failed") << std::endl;
            }

            std::cout << "Final basket size: " << demoCustomer->getBasket().size() << " items" << std::endl;

            // Display basket contents
            std::cout << "Basket contents:" << std::endl;
            const std::vector<Plant *> &basket = demoCustomer->getBasket();
            std::map<std::string, int> basketSummary;

            for (Plant *plant : basket)
            {
                if (plant)
                {
                    basketSummary[plant->getName()]++;
                }
            }

            for (const auto &item : basketSummary)
            {
                std::cout << "  - " << item.first << ": " << item.second << " units" << std::endl;
            }

            std::cout << "✓ Customer successfully has 2 different plant types in basket" << std::endl;
        }
    }

    // Cleanup two-plant test customers
    for (Customer *customer : twoPlantCustomers)
    {
        delete customer;
    }

    // Test new Browse functionality: time-based state transitions
    std::cout << "\n=====Testing Browse Time-Based State Transitions=====" << std::endl;

    // Create a nursery and inventory for testing
    Inventory *browseTestInventory = new Inventory();

    // Add plants to the inventory for browsing customer to purchase
    std::unique_ptr<Plant> testRose(flowerPlanter->planterMethod("Rose"));
    std::unique_ptr<Plant> testBasil(herbPlanter->planterMethod("Basil"));
    browseTestInventory->addPlant(std::move(testRose), 20);
    browseTestInventory->addPlant(std::move(testBasil), 15);

    std::cout << "\nInitial inventory state:" << std::endl;
    browseTestInventory->getCatalogue();

    // Create a browsing customer with specific plant
    Plant *targetPlant = flowerPlanter->planterMethod("Rose");
    Browse *browseAction = new Browse(targetPlant, 5);
    Customer *browsingCustomer = new Customer(browseAction, nullptr);

    std::cout << "\nCustomer ID " << browsingCustomer->getId() << " created with Browse action" << std::endl;
    std::cout << "Customer wants 5 of Rose" << std::endl;
    std::cout << "Note: Browse will wait 5-10 seconds, then randomly choose Enquire or Purchasing" << std::endl;
    std::cout << "If Purchasing is chosen, customer will add to basket and update inventory" << std::endl;

    // Note: We can't actually call handle(customer) here because it would block for 5-10 seconds
    // and requires a Nursery object. This demonstrates the setup.
    std::cout << "\nBrowse handle() demonstration (without blocking wait):" << std::endl;
    browsingCustomer->getAction()->handle(); // Calls simple handle without time delay

    std::cout << "\n=====Testing Inventory Update on Purchase=====" << std::endl;

    // Simulate what happens when customer purchases
    std::cout << "Simulating customer purchasing 5 Rose plants..." << std::endl;
    std::string plantName = "Rose";
    auto &invMap = browseTestInventory->getInventory();
    auto it = invMap.find(plantName);

    if (it != invMap.end())
    {
        std::cout << "Current inventory of " << plantName << ": " << it->second.second << std::endl;
        int quantityToPurchase = 5;
        int available = it->second.second;
        int toTake = std::min(quantityToPurchase, available);

        // Simulate adding to basket
        std::cout << "Customer adding " << toTake << " to basket..." << std::endl;

        // Update inventory
        it->second.second -= toTake;
        std::cout << "Updated inventory of " << plantName << ": " << it->second.second << std::endl;
    }

    std::cout << "\nUpdated inventory state:" << std::endl;
    browseTestInventory->getCatalogue();

    // Test edge case: customer wants more than available
    std::cout << "\n=====Testing Purchase with Insufficient Stock=====" << std::endl;
    std::cout << "Simulating customer wanting 50 Basil (only 15 available)..." << std::endl;

    plantName = "Basil";
    it = invMap.find(plantName);
    if (it != invMap.end())
    {
        std::cout << "Current inventory of " << plantName << ": " << it->second.second << std::endl;
        int quantityWanted = 50;
        int available = it->second.second;
        int toTake = std::min(quantityWanted, available);

        std::cout << "Customer wanted " << quantityWanted << " but only " << available << " available" << std::endl;
        std::cout << "Customer takes maximum available: " << toTake << std::endl;

        it->second.second = 0;
        std::cout << "Inventory set to zero for " << plantName << std::endl;
    }

    std::cout << "\nFinal inventory state:" << std::endl;
    browseTestInventory->getCatalogue();

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
    delete browsingCustomer;
    delete targetPlant;
    delete customerWithEmptyStock;
    delete customerFactory;
    delete testStock;
    delete testInventory;
    delete browseTestInventory;
    delete emptyStock;
    delete emptyInventory;
    delete flowerPlanter;
    delete herbPlanter;

    std::cout << "\nCustomer testing completed successfully!" << std::endl;
}*/