#include "CommandLine.h"
#include "Sheet.h"
#include "Refresh.h"
#include "Cell.h"
#include <string>

void CommandLine::modifyCell(int xCoord, int yCoord, string data)
{

	Cell.setData(data);
}
void CommandLine::drawSheet(ostream& out) //draws the sheet 
{

}
void CommandLine::mainLoop() // calls main menu
{

}