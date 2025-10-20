#ifndef PLANTDECORATOR_H
#define PLANTDECORATOR_H

class PlantDecorator : Plant {

public:
	Plant* plant;

	void package();
};

#endif
