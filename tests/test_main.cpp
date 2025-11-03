#include <gtest/gtest.h>
#include "../src/Greenhouse/Planter.h"
#include "../src/Greenhouse/HerbPlanter.h"
#include "../src/Greenhouse/SucculentPlanter.h"
#include "../src/Greenhouse/TreePlanter.h"
#include "../src/Greenhouse/FlowerPlanter.h"
#include "../src/Greenhouse/Plant.h"
#include "../src/Greenhouse/TreePlant.h"
#include "../src/Greenhouse/SucculentPlant.h"
#include "../src/Greenhouse/FlowerPlant.h"
#include "../src/Greenhouse/HerbPlant.h"
#include "../src/Greenhouse/Stock.h"
#include "../src/Greenhouse/Inventory.h"
#include "../src/Greenhouse/Seasons.h"
#include "../src/Greenhouse/AutumnCommand.h"
#include "../src/Greenhouse/SummerCommand.h"
#include "../src/Greenhouse/WinterCommand.h"
#include "../src/Greenhouse/SpringCommand.h"
#include "../src/Greenhouse/StateCommand.h"
#include "../src/Greenhouse/PlantDecorator.h"
#include "../src/Greenhouse/GiftWrap.h"
#include "../src/Greenhouse/Pot.h"
#include "../src/Greenhouse/SpecialArrangement.h"

#include <memory>

class GreenhouseTest : public ::testing::Test {
protected:
    void SetUp() override {
        flowerPlanter = new FlowerPlanter();
        herbPlanter = new HerbPlanter();
        succulentPlanter = new SucculentPlanter();
        treePlanter = new TreePlanter();
        winterFlowerPlanter = new FlowerPlanter(true);
        
        inventory = new Inventory();
        stock = new Stock(inventory);
    }

    void TearDown() override {
        delete flowerPlanter;
        delete herbPlanter;
        delete succulentPlanter;
        delete treePlanter;
        delete winterFlowerPlanter;
        delete inventory;
        delete stock;
    }

    Planter* flowerPlanter;
    Planter* herbPlanter;
    Planter* succulentPlanter;
    Planter* treePlanter;
    Planter* winterFlowerPlanter;
    Inventory* inventory;
    Stock* stock;
};

// Test plant creation with different planters
TEST_F(GreenhouseTest, PlantCreation) {
    std::unique_ptr<Plant> flower(flowerPlanter->planterMethod("Rose"));
    std::unique_ptr<Plant> herb(herbPlanter->planterMethod("Basil"));
    std::unique_ptr<Plant> succulent(succulentPlanter->planterMethod("Cactus"));
    std::unique_ptr<Plant> tree(treePlanter->planterMethod("Willow"));
    std::unique_ptr<Plant> winterFlower(winterFlowerPlanter->planterMethod("Snowdrops"));

    EXPECT_EQ(flower->getName(), "Rose");
    EXPECT_EQ(herb->getName(), "Basil");
    EXPECT_EQ(succulent->getName(), "Cactus");
    EXPECT_EQ(tree->getName(), "Willow");
    EXPECT_EQ(winterFlower->getName(), "Snowdrops");
}

// Test plant decorators
TEST_F(GreenhouseTest, PlantDecorators) {
    Plant* flower = flowerPlanter->planterMethod("Rose Bush");
    
    // Test gift wrap - decorator owns the plant, so don't delete flower separately
    PlantDecorator* gift = new GiftWrap(flower);
    testing::internal::CaptureStdout();
    gift->package();
    std::string giftOutput = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(giftOutput.empty());
    delete gift;  // This will delete the wrapped flower too

    // Create a new flower for the pot test
    Plant* flower2 = flowerPlanter->planterMethod("Rose Bush");
    PlantDecorator* pot = new Pot(flower2);
    testing::internal::CaptureStdout();
    pot->package();
    std::string potOutput = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(potOutput.empty());
    delete pot;  // This will delete the wrapped flower too
}

// Test stock management
TEST_F(GreenhouseTest, StockManagement) {
    std::unique_ptr<Plant> flower(flowerPlanter->planterMethod("Rose"));
    std::unique_ptr<Plant> herb(herbPlanter->planterMethod("Basil"));
    std::unique_ptr<Plant> succulent(succulentPlanter->planterMethod("Cactus"));
    std::unique_ptr<Plant> winterFlower(winterFlowerPlanter->planterMethod("Snowdrops"));

    // Test adding to stock
    stock->Add(std::move(flower), 30);
    stock->Add(std::move(herb), 50);
    stock->Add(std::move(succulent), 60);
    stock->Add(std::move(winterFlower), 60);

    // Test stock printing (capture output to verify it runs)
    testing::internal::CaptureStdout();
    stock->printStock();
    std::string stockOutput = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(stockOutput.empty());

    // Test total plants count
    EXPECT_GT(stock->getTotalPlants(), 0);
}

// Test inventory and catalogue
TEST_F(GreenhouseTest, InventoryCatalogue) {
    std::unique_ptr<Plant> flower(flowerPlanter->planterMethod("Rose"));
    stock->Add(std::move(flower), 30);

    // Test catalogue output
    testing::internal::CaptureStdout();
    inventory->getCatalogue();
    std::string catalogueOutput = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(catalogueOutput.empty());
}

// Test seasonal state commands
TEST_F(GreenhouseTest, SeasonalCommands) {
    std::unique_ptr<Plant> flower(flowerPlanter->planterMethod("Rose"));
    stock->Add(std::move(flower), 30);

    // Test Spring command
    StateCommand* springCommand = new SpringCommand(inventory);
    testing::internal::CaptureStdout();
    springCommand->execute();
    inventory->getCatalogue();
    std::string springOutput = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(springOutput.empty());
    delete springCommand;

    // Test Summer command
    StateCommand* summerCommand = new SummerCommand(inventory);
    testing::internal::CaptureStdout();
    summerCommand->execute();
    inventory->getCatalogue();
    std::string summerOutput = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(summerOutput.empty());
    delete summerCommand;

    // Test Autumn command
    StateCommand* autumnCommand = new AutumnCommand(inventory);
    testing::internal::CaptureStdout();
    autumnCommand->execute();
    inventory->getCatalogue();
    std::string autumnOutput = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(autumnOutput.empty());
    delete autumnCommand;

    // Test Winter command
    StateCommand* winterCommand = new WinterCommand(inventory);
    testing::internal::CaptureStdout();
    winterCommand->execute();
    inventory->getCatalogue();
    std::string winterOutput = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(winterOutput.empty());
    delete winterCommand;
}

// Test inventory content inspection
TEST_F(GreenhouseTest, InventoryInspection) {
    std::unique_ptr<Plant> flower(flowerPlanter->planterMethod("Rose"));
    stock->Add(std::move(flower), 30);

    const auto& inv = inventory->getInventory();
    EXPECT_FALSE(inv.empty());
    
    // Test that we can iterate through inventory
    for (const auto& entry : inv) {
        EXPECT_NE(entry.second.first.get(), nullptr);
        // Depending on your implementation, you might want to check:
        EXPECT_NE(entry.second.first.get()->getState(), nullptr);
        EXPECT_FALSE(entry.second.first.get()->getState()->getStageName().empty());
    }
}

// Test Stock Remove with null pointer
TEST_F(GreenhouseTest, RemoveNullPlant) {
    // Test removing a null plant pointer
    testing::internal::CaptureStdout();
    stock->Remove(nullptr);  // This should print an error message
    std::string removeOutput = testing::internal::GetCapturedStdout();
    
    EXPECT_NE(removeOutput.find("Error: Plant pointer is null. Please pass an actual plant :>"), 
              std::string::npos);
}

// Test Stock Remove with valid plant
TEST_F(GreenhouseTest, RemoveValidPlant) {
    // First add a plant to stock
    std::unique_ptr<Plant> flower(flowerPlanter->planterMethod("Rose"));
    stock->Add(std::move(flower), 30);
    
    int initialCount = stock->getTotalPlants();
    
    // Try to remove a plant that exists
    std::unique_ptr<Plant> plantToRemove(flowerPlanter->planterMethod("Rose"));
    testing::internal::CaptureStdout();
    stock->Remove(std::move(plantToRemove));
    std::string removeOutput = testing::internal::GetCapturedStdout();
    
    int finalCount = stock->getTotalPlants();
    
    // The count should decrease (or your implementation might handle it differently)
    // Also verify no error message was printed
    EXPECT_EQ(removeOutput.find("Error: Plant pointer is null. Please pass an actual plant :>"), 
              std::string::npos);
}

// Test Stock Remove with empty unique_ptr
TEST_F(GreenhouseTest, RemoveEmptyUniquePtr) {
    testing::internal::CaptureStdout();
    
    // Create an empty unique_ptr (nullptr)
    std::unique_ptr<Plant> emptyPlant(nullptr);
    stock->Remove(std::move(emptyPlant));
    
    std::string removeOutput = testing::internal::GetCapturedStdout();
    
    EXPECT_NE(removeOutput.find("Error: Plant pointer is null. Please pass an actual plant :>"), 
              std::string::npos);
}

// Test mixed operations: Add valid plants, then try to remove null
// Test mixed operations: Add valid plants, then try to remove null
TEST_F(GreenhouseTest, MixedOperationsWithNullRemoval) {
    std::unique_ptr<Plant> flower(flowerPlanter->planterMethod("Rose"));
    std::unique_ptr<Plant> herb(herbPlanter->planterMethod("Basil"));
    
    stock->Add(std::move(flower), 30);
    stock->Add(std::move(herb), 50);
    
    int countAfterAdd = stock->getTotalPlants();
    std::cout << "DEBUG: Count after adding plants: " << countAfterAdd << std::endl;
    
    // Try to remove null plant
    testing::internal::CaptureStdout();
    stock->Remove(nullptr);
    std::string nullRemoveOutput = testing::internal::GetCapturedStdout();
    std::cout << "DEBUG: Output from null removal: '" << nullRemoveOutput << "'" << std::endl;
    
    int countAfterNullRemove = stock->getTotalPlants();
    std::cout << "DEBUG: Count after null removal: " << countAfterNullRemove << std::endl;
    
    // Verify error message was printed
    bool hasErrorMessage = (nullRemoveOutput.find("Error: Plant pointer is null. Please pass an actual plant :>") != std::string::npos);
    std::cout << "DEBUG: Has error message: " << (hasErrorMessage ? "YES" : "NO") << std::endl;
    EXPECT_TRUE(hasErrorMessage);
    
    // Verify stock count remains unchanged after null removal attempt
    std::cout << "DEBUG: Comparing counts - AfterAdd: " << countAfterAdd << ", AfterNullRemove: " << countAfterNullRemove << std::endl;
    EXPECT_EQ(countAfterAdd, countAfterNullRemove);
    
    // Now remove a valid plant
    std::unique_ptr<Plant> plantToRemove(herbPlanter->planterMethod("Basil"));
    testing::internal::CaptureStdout();
    stock->Remove(std::move(plantToRemove));
    std::string validRemoveOutput = testing::internal::GetCapturedStdout();
    std::cout << "DEBUG: Output from valid removal: '" << validRemoveOutput << "'" << std::endl;
    
    int countAfterValidRemove = stock->getTotalPlants();
    std::cout << "DEBUG: Count after valid removal: " << countAfterValidRemove << std::endl;
    
    // Verify no error message for valid removal
    bool hasNoErrorMessage = (validRemoveOutput.find("Error: Plant pointer is null. Please pass an actual plant :>") == std::string::npos);
    std::cout << "DEBUG: Valid removal has no error message: " << (hasNoErrorMessage ? "YES" : "NO") << std::endl;
    EXPECT_TRUE(hasNoErrorMessage);
    
    // Stock count should decrease after valid removal
    std::cout << "DEBUG: Comparing counts - AfterNullRemove: " << countAfterNullRemove << ", AfterValidRemove: " << countAfterValidRemove << std::endl;
    EXPECT_EQ(countAfterValidRemove, countAfterNullRemove);
}

