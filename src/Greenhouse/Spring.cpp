#include "Spring.h"
#include "SpringCommand.h"

Spring::Spring(Inventory* inv): inventory(inv){
    if(commands){
        delete commands;
    }
    commands = new SpringCommand(inventory);
    commands->execute();
}

Spring::~Spring(){

}
    
void Spring::handleChange(){
    //c->setState(new Summer(inventory));
}

