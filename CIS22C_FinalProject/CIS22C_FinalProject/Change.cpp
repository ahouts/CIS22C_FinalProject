#include <string>
#include "Sheet.h"
#include "Change.h"
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
	Change() {
		isOpenParen = false;
		isCloseParen = false;
		isHead = true;
		row = -1;
		col = -1;
		prev = NULL;
		prevData = "NULL";
		newData = "NULL";
	
	};
	// true = openParen, false = closeParen
	Change(bool blockStart, bool blockEnd) {
		isOpenParen = blockStart;
		isCloseParen = blockEnd;
		row = -1;
		col = -1;
		prevData = "NULL";
		newData = "NULL";
		isHead = false;
	};
	void undo(Sheet *sheet) {
		if (isHead == false && isOpenParen == false && isCloseParen == false) {
			sheet->setCellData(row, col, prevData);
			deleteChange();
		}
		if (isHead == true) {
			next->undo(sheet);
		}
		if (isCloseParen == true) {
			while (next->getOpenParen() != true) {
				next->undo(sheet);
			}
			next->deleteChange();
			deleteChange();
		}
	};
	// we assume that this will only be called on the head Change
	Change(int nRow, int nCol, string nPrevData, string nNewData) {
		Change* newOne = new Change;
		newOne->col = nCol;
		newOne->row = nRow;
		newOne->prevData = nPrevData;
		newOne->newData = nNewData;
	};
	Change* getNext() {
		return next;
	}
	Change* getPrev() {
		return prev;
	}
	void setNext(Change* newNext) {
		next = newNext;
	}
	void setPrev(Change* newPrev) {
		prev = newPrev;
	}
	void pushBack(Change* newChange) {
		newChange->setPrev(this);
		newChange->setNext(next);
		this->next->setPrev(newChange);
		next = newChange;
	}
	void deleteChange() {
		prev->setNext(next);
		next->setPrev(prev);
		delete this;
	}
	bool getOpenParen() {
		return isOpenParen;
	}
};