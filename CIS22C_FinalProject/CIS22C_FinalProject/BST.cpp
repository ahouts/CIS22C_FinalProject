#include "BST.h"
;
void BST::rotateLeft(Node* target) 
{
	Node* holder = target;
	target = target->getRight();
	holder->setRight(target->getLeft());
	target->setLeft(holder);
}

void BST::rotateRight(Node* target) 
{
	Node* holder = target;
	target = target->getLeft();
	holder->setLeft(target->getRight());
	target->setRight(holder);
}

void BST::generateTree(Sheet &sheet)
{
	clearTree();
	for (int j = 0; j < sheet.getYSize(); j++)
	{
		for (int i = 0; i < sheet.getXSize(); i++)
		{
			Node temp = Node();
			temp.setMe(sheet(i, j));
			// addNode(temp, );
		}
	}
}

void BST::clearTree()
{
	Node* target = &headNode;
	target->clearTree();
}

void BST::removeNode(Node *targetNode) //moves all branches from node to left, assigns value of leftChild to targetNode, balances tree
{
	Node* holder = targetNode;
	addNode(targetNode->getRight(), targetNode->getLeft());
	delete holder;
}

Node* BST::search(string goal, Node* target, Sheet *sht) //compares value of goal to values in me and children, if not found, calls search recursively until no children found
{
	if (target->getMe() != goal) {
		if (target->hasLeftChild() == true) {
			if (target->getLeft()->getMe() == goal) {
				return target->getLeft();
			}
			else {
				if (search(goal, target->getLeft(), sht) != NULL) {
					return search(goal, target->getLeft(), sht);
				}
			}
		}
		if (target->hasRightChild() == true) {
			if (target->getRight()->getMe() == goal) {
				return target->getRight();
			}
			else {
				if (search(goal, target->getRight(), sht) != NULL) {
					return search(goal, target->getRight(), sht);
				}
			}
		}
		return NULL;
	}
}

void BST::balance(Node* target)//completely untested
{
	if (target->getLeft() != NULL) {
		if (target->getLeft()->getLeft() != NULL || target->getRight() == NULL) {
			rotateRight(target);
		}
	}
	balance(target->getLeft());
	if (target->getRight() != NULL) {
		if (target->getRight()->getRight() != NULL || target->getLeft() == NULL) {
			rotateLeft(target);
		}
	}
	balance(target->getRight());
}

Node BST::getHead()
{
	return headNode;
}

void BST::addNode(Node* newNode, Node* target) {
	if (target->hasLeftChild() == false && target->hasRightChild() == false) {
		if (target->getMe() > newNode->getMe()) {
			target->setRight(newNode);
		}
		else {
			target->setLeft(newNode);
		}
	}
	if (target->hasLeftChild() == true) {
		if (newNode->getMe() < target->getMe()) {
			addNode(newNode, target->getLeft());
		}
		else {
			target->setRight(newNode);
		}
	}
	if (target->hasRightChild() == true) {
		if (newNode->getMe() > target->getMe()) {
			addNode(newNode, target->getRight());
		}
		else {
			target->setLeft(newNode);
		}
	}
}
