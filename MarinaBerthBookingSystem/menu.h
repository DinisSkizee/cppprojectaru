#pragma once

#include "menu.h"
#include "quotation.h"
#include "booking.h"
#include "linkedlist.h"
#include <iostream>
#include <cstdlib>

using namespace std;

class Menu
{
public:
	void DisplayMenu();
	void SelectMenu();
	void DeleteRecord();
};