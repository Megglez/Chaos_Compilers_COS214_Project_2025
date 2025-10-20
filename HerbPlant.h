#ifndef HERBPLANT_H
#define HERBPLANT_H

class HerbPlant : Plant {


public:
	virtual Plant* clone() = 0;

	void package();
};

#endif
