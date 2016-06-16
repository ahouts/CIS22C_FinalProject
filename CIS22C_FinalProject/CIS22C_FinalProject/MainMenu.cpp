#include "MainMenu.h"

MainMenu::MainMenu(Sheet *sheet, Change *change) : commandLine(sheet, change)
{
	this->sheet = sheet;
	this->change = change;
}

void MainMenu::showMainMenu()
{
	bool done = false;
	while (!done)
	{
		system("CLS");
		cout << "__      __ _       _              _       \n"
			<< "\\ \\    / /(_)     (_)            | |      \n"
			<< " \\ \\  / /  _  ___  _   ___  __ _ | |  ___ \n"
			<< "  \\ \\/ /  | |/ __|| | / __|/ _` || | / __|\n"
			<< "   \\  /   | |\\__ \\| || (__| (_| || || (__ \n"
			<< "    \\/    |_||___/|_| \\___|\\__,_||_| \\___|\n\n\n";
		cout << "Main Menu:\n\n";
		cout << "1. Create a New Sheet\n";
		cout << "2. Open an Existing Sheet\n";
		cout << "3. Delete an Existing Sheet.\n";
		cout << "0. Exit\n";
		cout << "=> ";
		string response = "-1";
		cin >> response;
		switch (response[0])
		{
		case '1':
			createSheet();
			break;
		case '2':
			openSheet();
			break;
		case '3':
			deleteSheet();
			break;
		case '0':
			cout << "Exiting...\n";
			done = true;
			break;
		default:
			system("CLS");
			cout << "You gave an invalid response.\n";
			cin.clear();
			system("pause");
			break;
		}
		cin.clear();
		cin.ignore();
	}
}

void MainMenu::createSheet()
{
	cout << "What is the path of the sheet you wish to create?\n";
	cout << "=> ";
	string response = "./default";
	cin >> response;
	sheet->setFilePath(response);
	cout << "What are the desired dimensions of the sheet?\n";
	unsigned int x, y;
	cout << "X size, (1-20) => ";
	cin >> x;
	cout << "Y size, (1-1000) => ";
	cin >> y;
	if (y < 1 || x < 1)
	{
		cout << "Invalid sheet size given." << endl;
		system("pause");
	}
	else
	{
		try
		{
			sheet->resizeSheet(x, y);
			cout << "Sheet successfully created.\n";
			commandLine.mainLoop(cout, cin);
		}
		catch (char e[])
		{
			cout << e << endl;
			system("pause");
		}
	}
}

void MainMenu::openSheet()
{
	cout << "What is the path of the sheet you wish to open?\n";
	cout << "=> ";
	string response = "./default";
	cin >> response;
	sheet->setFilePath(response);
	try
	{
		sheet->fromFile();
		cout << "Sheet successfully loaded.\n";
		commandLine.mainLoop(cout, cin);
	}
	catch (char e[])
	{
		cout << e;
		system("pause");
	}
}

void MainMenu::deleteSheet()
{
	cout << "What is the path of the sheet you wish to delete?\n";
	cout << "=> ";
	string response = "./default";
	cin >> response;
	if (remove(response.c_str()) != 0)
	{
		cout << "Error deleting file.\n";
		system("pause");
	}
	else
	{
		cout << "File successfully deleted.\n";
		system("pause");
	}
}

int main()
{
	HWND hwnd = GetConsoleWindow();
	if (hwnd != NULL) { MoveWindow(hwnd, 0, 0, 1280, 800, TRUE); }
	Change *change = new Change();
	Sheet *sheet = new Sheet(1, 1, change);
	MainMenu menu = MainMenu(sheet, change);
	menu.showMainMenu();
	delete sheet;
	return 0;
}
