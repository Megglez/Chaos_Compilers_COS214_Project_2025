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

#include <memory>



int main(){
    Planter* FlowerP = new FlowerPlanter();
    Planter* HerbP = new HerbPlanter();
    Planter* SuccP = new SucculentPlanter();
    Planter* TreeP = new TreePlanter();
    Planter* FlowerW = new FlowerPlanter(true);

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
    PlantDecorator* gift = new GiftWrap(Flower2);
    PlantDecorator* pot = new Pot(Flower2);
    gift->package();
    pot->package();

    //StaffT* staff1 = new StaffT();

    Inventory* test_inv = new Inventory();
    //test_inv->attach(staff1);
    Stock* test_st = new Stock(test_inv);
    test_st->Add(std::move(Flower), 30);
    test_st->Add(std::move(Herb), 50);
    test_st->Add(std::move(Succ), 60);
    test_st->Add(std::move(FlowerWinter), 60);
    test_st->Remove(nullptr);
    //test_st->Remove(std::unique_ptr<Plant>(FlowerP->planterMethod("Rose")));
    test_st->printStock();
    test_inv->getCatalogue();
    test_inv->getCatalogue();

    StateCommand* command = new SpringCommand(test_inv);
    command->execute();
    test_inv->getCatalogue();
    

    StateCommand* command2 = new SummerCommand(test_inv);
    command2->execute();
    test_inv->getCatalogue();

    StateCommand* command3 = new AutumnCommand(test_inv);
    command3->execute();
    test_inv->getCatalogue();

    StateCommand* command4 = new WinterCommand(test_inv);
    command4->execute();
    test_inv->getCatalogue();
    std::cout << test_st->getTotalPlants();
    const auto&  inv = test_inv->getInventory();
    for (const auto& entry : inv) {
        std::cout << "- " << entry.second.first.get()->getState()->getStageName();
    }
    
    
    
    return 0;

}