#ifndef COMMAND_LINE_H
#define COMMAND_LINE_H

#include <string>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include "Sheet.h"
#include "Refresh.h"
#include "Cell.h"
#include "MainMenu.h"
using namespace std;

class CommandLine
{
private:
	Sheet *sheet;
public:
	CommandLine(Sheet *sheet);
	void modifyCell(int xCoord, int yCoord, string data);
	void drawSheet(ostream& out);
	void mainLoop();
};

#endif