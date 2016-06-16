#ifndef _BST_1_H
#define _BST_1_H

#include <string>
#include <iostream>
#include "Node1.h"
#include "Sheet.h"
using namespace std;

struct CellContainer
{
	int numCells;
	Cell** cells;
};

class BST1
{
private:
	Node1 *headerNode;
	Sheet *sheet;
public:
	BST1(Sheet *sheet);
	~BST1();
	void addNode(Cell *cell);
	void loadFromSheet();
	CellContainer* search(string data);
	void destroyTree();
	void printTree(ostream &out);
	void updateHeaderNode();
protected:
	void addNode(Cell *cell, Node1 *target);
	void search(string data, Node1 *target, CellContainer *cells);
	void destroyTree(Node1 *target);
	void printTree(ostream &out, int height, Node1 *target);
};

#endif