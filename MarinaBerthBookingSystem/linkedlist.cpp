#include "linkedlist.h"

LinkedList::LinkedList()
{
	head = NULL;
	curr = NULL;
	temp = NULL;
}
void LinkedList::AddNode(Customer addCustomer)
{
	nodePtr n = new node;
	n->next = NULL;
	n->customer = addCustomer;
	if (head != NULL)
	{
		curr = head;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = n;
	}
	else
	{
		head = n;
	}
}

void LinkedList::DeleteNode(Customer delData)
{
	nodePtr delPtr = NULL;
	temp = head;
	curr = head;
	while (curr != NULL && curr->customer.getID() != delData.getID())
	{
		temp = curr;
		curr = curr->next;
	}
	if (curr == NULL)
	{
		std::cout << delData.getID() << "the data couldn't be found in the LinkedList\n";
	}
	else
	{
		delPtr = curr;
		curr = curr->next;
		temp->next = curr;
		delete delPtr;
		std::cout << "The ID: " << delData.getID() << " - " << delData.getCustomerName() << " was deleted from the List\n";
		if (delPtr == head)
		{
			head = head->next;
			temp = NULL;
		}
	}
}

void LinkedList::PrintList()
{
	char pound = 156;
	float sum = 0;
	float months = 0;
	float space = 150;

	curr = head;
	
	while (curr != nullptr)
	{
	
		std::cout << "				        -----------------------  Booking -----------------------\n";
		std::cout << "				                 Customer ID: " << curr->customer.getID() << "\n";
		std::cout << "				                 Transaction ID: " << curr->customer.getTransaction().getTransID() << "\n";
		std::cout << "				                 Boat Space: " << curr->customer.getCustomerBoat().getBoatName() << "\n";
		std::cout << "				                 Customer Name: " << curr->customer.getCustomerName() << "\n";
		std::cout << "				                 Boat Length: " << curr->customer.getCustomerBoat().getBoatLength() << "\n";
		std::cout << "				                 Booking Expiry: " << curr->customer.getCustomerBoat().getBoatStay() << "\n";
		std::cout << "				                 Booking Value: " << curr->customer.getTransaction().getTotalPrice() << "\"n";
		std::cout << "				        --------------------------------------------------------\n";
	

		sum += curr->customer.getTransaction().getTotalPrice();
		space -= curr->customer.getCustomerBoat().getBoatLength();

		curr = curr->next;
	}

	std::cout << "There's " << space << " meters left at the marina\n";
	std::cout << "The total earnings stand at " << pound + sum << "\n";
}

int LinkedList::ListSize()
{
	int size = 0;

	curr = head;

	while (curr != NULL)
	{
		size++;
		curr = curr->next;
	}

	return size;
}

void LinkedList::DeleteInst(Marina nListSpaces)
{
	curr = head;

	while (curr != NULL)
	{
		nListSpaces.listSpaces.remove(curr->customer.getMarinaPosition());
		curr = curr->next;
	}

	updatedSpaces = nListSpaces;
}

string LinkedList::FindFirst()
{
	string temp;

	curr = head;

	while (curr != NULL)
	{
		if (curr->customer.getMarinaPosition() == 1)
		{
			temp = curr->customer.getCustomerName() + " - " + curr->customer.getCustomerBoat().getBoatName() + " #1";
			break;
		}

		curr = curr->next;
	}
	return temp;
}

Customer LinkedList::DeleteBooking(string custName, string boatName)
{
	// Data that will be looping from the list
	string currentData;
	string currentData2;

	// Data to be checked (and deleted)
	string dataToCheck;
	string dataToCheck2;

	dataToCheck = custName;
	dataToCheck2 = boatName;

	// Convert everything in the string to Upper Case
	std::for_each(dataToCheck.begin(), dataToCheck.end(), [](char& c) {
		c = ::toupper(c);
		});

	std::for_each(dataToCheck2.begin(), dataToCheck2.end(), [](char& c) {
		c = ::toupper(c);
		});

	curr = head; // go to the start of the list

	// While loop to check the values from the list and assign it to the currentData variables
	while (curr != NULL)
	{
		currentData = curr->customer.getCustomerName();
		std::for_each(currentData.begin(), currentData.end(), [](char& c) {
			c = ::toupper(c);
			});

		currentData2 = curr->customer.getCustomerBoat().getBoatName();
		std::for_each(currentData2.begin(), currentData2.end(), [](char& c) {
			c = ::toupper(c);
			});

		// Check if the data to check is equal to the current data so it can delete the correct value
		if (currentData == dataToCheck && currentData2 == dataToCheck2)
		{
			Customer custTemp;
			custTemp = curr->customer;
			return custTemp;
		}
		// Next in the list
		curr = curr->next;
	}
}

Marina LinkedList::ReturnSpace()
{
	return updatedSpaces;
}

float LinkedList::ReturnRemainSpace()
{
	return space;
}

void LinkedList::CalculateRemainSpace()
{
	float space = 150;

	curr = head;

	while (curr != nullptr)
	{
		space -= curr->customer.getCustomerBoat().getBoatLength();

		curr = curr->next;
	}
	this->space = space;
}