#include "boat.h"

Boat::Boat() {
	boatLength = 0;
	boatShallow = 0;
	boatStay = 0;
}

Boat::Boat(float nBoatLength, float nBoatShallow, string nBoatType, string nBoatName, int nBoatStay)
{
	boatLength = nBoatLength;
	boatShallow = nBoatShallow;
	boatType = nBoatType;
	boatName = nBoatName;
	boatStay = nBoatStay;
}

Boat::~Boat() {}

float Boat::getBoatLength()
{
	return boatLength;
}

void Boat::setBoatLength(float nBoatLength)
{
	boatLength = nBoatLength;
}

float Boat::getBoatShallow()
{
	return boatShallow;
}

void Boat::setBoatShallow(float nBoatShallow)
{
	boatShallow = nBoatShallow;
}

string Boat::getBoatType()
{
	return boatType;
}

void Boat::setBoatType(string nBoatType)
{
	boatType = nBoatType;
}

string Boat::getBoatName()
{
	return boatName;
}

void Boat::setBoatName(string nBoatName)
{
	boatName = nBoatName;
}

int Boat::getBoatStay()
{
	return boatStay;
}

void Boat::setBoatStay(int nBoatStay)
{
	boatStay = nBoatStay;
}

