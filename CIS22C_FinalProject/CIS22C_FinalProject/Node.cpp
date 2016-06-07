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

void Node::setRight(Node* in) {
	rightChild = in;
}

void Node::setLeft(Cell * in)
{
	leftChild->me = in;
}

void Node::setLeft(Node* in) {
	leftChild = in;
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
	Node* top = this;			// changed it so it didn't require itself to be passed in as a variable
	bool isItBigger = false;
	int leftLength = 0;
	int rightLength = 0;
	while (top->leftChild != nullptr) {
		leftLength++;
		top = leftChild;
	}
	top = this;
	while (top->rightChild != nullptr) {
		rightLength++;
		top = rightChild;
	}
	if (rightLength<leftLength + 1) {
		isItBigger = true;
	}
	if (leftLength<rightLength + 1) {
		isItBigger = true;
	}
	return isItBigger;
}
