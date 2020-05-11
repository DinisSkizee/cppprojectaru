#include "linkedlist.h"

// Constructor with initial values for the head of the LinkedList
// Current Pointer in the List
LinkedList::LinkedList()
{
	head = NULL;
	curr = NULL;
	temp = NULL;
}

// Add a node in the List
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

// Delete a Node in the List
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
		std::cout << delData.getID() << " the data wasn't found in the Database\n";
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

// Print the List with custom cout
void LinkedList::PrintList()
{
	// Price
	float sum = 0;
	// Stay Duration
	float months = 0;
	// Marina Space
	float space = 150;

	curr = head;
	
	// Untill the list isn't finished it will keep printing node by node this table
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
	

		// The total price will added to the total price method in the transaction class to get the total made
		sum += curr->customer.getTransaction().getTotalPrice();
		// Space will be removed from the marina depending on the boat Length to get the total
		space -= curr->customer.getCustomerBoat().getBoatLength();

		curr = curr->next;
	}

	// Just some info for the user about the space left and the total earnings
	std::cout << "There's " << space << " meters left at the marina\n";
	std::cout << "The total earnings stand at " << pound << sum << "\n";
}

// Size of the List to check how many customers it has
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

// Delete Instance
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

// Find First Method to get the first customer and his boat name
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

// LinkedList Deletion Method wasn't needed because data is being deleted directly from the database
/*Customer LinkedList::DeleteBooking(string custName, string boatName)
{
}*/

// Get the amount of used spaces
Marina LinkedList::getSpace()
{
	return updatedSpaces;
}

// Get remaining space in the marina
float LinkedList::getRemainSpace()
{
	return space;
}

// Method to check how much space we have in the marina going
// from boat to boat until it reaches the end of the list
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