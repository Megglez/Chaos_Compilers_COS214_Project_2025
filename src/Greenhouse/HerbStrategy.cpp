#include "HerbStrategy.h"

void HerbStrategy::helpPlant(std::string& care) {
	cout << "Herb currently being cared for by: " << care << std::endl;
}

HerbStrategy::HerbStrategy() {
	// TODO - implement HerbStrategy::HerbStrategy
	
}

HerbStrategy::~HerbStrategy()
{
}

CareStrategy* HerbStrategy::clone(){
	return new HerbStrategy();
}
