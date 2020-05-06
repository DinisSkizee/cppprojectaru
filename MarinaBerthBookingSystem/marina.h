#pragma once

#include <iostream>
#include <stdlib.h>
#include <iterator>
#include <list>

using namespace std;

class Marina
{

public:
	void createSpaces();

	int getSpaceID();
	int getSpacesCount();
	void setSpaceID(int);
	int spaceAssignment();

	list<int> listSpaces;

	int ID;
};