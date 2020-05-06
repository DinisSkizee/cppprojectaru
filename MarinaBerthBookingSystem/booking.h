#pragma once
#include "menu.h"
#include "boat.h"
#include "customer.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <limits>

class Booking
{
public:
	void OwnerDetails();
	void BookingTypeDisplay();
	void BookingTypeSelect();
	void BookingLengthShallow();
	void Confirmation();
	void CompletedBookingDisplay();
};