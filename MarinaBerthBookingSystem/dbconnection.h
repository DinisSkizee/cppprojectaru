#pragma once
#include "sqlite3.h"
#include "customer.h"
#include "marina.h"
#include "linkedlist.h"
#include <list>
#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

/* ALL THE COMMENTS ARE IN THE CPP FILES */

class DBConnection
{
public:

	static int CreateDatabase(const char* x);
	static int CreateTable(const char* x);
	static int InsertData(const char* x, Customer);
	static int SelectData(const char* x);
	static int CallBack(void* NotUsed, int argc, char** argv, char** azColName);
	static int DeleteData(const char* x, string, string);
	static inline LinkedList mainList;
	LinkedList getList();
	void setList(LinkedList);
};