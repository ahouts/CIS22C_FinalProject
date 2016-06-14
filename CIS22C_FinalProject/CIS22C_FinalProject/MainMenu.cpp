#include "MainMenu.h"

MainMenu::MainMenu(Sheet *sheet) : commandLine(sheet)
{
	this->sheet = sheet;
}

void MainMenu::showMainMenu()
{
	bool done = false;
	while (!done)
	{
		system("CLS");
		cout << "What would you like to do?\n";
		cout << "1. create a new sheet.\n";
		cout << "2. open an existing sheet.\n";
		cout << "3. delete an existing sheet.\n";
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
			system("pause");
			string temp;
			cin >> temp;
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
	cout << "=> ";
	unsigned int x, y;
	cin >> x >> y;
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
	Sheet *sheet = new Sheet(1, 1);
	MainMenu menu = MainMenu(sheet);
	menu.showMainMenu();
	delete sheet;
	return 0;
}
