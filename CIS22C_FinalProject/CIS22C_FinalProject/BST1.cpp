#include "BST1.h"

BST1::BST1(Sheet *sheet)
{
	headerNode = nullptr;
	this->sheet = sheet;
}

BST1::~BST1()
{
	destroyTree();
}

void BST1::addNode(Cell * cell)
{
	if (headerNode == nullptr)
	{
		Node1 *newNode = new Node1();
		newNode->setCell(cell);
		headerNode = newNode;
	}
	else if (headerNode->getCell()->getData() > cell->getData())
	{
		if (headerNode->getLeftChild() == nullptr)
		{
			Node1 *newNode = new Node1();
			newNode->setCell(cell);
			newNode->setParent(headerNode);
			headerNode->setLeftChild(newNode);
		}
		else
		{
			addNode(cell, headerNode->getLeftChild());
		}
	}
	else
	{
		if (headerNode->getRightChild() == nullptr)
		{
			Node1 *newNode = new Node1();
			newNode->setCell(cell);
			newNode->setParent(headerNode);
			headerNode->setRightChild(newNode);
		}
		else
		{
			addNode(cell, headerNode->getRightChild());
		}
	}
	updateHeaderNode();
}

void BST1::loadFromSheet()
{
	destroyTree();
	for (int i = 0; i < sheet->getXSize(); i++)
	{
		for (int j = 0; j < sheet->getYSize(); j++)
		{
			addNode(sheet->operator()(i, j));
		}
	}
}

CellContainer * BST1::search(string data)
{
	CellContainer *cells = new CellContainer;
	cells->numCells = 0;
	cells->cells = new Cell*[1000]();

	if (data == headerNode->getCell()->getData())
	{
		cells->cells[cells->numCells] = headerNode->getCell();
		cells->numCells++;
	}
	
	if (data < headerNode->getCell()->getData())
	{
		if (headerNode->getLeftChild() != nullptr)
		{
			search(data, headerNode->getLeftChild(), cells);
		}
	}
	else
	{
		if (headerNode->getRightChild() != nullptr)
		{
			search(data, headerNode->getRightChild(), cells);
		}
	}
	return cells;
}

void BST1::destroyTree()
{
	if (headerNode != nullptr)
	{
		if (headerNode->getLeftChild() != nullptr)
		{
			destroyTree(headerNode->getLeftChild());
		}
		if (headerNode->getRightChild() != nullptr)
		{
			destroyTree(headerNode->getRightChild());
		}
		delete headerNode;
	}
}

void BST1::printTree(ostream & out)
{
	if (headerNode != nullptr)
	{
		if (headerNode->getCell()->getData() != "0")
		{
			out << headerNode->getCell()->getData() << endl;
		}
		if (headerNode->getLeftChild() != nullptr)
		{
			printTree(out, 1, headerNode->getLeftChild());
		}

		if (headerNode->getRightChild() != nullptr)
		{
			printTree(out, 1, headerNode->getRightChild());
		}
	}
}

void BST1::updateHeaderNode()
{
	if (headerNode != nullptr)
	{
		if (headerNode->getParent() != nullptr)
		{
			headerNode = headerNode->getParent();
			updateHeaderNode();
		}
	}
}

void BST1::addNode(Cell * cell, Node1 * target)
{
	if (target->getCell()->getData() > cell->getData())
	{
		if (target->getLeftChild() == nullptr)
		{
			Node1 *newNode = new Node1();
			newNode->setCell(cell);
			newNode->setParent(target);
			target->setLeftChild(newNode);
			Node1 *tempNode = newNode;
			while (tempNode->getParent() != nullptr)
			{
				if (tempNode->getImbalance() == -2)
				{
					tempNode->rotateRight();
				}
				else if (tempNode->getImbalance() == -1)
				{
					tempNode->getLeftChild()->rotateLeft();
					tempNode->rotateRight();
				}
				else if (tempNode->getImbalance() == 1)
				{
					tempNode->getRightChild()->rotateRight();
					tempNode->rotateLeft();
				}
				else if (tempNode->getImbalance() == 2)
				{
					tempNode->rotateLeft();
				}
				tempNode = tempNode->getParent();
			}
			if (tempNode->getImbalance() == -2)
			{
				tempNode->rotateRight();
			}
			else if (tempNode->getImbalance() == -1)
			{
				tempNode->getLeftChild()->rotateLeft();
				tempNode->rotateRight();
			}
			else if (tempNode->getImbalance() == 1)
			{
				tempNode->getRightChild()->rotateRight();
				tempNode->rotateLeft();
			}
			else if (tempNode->getImbalance() == 2)
			{
				tempNode->rotateLeft();
			}
		}
		else
		{
			addNode(cell, target->getLeftChild());
		}
	}
	else
	{
		if (target->getRightChild() == nullptr)
		{
			Node1 *newNode = new Node1();
			newNode->setCell(cell);
			newNode->setParent(target);
			target->setRightChild(newNode);
		}
		else
		{
			addNode(cell, target->getRightChild());
		}
	}
}

void BST1::search(string data, Node1 * target, CellContainer *cells)
{
	if (data == target->getCell()->getData())
	{
		cells->cells[cells->numCells] = target->getCell();
		cells->numCells++;
	}

	if (data < target->getCell()->getData())
	{
		if (target->getLeftChild() != nullptr)
		{
			search(data, target->getLeftChild(), cells);
		}
	}
	else
	{
		if (target->getRightChild() != nullptr)
		{
			search(data, target->getRightChild(), cells);
		}
	}
}

void BST1::destroyTree(Node1 * target)
{
	if (target->getLeftChild() != nullptr)
	{
		destroyTree(target->getLeftChild());
	}
	if (target->getRightChild() != nullptr)
	{
		destroyTree(target->getRightChild());
	}
	delete target;
}

void BST1::printTree(ostream & out, int height, Node1 * target)
{
	if (target->getCell()->getData() != "0")
	{
		for (int i = 0; i < height; i++)
		{
			out << "-";
		}
		out << target->getCell()->getData() << endl;
	}
	if (target->getLeftChild() != nullptr)
	{
		printTree(out, height + 1, target->getLeftChild());
	}

	if (target->getRightChild() != nullptr)
	{
		printTree(out, height + 1, target->getRightChild());
	}
}
