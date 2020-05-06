#include "menu.h"

void Menu::DisplayMenu()
{
	// Main menu that displays all the different options for the booking system
	std::cout << "                Welcome to my Marina Berth Booking System       " << "\n" << endl;
	std::cout << "	---------------------- Main Menu ----------------------" << endl;
	std::cout << "	|                                                     |" << endl;
	std::cout << "	|  1)  Quotation                                      |" << endl;
	std::cout << "	|  2)  Record a New Booking                           |" << endl;
	std::cout << "	|  3)  Delete a Record                                |" << endl;
	std::cout << "	|  4)  Manage Records                                 |" << endl;
	std::cout << "	|  5)  Display All Records                            |" << endl;
	std::cout << "	|                                                     |" << endl;
	std::cout << "	|  6)  Exit the Program                               |" << endl;
	std::cout << "	|                                                     |" << endl;
	std::cout << "	-------------------------------------------------------" << "\n" << endl;
}

void Menu::SelectMenu()
{
	// Variable Declaration
	int option;

	// Do-While to Check if the input is valid
	do
	{
		// Ask and get the user option
		std::cout << "	SELECT: ";
		std::cin >> option;
		cin.ignore();
		switch (option)
		{
		case 1:  // Quotation
			system("CLS");
			Quotation quotation;
			quotation.QuotationDisplay();
			break;
		case 2:  // Record a New Booking
			system("CLS");
			Booking booking;
			booking.OwnerDetails();
			break;
		case 3:  // Delete a Record
			DeleteRecord();
			break;
		case 4:  // Manage Records

			break;
		case 5:  // Display All Records

			break;
		case 6:  // Exit the program
			std::cout << "\nThe Program will now close..." << endl;
			exit(0);
			break;
		}
		// Clear the cin function last input
		cin.clear();

		// Discard previous input
		cin.ignore(1234, '\n');
	} while (option < 1 || option > 6);
}

void Menu::DeleteRecord()
{
	string tempOwnerName;
	string tempBoatName;

	// Display a board to get input from the user to Delete a Booking
	std::cout << "\n\n";
	std::cout << "	--------------------- Delete Booking ------------------\n";
	std::cout << "\n";
	std::cout << "	             Full Name: "; std::getline(cin, tempOwnerName);
	std::cout << "	             Boat Name: "; std::getline(cin, tempBoatName);
	std::cout << "\n";

	
}