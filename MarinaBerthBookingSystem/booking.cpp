#include "booking.h"
#include "menu.h"
#include <iostream>
#include <cstdlib>
#include <limits>

using namespace std;

// Pound symbol needs to be added this way in C++
char pound = 156;

std::string ownerName;
std::string boatName;
std::string boatType;
int boatStay;
int boatLength;
int boatShallow;

void Booking::OwnerDetails()
{
	// Display a board for the booking class
	std::cout << "\n\n";
	std::cout << "	------------------------ Booking ----------------------\n";
	std::cout << "\n";
	std::cout << "	             Full Name: "; std::getline(cin, ownerName);
	std::cout << "	             Boat Name: "; std::getline(cin, boatName);
	std::cout << "	             Stay Duration (months): "; std::cin >> boatStay;
	std::cout << "\n";
	BookingTypeDisplay();
}

void Booking::BookingTypeDisplay()
{
	std::cout << "	             What is your Boat Type?\n";
	std::cout << "	             1) Narrow\n";
	std::cout << "	             2) Sailing\n";
	std::cout << "	             3) Motor\n";
	BookingTypeSelect();
}

void Booking::BookingTypeSelect()
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
	BookingLengthShallow();
}

void Booking::BookingLengthShallow()
{
	// Display a board and ask the user to input the boat type
	std::cout << "\n 	          Length must be between 1 and 15 meters\n";
	
	do
	{
		// Get user input for boatLength
		std::cout << "	             Boat Length: "; std::cin >> boatLength;
	} while (boatLength < 1 || boatLength > 15);

	std::cout << "" << endl;
	std::cout << "	          Shallow must be between 1 and 5 meters\n";
	do
	{
		// Get user input for boatShallow
		std::cout << "	             Boat Shallow: "; std::cin >> boatShallow;
	} while (boatLength < 1 || boatShallow > 5);
	
	system("CLS");
	Confirmation();
}

void Booking::Confirmation()
{
	// Variable Declaration
	string confirmed;

	std::cout << "	-----------------------  Confirmation ---------------------\n\n";
	std::cout << "	                " << pound << "10 * Length * Duration\n\n";
	std::cout << "	               Your Name: " << ownerName << "\n";
	std::cout << "	               Your Boat's Name: " << boatName << "\n";
	std::cout << "	               Your Boat's Type: " << boatType << "\n";
	std::cout << "	               Your Boat's Length: " << boatLength << "\n";
	std::cout << "	               Your Boat's Shallow: " << boatShallow << "\n\n";
	std::cout << "	               Total Price: " << pound << (boatLength * boatStay * 10) << "\n\n";
	std::cout << "       Type CONFIRM to complete the booking or else to leave\n\n";
	std::cout << "	-----------------------------------------------------------" << "\n\n";
	
	std::cin.ignore(1234, '\n');
	std::getline(cin, confirmed);

	if (confirmed == "CONFIRM")
	{
		system("CLS");
		CompletedBookingDisplay();
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

void Booking::CompletedBookingDisplay()
{
	std::cout << "\n	-----------------  Completed Booking -----------------\n\n\n";
	std::cout << "             THANKS COMPLETING YOUR BOOKING\n";
	std::cout << "             YOUR BOAT WILL NOW BE ADDED TO\n";
	std::cout << "                 OUR MARINA FOR " << boatStay << " MONTHS\n\n\n";
	std::cout << "	-----------------------------------------------------------\n";

	system("PAUSE");

	Menu menu;
	system("CLS");
	// Access the menu object DisplayMenu() and SelectMenu() Methods to display and select from the menu
	menu.DisplayMenu();
	menu.SelectMenu();
}