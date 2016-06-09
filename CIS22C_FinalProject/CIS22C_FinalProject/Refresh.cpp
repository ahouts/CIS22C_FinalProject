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

double Refresh::add(int xCoord, int yCoord, int xCoord1, int yCoord1)
{
	int itterations = 0;
	int total = 0;
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

			}

		}
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

			}

		}
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

			}

		}
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
			}
		}
		return total;
	}
}
double Refresh::multiply(int xCoord, int yCoord, int xCoord1, int yCoord1)
{

	int total = 1;
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
						total *= a;
					}
					catch (char e[])
					{
						//does nothing if it is out of bounds
					}

				}
			}
		}
		return total;
	}

	else if (xCoord >= xCoord1 && yCoord <= yCoord1)
	{
		for (int m = yCoord; m <= yCoord1; m++)
		{
			for (int i = xCoord; i >= xCoord1; i--)
			{
				if (stoi(sheet->getCellData(i, m)))
				{
					try
					{
						int a = stoi(sheet->getCellData(i, m));
						total *= a;
					}
					catch (char e[])
					{
						//does nothing if it is out of bounds
					}

				}
			}
		}
		return total;
	}

	else if (xCoord <= xCoord1 && yCoord >= yCoord1)
	{
		for (int m = yCoord; m >= yCoord1; m--)
		{
			for (int i = xCoord; i <= xCoord1; i++)
			{
				if (stoi(sheet->getCellData(i, m)))
				{
					try
					{
						int a = stoi(sheet->getCellData(i, m));
						total *= a;
					}
					catch (char e[])
					{
						//does nothing if it is out of bounds
					}

				}
			}
		}
		return total;
	}

	else if (xCoord >= xCoord1 && yCoord >= yCoord1)
	{
		for (int m = yCoord; m >= yCoord1; m--)
		{
			for (int i = xCoord; i >= xCoord1; i--)
			{
				if (stoi(sheet->getCellData(i, m)))
				{
					try
					{
						int a = stoi(sheet->getCellData(i, m));
						total *= a;
					}
					catch (char e[])
					{
						//does nothing if it is out of bounds
					}

				}
			}
		}
		return total;
	}
}