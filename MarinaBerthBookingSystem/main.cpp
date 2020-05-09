#include "menu.h"
#include "linkedlist.h"
#include "dbconnection.h"
#include <stdlib.h>
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	// Classes Declaration
	Menu menu;
	Marina marina;

	const char* db = "..\\database.db";

	// Creates 150 spaces in the Marina
	marina.CreateSpaces();

	DBConnection database;
	database.CreateDatabase(db);
	database.CreateTable(db);

	LinkedList mainList;
	start:
	// Need something to populate the data !!!!
	menu.setList(mainList);

	// Method Calls
	menu.DisplayMenu();
	menu.SelectMenu();

	goto start;
	// Pause the program
	system("PAUSE");
	return 0;
}