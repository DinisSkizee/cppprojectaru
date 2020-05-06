#pragma once

#include <iostream>
#include <string>

using namespace std;

class Boat
{

public:
	// Default Constructor
	Boat();

	// Constructor
	Boat(float, float, string, string, int);

	// Destructor
	~Boat();

	// Accessors
	float getBoatLength();

	void setBoatLength(float);

	float getBoatShallow();

	void setBoatShallow(float);

	string getBoatType();

	void setBoatType(string);

	string getBoatName();

	void setBoatName(string);

	int getBoatStay();

	void setBoatStay(int);


private:
	float boatLength;
	float boatShallow;
	string boatType;
	string boatName;
	int boatStay;

};

/*
Length
Type
Name
Shallow
Stay
*/