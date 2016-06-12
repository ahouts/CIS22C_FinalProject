#include "CommandLine.h"


CommandLine::CommandLine(Sheet * sheet)
{
	this->sheet = sheet;
	change = Change();
	refresh = Refresh(sheet);
	bst = BST();
}

void CommandLine::modifyCell(int xCoord, int yCoord, string data)
{
	sheet->setCellData(xCoord, yCoord, data);
}
void CommandLine::drawSheet(ostream& out) 
{
	for (int x = 0; x < sheet->getXSize(); x++)
	{
		for (int y = 0; y < sheet->getYSize(); y++)
		{
			out << sheet->getCellData(x, y);
		}
	}
}

void CommandLine::mainLoop()
{
	string masterString, string1;
	while (masterString != "exit")
	{
		drawSheet(cout);
		cout << "enter the command you wish to do next: ";
		cin.ignore();
		getline(cin, masterString);

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

						cin.ignore();
						getline(cin, string1);


						change.pushBack(a, b, sheet->getCellData(a, b), string1);

						sheet->setCellData(a, b, string1);
					}
				}
			}
			else if (word[0] == "undo")
			{
				change.undo(sheet);
			}
			else if (word[0] == "search")
			{
				
			}
			else
			{
				cout << "invalid entry\n";
				system("pause");
			}
			}
		}
	}
