#include "menu.h"
#include "linkedlist.h"
#include <stdlib.h>
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	// Classes Declaration
	Menu menu;

	// Create LinkedList
	LinkedList Linlist;

	// Method Calls
	menu.DisplayMenu();
	menu.SelectMenu();
	// Pause the program
	system("PAUSE");
	return 0;
}