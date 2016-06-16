#include "CommandLine.h"

CommandLine::CommandLine(Sheet *sheet) : refresh(sheet)
{
	//initializes all the variables
	this->sheet = sheet; 
	change = Change();
	bst = BST();
	CELL_WIDTH = 12;
	COUNT_WIDTH = 4;
	CELLS_TO_DISPLAY_X = 12;
	CELLS_TO_DISPLAY_Y = 40;
}

void CommandLine::modifyCell(int xCoord, int yCoord, string data)
{
	//called when the data ina node needs to be changed
	sheet->setCellData(xCoord, yCoord, data);
}
void CommandLine::drawSheet(ostream& out)
{

	system("CLS");

	if (CELLS_TO_DISPLAY_X > sheet->getXSize())
	{
		CELLS_TO_DISPLAY_X = sheet->getXSize();
	}

	if (CELLS_TO_DISPLAY_Y > sheet->getYSize())
	{
		CELLS_TO_DISPLAY_Y = sheet->getYSize();
	}

	for (int countWidth = 0; countWidth <= COUNT_WIDTH; countWidth++)
	{
		out << " ";
	}

	for (int i = 0; i < CELLS_TO_DISPLAY_X; i++)
	{
		out << right << setw(CELL_WIDTH) << fixed << setprecision(3) << i << "|";
	}
	out << endl;
	
	for (int countWidth = 0; countWidth <= COUNT_WIDTH; countWidth++)
	{
		out << " ";
	}

	// goes thorugh both x and y values and plots the sheet for the user to see
	for (int i = 0; i < CELLS_TO_DISPLAY_X; i++) 
	{
		for (int cellWidth = 0; cellWidth <= CELL_WIDTH; cellWidth++)
		{
			out << "-";
		}
	}
	out << endl;

	for (int y = 0; y < CELLS_TO_DISPLAY_Y; y++)
	{
		out << left << setw(COUNT_WIDTH) << fixed << y << "|";
		for (int x = 0; x < CELLS_TO_DISPLAY_X; x++)
		{
			out << right << setw(CELL_WIDTH) << fixed << setprecision(3) << sheet->getCellData(x, y).substr(0, CELL_WIDTH);
			out << "|";
		}
		out << endl;
	}
}

void CommandLine::mainLoop(ostream &out, istream &in)
{
	CELL_WIDTH = 12;
	COUNT_WIDTH = 4;
	CELLS_TO_DISPLAY_X = 12;
	CELLS_TO_DISPLAY_Y = 40;

	string word1, string1;
	while (word1 != "exit")
	{
		refresh.findfunctions();
		drawSheet(cout);
		out << "=> ";
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
			Node* targetNode = NULL;

			cin >> searchstring;
			bst.generateTree(*sheet);
			targetNode = bst.search(searchstring, &bst.getHead(), sheet);
			if (targetNode == NULL) {
				cout << "Target not found" << endl;
				cin.ignore(1000, '\n');
				system("pause");
			}
			else {
				cout << "Target at:" << targetNode->getMeX() << ", " << targetNode->getMeY() << endl;
				cin.ignore(1000, '\n');
				system("pause"); 
			}
		}
		else if (word1 == "setfilepath")
		{
			string newFileName;

			cin >> newFileName;
			try
			{
				sheet->setFilePath(newFileName);
				cout << "File path changed successfully.\n";
				system("pause");
			}
			catch (...)
			{
				cout << "Unable to change file path.\n";
				system("pause");
			}
		}
		else if (word1 == "cellstodisplayx")
		{
			unsigned int toDisplay;
			cin >> toDisplay;
			if (toDisplay <= sheet->getXSize() && toDisplay > 0)
			{
				CELLS_TO_DISPLAY_X = toDisplay;
				cout << "X Axis cells to display set to " << toDisplay << ".\n";
				system("pause");
			}
			else
			{
				cout << "An invalid number of cells to display was given.\n";
				system("pause");
			}
		}
		else if (word1 == "cellstodisplayy")
		{
			unsigned int toDisplay;
			cin >> toDisplay;
			if (toDisplay <= sheet->getYSize() && toDisplay > 0)
			{
				CELLS_TO_DISPLAY_Y = toDisplay;
				cout << "Y Axis cells to display set to " << toDisplay << ".\n";
				system("pause");
			}
			else
			{
				cout << "An invalid number of cells to display was given.\n";
				system("pause");
			}
		}
		else if (word1 == "charstodisplay")
		{
			unsigned int toDisplay;
			cin >> toDisplay;
			if (toDisplay <= 40 && toDisplay > 1)
			{
				CELL_WIDTH = toDisplay;
				cout << "Now displaying " << toDisplay << " characters for each cell.\n";
				system("pause");
			}
			else
			{
				cout << "An invalid number of characters was provided.\n";
				system("pause");
			}
		}
		else if (word1 == "save")
		{
			try
			{
				sheet->toFile();
				cout << "Save of file " << sheet->getFilePath() << " successfully completed.\n";
				system("pause");
			}
			catch (...)
			{
				cout << "Failed to save file.\n";
				system("pause");
			}
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
		else if (word1 == "help")
		{
			system("cls");
			cout << "Commands:\n";
			cout << "set [int] [int] [string/int/double]\n";
			cout << "search [string/int/double]\n";
			cout << "sortrow [xCoord1] [xCoord2] [yCoord]\n";
			cout << "sortcol [yCoord1] [yCoord2] [xCoord]\n";
			cout << "undo\n";
			cout << "setfilepath [newFilePath]\n";
			cout << "cellstodisplayx [int]\n";
			cout << "cellstodisplayy [int]\n";
			cout << "charstodisplay [int]\n";
			cout << "save\n";
			cout << "exit\n";
			system("pause");
		}
		else
		{
			cout << "\nInvalid entry (type help for a list of commands)\n";
			cin.ignore(1000, '\n');
			system("pause");
		}
	}
	change.deleteStack();
}
