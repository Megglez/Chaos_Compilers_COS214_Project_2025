#include "AutumnCommand.h"

AutumnCommand::AutumnCommand(Inventory* inv): inventory(inv){

}

void AutumnCommand::execute(){
    std::string autumn = "autumn";
    std::string summer = "summer";
    inventory->seasonalChange(summer, autumn);
}


