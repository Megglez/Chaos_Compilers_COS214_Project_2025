#ifndef COMMAND_H
#define COMMAND_H

class Command {


public:
	virtual void execute() = 0;

	Command();

	virtual void ~Command() = 0;
};

#endif
