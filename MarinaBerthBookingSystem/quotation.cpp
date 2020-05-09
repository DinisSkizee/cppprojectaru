#include "quotation.h"

// Pound symbol needs to be added this way in C++
unsigned char pound = 156;

void Quotation::QuotationDisplay()
{
	// Variable Declaration
	int boatLength;
	int durationStay;

	// Display a board and ask the user to input some necessary data - Boat Length and Stay Duration for the total price
	std::cout << "\n" << endl;
	std::cout << "	----------------------- Quotation ---------------------" << endl;

	// Display a board and ask the user to input the boat type
	std::cout << "\n 	          Length must be between 1 and 15 meters" << endl;

	do
	{
		// Get user input for boatLength
		std::cout << " 	          Boat Length: "; std::cin >> boatLength;
	} while (boatLength < 1 || boatLength > 15);

	std::cout << " 	          Stay Duration: "; std::cin >> durationStay;

	// Clean the console
	system("CLS");
	// Call QuotationFinalDisplay() method to show details and total value
	QuotationFinalDisplay(boatLength, durationStay);
}


void Quotation::QuotationFinalDisplay(int length, int stay)
{
	// Board to display the details and total value of the Quotation
	std::cout << "\n" << endl;
	std::cout << "	----------------------- Quotation ---------------------" << endl;
	std::cout << "	 " << endl;
	std::cout << "	                 " << pound << "10 * Length * Duration" << endl;
	std::cout << "	 " << endl;
	std::cout << "	                 Your Boat Length: " << length << endl;
	std::cout << "	                 Your Stay Duration: " << stay << endl;
	std::cout << "	                 Total Price: " << (length * stay * 10) << endl;
	// Pause the program so the user can actually see the total price board
	system("PAUSE");
	std::cout << "	-------------------------------------------------------" << "\n" << endl;
		
	// Clean the console
	system("CLS");

	// Create menu object
	Menu menu;

	// Access the menu object DisplayMenu() and SelectMenu() Methods to display and select from the menu
	menu.DisplayMenu();
	menu.SelectMenu();

}