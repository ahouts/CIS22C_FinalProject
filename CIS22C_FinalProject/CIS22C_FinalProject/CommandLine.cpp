#include "CommandLine.h"

CommandLine::CommandLine(Sheet *sheet) : refresh(sheet)
{
	//initializes all the variables
	this->sheet = sheet; 
	change = Change();
	bst = BST();
}

void CommandLine::modifyCell(int xCoord, int yCoord, string data)
{
	//called when the data ina node needs to be changed
	sheet->setCellData(xCoord, yCoord, data);
}
void CommandLine::drawSheet(ostream& out)
{

	system("CLS");

	out << "     ";
	for (int i = 0; i < sheet->getXSize(); i++)
	{
		out << right << setw(8) << fixed << setprecision(3) << i << "|";
	}
	out << endl;
	
	out << "     ";
	// goes thorugh both x and y values and plots the sheet for the user to see
	for (int i = 0; i < sheet->getXSize(); i++) 
	{
		out << "---------";
	}
	out << endl;

	for (int y = 0; y < sheet->getYSize(); y++)
	{
		out << left << setw(4) << fixed << y << "|";
		for (int x = 0; x < sheet->getXSize(); x++)
		{
			out << right << setw(8) << fixed << setprecision(3) << sheet->getCellData(x, y).substr(0, 8);
			out << "|";
		}
		out << endl;
	}
}

void CommandLine::mainLoop(ostream &out, istream &in)
{
	string word1, string1;
	while (word1 != "exit")
	{
		refresh.findfunctions();
		drawSheet(cout);
		out << "enter the command you wish to do next: ";
		cin >> word1;

		if (word1 == "set")
		{
			string word2, word3;
			cin >> word2 >> word3;
			try
			{
				if (stoi(word2) || stoi(word2) == 0)//if the second word is convertable to an int, do so, and continue, otherwise gve an error
				{
					int a = stoi(word2);
					try
					{
						if (stoi(word3) || stoi(word3) == 0)    //if the third word is convertable to an int, do so, and continue, otherwise gve an error
						{
							int b = stoi(word3);

							cin.ignore();
							getline(cin, string1);  //takes a string of what to add into the correct cell



							if (a >= sheet->getXSize() || b >= sheet->getYSize())
							{
								cout << "one or more values are out of bounds.";
								system("pause");
							}
							else
							{
								change.pushBack(a, b, sheet->getCellData(a, b), string1);
								sheet->setCellData(a, b, string1);
							}

						}
					}
					catch (std::invalid_argument)
					{
						cout << "invalid 'Y' value entered\n";
						cin.ignore(1000, '\n');
						system("pause");
					}
				}
			}
			catch (std::invalid_argument)
			{
				cout << "invalid 'X' value entered\n";
				cin.ignore(1000, '\n');
				system("pause");
			}
		}
		else if (word1 == "undo")
		{
			try
			{
				change.undo(sheet);
				// successfully undone
			}
  			catch (char e[])
			{
				cout << "\nChange Log Empty\n";
				cin.ignore(1000, '\n');
				system("pause");
			}
		}
		else if (word1 == "search")
		{
			string searchstring;

			cin >> searchstring;
			bst.search(searchstring, &bst.getHead(), sheet);
		}
		else if (word1 == "save")
		{
			sheet->toFile();
		}
		else if (word1 == "exit")
		{
			// do nothing
		}
		else if (word1 == "sortrow") {
			int x1, x2, y;
			cin >> x1 >> x2 >> y;
			refresh.sortRow(x1, x2, y);
		}
		else if (word1 == "sortcol") {
			int x1, x2, y;
			cin >> x1 >> x2 >> y;
			refresh.sortCol(x1, x2, y);
		}
		else
		{
			cout << "\ninvalid entry\n";
			cin.ignore(1000, '\n');
			system("pause");
		}
	}
	change.deleteStack();
}
