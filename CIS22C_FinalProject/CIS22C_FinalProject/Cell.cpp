#include "Cell.h"

string Cell::getData()
{
	return contents;
}

void Cell::setData(string in)
{
	contents = in;
}

Cell::Cell()
{
	contents = "";
	above = nullptr;
	left = nullptr;
	right = nullptr;
	below = nullptr;
}

Cell * Cell::getAbove()
{
	return above;
}

Cell * Cell::getLeft()
{
	return left;
}

Cell * Cell::getRight()
{
	return right;
}

Cell * Cell::getBelow()
{
	return below;
}

void Cell::setAbove(Cell * above)
{
	this->above = above;
}

void Cell::setLeft(Cell * left)
{
	this->left = left;
}

void Cell::setRight(Cell * right)
{
	this->right = right;
}

void Cell::setBelow(Cell * below)
{
	this->below = below;
}
