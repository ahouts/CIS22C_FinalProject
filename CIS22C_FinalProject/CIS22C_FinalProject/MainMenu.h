#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <string>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "Sheet.h"
#include "CommandLine.h"
using namespace std;

class MainMenu
{
private:
	Sheet *sheet;
	CommandLine commandLine;
public:
	MainMenu(Sheet *sheet);
	void showMainMenu();
	void createSheet();
	void openSheet();
	void deleteSheet();
};

#endif