#include <Python.h>
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <cmath>
#include <string>

using namespace std;

#include "Menu.h"
#include "PythonApi.h"

int main()
{
	// variable declarations
	int menuInput;
	bool exit = false;
	Menu* produceMenu = nullptr;
	PythonApi* pythonInterface = nullptr;
	string readFileName = "input.txt";
	string produceItem;

	produceMenu->displayMenu(); // display options
	cout << endl;
	menuInput = produceMenu->validateUserEntryMenuOption(produceMenu->promtUserMenuOption()); // prompt user for input, validate, store value

	while (exit != true) {
		switch (menuInput) {
		case 1: // frequency of each produce item
			produceMenu->clearScreen();
			pythonInterface->CallIntFunc("frequency_of_each_item", readFileName); // use Python to print a list of items and purchase counts
			break;
		case 2: // frequency of a specific produce item
			produceMenu->clearScreen();
			produceItem = produceMenu->validateUserEntryString(produceMenu->promptUserProduceItemName()); // prompt user for the name of a produce item, validate, store value
			cout << pythonInterface->CallIntFunc("frequency_of_specific_item", readFileName + " " + produceItem) << endl; // print the returned frequency from Python result
			break;
		case 3: // print histogram of each produce item
			produceMenu->clearScreen();
			pythonInterface->CallIntFunc("histogram_preperation", readFileName); // use Python to create a list of items purchased and output to a file
			produceMenu->printProduceHistogram("frequency.dat"); // use the file output by Python to print histogram
			break;
		case 4:
			exit = true;
			break;
		}

		if (exit) {
			delete produceMenu; // clean up
			delete pythonInterface; // clean up
			cout << endl << "Goodbye! Have a nice day!" << endl; // print a farewell message for the user
			break;
		}

		cout << endl; // skip space to separate the menu from the previous output
		produceMenu->displayMenu(); // display options
		cout << endl;
		menuInput = produceMenu->validateUserEntryMenuOption(produceMenu->promtUserMenuOption()); // prompt user for input, validate, store value
	}

	return 0;
}