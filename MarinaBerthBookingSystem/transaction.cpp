#include "transaction.h"

Transaction::Transaction() {}
Transaction::~Transaction() {}

// Set a standard math for the calculation of the Transaction
void Transaction::CTransaction(int months, float length, int nID)
{
	totalCost = length * 10 * months;
	ID = nID;
}

// Gets Transaction ID
int Transaction::getTransID()
{
	return ID;
}

// Sets a new ID for the transaction
void Transaction::setTransID(int nID)
{
	ID = nID;
}

// Sets the Transaction price with the total cost from the CTransaction Method
void Transaction::setTransPrice(float nTotalCost)
{
	totalCost = nTotalCost;
}

// Returns the total Price
float Transaction::getTotalPrice()
{
	return totalCost;
}