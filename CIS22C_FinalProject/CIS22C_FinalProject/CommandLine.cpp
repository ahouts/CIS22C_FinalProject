#include "CommandLine.h"


void CommandLine::modifyCell(int xCoord, int yCoord, string data)
{
	sheet->setCellData(xCoord, yCoord, data);
}
void CommandLine::drawSheet(ostream& out) 
{
	for (int x = 0; x < sheet->getXSize; x++)
	{
		for (int y = 0; y < sheet->getYSize; y++)
		{
			out << sheet->getCellData(x, y);
		}
	}
}
void CommandLine::mainLoop()
{
	
	drawSheet(cout);
	cout << "enter the command you wish to do next: ";
	string masterString;
	getline(cin, masterString);
	
	string masterString("hello world this is andrew speaking");


	stringstream iss(masterString);

	while (iss)
	{
		string word[100];
		for (int i = 0; i < masterString.length(); i++)
		{
			iss >> word[i];
		}

		// || SET VALUE ||
		if (word[0] == "set")
		{
			if (stoi(word[1]))
			{
				int a = stoi(word[1]);
				if (stoi(word[2]))
				{
					int b = stoi(word[2]);
					modifyCell(a, b, word[3]);
				}
			}
		}
		
	}
}
