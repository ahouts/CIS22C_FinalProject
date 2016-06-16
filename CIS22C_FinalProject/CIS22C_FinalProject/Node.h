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
#include <iostream>
#include "Cell.h"
using namespace std;

class Node {
protected:
	Cell* me;
	Node* parent;
	Node* leftChild;
	Node* rightChild;
public:
	Node getNode();
	bool hasLeftChild();
	bool hasRightChild();
	Node* getRight();
	Node* getLeft();
	Node* getParent();
	string getMe();
	void setMe(Cell* in);
	void setRight(Cell* in);
	void setRight(Node* in);
	void setLeft(Cell* in);
	void setLeft(Node* in);
	void setParent(Node* in);
	void rotateRight();
	void rotateLeft();
	bool getImbalance();
	int getMeX();
	int getMeY();
	Node();
	void printTree(const int k);
};

#endif