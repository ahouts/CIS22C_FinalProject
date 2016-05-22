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
