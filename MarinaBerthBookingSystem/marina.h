#pragma once

#include <iostream>
#include <stdlib.h>
#include <iterator>
#include <list>

using namespace std;

class Marina
{

public:
	Marina();

	int ID;
	float marina;

	void CreateSpaces();

	int getSpaceNumber();
	int getSpacesCount();
	void setSpaceID(int);
	int SpaceAssignment();

	float getSpaceLeft();
	void setSpaceLeft(float);

	list<int> listSpaces;

};