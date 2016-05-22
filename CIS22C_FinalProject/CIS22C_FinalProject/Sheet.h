#ifndef _SHEET_H
#define _SHEET_H

#include <string>
#include "Cell.h"
using namespace std;

class Sheet
{
private:
	Cell *headerCell;
	int xSize;
	int ySize;
	Change changeLog;
public:
	Sheet(int xSize, int ySize);
	Cell* operator()(int x, int y);
	void refresh();
	void undo();
	void toFile(string fileName);
	void fromFile(string fileName);
	void swapRow(int y1, int y2);
	void swapCol(int x1, int x2);
};

#endif