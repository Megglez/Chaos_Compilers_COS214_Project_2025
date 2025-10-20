#ifndef FLOWERPLANT_H
#define FLOWERPLANT_H

class FLowerPlant : Plant {


public:
	virtual Plant* clone() = 0;

	void package();
};

#endif
