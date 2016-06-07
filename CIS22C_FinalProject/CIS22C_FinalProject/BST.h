#ifndef BST_H
#define BST_H

#include "Sheet.h"
#include "Node.h"

using namespace std;

class BST /*friend Node*/{

private:
	Node headNode;
public:
	void addNode(Node newNode);
	void removeNode(Node targetNode);
	void balance(Node* target);
	Node* search(string goal, Node* target);
	void rotateLeft(Node* target);
	void rotateRight(Node* target);
}
#endif