
#ifndef CHANGE_H
#define CHANGE_H

#include <string>
#include "Sheet.h"
using namespace std;

class Change
{
private:
	Change *prev;
	Change *next;
	int row;
	int col;
	string prevData;
	string newData;
	bool isOpenParen;
	bool isCloseParen;
	bool isHead;		// if it is the head Change, don't undo it
public:
	// This creates the head Change that will be used in other classes
	Change();
	~Change();
	// true = openParen, false = closeParen
	Change(bool blockStart, bool blockEnd);
	//
	void undo(Sheet *sheet);
	// we assume that this will only be called on the head Change
	Change(int nRow, int nCol, string nPrevData, string nNewData);
	void setNext(Change* newNext);
	void setPrev(Change* newPrev);
	Change* getNext();
	Change* getPrev();
	void pushBack(Change* newChange);
	void deleteChange();
	bool getOpenParen();
	void pushBack(int nRow, int nCol, string nPrevData, string nNewData);
};

#endif