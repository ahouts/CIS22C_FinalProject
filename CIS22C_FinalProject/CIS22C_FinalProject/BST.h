#ifndef BST_H
#define BST_H

#include "Sheet.h"
#include "Node.h"

using namespace std;

class BST /*friend Node*/{

protected:
	Node headNode;
public:
	Node getHead();
	void addNode(Node* newNode, Node* target);
	void removeNode(Node *targetNode);
	void balance(Node* target);
	Node* search(string goal, Node* target);
	void rotateLeft(Node* target);
	void rotateRight(Node* target);
	void generateTree(Sheet &sheet);
	void clearTree();
}
#endif