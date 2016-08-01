#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <string>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "Sheet.h"
#include "CommandLine.h"

using namespace std;

class MainMenu {
private:
    Sheet *sheet;
    Change *change;
    CommandLine commandLine;
public:
    MainMenu(Sheet *sheet, Change *change);

    void showMainMenu();

    void createSheet();

    void openSheet();

    void deleteSheet();
};

#endif