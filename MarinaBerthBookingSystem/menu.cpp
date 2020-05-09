#include "menu.h"

void Menu::DisplayMenu()
{
	Marina marinaClass;
	// Main menu that displays all the different options for the booking system
	std::cout << "                Welcome to my Marina Berth Booking System       " << "\n" << endl;
	std::cout << "	---------------------- Main Menu ----------------------" << endl;
	std::cout << "	|                                                     |" << endl;
	std::cout << "	|  1)  Quotation                                      |" << endl;
	std::cout << "	|  2)  Record a New Booking                           |" << endl;
	std::cout << "	|  3)  Delete a Record                                |" << endl;
	std::cout << "	|  4)  Display All Records                            |" << endl;
	std::cout << "	|                                                     |" << endl;
	std::cout << "	|  5)  Exit the Program                               |" << endl;
	std::cout << "	|                                                     |" << endl;
	std::cout << "	|  Meters Left: "<< marinaClass.getSpaceLeft() << "                                    |" << endl;
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
		std::cin.ignore();
		switch (option)
		{
		case 1: // Quotation
		{
			system("CLS");
			Quotation quotation;
			quotation.QuotationDisplay();
			break;
		}
		case 2:  // Record a New Booking
		{
			system("CLS");
			Booking booking;
			booking.OwnerDetails();
			break;
		}
		case 3:  // Delete a Record
		{
			if (dbase.mainList.ListSize() != 0)
			{
				// Temporary Variables
				string tempOwnerName;
				string tempBoatName;

				// Display a board to get input from the user to Delete a Booking
				std::cout << "\n\n";
				std::cout << "	--------------------- Delete Booking ------------------\n";
				std::cout << "\n";
				std::cout << "	             Full Name: "; std::getline(cin, tempOwnerName);
				// Converts the string into upper case
				std::for_each(tempOwnerName.begin(), tempOwnerName.end(), [](char& c) {
					c = ::toupper(c);
					});
				std::cout << "	             Boat Name: "; std::getline(cin, tempBoatName);
				std::for_each(tempBoatName.begin(), tempBoatName.end(), [](char& c) {
					c = ::toupper(c);
					});
				std::cout << "\n";


				// Deletes the booking by knowing the OwnerName and the BoatName, if they don't match anything it won't delete
				dbase.DeleteData("..\\database.db", tempOwnerName, tempBoatName);

				break;
			}
			else {
				std::cout << "There's no data in the database, try adding something first" << endl;
			}
		}
		case 4:  // Display All Records
		{
			menuList.PrintList();
			break;
		}
		case 5:  // Exit the program
		{
			std::cout << "\nThe Program will now close..." << endl;
			exit(0);
			break;
		}
		}
		// Clear the cin function last input
		std::cin.clear();

		// Discard previous input
		std::cin.ignore(1234, '\n');
	} while (option < 1 || option > 6);
}

LinkedList Menu::GetList()
{
	return menuList;
}

void Menu::setList(LinkedList newList)
{
	menuList = newList;
}