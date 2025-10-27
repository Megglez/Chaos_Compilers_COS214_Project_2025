#include "SummerCommand.h"

SummerCommand::SummerCommand(Inventory* inv): inventory(inv){

}

void SummerCommand::execute(){
    std::string spring = "spring";
    std::string summer = "summer";
    inventory->seasonalChange(spring, summer);
}

