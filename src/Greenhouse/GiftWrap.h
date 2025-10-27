#ifndef GIFTWRAP_H
#define GIFTWRAP_H
#include <iostream>
#include "PlantDecorator.h"
using namespace std;

class GiftWrap : public PlantDecorator {
public:
	void package();
	GiftWrap();
	virtual ~GiftWrap();
};

#endif
