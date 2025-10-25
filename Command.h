#ifndef COMMAND_H
#define COMMAND_H
#include <iostream>
using namespace std;

class Command {
public:
	virtual void execute(std::unique_ptr<Plant>&& plant, int quantity) = 0;
	Command();
	virtual ~Command();
};

#endif
