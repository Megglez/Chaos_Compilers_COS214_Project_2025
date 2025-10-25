#include "Autumn.h"
#include "AutumnCommand.h"

Autumn::Autumn(Inventory* inv): inventory(inv){
    if(commands){
        delete commands;
    }
    commands = new AutumnCommand(inventory);
    commands->execute();
}

Autumn::~Autumn(){

}

void Autumn::handleChange(){
    //c->setState(new Winter(inventory));
}

