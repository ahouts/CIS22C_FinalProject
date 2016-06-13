#ifndef REFRESH_H
#define REFRESH_H
#include "Sheet.h"


class Refresh
{
private:
	Sheet* sheet;
public:
	Refresh(Sheet *sheet);
	void findfunctions();
	double add(int xCoord, int yCoord, int xCoord1, int yCoord1);
	double subtract(int xCoord, int yCoord, int xCoord1, int yCoord1);
	double multiply(int xCoord, int yCoord, int xCoord1, int yCoord1);
	double divide(int xCoord, int yCoord, int xCoord1, int yCoord1);
	void sortRow(int x1, int x2, int y);
	void sortCol(int y1, int y2, int x);
	double average(int xCoord, int yCoord, int xCoord1, int yCoord1);
};

#endif