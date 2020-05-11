#pragma once

#include "customer.h"
#include <cstdlib>
#include <list>
#include <iostream>
#include <algorithm>

/* ALL THE COMMENTS ARE IN THE CPP FILES */

class LinkedList
{

public:
	LinkedList();
	void AddNode(Customer);
	void DeleteNode(Customer);
	void PrintList();
	void CalculateRemainSpace();
	float getRemainSpace();
	int ListSize();
	void DeleteInst(Marina);
	string FindFirst();
	//Customer DeleteBooking(string, string);
	Marina getSpace();

private:
	char pound = 156;
	Marina updatedSpaces;
	float space;

	// Blueprint for the Linked List node
	typedef struct node {
		Customer customer;
		node* next;
	}*nodePtr;
	nodePtr head;
	nodePtr curr;
	nodePtr temp;
};