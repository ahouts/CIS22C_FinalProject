#include "Sheet.h"

Sheet::Sheet(int xSize, int ySize)
{
	initializeSheet(xSize, ySize);
	generateHashTable();
	filePath = "./spreadsheet.dat";
	dummyCell = new Cell();
	dummyCell->setData("this is the forbidden text");
};

Sheet::~Sheet()
{
	wipeSheet();
	delete[] hashTable;
	delete dummyCell;
};

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
	int index = getHashIndex(x, y, hashTableMultiplier, hashTableAddition, hashTableSize);
	Cell *data = hashTable[index];
	while (!(data->getXCoord() == x && data->getYCoord() == y))
	{
		index = quadraticResolution(index, hashTableSize);
		data = hashTable[index];
	}

	return data;
};

void Sheet::generateHashTable()
{
 	hashTableSize = getPrimeGreaterThan(xSize * ySize * HASH_TABLE_SIZE_MULTIPLIER);
	if (hashTableSize > 500)
	{
		hashTableMultiplier = getPrimeGreaterThan(hashTableSize / 50);
	}
	else
	{
		hashTableMultiplier = 13;
	}
	if (hashTableSize > 500)
	{
		hashTableAddition = getPrimeGreaterThan(hashTableSize / 70);
	}
	else
	{
		hashTableAddition = 7;
	}

	hashTable = new Cell*[hashTableSize];		// create a hash table to store cell pointers in

	for (int i = 0; i < hashTableSize; i++)			// set all pointers in hash table to null
	{
		hashTable[i] = nullptr;
	}

	for (int j = 0; j < ySize; j++)
	{
		for (int i = 0; i < xSize; i++)
		{
			int cellX = nonHashSearch(i, j)->getXCoord();
			int cellY = nonHashSearch(i, j)->getYCoord();
			int index = getHashIndex(cellX, cellY, hashTableMultiplier, hashTableAddition, hashTableSize);
			if (hashTable[index] == nullptr)
			{
				hashTable[index] = nonHashSearch(i, j);
			}
			else
			{
				bool done = false;
				int count = 0;
				while (!done && count < MAX_RESOLUTION_ATTEMPTS)
				{
					index = quadraticResolution(index, hashTableSize);
 					if (hashTable[index] == nullptr)
					{
						hashTable[index] = nonHashSearch(i, j);
						done = true;
					}
					else
					{
						count++;
					}
				}
				if (count == MAX_RESOLUTION_ATTEMPTS)
				{
					char error[] = "Hash resolution took too many cycles.\n";
					throw error;
				}
			}
		}
	}
};

Cell * Sheet::nonHashSearch(int x, int y)
{
	if (x >= xSize || x < 0)
	{
		char error[] = "Sheet passed an index x that is out of bounds.\n";
		throw error;
	}
	if (y >= ySize || y < 0)
	{
		char error[] = "Sheet passed an index y that is out of bounds.\n";
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
};


void Sheet::setCellData(int x, int y, string str)
{
	operator()(x, y)->setData(str);
};

string Sheet::getCellData(int x, int y)
{
	return operator()(x, y)->getData();
};

void Sheet::toFile()
{
	ofstream fout = ofstream();
	fout.open(filePath);
	if (fout.fail())
	{
		char error[] = "Failed to open file for writing.\n";
		throw error;
	}

	fout << xSize << endl;
	fout << ySize << endl;
	fout << hashTableSize << endl;
	fout << hashTableMultiplier << endl;
	fout << hashTableAddition << endl;

	for (int i = 0; i < hashTableSize; i++)
	{
		if (hashTable[i] != nullptr)
		{
			fout << i << " ";
			Cell *temp = hashTable[i];
			fout << temp->getXCoord() << " ";
			fout << temp->getYCoord() << " ";
			fout << temp->getData() << endl;
		}
		else
		{
			fout << i << endl;
		}
	}

	fout.close();
};

void Sheet::fromFile()
{
	ifstream fin = ifstream();
	fin.open(filePath);
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

	for (int j = 0; j < ySize; j++)
	{
		for (int i = 0; i < xSize; i++)
		{
			int index = getHashIndex(i, j, hashTableModifier, hashTableAddition, hashTableSize);

			string *data = getIndexData(fin, index);
			
			if (data[3] == "")
			{
				// do nothing
			}
			else if (stoi(data[1]) == i && stoi(data[2]) == j)
			{
				nonHashSearch(i, j)->setData(data[3]);
			}
			else
			{
				bool done = false;
				int count = 0;
				while (!done && count < MAX_RESOLUTION_ATTEMPTS)
				{
					index = quadraticResolution(index, hashTableSize);
					string *data2 = getIndexData(fin, index);

					if (data[3] == "")
					{
						done = true;
					}
					else if (stoi(data[1]) == i && stoi(data[2]) == j)
					{
						setCellData(i, j, data[3]);
						done = true;
					}
					else
					{
						count++;
					}
					delete[] data2;
				}
			}
			delete[] data;
		}
	}

	generateHashTable();
};

void Sheet::swapRow(int y1, int y2)
{
	string *row = new string[xSize];

	Cell *temp = operator()(0, y2);
	for (int i = 0; i < xSize; i++)
	{
		row[i] = temp->getData();
		temp = temp->getRight();
	}

	temp = operator()(0, y1);
	Cell *temp2 = operator()(0, y2);
	for (int i = 0; i < xSize; i++)
	{
		setCellData(temp2->getXCoord(), temp2->getYCoord(), temp->getData());
		temp = temp->getRight();
		temp2 = temp2->getRight();
	}

	temp = operator()(0, y1);
	for (int i = 0; i < xSize; i++)
	{
		setCellData(temp->getXCoord(), temp->getYCoord(), row[i]);
		temp = temp->getRight();
	}

	delete[] row;
};

void Sheet::swapCol(int x1, int x2)
{
	string *col = new string[ySize];

	Cell *temp = operator()(0, x2);
	for (int i = 0; i < ySize; i++)
	{
		col[i] = temp->getData();
		temp = temp->getBelow();
	}

	temp = operator()(0, x1);
	Cell *temp2 = operator()(0, x2);
	for (int i = 0; i < ySize; i++)
	{
		setCellData(temp2->getXCoord(), temp2->getYCoord(), temp->getData());
		temp = temp->getBelow();
		temp2 = temp2->getBelow();
	}

	temp = operator()(0, x1);
	for (int i = 0; i < ySize; i++)
	{
		setCellData(temp->getXCoord(), temp->getYCoord(), col[i]);
		temp = temp->getBelow();
	}

	delete[] col;
};

int Sheet::getXSize()
{
	return xSize;
};

int Sheet::getYSize()
{
	return ySize;
};

string Sheet::getFilePath()
{
	return filePath;
};

void Sheet::setFilePath(string filePath)
{
	this->filePath = filePath;
};

void Sheet::resizeSheet(int xSize, int ySize)
{
	wipeSheet();
	initializeSheet(xSize, ySize);
	generateHashTable();
};

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

	for (int j = 0; j < ySize; j++)
	{
		for (int i = 0; i < xSize; i++)
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
};

void Sheet::wipeSheet()
{
	Cell *currentRow = headerCell;
	Cell *nextRow = headerCell;
	for (int j = 0; j < ySize; j++)
	{
		if (j < ySize - 1)
		{
			nextRow = currentRow->getBelow();
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
};

int Sheet::index(int x, int y, int width)
{
	return x + width * y;
};

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
};

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
};

int Sheet::getHashIndex(int cellXIndex, int cellYIndex , int multiplier, int addition, int hashTableSize)
{
	int temp = abs((cellXIndex + addition * cellYIndex - multiplier) * multiplier + addition);
	return temp % hashTableSize;
};

int Sheet::quadraticResolution(int index, int hashTableSize)
{
	return index * index % hashTableSize;
};

string * Sheet::getIndexData(ifstream & file, int index)
{
	file.clear();
	file.seekg(0, ios::beg);

	int junk;
	file >> junk >> junk >> junk >> junk >> junk;

	string *answer = new string[4];
	for (int i = 0; i < 4; i++)
	{
		answer[i] = "";
	}

	file.ignore();
	do
	{
		string data;
		getline(file, data);

		for (int i = 0; i < 4; i++)
		{
			answer[i] = "";
		}

		stringstream ssin(data);
		int i = 0;
		while (ssin.good() && i < 4)
		{
			ssin >> answer[i];
			++i;
		}
	} while (stoi(answer[0]) != index && file.good());

	if (stoi(answer[0]) != index)
	{
		for (int i = 0; i < 4; i++)
		{
			answer[i] = "";
		}
	}
	return answer;
};
