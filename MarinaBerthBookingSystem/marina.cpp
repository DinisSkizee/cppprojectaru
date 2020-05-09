#include "marina.h"

Marina::Marina()
{
	marina = 150;
}

// Removes the first number of the list (to the holding bay) and then returns when it's assigned to a new boat
int Marina::SpaceAssignment()
{
	int temp = listSpaces.front();
	listSpaces.pop_front();
	return temp;
}

// Create Spaces when the program starts, it's initialized in main
void Marina::CreateSpaces()
{
	int spaces;

	for (int i = 0; i < 100; i++)
	{
		spaces = i + 1;
		listSpaces.push_back(spaces);
	}
}

// Get the Space ID
int Marina::getSpaceNumber()
{ 
	return ID;
}

// Set positions for the space
void Marina::setSpaceID(int nID)
{
	ID = nID;
}

// Get the ammount of Spaces being used by boats
int Marina::getSpacesCount()
{
	return listSpaces.size();
}

// Get the space left in the marina
float Marina::getSpaceLeft()
{
	return marina;
}

// Remove meters from the marina
void Marina::setSpaceLeft(float spaceRemove)
{
	marina = spaceRemove;
}