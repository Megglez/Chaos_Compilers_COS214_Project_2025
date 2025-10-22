#ifndef GIFTWRAP_H
#define GIFTWRAP_H
#include <iostream>
using namespace std;

class GiftWrap : PlantDecorator {


public:
	void package();

	GiftWrap();

	virtual ~GiftWrap();
};

#endif
