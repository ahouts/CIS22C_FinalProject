#ifndef _SHEET_H
#define _SHEET_H

#include <string>
#include <iostream>
#include <fstream>
#include <limits>
#include <sstream>
#include "Change.h"
#include "Cell.h"
using namespace std;

class Sheet
{
private:
	Cell *headerCell;		// refers to the Cell at (0, 0)
	int xSize;
	int ySize;
	string filePath;
	// hash table settings for searching objects and file in & out
	double hashTableSizeMultiplier;
	int maxResolutionAttempts;
	int hashTableSize;
	int hashTableMultiplier;
	int hashTableAddition;
	Cell **hashTable;
	Change *change;
public:
	Sheet(int xSize, int ySize, Change *change);
	~Sheet();
	Cell* operator()(int x, int y);
	void setCellData(int x, int y, string str);
	string getCellData(int x, int y);
	void resizeSheet(int xSize, int ySize);			// WARNING!!! Deletes all elements in sheet
	void toFile();
	void fromFile();
	void swapRow(int y1, int y2);
	void swapCol(int x1, int x2);
	int getXSize();
	int getYSize();
	string getFilePath();
	void setFilePath(string filePath);
	void changeOpenParen();
	void changeCloseParen();
	void printHashTable(ostream out);
protected:
	void generateHashTable();
	Cell* nonHashSearch(int x, int y);
	void initializeSheet(int xSize, int ySize);
	void wipeSheet();								// Deletes all cells in Sheet
	int index(int x, int y, int width);				// for *arr in the initializer
	bool isPrime(int number);
	int getPrimeGreaterThan(int number);
	int getHashIndex(int cellXIndex, int cellYIndex, int multiplier, int addition, int hashTableSize);		// generates a hash value for a cell
	int quadraticResolution(int index, int hashTableSize);													// returns new index for cell
};
#endif