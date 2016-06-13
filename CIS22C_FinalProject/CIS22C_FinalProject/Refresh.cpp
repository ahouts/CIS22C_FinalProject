#include "Refresh.h"
#include "BST.h"

double Refresh::average(int xCoord, int yCoord, int xCoord1, int yCoord1)
{
	int itterations = 0;
	double total = 0;
	if (xCoord <= xCoord1 && yCoord <= yCoord1)
	{
		for (int m = yCoord; m <= yCoord1; m++)
		{
			for (int i = xCoord; i <= xCoord1; i++)
			{
				if (stoi(sheet->getCellData(i, m)))
				{
					try
					{
						int a = stoi(sheet->getCellData(i, m));
						total += a;
					}
					catch (char e[])
					{
						//does nothing if it is out of bounds
					}

				}
				itterations++;
			}
		}

		return (total / itterations);
	}

	else if (xCoord >= xCoord1 && yCoord <= yCoord1)
	{
		for (int m = yCoord; m <= yCoord1; m++)
		{
			for (int i = xCoord; i <= xCoord1; i--)
			{
				if (stoi(sheet->getCellData(i, m)))
				{
					try
					{
						int a = stoi(sheet->getCellData(i, m));
						total += a;
					}
					catch (char e[])
					{
						//does nothing if it is out of bounds
					}

				}
				itterations++;
			}
		}
		return (total / itterations);
	}

	else if (xCoord <= xCoord1 && yCoord >= yCoord1)
	{
		for (int m = yCoord; m <= yCoord1; m--)
		{
			for (int i = xCoord; i <= xCoord1; i++)
			{
				if (stoi(sheet->getCellData(i, m)))
				{
					try
					{
						int a = stoi(sheet->getCellData(i, m));
						total += a;
					}
					catch (char e[])
					{
						//does nothing if it is out of bounds
					}

				}
				itterations++;
			}
		}
		return (total / itterations);
	}

	else if (xCoord >= xCoord1 && yCoord >= yCoord1)
	{
		for (int m = yCoord; m <= yCoord1; m--)
		{
			for (int i = xCoord; i <= xCoord1; i--)
			{
				if (stoi(sheet->getCellData(i, m)))
				{
					try
					{
						int a = stoi(sheet->getCellData(i, m));
						total += a;
					}
					catch (char e[])
					{
						//does nothing if it is out of bounds
					}

				}
				itterations++;
			}
		}
		return (total / itterations);
	}
}

Refresh::Refresh(Sheet *sheet)
{
	this->sheet = sheet;
}

void Refresh::findfunctions()
{
	BST tokens;
	Node* target = &tokens.getHead();
	for (int i = 0; i < sheet->getXSize; i++) {
		for (int p = 0; p < sheet->getYSize; p++) {

		}
	}
}

double Refresh::add(int xCoord, int yCoord, int xCoord1, int yCoord1)
{
	int a = stoi(sheet->getCellData(xCoord, yCoord));
	int b = stoi(sheet->getCellData(xCoord1, yCoord1));
	double c = a+b;
	return c;
}

double Refresh::multiply(int xCoord, int yCoord, int xCoord1, int yCoord1)
{
	int a = stoi(sheet->getCellData(xCoord, yCoord));
	int b = stoi(sheet->getCellData(xCoord1, yCoord1));
	double c = a * b;
	return c;
}

double Refresh::subtract(int xCoord, int yCoord, int xCoord1, int yCoord1)
{
	int a = stoi(sheet->getCellData(xCoord, yCoord));
	int b = stoi(sheet->getCellData(xCoord1, yCoord1));
	double c = a - b;
	return c;
}

double Refresh::divide(int xCoord, int yCoord, int xCoord1, int yCoord1) {
	double a = stoi(sheet->getCellData(xCoord, yCoord));
	double b = stoi(sheet->getCellData(xCoord1, yCoord1));
	double c = a / b;
	return c;
}

void Refresh::sortRow(int x1, int x2, int y) {
	string* sorter;
	sorter = new string[x2 - x1];
	for (int i = 0; i < (x2 - x1); i++) {
		sorter[i] = sheet->getCellData(i, y);
	}
	for (int i = 0; i < (x2 - x1); i++) {
		for (int p = 0; p < i; p++) {
			if (sorter[i] > sorter[p]) {
				sheet->swapCol(i, p);
			}
		}
	}
}

void Refresh::sortCol(int y1, int y2, int x) {
	string* sorter;
	sorter = new string[y2 - y1];
	for (int i = 0; i < (y2 - y1); i++) {
		sorter[i] = sheet->getCellData(i, x);
	}
	for (int i = 0; i < (y2 - y1); i++) {
		for (int p = 0; p < i; p++) {
			if (sorter[i] > sorter[p]) {
				sheet->swapRow(i, p);
			}
		}
	}
}
