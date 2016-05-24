#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <string>
#include "Sheet.h"
using namespace std;

class MainMenu
{
private:
	Sheet *sheet;
public:
	MainMenu(Sheet *sheet);
	void showMainMenu();
	void createSheet(string path);
	void openSheet(string path);
	void deleteSheet(string path);
};

#endif