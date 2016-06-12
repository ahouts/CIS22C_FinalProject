#include "Refresh.h"


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