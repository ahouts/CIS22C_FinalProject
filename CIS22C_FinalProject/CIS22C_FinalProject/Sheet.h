#ifndef _SHEET_H
#define _SHEET_H

#include <string>
#include "Cell.h"
using namespace std;

class Sheet
{
private:
	Cell *headerCell;		// refers to the Cell at (0, 0)
	int xSize;
	int ySize;
public:
	Sheet(int xSize, int ySize);
	~Sheet();
	Cell* operator()(int x, int y);
	//void refresh();				refresh and undo should become methods of Change and Refresh to avoid recursive definitions
	//void undo();					
	void toFile(string fileName);
	void fromFile(string fileName);
	void swapRow(int y1, int y2);
	void swapCol(int x1, int x2);
};

#endif