#include "CommandLine.h"

CommandLine::CommandLine(Sheet *sheet) : refresh(sheet)
{
	this->sheet = sheet;
	change = Change();
	bst = BST();
}

void CommandLine::modifyCell(int xCoord, int yCoord, string data)
{
	sheet->setCellData(xCoord, yCoord, data);
}
void CommandLine::drawSheet(ostream& out) 
{
	system("CLS");
	for (int y = 0; y < sheet->getXSize(); y++)
	{
		for (int x = 0; x < sheet->getYSize(); x++)
		{
			out << sheet->getCellData(x, y);
			out << " ";
		}
		out << endl;
	}
}

void CommandLine::mainLoop(ostream &out, istream &in)
{
	string masterString = "", string1 = "";
	while (masterString != "exit")
	{
		drawSheet(cout);
		out << "enter the command you wish to do next: ";
		string word1;
		cin >> word1;

		if (word1 == "set")
		{
			string word2, word3;
			cin >> word2 >> word3;
			if (stoi(word2))   //if the second word is convertable to an int, do so, and continue, otherwise gve an error
			{
				int a = stoi(word2);
				if (stoi(word3))    //if the third word is convertable to an int, do so, and continue, otherwise gve an error
				{
					int b = stoi(word3);

					cin.ignore(); 
					getline(cin, string1);  //takes a string of what to add into the correct cell


					change.pushBack(a, b, sheet->getCellData(a, b), string1);

					sheet->setCellData(a, b, string1);
				}
			}
		}
		else if (word1 == "undo")
		{
			change.undo(sheet);
		}
		else if (word1 == "search")
		{
			string searchstring;
			cin.ignore();
			getline(cin, searchstring);
			bst.search(searchstring, &bst.getHead());
		}
		else if (word1 == "save")
		{
			sheet->toFile();
		}
		else
		{
			cout << "invalid entry\n";
			
			cout << "enter the command you wish to do next: ";
			cin.ignore(1000, '\n');
			getline(cin, masterString);
		}
	}
}
