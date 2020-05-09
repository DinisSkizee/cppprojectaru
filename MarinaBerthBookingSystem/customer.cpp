#include "customer.h"

Customer::Customer()
{
	Boat boat;
}

Boat Customer::getCustomerBoat()
{
	return boat;
}

void Customer::setCustomerBoat(Boat inputBoat)
{
	boat = inputBoat;
}

string Customer::getCustomerName()
{
	return CustomerName;
}

void Customer::setCustomerName(string nCustomerName)
{
	CustomerName = nCustomerName;
}

int Customer::getID()
{
	return ID;
}

void Customer::setID(int nID)
{
	ID = nID;
}

int Customer::getMarinaPosition()
{
	return marinaPosition;
}

void Customer::setMarinaPosition(int nMarinaPosition)
{
	marinaPosition = nMarinaPosition;
}

void Customer::AddTransaction(Transaction nTransaction)
{
	transaction = nTransaction;
}

Transaction Customer::getTransaction()
{
	return transaction;
}