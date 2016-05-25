#ifndef BST_H
#define BST_H

#include "Sheet.h"
#include "Node.h"

using namespace std;
class BST{


private:
	Node headNode;
public:
	void addNode(Node newNode);
	void removeNode(Node targetNode);
	void balance();
	Node* search(string target);

}
#endif