#include "Summer.h"
#include "SummerCommand.h"

Summer::Summer(Inventory* inv): inventory(inv){
    if(commands){
        delete commands;
    }
    commands = new SummerCommand(inventory);
    commands->execute();
}

Summer::~Summer(){

}

void Summer::handleChange(){
    //c->setState(new Autumn(inventory));
    
}

