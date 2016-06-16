#ifndef BST_H
#define BST_H

#include <string>
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
	Node* search(string goal, Node* target, Sheet *sht);
	void rotateLeft(Node* target);
	void rotateRight(Node* target);
	void generateTree(Sheet &sheet);
	void clearTree();
	void clearTree(Node* target);
};

#endif