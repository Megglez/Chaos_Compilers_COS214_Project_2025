#ifndef FLOWERPLANT_H
#define FLOWERPLANT_H

class FlowerPlant : Plant {


public:
	virtual Plant* clone() = 0;

	void package();

	FlowerPlant();

	virtual ~FlowerPlant();
};

#endif
