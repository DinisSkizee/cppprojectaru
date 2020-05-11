#include "dbconnection.h"

// All the database connection and configuration was created by following the tutorial: https://www.youtube.com/watch?v=L-hnA82JsEM

// Creates the Database
int DBConnection::CreateDatabase(const char* x)
{
	sqlite3* DB;
	int exit = 0;

	exit = sqlite3_open(x, &DB);

	sqlite3_close(DB);

	return 0;
}

// Creates the database table if it doesn't exist already
int DBConnection::CreateTable(const char* x)
{
	sqlite3* DB;

	// SQL String to create the table
	string sql = "CREATE TABLE IF NOT EXISTS CUSTOMERS("
		"ID     INTEGER(6), "
		"SPACE     INTEGER(6), "
		"NAME       CHAR(50), "
		"BOAT_NAME      CHAR(50), "
		"BOAT_TYPE      CHAR(10), "
		"BOAT_LENGTH      FLOAT(5,2), "
		"BOAT_SHALLOW      FLOAT(5,2), "
		"TRANSACTION_ID      INTEGER(5), "
		"TOTAL_PRICE      FLOAT(20));";

	// Try Catch to try and create the table if it goes to the catch
	// the system will output what error ocurred
	try
	{
		int exit = 0;
		exit = sqlite3_open(x, &DB);

		char* messageError;
		exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

		if (exit != SQLITE_OK) {
			cerr << "Error Creating Table" << endl;
			sqlite3_free(messageError);
		}
		else 
			std::cout << "Table Created Successfully" << endl;
		sqlite3_close(DB);
	}
	catch (const exception & e)
	{
		cerr << e.what();
	}

	return 0;
}

// Insertion of Data to the Database
int DBConnection::InsertData(const char* x, Customer customer)
{
	sqlite3* DB;
	char* messageError;

	int exit = sqlite3_open(x, &DB);

	// SQL String to insert data into the table
	string sql = "INSERT INTO CUSTOMERS (ID, SPACE, NAME, BOAT_NAME, BOAT_TYPE, BOAT_LENGTH, BOAT_SHALLOW, TRANSACTION_ID, TOTAL_PRICE) VALUES('"
		+ std::to_string(customer.getID()) + "', '" // Customer ID
		+ std::to_string(customer.getMarinaPosition()) + "', '" // Boat Position in the Marina
		+ customer.getCustomerName() + "', '" // Customer Name
		+ customer.getCustomerBoat().getBoatName() + "', '" // Get Boat Name
		+ customer.getCustomerBoat().getBoatType() + "', '" // Get Boat Type
		+ std::to_string(customer.getCustomerBoat().getBoatLength()) + "', '" // Get Boat Length
		+ std::to_string(customer.getCustomerBoat().getBoatShallow()) + "', '" // Get Boat Shallow
		+ std::to_string(customer.getTransaction().getTransID()) + "', '"
		+ std::to_string(customer.getTransaction().getTotalPrice()) + "');";

	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

	if (exit != SQLITE_OK) {
		cerr << "Error Inserting Data" << endl;
		sqlite3_free(messageError);
		exit = sqlite3_close(DB);
	}
	else {
		std::cout << "Records added Successfully!" << endl;
		exit = sqlite3_close(DB);
	}

	return 0;
}

// Method to Select Data from the Database
int DBConnection::SelectData(const char* x)
{
	sqlite3* DB;

	int exit = sqlite3_open(x, &DB);

	string sql = "SELECT * FROM CUSTOMERS;";

	sqlite3_exec(DB, sql.c_str(), CallBack, NULL, NULL);

	return 0;
}

// Call Back
int DBConnection::CallBack(void* NotUsed, int argc, char** argv, char** azColName)
{
	
	Customer cust;
	Boat boat;
	Transaction trans;

	// ID, SPACE, NAME, BOAT_NAME, BOAT_TYPE, BOAT_LENGTH, BOAT_SHALLOW, TRANSACTION_ID, TOTAL_PRICE
	cust.setID(std::stoi(argv[0]));
	cust.setMarinaPosition(std::stoi(argv[1]));
	cust.setCustomerName(argv[2]);
	boat.setBoatName(argv[3]);
	boat.setBoatType(argv[4]);
	boat.setBoatLength(std::stof(argv[5]));
	boat.setBoatShallow(std::stof(argv[6]));
	trans.setTransID(std::stoi(argv[7]));
	trans.setTransPrice(std::stof(argv[8]));

	cust.setCustomerBoat(boat);
	cust.AddTransaction(trans);
	mainList.AddNode(cust);

	std::cout << endl;

	return 0;
}

// Deletion of Data by getting the Customer Name and Boat Name, as it's a small program should work fine, but for
// larger companies this won't work because there can be 2 customers with the same name and boat name, so the ID
// would be necessary in that case
int DBConnection::DeleteData(const char* x, string customerName, string boatName)
{
	sqlite3* DB;
	char* messageError;
	int exit = sqlite3_open(x, &DB);

	string sql = "DELETE FROM CUSTOMERS WHERE NAME='" + customerName + "' AND BOAT_NAME='" + boatName + "';";
	sqlite3_exec(DB, sql.c_str(), CallBack, NULL, &messageError);

	return 0;
}

// Get Set for the List
LinkedList DBConnection::getList()
{
	return mainList;
}
void DBConnection::setList(LinkedList list)
{
	mainList = list;
}