#include "transaction.h"

Transaction::Transaction() {}
Transaction::~Transaction() {}

void Transaction::cTransaction(int months, float length, int nID)
{
	totalCost = length * 10 * months;
	ID = nID;
}

int Transaction::getTransID()
{
	return ID;
}

void Transaction::setTransID(int nID)
{
	ID = nID;
}

void Transaction::setTransPrice(float nTotalCost)
{
	totalCost = nTotalCost;
}
float Transaction::getTotalPrice()
{
	return totalCost;
}