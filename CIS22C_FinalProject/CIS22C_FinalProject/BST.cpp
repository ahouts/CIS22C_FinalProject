#include "BST.h"
BST::void addNode(Node newNode) //stores node to be added in holder, appends existing tree to holder, assigns value of headNode to holder address, balances tree
{
	Node holder = headNode;
	headNode = newNode;
	headNode.left = &holder;
	//headNode.balance(); :(
}
BST::void removeNode(Node targetNode) //moves all branches from node to left, assigns value of leftChild to targetNode, balances tree
{
	while (targetNode.hasRightChild == true) {
		targetNode.rotateLeft;
	}
	targetNode = *targetNode.leftChild;
	//targetNode.balance(); :(
}
BST::Node* search(string target) //compares value of target to values in me and children, if not found, calls search recursively until no children found
{
	if(this.get)
	if (this.hasLeftChild == true) {
		if (this.getLeft()->getMe() == target) {
			return this.getLeft();
		}
		else {
			if (this.getLeft()->search(target) != null) {
				return this.getLeft()->search(target);
			}
		}
	}
	if (this.hasRightChild == true) {
		if (this.getRight->getMe() == target) {
			return this.getRight();
		}
		else {
			if (this.getRight()->search(target) != null) {
				return this.getLeft()->search(target);
			}
		}
	}
	return null;
}