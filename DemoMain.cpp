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
#include "src/Nursery/Nursery.h"
#include <map>
#include <memory>

int main()
{
    //creating the initial inventory
    //20 difference plants
    std::map<string,int>succulents= {{"Elephant Bush",10},{"Candelabra Aloe Vera",4},{"Jade",1},{"Red Pagoda",2},{"Portulaca",1}};

    std::map<string,std::pair<int,bool>>flowers= {{"Bush Lily",make_pair(12,false)},{"Hibiscus",make_pair(20,true)},{"Agapanthus",make_pair(13,false)},{"King Protea",make_pair(7,true)},{"Rose",make_pair(0,true)},{"Daisy",make_pair(2,false)},{"Poppy",make_pair(4,false)},{"Orchid",make_pair(0,true)}};

    std::map<string,int>trees= {{"Jacaranda",6},{"Acacia",4}};

    std::map<string,int>herbs= {{"Oregon",20},{"chives",24},{"parsley",22},{"sage",19}};
    
    SucculentPlanter* succulentP = new SucculentPlanter();
    FlowerPlanter* flowerP = new FlowerPlanter(false);
    FlowerPlanter* winterFlowerP = new FlowerPlanter(true);
    TreePlanter* treeP = new TreePlanter();
    HerbPlanter* herbP = new HerbPlanter();

    for(const auto& p : succulents)
    {
        std::unique_ptr<Plant> SuccP(succulentP->planterMethod(p.first));
        //Nursery->setStock(std::move(SuccP), pair.second);
    }

    for(const auto& p : flowers)
    {
        if(p.second.second) // is winter flower
        {
            std::unique_ptr<Plant> FlowP(winterFlowerP->planterMethod(p.first));
            
            continue;
        }
        std::unique_ptr<Plant> FlowP(flowerP->planterMethod(p.first));
        //Nursery->setStock(std::move(FlowP), pair.second.first);
    }
    
    for(const auto& pair : trees)
    {
        std::unique_ptr<Plant> treesP(treeP->planterMethod(pair.first));
        //Nursery->setStock(std::move(SuccP), pair.second);
    }

    for(const auto& pair : herbs)
    {
        std::unique_ptr<Plant> herbsP(herbP->planterMethod(pair.first));
        //Nursery->setStock(std::move(SuccP), pair.second);
    }

    
    return 0;
}