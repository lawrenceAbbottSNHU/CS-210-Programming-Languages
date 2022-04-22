#ifndef MENU_H
#define MENU_H

class Menu {
	public:
		void displayMenu();
		string promtUserMenuOption();
		string promptUserProduceItemName();
		string validateUserEntryString(string);
		int validateUserEntryMenuOption(string);
		void printProduceHistogram(string);
		void clearScreen();
};

#endif