#include "boat.h"

// Constructor Variable initialization
Boat::Boat() {
	boatLength = 0;
	boatShallow = 0;
	boatStay = 0;
}

// Constructor
Boat::Boat(float nBoatLength, float nBoatShallow, string nBoatType, string nBoatName, int nBoatStay)
{
	boatLength = nBoatLength;
	boatShallow = nBoatShallow;
	boatType = nBoatType;
	boatName = nBoatName;
	boatStay = nBoatStay;
}

// Destructor
Boat::~Boat() {}

// Get Set for the Boat length
float Boat::getBoatLength()
{
	return boatLength;
}
void Boat::setBoatLength(float nBoatLength)
{
	boatLength = nBoatLength;
}

// Get Set for the Boat Shallow
float Boat::getBoatShallow()
{
	return boatShallow;
}
void Boat::setBoatShallow(float nBoatShallow)
{
	boatShallow = nBoatShallow;
}

// Get Set for the boat Type
string Boat::getBoatType()
{
	return boatType;
}
void Boat::setBoatType(string nBoatType)
{
	boatType = nBoatType;
}

// Get Set for the boat Name
string Boat::getBoatName()
{
	return boatName;
}
void Boat::setBoatName(string nBoatName)
{
	boatName = nBoatName;
}

// Get Set for the Boat Stay Duration
int Boat::getBoatStay()
{
	return boatStay;
}
void Boat::setBoatStay(int nBoatStay)
{
	boatStay = nBoatStay;
}

