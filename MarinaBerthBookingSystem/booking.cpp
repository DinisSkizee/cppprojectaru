#include "booking.h"

// Pound symbol needs to be added this way in C++
char pound = 156;

std::string ownerName;
std::string boatName;
std::string boatType;
int boatStay;
int boatLength;
int boatShallow;

// Get Details from the user, Name, Boat name and Stay Duration
void Booking::OwnerDetails(LinkedList &list)
{

	// Display a board for the booking class
	std::cout << "\n\n";
	std::cout << "	------------------------ Booking ----------------------\n";
	std::cout << "\n";
	std::cout << "	             Full Name: "; std::getline(cin, ownerName);
	std::cout << "	             Boat Name: "; std::getline(cin, boatName);
	std::cout << "	             Stay Duration (months): "; std::cin >> boatStay;
	std::cout << "\n";
	BookingTypeDisplay(list);
}

// Type Display (Front-End)
void Booking::BookingTypeDisplay(LinkedList &list)
{
	std::cout << "	             What is your Boat Type?\n";
	std::cout << "	             1) Narrow\n";
	std::cout << "	             2) Sailing\n";
	std::cout << "	             3) Motor\n";
	BookingTypeSelect(list);
}

// Selection of the Boat Type (Back-End)
void Booking::BookingTypeSelect(LinkedList &list)
{
	// Variable Declaration
	int option;

	

	// Do-While to Check if the input is valid
	do
	{
		// Ask for and get the user input
		std::cout << "	             SELECT: ";
		std::cin >> option;

		switch (option)
		{
		case 1:
			boatType = "Narrow";
			break;
		case 2:
			boatType = "Sailing";
			break;
		case 3:
			boatType = "Motor";
		}
		// Clear the cin function last input
		cin.clear();

		// Discard previous input
		cin.ignore(1234, '\n');
	} while (option < 1 || option > 3);

	// Call Method to get Boat Length Display and Select
	BookingLengthShallow(list);
}

// Get the Boat Length and Shallow and verify input
void Booking::BookingLengthShallow(LinkedList& list)
{
	// Display a board and ask the user to input the boat type
	std::cout << "\n 	          Length must be between 1 and 15 meters\n";
	
	// Get user input for boatLength
	boatLengthgt:
	std::cout << "	             Boat Length: ";
	std::cin >> boatLength;
	if (cin)
	{
		boatShallowgt:
		std::cout << "" << endl;
		std::cout << "	          Shallow must be between 1 and 5 meters\n";

		// Get user input for boatShallow
		std::cout << "	             Boat Shallow: ";
		std::cin >> boatShallow;
		if (cin)
		{
			system("CLS");
			Confirmation(list);
		}
		else
		{
			std::cout << "Incorrect input, Only Numbers Allowed\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			goto boatShallowgt;
		}
	}
	else
	{
		std::cout << "Incorrect Input, Only Numbers Allowed\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		goto boatLengthgt;
	}
}

// Variable for the Booking Price as it is always the Length * Stay * 10
int bookingPrice = boatLength * boatStay * 10;

// Method for the Confirmation that will display a small panel with details and a
// Confirmation input to confirm
void Booking::Confirmation(LinkedList& list)
{
	// Variable Declaration
	string confirmed;

	// Small Panel To Output the previous Inputs
	std::cout << "	-----------------------  Confirmation ---------------------\n\n";
	std::cout << "	                " << pound << "10 * Length * Duration\n\n";
	std::cout << "	               Your Name: " << ownerName << "\n";
	std::cout << "	               Your Boat's Name: " << boatName << "\n";
	std::cout << "	               Your Boat's Type: " << boatType << "\n";
	std::cout << "	               Your Boat's Length: " << boatLength << "\n";
	std::cout << "	               Your Boat's Shallow: " << boatShallow << "\n\n";
	std::cout << "	               Total Price: " << pound + bookingPrice << "\n\n";
	std::cout << "       Type CONFIRM to complete the booking or else to leave\n\n";
	std::cout << "	-----------------------------------------------------------" << "\n\n";
	
	std::cin.ignore(1234, '\n');
	std::getline(cin, confirmed);

	// Confirmation input
	if (confirmed == "CONFIRM")
	{
		system("CLS");
		CompletedBookingDisplay(list);
	}
	else
	{
		Menu menu;
		system("CLS");
		// Access the menu object DisplayMenu() and SelectMenu() Methods to display and select from the menu
		menu.DisplayMenu();
		menu.SelectMenu();
	}
}

// Display for when the booking is completed
// Plus asset variables to it's classes, Insert Data into the DB
// Go to the menu again
void Booking::CompletedBookingDisplay(LinkedList &list)
{
	std::cout << "\n	-----------------  Completed Booking -----------------\n\n\n";
	std::cout << "                THANKS COMPLETING YOUR BOOKING\n";
	std::cout << "                YOUR BOAT WILL NOW BE ADDED TO\n";
	std::cout << "                        OUR MARINA FOR " << boatStay << " MONTHS\n\n\n";
	std::cout << "	-----------------------------------------------------------\n";

	// Add data to the boat class
	Boat newBoat;
	newBoat.setBoatLength(boatLength);
	newBoat.setBoatShallow(boatShallow);
	newBoat.setBoatName(boatName);
	newBoat.setBoatType(boatType);
	newBoat.setBoatStay(boatStay);
	
	// Add data to the Customer class
	Customer newCustomer;
	newCustomer.setCustomerBoat(newBoat);
	newCustomer.setCustomerName(ownerName);
	//newCustomer.setMarinaPosition(marina.SpaceAssignment());
	newCustomer.setCustomerBoat(newBoat);
	newCustomer.AddTransaction(trans);

	// Add data to the transaction class
	Transaction newTransaction;
	newTransaction.setTransPrice(bookingPrice);

	// Insert the data into the database
	const char* db = "..\\database.db";
	DBConnection database;
	database.InsertData(db, newCustomer);
	list.AddNode(newCustomer);
}