#include "GiftWrap.h"

void GiftWrap::package() {
	PlantDecorator::package();
    
    cout << "Adding beautiful gift wrap with a bow!" << endl;
	
}

GiftWrap::GiftWrap(Plant* plant):PlantDecorator(plant) {
	// TODO - implement GiftWrap::GiftWrap
	
}

GiftWrap::~GiftWrap()
{
}

Plant* GiftWrap::clone() {
    return new GiftWrap(plantDec ? plantDec->clone() : nullptr);
}
