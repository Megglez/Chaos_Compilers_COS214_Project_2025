#include "Pot.h"

void Pot::package() {
	PlantDecorator::package();
    
    cout << "Adding the plant to a pot!" << endl;
	
}

Pot::Pot(Plant* plant): PlantDecorator(plant) {
	// TODO - implement Pot::Pot
	
}

Pot::~Pot()
{
}

Plant* Pot::clone() {
    return new Pot(plantDec ? plantDec->clone() : nullptr);
}
