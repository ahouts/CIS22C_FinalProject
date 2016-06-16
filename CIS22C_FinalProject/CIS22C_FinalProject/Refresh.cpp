#include "Refresh.h"

double Refresh::average(int xCoord, int yCoord, int xCoord1, int yCoord1)
{
	sheet->changeOpenParen();
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
		sheet->changeCloseParen();
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
		sheet->changeCloseParen();
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
		sheet->changeCloseParen();
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
		sheet->changeCloseParen();
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
			bool condition, condition2;
			try
			{
				condition = (stoi(answer[1]) == i&&stoi(answer[2]) == p || stoi(answer[3]) == i&&stoi(answer[4]) == p);
				condition2 = i >= stoi(answer[1]) && i <= stoi(answer[3]) || p >= stoi(answer[2]) && p <= stoi(answer[4]);
				if (answer[0] == "add") {
					if (condition) {
						sheet->setCellData(i, p, "recursive");
					}
					else {
						sheet->setCellData(i, p, to_string(add(stod(answer[1]), stod(answer[2]), stod(answer[3]), stod(answer[4]))));
					}
				}
				if (answer[0] == "multiply") {
					if (condition) {
						sheet->setCellData(i, p, "recursive");
					}
					else {
						sheet->setCellData(i, p, to_string(multiply(stod(answer[1]), stod(answer[2]), stod(answer[3]), stod(answer[4]))));
					}
				}
				if (answer[0] == "average") {
					if (condition)
					{
						sheet->setCellData(i, p, "recursive");
					}
					else {
						sheet->setCellData(i, p, to_string(average(stod(answer[1]), stod(answer[2]), stod(answer[3]), stod(answer[4]))));
					}
				}
				if (answer[0] == "subtract") {
					if (condition) {
						sheet->setCellData(i, p, "recursive");
					}
					else {
						sheet->setCellData(i, p, to_string(subtract(stod(answer[1]), stod(answer[2]), stod(answer[3]), stod(answer[4]))));
					}
				}
				if (answer[0] == "divide") {
					if (condition) {
						sheet->setCellData(i, p, "recursive");
					}
					else {
						sheet->setCellData(i, p, to_string(divide(stod(answer[1]), stod(answer[2]), stod(answer[3]), stod(answer[4]))));
					}
				}
				if (answer[0] == "sum") {
					if (condition2)
					{
						sheet->setCellData(i, p, "recursive");
					}
					else {
						sheet->setCellData(i, p, to_string(sum(stod(answer[1]), stod(answer[2]), stod(answer[3]), stod(answer[4]))));
					}
				}
			}
			catch (...)
			{
				
			}
		}
	}
}

double Refresh::sum(int xCoord, int yCoord, int xCoord1, int yCoord1)

{
	sheet->changeOpenParen();
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
		sheet->changeCloseParen();
		return total;
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
		sheet->changeCloseParen();
		return total;
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
		sheet->changeCloseParen();
		return total;
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
		sheet->changeCloseParen();
		return total;
	}
}

double Refresh::add(int xCoord, int yCoord, int xCoord1, int yCoord1)
{
	double a, b;
	try
	{
		a = stod(sheet->getCellData(xCoord, yCoord));
		b = stod(sheet->getCellData(xCoord1, yCoord1));
	}
	catch (...)
	{
		return -1;
	}

	double c = a + b;
	return c;
}

double Refresh::multiply(int xCoord, int yCoord, int xCoord1, int yCoord1)
{
	double a, b;

	try
	{
		a = stod(sheet->getCellData(xCoord, yCoord));
		b = stod(sheet->getCellData(xCoord1, yCoord1));
	}
	catch (...)
	{
		return -1;
	}
	double c = a * b;
	return c;
}

double Refresh::subtract(int xCoord, int yCoord, int xCoord1, int yCoord1)
{
	double a, b;
	
	try
	{
		a = stod(sheet->getCellData(xCoord, yCoord));
		b = stod(sheet->getCellData(xCoord1, yCoord1));
	}
	catch (std::invalid_argument)
	{
		return -1;
	}
	catch (std::out_of_range)
	{
		return -1;
	}
	double c = a - b;
	return c;
}

double Refresh::divide(int xCoord, int yCoord, int xCoord1, int yCoord1) 
{
	double a, b;
	
	try
	{
		a = stod(sheet->getCellData(xCoord, yCoord));
		b = stod(sheet->getCellData(xCoord1, yCoord1));
	}
	catch (std::invalid_argument)
	{
		return -1;
	}
	catch (std::out_of_range)
	{
		return -1;
	}
	double c = a / b;
	return c;
}

void Refresh::sortRow(int x1, int x2, int y) {
	sheet->changeOpenParen();
	for (int i = 0; i <= x2 - x1; i++) {
		for (int j = 0; j <= x2 - x1; j++) {
			if (sheet->getCellData(i, y) > sheet->getCellData(j, y)) {
				sheet->swapRow(i, j);
			}
		}
	}
	sheet->changeCloseParen();
}

void Refresh::sortCol(int y1, int y2, int x) {
	sheet->changeOpenParen();
	for (int i = 0; i <= y2 - y1; i++) {
		for (int j = 0; j <= y2 - y1; j++) {
			if (sheet->getCellData(x, i) > sheet->getCellData(x, j)) {
				sheet->swapRow(i, j);
			}
		}
	}
	sheet->changeCloseParen();
}
