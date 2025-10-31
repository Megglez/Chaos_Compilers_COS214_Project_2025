#include "PlantDecorator.h"

void PlantDecorator::package() {
	if(plantDec){
		plantDec->package();
	}
	
}

PlantDecorator::PlantDecorator() {
	// TODO - implement PlantDecorator::PlantDecorator
	
}

PlantDecorator::~PlantDecorator()
{
}
