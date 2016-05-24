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
	string contents;
	Cell* above;
	Cell* left;
	Cell* right;
	Cell* below;
public:
	string getData();
	void setData(string in);
	Cell();
	Cell* getAbove();
	Cell* getLeft();
	Cell* getRight();
	Cell* getBelow();
};

#endif