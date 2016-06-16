#include "Node1.h"

Node1::Node1()
{
	cell = nullptr;
	parent = nullptr;
	leftChild = nullptr;
	rightChild = nullptr;
}

Node1::~Node1()
{

}

Cell * Node1::getCell()
{
	return cell;
}

void Node1::setCell(Cell * cell)
{
	this->cell = cell;
}

Node1 * Node1::getParent()
{
	return parent;
}

void Node1::setParent(Node1 * parent)
{
	this->parent = parent;
}

Node1 * Node1::getLeftChild()
{
	return leftChild;
}

void Node1::setLeftChild(Node1 * leftChild)
{
	this->leftChild = leftChild;
}

Node1 * Node1::getRightChild()
{
	return rightChild;
}

void Node1::setRightChild(Node1 * rightChild)
{
	this->rightChild = rightChild;
}

void Node1::rotateRight()
{
	if (getLeftChild() != nullptr)
	{
		Node1 *leftChild = getLeftChild();
		Node1 *leftRightChild = leftChild->getRightChild();
		leftChild->setRightChild(this);
		leftChild->setParent(getParent());
		setParent(leftChild);
		setLeftChild(leftRightChild);
		if (leftRightChild != nullptr)
		{
			leftRightChild->setParent(this);
		}
	}
}

void Node1::rotateLeft()
{
	if (getRightChild() != nullptr)
	{
		Node1 *rightChild = getRightChild();
		Node1 *rightLeftChild = rightChild->getLeftChild();
		rightChild->setLeftChild(this);
		rightChild->setParent(getParent());
		setParent(rightChild);
		setRightChild(rightLeftChild);
		if (rightLeftChild != nullptr)
		{
			rightLeftChild->setParent(this);
		}
	}
}

/*
-2 = left of left
-1 = right of left
0 = balanced
1 = left of right
2 = right of right
*/
int Node1::getImbalance()
{
	if (getLeftChild() == nullptr)
	{
		if (getRightChild() != nullptr)
		{
			if (getRightChild()->getRightChild() != nullptr)
			{
				return 2;
			}
			if (getRightChild()->getLeftChild() != nullptr)
			{
				return 1;
			}
		}
	}
	else
	{
		if (getLeftChild()->getRightChild() == nullptr && getLeftChild()->getLeftChild() == nullptr)
		{
			if (getRightChild() != nullptr && getRightChild()->getRightChild() != nullptr && (getRightChild()->getRightChild()->getRightChild() == nullptr && getRightChild()->getRightChild()->getLeftChild() == nullptr))
			{
				return 2;
			}
			else if (getRightChild() != nullptr && getRightChild()->getLeftChild() != nullptr && (getRightChild()->getLeftChild()->getRightChild() == nullptr && getRightChild()->getLeftChild()->getLeftChild() == nullptr))
			{
				return 1;
			}
		}
	}

	if (getRightChild() == nullptr)
	{
		if (getLeftChild() != nullptr)
		{
			if (getLeftChild()->getLeftChild() != nullptr)
			{
				return -2;
			}
			if (getLeftChild()->getRightChild() != nullptr)
			{
				return -1;
			}
		}
	}
	else
	{
		if (getRightChild()->getLeftChild() == nullptr && getRightChild()->getRightChild() == nullptr)
		{
			if (getLeftChild() != nullptr && getLeftChild()->getLeftChild() != nullptr && (getLeftChild()->getLeftChild()->getLeftChild() == nullptr && getLeftChild()->getLeftChild()->getRightChild() == nullptr))
			{
				return -2;
			}
			else if (getLeftChild() != nullptr && getLeftChild()->getRightChild() != nullptr && (getLeftChild()->getRightChild()->getLeftChild() == nullptr && getLeftChild()->getRightChild()->getRightChild() == nullptr))
			{
				return -1;
			}
		}
	}
	return 0;
}
