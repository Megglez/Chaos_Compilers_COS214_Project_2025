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


int main(){
    Planter* FlowerP = new FlowerPlanter();
    Planter* HerbP = new HerbPlanter();
    Planter* SuccP = new SucculentPlanter();
    Planter* TreeP = new TreePlanter();

    Plant* Flower = FlowerP->planterMethod("Rose");
    Plant* Herb = HerbP->planterMethod("Basil");
    Plant* Succ = SuccP->planterMethod("Cactus");
    Plant* Tree = TreeP->planterMethod("Willow");

    std::cout << Flower->getName() << std::endl;
    std::cout << Herb->getName() <<std::endl;
    std::cout << Succ->getName()<< std::endl;
    std::cout <<Tree->getName() <<std::endl;

    return 0;

}