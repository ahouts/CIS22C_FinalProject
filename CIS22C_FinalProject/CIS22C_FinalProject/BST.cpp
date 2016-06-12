#include "BST.h"

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

void BST::addNode(Node newNode) //stores node to be added in holder, appends existing tree to holder, assigns value of headNode to holder address, balances tree
{
	Node holder = headNode;
	headNode = newNode;
	headNode.setLeft(&holder);
	balance(&headNode);
}

void BST::removeNode(Node targetNode) //moves all branches from node to left, assigns value of leftChild to targetNode, balances tree
{
	while (targetNode.hasRightChild() == true) {
		targetNode.rotateLeft();
	}
	targetNode = *targetNode.getLeft();
	balance(&targetNode);
}

Node* BST::search(string goal, Node* target) //compares value of goal to values in me and children, if not found, calls search recursively until no children found
{
	if (target->getMe() != goal) {
		if (target->hasLeftChild() == true) {
			if (target->getLeft()->getMe() == goal) {
				return target->getLeft();
			}
			else {
				if (search(goal, target->getLeft()) != NULL) {
					return search(goal, target->getLeft());
				}
			}
		}
		if (target->hasRightChild() == true) {
			if (target->getRight->getMe() == goal) {
				return target->getRight();
			}
			else {
				if (search(goal, target->getRight()) != NULL) {
					return search(goal, target->getRight());
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
