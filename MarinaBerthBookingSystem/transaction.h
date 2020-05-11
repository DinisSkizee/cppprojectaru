#pragma once

#include <stdio.h>
#include <time.h>
#include <iostream>
#include <string>
#include <ctime>
#include <chrono>

using namespace std;

/* ALL THE COMMENTS ARE IN THE CPP FILES */

class Transaction
{

public:

	// Constructor
	Transaction();
	
	// Destructor
	~Transaction();

	void CTransaction(int, float, int);

	int getTransID();

	void setTransID(int);

	void setTransPrice(float);

	float getTotalPrice();

private:

	int ID = 0;
	float totalCost;
	string expTime;

};