#include "Sheet.h"

Sheet::Sheet(int xSize, int ySize)
{
	initializeSheet(xSize, ySize);
}

Sheet::~Sheet()
{
	wipeSheet();
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

void Sheet::toFile(string fileName)
{
	const double HASH_TABLE_MULTIPLIER = 1.5;
	const int HASH_TABLE_SIZE = getPrimeGreaterThan(xSize * ySize * HASH_TABLE_MULTIPLIER);
	int hashTableMultiplier;
	if (HASH_TABLE_SIZE > 500)
	{
		hashTableMultiplier = getPrimeGreaterThan(HASH_TABLE_SIZE / 50);
	}
	else
	{
		hashTableMultiplier = 13;
	}
	int hashTableAddition;
	if (HASH_TABLE_SIZE > 500)
	{
		hashTableAddition = getPrimeGreaterThan(HASH_TABLE_SIZE / 70);
	}
	else
	{
		hashTableAddition = 7;
	}

	Cell **hashTable = new Cell*[HASH_TABLE_SIZE];		// create a hash table to store cell pointers in

	for (int j = 0; j < ySize; j++)
	{
		for (int i = 0; i < xSize; i++)
		{
			string cellData = operator()(i, j)->getData();
			int index = hashCell(cellData, hashTableMultiplier, hashTableAddition, HASH_TABLE_SIZE);
			if (hashTable[index] == nullptr)
			{
				hashTable[index] = operator()(i, j);
			}
			else
			{
				bool done = false;
				int count = 0;
				int maxCount = 10;
				while (!done && count < maxCount)
				{
					index = quadraticResolution(index, HASH_TABLE_SIZE);
					if (hashTable[index] == nullptr)
					{
						hashTable[index] = operator()(i, j);
						done == true;
					}
					else
					{
						count++;
					}
				}
				if (count == maxCount)
				{
					char error[] = "Hash resolution took too many cycles.\n";
					throw error;
				}
			}
		}
	}

	ofstream fout = ofstream();
	fout.open(fileName);
	if (fout.fail())
	{
		char error[] = "Failed to open file for writing.\n";
		throw error;
	}

	fout << xSize << endl;
	fout << ySize << endl;
	fout << HASH_TABLE_SIZE << endl;
	fout << hashTableMultiplier << endl;
	fout << hashTableAddition << endl;

	for (int i = 0; i < HASH_TABLE_SIZE; i++)
	{
		if (hashTable[i] != nullptr)
		{
			Cell *temp = hashTable[i];
			fout << temp->getData() << endl;
			fout << temp->getAbove() << endl;
			fout << temp->getBelow() << endl;
			fout << temp->getLeft() << endl;
			fout << temp->getRight() << endl;
		}
	}

	fout.close();
	delete[] hashTable;
}

void Sheet::fromFile(string fileName)
{
	ifstream fin = ifstream();
	fin.open(fileName);
	if (fin.fail())
	{
		char error[] = "Failed to open file for writing.\n";
		throw error;
	}
	int xSize;
	int ySize;
	int hashTableSize;
	int hashTableModifier;
	int hashTableAddition;
	fin >> xSize;
	fin >> ySize;
	fin >> hashTableSize;
	fin >> hashTableModifier;
	fin >> hashTableAddition;

	resizeSheet(xSize, ySize);

	for (int i = 0; i < hashTableSize; i++)
	{
		// how do we read from hashed file?
	}
}

void Sheet::resizeSheet(int xSize, int ySize)
{
	wipeSheet();
	initializeSheet(xSize, ySize);
}

void Sheet::initializeSheet(int xSize, int ySize)
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

	for (int i = 0; i < ySize; i++)
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

void Sheet::wipeSheet()
{
	Cell *currentRow = headerCell;
	Cell *nextRow = headerCell;
	for (int j = 0; j < ySize; j++)
	{
		if (j < ySize - 1)
		{
			nextRow = operator()(0, j + 1);
		}
		Cell *nextCell = currentRow;
		for (int i = 0; i < xSize; i++)
		{
			Cell *currentCell = nextCell;
			nextCell = nextCell->getRight();
			delete currentCell;
		}
		currentRow = nextRow;
	}
}

int Sheet::index(int x, int y, int width)
{
	return x + width * y;
}

bool Sheet::isPrime(int number)
{
	bool flag = false;
	for (int i = 2; i < number / 2; i++)
	{
		if (number % i == 0)
		{
			flag = true;
		}
	}
	return !flag;
}

int Sheet::getPrimeGreaterThan(int number)
{
	if (number <= 1)
	{
		char error[] = "Invalid number passed into getPrimeGreaterThan().\n";
		throw error;
	}
	int count = number + 1;
	while (!isPrime(count))
	{
		count++;
	}
	return count;
}

int Sheet::hashCell(string cellData, int multiplier, int addition, int hashTableSize)
{
	int temp = 0;
	for (int i = 0; i < cellData.length(); i++)
	{
		temp += (int)cellData[i];
	}
	return (temp * multiplier + addition) % hashTableSize;
}

int Sheet::quadraticResolution(int index, int hashTableSize)
{
	return index * index % hashTableSize;
}
