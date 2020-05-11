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
	LinkedList freshList;
	database.CreateDatabase(db);
	database.CreateTable(db);

	start:
	database.setList(freshList);
	database.SelectData(db);

	menu.setList(database.getList());

	// Method Calls
	menu.DisplayMenu();
	menu.SelectMenu();

	goto start;
	// Pause the program
	system("PAUSE");
	return 0;
}