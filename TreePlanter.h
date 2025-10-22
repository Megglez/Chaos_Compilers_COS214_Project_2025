#ifndef TREEPLANTER_H
#define TREEPLANTER_H

class TreePlanter : Planter {


public:
	Plant* planterMethod();

	TreePlanter();

	virtual void ~TreePlanter() = 0;
};

#endif
