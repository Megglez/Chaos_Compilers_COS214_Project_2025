#ifndef TREEPLANT_H
#define TREEPLANT_H

class TreePlant : Plant {


public:
	virtual Plant* clone() = 0;

	void package();

	TreePlant();

	virtual void ~TreePlant() = 0;
};

#endif
