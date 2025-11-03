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
    // struct SellingPlants:
    // {
    //     int num;
    //     std::string name;

    //     SellingPlants(int num,string name):num(i),name(pn){}

    //     SellingPlants(1,"Rose"){}
    // };
    // std::vector<SellingPlants> plants;
 
    // plants->push_back(SellingPlants(0,"Elephant bush"));
    // plants->push_back(SellingPlants(1,"Candelabra Aloe vera"));
    // plants->push_back(SellingPlants(2,"Jade"));
    // plants->push_back(SellingPlants(3,"Red Pagoda"));
    // plants->push_back(SellingPlants(4,"Portulaca"));
    // plants->push_back(SellingPlants(5,"Elephant"));
    // plants->push_back(SellingPlants(6,"Elephant"));
    // plants->push_back(SellingPlants(7,"Elephant"));
    // plants->push_back(SellingPlants(8,"Elephant"));
    // plants->push_back(SellingPlants(9,"Elephant"));
    // plants->push_back(SellingPlants(10,"Elephant"));
    // plants->push_back(SellingPlants(11,"Elephant"));
    // plants->push_back(SellingPlants(12,"Elephant"));
    // plants->push_back(SellingPlants(13,"Elephant"));

    //creating the initial inventory
    //20 difference plants
    std::map<string,int>succulents= {{"Elephant Bush",10},{"Candelabra Aloe Vera",4},{"Jade",1},{"Red Pagoda",2},{"Portulaca",1}};

    std::map<string,int,bool>flowers= {{"Bush Lily",12},{"Hibiscus",20},{"Agapanthus",13},{"King Protea",7},{"Rose",0},{"Daisy",2},{"Poppy",4},{"Orchid",0}};

    std::map<string,int>trees= {{"Jacaranda",6},{"Acacia",4}};

    std::map<string,int>herbs= {{"Oregon",20},{"chives",24},{"parsley",22},{"sage",19}};

    return 0;
}