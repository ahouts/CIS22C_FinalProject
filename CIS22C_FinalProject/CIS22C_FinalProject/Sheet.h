#ifndef _SHEET_H
#define _SHEET_H

#include <string>
#include <fstream>
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
	int getXSize();
	int getYSize();
protected:
	void resizeSheet(int xSize, int ySize);			// WARNING!!! Deletes all elements in sheet
	void initializeSheet(int xSize, int ySize);
	void wipeSheet();								// Deletes all cells in Sheet
	int index(int x, int y, int width);				// for *arr in the initializer
	bool isPrime(int number);
	int getPrimeGreaterThan(int number);
	int hashCell(string cellData, int multiplier, int addition, int hashTableSize);		// generates a hash value for a cell
	int quadraticResolution(int index, int hashTableSize);								// returns new index for cell
};

#endif