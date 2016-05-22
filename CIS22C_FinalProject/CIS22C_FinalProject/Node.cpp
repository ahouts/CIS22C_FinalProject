#include "Node.h"

bool Node::hasLeftChild()
{
	if (leftChild != nullptr) {
		return true;
	}
	return false;
}

bool Node::hasRightChild()
{
	if (rightChild != nullptr) {
		return true;
	}
	return false;
}

Node * Node::getRight()
{
	return rightChild;
}

Node * Node::getLeft()
{
	return leftChild;
}

string Node::getMe()
{
	return me->getData();
}

void Node::setMe(Cell * in)
{
	me = in;
}

void Node::setRight(Cell * in)
{
	rightChild->me = in;
}

void Node::setLeft(Cell * in)
{
	leftChild->me = in;
}

void Node::rotateRight()
{
	Cell* cellHolder;
	Node* nodeHolder;
	if (hasLeftChild() == true) {
		cellHolder = leftChild->me;
		setLeft(me);
		leftChild->me = cellHolder;
	}
	cellHolder = me;
	me = rightChild->me;
	nodeHolder = leftChild->leftChild;
	leftChild->me = me;
	leftChild->leftChild->leftChild = nodeHolder;
}

void Node::rotateLeft()
{
	Cell* cellHolder;
	Node* nodeHolder;
	if (hasRightChild() == true) {
		cellHolder = rightChild->me;
		setRight(me);
		rightChild->me = cellHolder;
	}
	cellHolder = me;
	me = leftChild->me;
	nodeHolder = rightChild->rightChild;
	rightChild->me = me;
	rightChild->rightChild->rightChild = nodeHolder;
}

bool Node::getImbalance()
{
	bool isItBigger = false;
	int treeLength = 0;
	//      :(
	return isItBigger;
}
