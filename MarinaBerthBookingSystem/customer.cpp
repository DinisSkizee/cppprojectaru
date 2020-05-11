#include "customer.h"

// Constructor
Customer::Customer()
{
	Boat boat;
}

// Get Set for the Customer Boat
Boat Customer::getCustomerBoat()
{
	return boat;
}
void Customer::setCustomerBoat(Boat inputBoat)
{
	boat = inputBoat;
}

// Get Set for the Customer Name
string Customer::getCustomerName()
{
	return CustomerName;
}
void Customer::setCustomerName(string nCustomerName)
{
	CustomerName = nCustomerName;
}

// Get Set for the ID
int Customer::getID()
{
	return ID;
}
void Customer::setID(int nID)
{
	ID = nID;
}

// Get Set for the Marina Position
int Customer::getMarinaPosition()
{
	return marinaPosition;
}
void Customer::setMarinaPosition(int nMarinaPosition)
{
	marinaPosition = nMarinaPosition;
}

// Get Set for the Transaction
void Customer::AddTransaction(Transaction nTransaction) // Set
{
	transaction = nTransaction;
}
Transaction Customer::getTransaction()
{
	return transaction;
}