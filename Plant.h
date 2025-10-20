#ifndef PLANT_H
#define PLANT_H

class Plant {

private:
	int water;
	int soil;
	int sunlight;
	StageOfDevelopment stage;
	CareStrategy* strategy;

public:
	virtual Plant* clone() = 0;

	virtual void package() = 0;

	void grow();

	void helpPlant();
};

#endif
