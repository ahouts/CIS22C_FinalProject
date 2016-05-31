#include "BST.h"
BST::void addNode(Node newNode) {
	Node holder = headNode;
	headNode = newNode;
	headNode.left = &holder;
	//headNode.balance();
}
BST::void removeNode(Node targetNode) {
	while (targetNode.hasRightChild == true) {
		targetNode.rotateLeft;
	}
	targetNode = *targetNode.leftChild;
	//targetNode.balance();
}
BST::Node* search(string target) {
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