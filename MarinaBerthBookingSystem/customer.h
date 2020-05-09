#pragma once
#include "transaction.h"
#include "boat.h"
#include "marina.h"
#include <iostream>
#include <string>

using namespace std;

class Customer
{

public:
	// Constructor
	Customer();

	Boat getCustomerBoat();

	void setCustomerBoat(Boat);

	string getCustomerName();

	void setCustomerName(string);

	int getID();

	void setID(int);

	int getMarinaPosition();

	void setMarinaPosition(int);

	void AddTransaction(Transaction);

	Transaction getTransaction();

private:
	int ID;
	int marinaPosition;
	string CustomerName;

	Transaction transaction;

	Boat boat;

};

/*
Customer Boat
Name
ID
Transaction
MarinaSpace
*/