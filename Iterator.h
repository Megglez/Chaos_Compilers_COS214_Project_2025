#ifndef ITERATOR_H
#define ITERATOR_H
#include <iostream>
using namespace std;

class Iterator {


public:
	virtual void first() = 0;

	virtual void next() = 0;

	virtual void isDone() = 0;

	virtual void currentItem() = 0;

	Iterator();

	virtual ~Iterator();
};

#endif
