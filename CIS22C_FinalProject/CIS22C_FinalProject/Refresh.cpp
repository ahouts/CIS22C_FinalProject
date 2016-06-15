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

	for (int i = 0; i < sheet->getXSize(); i++) {
		for (int p = 0; p < sheet->getYSize(); p++) {
			string *answer = new string[5];
			for (int i = 0; i < 5; i++)
			{
				answer[i] = "";
			}
			string line = sheet->getCellData(i, p);
			stringstream ssin(line);
			int count = 0;
			while (ssin.good() && count < 5)
			{
				ssin >> answer[count];
				count++;
			}
			if (answer[0] == "add") {
				sheet->setCellData(i, p, to_string(add(stod(answer[1]), stod(answer[2]), stod(answer[3]), stod(answer[4]))));
			}
			if (answer[0] == "multiply") {
				sheet->setCellData(i, p, to_string(multiply(stod(answer[1]), stod(answer[2]), stod(answer[3]), stod(answer[4]))));
			}
			if (answer[0] == "average") {
				sheet->setCellData(i, p, to_string(average(stod(answer[1]), stod(answer[2]), stod(answer[3]), stod(answer[4]))));
			}
			if (answer[0] == "subtract") {
				sheet->setCellData(i, p, to_string(subtract(stod(answer[1]), stod(answer[2]), stod(answer[3]), stod(answer[4]))));
			}
			if (answer[0] == "divide") {
				sheet->setCellData(i, p, to_string(divide(stod(answer[1]), stod(answer[2]), stod(answer[3]), stod(answer[4]))));
			}
			if (answer[0] == "sum") {
				sheet->setCellData(i, p, to_string(sum(stod(answer[1]), stod(answer[2]), stod(answer[3]), stod(answer[4]))));
			}
		}
	}
}

double Refresh::sum(int xCoord, int yCoord, int xCoord1, int yCoord1)
{
	double total = 0;
	if (xCoord <= xCoord1 && yCoord <= yCoord1)
	{
		for (int m = yCoord; m <= yCoord1; m--)
		{
			for (int i = xCoord; i <= xCoord1; i++)
			{
				try
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

				}
				catch (char e[])
				{
					//does nothing if it is out of bounds
				}
			}
			return (total);
		}
	}

	else if (xCoord >= xCoord1 && yCoord <= yCoord1)
	{
		for (int m = yCoord; m <= yCoord1; m--)
		{
			for (int i = xCoord; i <= xCoord1; i++)
			{
				try
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

				}
				catch (char e[])
				{
					//does nothing if it is out of bounds
				}
			}
			return (total);
		}
	}

	else if (xCoord <= xCoord1 && yCoord >= yCoord1)
	{
		for (int m = yCoord; m <= yCoord1; m--)
		{
			for (int i = xCoord; i <= xCoord1; i++)
			{
				try
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

				}
				catch (char e[])
				{
					//does nothing if it is out of bounds
				}
			}
			return (total);
		}
	}

	else if (xCoord >= xCoord1 && yCoord >= yCoord1)
	{
		for (int m = yCoord; m <= yCoord1; m--)
		{
			for (int i = xCoord; i <= xCoord1; i++)
			{
				try
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

				}
				catch (char e[])
				{
					//does nothing if it is out of bounds
				}
			}
			return (total);
		}
	}
}

double Refresh::add(int xCoord, int yCoord, int xCoord1, int yCoord1)
{
	double a = stod(sheet->getCellData(xCoord, yCoord));
	double b = stod(sheet->getCellData(xCoord1, yCoord1));
	double c = a + b;
	return c;
}

double Refresh::multiply(int xCoord, int yCoord, int xCoord1, int yCoord1)
{
	double a = stod(sheet->getCellData(xCoord, yCoord));
	double b = stod(sheet->getCellData(xCoord1, yCoord1));
	double c = a * b;
	return c;
}

double Refresh::subtract(int xCoord, int yCoord, int xCoord1, int yCoord1)
{
	double a = stod(sheet->getCellData(xCoord, yCoord));
	double b = stod(sheet->getCellData(xCoord1, yCoord1));
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
	for (int i = 0; i < x2 - x1; i++) {
		for (int j = 0; j < x2 - x1; j++) {
			if (sheet->getCellData(i, y) > sheet->getCellData(j, y)) {
				sheet->swapRow(i, j);
			}
		}
	}
}

void Refresh::sortCol(int y1, int y2, int x) {
	for (int i = 0; i < y2 - y1; i++) {
		for (int j = 0; j < y2 - y1; j++) {
			if (sheet->getCellData(x, i) > sheet->getCellData(x, j)) {
				sheet->swapRow(i, j);
			}
		}
	}
}
