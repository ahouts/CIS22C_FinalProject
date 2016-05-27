#include "Sheet.h"

// for *arr in the initializer
int index(int x, int y, int width)
{
	return x + width * y;
}

Sheet::Sheet(int xSize, int ySize)
{
	if (xSize <= 0 || ySize <= 0)
	{
		char error[] = "Invalid size chosen for Sheet.\n";
		throw error;
	}
	this->xSize = xSize;
	this->ySize = ySize;

	// create a dynamically allocated array of pointers
	Cell **arr = new Cell*[xSize * ySize];

	// initialize all cells
	for (int i = 0; i < xSize * ySize; i++)
	{
		arr[i] = new Cell();
	}
	
	for (int i = 0; i < xSize; i++)
	{
		for (int j = 0; j < xSize; j++)
		{
			// go through and form 2 way linkage between every cell above and to the left of the current cell
			if (i > 0 && j > 0)
			{
				arr[index(i, j, xSize)]->setLeft(arr[index(i - 1, j, xSize)]);
				arr[index(i - 1, j, xSize)]->setRight(arr[index(i, j, xSize)]);
				arr[index(i, j, xSize)]->setAbove(arr[index(i, j - 1, xSize)]);
				arr[index(i, j - 1, xSize)]->setBelow(arr[index(i, j, xSize)]);
			}
			else if (i > 0)
			{
				arr[index(i, j, xSize)]->setLeft(arr[index(i - 1, j, xSize)]);
				arr[index(i - 1, j, xSize)]->setRight(arr[index(i, j, xSize)]);
			}
			else if (j > 0)
			{
				arr[index(i, j, xSize)]->setAbove(arr[index(i, j - 1, xSize)]);
				arr[index(i, j - 1, xSize)]->setBelow(arr[index(i, j, xSize)]);
			}
			else
			{

			}
		}
	}
	headerCell = arr[0];
	// delete the array of pointers
	delete[] arr;
}

Cell * Sheet::operator()(int x, int y)
{
	if (x >= xSize || x < 0)
	{
		char error[] = "Index x is out of bounds.\n";
		throw error;
	}
	if (y >= ySize || y < 0)
	{
		char error[] = "Index y is out of bounds.\n";
		throw error;
	}
	Cell *temp = headerCell;
	for (int i = 0; i < x; i++)
	{
		temp = temp->getRight();
	}
	for (int i = 0; i < y; i++)
	{
		temp = temp->getBelow();
	}
	return temp;
}
