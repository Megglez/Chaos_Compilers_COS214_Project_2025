#include "Winter.h"
#include "WinterCommand.h"

Winter::Winter(Inventory* inv): inventory(inv){
    if(commands){
        delete commands;
    }
    commands = new WinterCommand(inventory);
    commands->execute();
}

Winter::~Winter(){
    //delete inventory?
}

void Winter::handleChange(){
    //c->setState(new Spring(inventory));
    
}

