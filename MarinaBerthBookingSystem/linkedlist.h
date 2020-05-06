#pragma once

#include "customer.h"
#include <cstdlib>
#include <list>
#include <iostream>
#include <algorithm>

class LinkedList
{

public:
	LinkedList();
	void AddNode(Customer);
	void DeleteNode(Customer);
	void PrintList();
	void CalculateRemainSpace();
	float ReturnRemainSpace();
	int ListSize();
	void DeleteInst(Marina);
	string FindFirst();
	Customer DeleteBooking(string, string);
	Marina ReturnSpace();

private:
	Marina updatedSpaces;
	typedef struct node {
		Customer customer;
		node* next;
	}*nodePtr;
	nodePtr head;
	nodePtr curr;
	nodePtr temp;
	float space;
};