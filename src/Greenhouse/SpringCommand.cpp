#include "SpringCommand.h"

SpringCommand::SpringCommand(Inventory* inv): inventory(inv){

}

void SpringCommand::execute(){
    std::string winter = "winter";
    std::string spring = "spring";
    inventory->seasonalChange(winter, spring);
}


