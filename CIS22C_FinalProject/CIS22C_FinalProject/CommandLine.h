#ifndef _COMMAND_LINE_H
#define _COMMAND_LINE_H

#include "Sheet.h"
using namespace std;

class CommandLine
{
private:
	Sheet *sheet;
public:
	CommandLine(Sheet *sheet);
	void modifyCell(int xCoord, int yCoord, string data);
	void mainLoop();
};

#endif