// PlantDecorator.h
#ifndef PLANTDECORATOR_H
#define PLANTDECORATOR_H

#include "Plant.h"

class PlantDecorator : public Plant {
protected:
    Plant* plantDec;

public:
    PlantDecorator(Plant* plant);
    virtual ~PlantDecorator();
    
    // Implement pure virtual functions from Plant
    virtual Plant* clone() = 0;
    virtual void package() override;
    virtual string getType() override;
    virtual string getName() override;
    
    // Delegate other methods to the decorated plant
    virtual void grow() override;
    virtual void setState(StageOfDevelopment* stage);
    virtual void helpPlant() override;
    virtual StageOfDevelopment* getState() override;
    bool isWinter() const override;

	
};

#endif