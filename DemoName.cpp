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

    std::map<string,int,bool>flowers= {{"Bush Lily",12,false},{"Hibiscus",20,true},{"Agapanthus",13,false},{"King Protea",7,true},{"Rose",0.true},{"Daisy",2,false},{"Poppy",4,false},{"Orchid",0,true}};

    std::map<string,int>trees= {{"Jacaranda",6},{"Acacia",4}};

    std::map<string,int>herbs= {{"Oregon",20},{"chives",24},{"parsley",22},{"sage",19}};


    
    return 0;
}