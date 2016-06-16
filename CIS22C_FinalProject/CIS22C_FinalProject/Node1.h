#ifndef _NODE_1_H
#define _NODE_1_H

#include <string>
#include "Cell.h"
using namespace std;

class Node1
{
private:
	Cell *cell;
	Node1 *parent;
	Node1 *leftChild;
	Node1 *rightChild;
public:
	Node1();
	~Node1();
	Cell* getCell();
	void setCell(Cell *cell);
	Node1* getParent();
	void setParent(Node1 *parent);
	Node1* getLeftChild();
	void setLeftChild(Node1 *leftChild);
	Node1* getRightChild();
	void setRightChild(Node1 *rightChild);
	void rotateRight();
	void rotateLeft();
	int getImbalance();
};

#endif
