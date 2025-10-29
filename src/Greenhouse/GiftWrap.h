#ifndef GIFTWRAP_H
#define GIFTWRAP_H
#include <iostream>
#include "PlantDecorator.h"
using namespace std;

class GiftWrap : public PlantDecorator {
public:
	virtual void package() override;
	GiftWrap(Plant* plant);
	virtual ~GiftWrap();
	virtual Plant* clone() override;
};

#endif
