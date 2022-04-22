#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

#include "Menu.h"

void Menu::displayMenu() {
	cout << "************** Menu **************" << endl;
	cout << "1: Display a list of each item purchased and the number of times it was purchased" << endl;
	cout << "2: Display the number of times a specific item was purchased" << endl;
	cout << "3: Display a text-based histogram representing the number of times each item was purchased" << endl;
	cout << "4: Exit" << endl;
};

string Menu::promtUserMenuOption() {
	return "Enter your selection as a number 1, 2, 3, or 4: ";
}

string Menu::promptUserProduceItemName() {
	return "Enter the name of the produce item: ";
}

void Menu::clearScreen() {
	system("CLS"); // clear the screen
}

string Menu::validateUserEntryString(string prompt) {
	string userInput;
	bool inputError = false;

	do {
		inputError = false;
		cout << prompt;
		cin >> userInput;
		if (cin.fail()) {
			cout << "The value entered is invalid." << endl;
			inputError = true;
		}
		if (inputError) {
			// prepare for a new user entry
			cin.clear();
			cin.ignore();
		}
	} while (inputError);

	return userInput;
}

int Menu::validateUserEntryMenuOption(string prompt) {
	int userInput;
	bool inputError = false;

	do {
		inputError = false;
		cout << prompt;
		cin >> userInput;
		if (cin.fail()) {
			cout << "The value entered is invalid." << endl;
			inputError = true;
		}
		else {
			switch (userInput) {
				case 1:
				case 2:
				case 3:
				case 4:
					break;
				default:
					cout << "The value entered is not a valid menu option." << endl;
					inputError = true;
					break;
				}
		}
		if (inputError) {
			// prepare for a new user entry
			cin.clear();
			cin.ignore();
		}
	} while (inputError);

	return userInput;
}

void Menu::printProduceHistogram(string inputFileName) {
	
	// variable declarations
	string lineItem;
	string produceItem;
	int produceCount;
	ifstream inputFS;

	inputFS.open(inputFileName);
	if (!inputFS.is_open()) {
		cout << "Failed to open " + inputFileName << endl;
		return;
	}

	inputFS >> produceItem; // get name of item
	while (!inputFS.fail()) {
		inputFS >> produceCount; // get item frequency
		cout << produceItem << " " << setw(produceCount) << setfill('*') << "" << endl; // print item name and histogram graphic
		inputFS >> produceItem; // attempt to get the next item
	}

	inputFS.close();
}