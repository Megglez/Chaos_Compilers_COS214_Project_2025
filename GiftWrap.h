#ifndef GIFTWRAP_H
#define GIFTWRAP_H

class GiftWrap : PlantDecorator {


public:
	void package();

	GiftWrap();

	virtual void ~GiftWrap() = 0;
};

#endif
