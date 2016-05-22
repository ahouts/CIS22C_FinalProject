//
//  Node.h
//  
//
//  Created by Roark Burney on 5/19/16.
//
//

#ifndef NODE_H
#define NODE_H

#include <string>
#include "Cell.h"
using namespace std;

class Node {
	Cell* me;
	Node* parent;
	Node* leftChild;
	Node* rightChild;
public:
	bool hasLeftChild();
	bool hasRightChild();
	Node* getRight();
	Node* getLeft();
	string getMe();
	void setMe(Cell* in);
	void setRight(Cell* in);
	void setLeft(Cell* in);
	void rotateRight();
	void rotateLeft();
	bool getImbalance();
};

#endif