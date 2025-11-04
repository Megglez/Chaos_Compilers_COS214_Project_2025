/**
 * @file SpecialArrangement.cpp
 * @brief Implementation of the SpecialArrangement class
 * @author Chaos_Compilers
 * @date 2025
 */

#include "SpecialArrangement.h"

void SpecialArrangement::package() {
	PlantDecorator::package();
    
    cout << "Arrange the Flowers in a special order!" << endl;
	
}

SpecialArrangement::SpecialArrangement(Plant* plant):PlantDecorator(plant) {
	// TODO - implement SpecialArrangement::SpecialArrangement
	
}

SpecialArrangement::~SpecialArrangement()
{
}

Plant* SpecialArrangement::clone() {
    return new SpecialArrangement(plantDec ? plantDec->clone() : nullptr);
}
