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
	void addNode(Customer);
	void deleteNode(Customer);
	void printList();
	void calculateRemainSpace();
	float returnRemainSpace();
	int listSize();
	void deleteInst(Marina);
	string findFirst();
	Customer deleteCustomer(string, string);
	Marina returnSpace();

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