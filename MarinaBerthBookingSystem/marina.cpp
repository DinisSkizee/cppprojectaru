#include "marina.h"
int Marina::spaceAssignment()
{
	int temp = listSpaces.front();
	listSpaces.pop_front();
	return temp;
}

void Marina::createSpaces()
{
	int spaces;

	for (int i = 0; i < 100; i++)
	{
		spaces = i + 1;
		listSpaces.push_back(spaces);
	}
}

int Marina::getSpaceID()
{ 
	return ID;
}

void Marina::setSpaceID(int nID)
{
	ID = nID;
}

int Marina::getSpacesCount()
{
	return listSpaces.size();
}