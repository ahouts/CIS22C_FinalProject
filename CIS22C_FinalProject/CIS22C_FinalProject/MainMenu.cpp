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
	sheet->resizeSheet(x, y);
	cout << "Sheet successfully created.\n";
	commandLine.mainLoop(cout, cin);
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

void SetWindow(int Width, int Height)
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle 
	SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size 
	SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size 
}

int main()
{
	SetWindow(300, 200);
	Sheet *sheet = new Sheet(1, 1);
	MainMenu menu = MainMenu(sheet);
	menu.showMainMenu();
	delete sheet;
}