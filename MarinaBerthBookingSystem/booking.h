#pragma once
#include "menu.h"
#include "boat.h"
#include "customer.h"
#include "linkedlist.h"
#include "transaction.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <limits>

using namespace std;

/* ALL THE COMMENTS ARE IN THE CPP FILES */

class Booking
{
public:
	void OwnerDetails(LinkedList& list);
	void BookingTypeDisplay(LinkedList& list);
	void BookingTypeSelect(LinkedList& list);
	void BookingLengthShallow(LinkedList& list);
	void Confirmation(LinkedList& list);
	void CompletedBookingDisplay(LinkedList& list);
	LinkedList list;
	Marina marina;
	Transaction trans;
};