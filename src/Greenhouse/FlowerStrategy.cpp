#include "FlowerStrategy.h"

void FlowerStrategy::helpPlant(std::string& care) 
{
	cout << "Flower currently being cared for by: " << care << std::endl;
}



FlowerStrategy::FlowerStrategy() 
{

}

FlowerStrategy::~FlowerStrategy()
{
}

CareStrategy* FlowerStrategy::clone(){
	return new FlowerStrategy();
}
