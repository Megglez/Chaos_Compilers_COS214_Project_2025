#include "WinterCommand.h"

WinterCommand::WinterCommand(Inventory* inv): inventory(inv){

}

void WinterCommand::execute(){
    std::string autumn = "autumn";
    std::string winter = "winter";
    inventory->seasonalChange(autumn, winter);
}
