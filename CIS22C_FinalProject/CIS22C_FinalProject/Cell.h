//
//  Cell.h
//  
//
//  Created by Roark Burney on 5/19/16.
//
//

#ifndef CELL_H
#define CELL_H

#include <string>
using namespace std;

class Cell {
protected:
	string contents;
	Cell* above;
	Cell* left;
	Cell* right;
	Cell* below;
public:
	string getData();
	void setData(string in);
	Cell();
	int getXCoord();
	int getYCoord();
	Cell* getAbove();
	Cell* getLeft();
	Cell* getRight();
	Cell* getBelow();
	void setAbove(Cell *above);
	void setLeft(Cell *left);
	void setRight(Cell *right);
	void setBelow(Cell *below);
};

#endif