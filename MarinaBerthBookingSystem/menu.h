#pragma once

#include "menu.h"
#include "quotation.h"
#include "booking.h"
#include "linkedlist.h"
#include "dbconnection.h"
#include "marina.h"
#include <iostream>
#include <cstdlib>

using namespace std;

class Menu
{
public:
	void DisplayMenu();
	void SelectMenu();
	LinkedList GetList();
	void setList(LinkedList);

private:
	LinkedList menuList;
	DBConnection dbase;
};