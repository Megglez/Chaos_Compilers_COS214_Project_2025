#ifndef SUCCULANTPLANT_H
#define SUCCULANTPLANT_H

class SucculantPlant : Plant {


public:
	virtual Plant* clone() = 0;

	void package();

	SucculantPlant();

	virtual void ~SucculantPlant() = 0;
};

#endif
