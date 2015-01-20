// Jonathan Adams
// Definitions for Address member functions

#include "utility_classes.h"

Address::Address(string street_in, string city_in, string state_in, string zip_in)
{
	// Precondition: called when address function is initializing
	// Postcondition: sets address variables to given input

	street = street_in;
	city = city_in;
	state = state_in;
	zip = zip_in;
}

void Address::printAddress()
{
	// Precondition: called when address information is printed
	// Postcondition: prints address information

	cout << street << endl;
	cout << city << ", " << state << " " << zip << endl;
}

//////////////// FACILITY ////////////////////

Facility::Facility(int location_id_in, Address address_in)
{
	// Precondition: called when facility class is initialized
	// Postcondition: sets location_id to input and gets inputs from address class

	location_id = location_id_in;
	address = address_in;
}

Facility::~Facility()
{
	// destructor clears all memory pertaining to facility class

}

int Facility::get_id()
{
	// Precondition: called when id number needs to be taken from Facility array
	// Postcondition: returns id number

	return location_id;
}

void Facility::print()
{
	// Precondition: called when facility information is printed
	// Postcondition: prints id number of facility then calls address print function

	cout << "Facility ID:    " << location_id << endl << endl << "Location:\n";
	address.printAddress();
}

//////////////////// DRIVE-THROUGH LANE /////////////////////////

Drive_through_lane::Drive_through_lane()
{
	// Precondition: called by full service or drive through facilities to initialize drive through lanes
	// Postcondition: sets lanes to CLOSED

	open_or_closed = CLOSED;
}

void Drive_through_lane::open_lane()
{
	// Precondition: called by facility classes with drive through lanes
	// Postcondition: sets given lane to Open

	open_or_closed = OPEN;
}

void Drive_through_lane::close_lane()
{
	// Precondition: called by facility classes with drive through lanes
	// Postcondition: sets given lane to Closed

	open_or_closed = CLOSED;
}

int Drive_through_lane::withdraw()
{
	// Precondition: called by full service or drive thorugh facility when a withdrawal is
				// attempted from a drive through lane
	// Postcondition: tests if withdrawal can be made then executes

	if (open_or_closed == CLOSED)
	{
		return 0;	// lane closed
	}
	else
	{
		return 1;
	}
}

int Drive_through_lane::deposit()
{
	// Precondition: called by full service or drive through facility when a deposit is attempted
					// from a drive through lane
	// Postconidtion: tests if deposit can be made then executes

	if (open_or_closed == CLOSED)
	{
		return 0;	// lane closed
	}
	else
	{
		return 1;
	}
}

void Drive_through_lane::print()
{
	// Precondition: called by full service or drive through facility to print status of drive-
				// through lanes
	// Postcondition: prints 'closed' if open_or_closed = 0 and 'open' if open_or_closed = 1

	if (open_or_closed == CLOSED)
	{
		cout << "closed\n";
	}
	if (open_or_closed == OPEN)
	{
		cout << "open\n";
	}
}

//////////////// TELLER WINDOW ///////////////////

Teller_window::Teller_window()
{
	// Precondition: called by full service facility to intialize teller windows
	// Postcondition: sets teller windows to closed with zero cash

	open_or_closed = CLOSED;
	amount_of_cash = 0;
	amount_of_dollars = amount_of_cash / 100;
	amount_of_cents = amount_of_cash - (amount_of_dollars * 100);
}

void Teller_window::open_teller(long int cash_in)
{
	// Precondition: called by full service facility
	// Postcondition: opens given teller and sets cash to given value

	open_or_closed = OPEN;
	amount_of_cash = cash_in;
	amount_of_dollars = amount_of_cash / 100;
	amount_of_cents = amount_of_cash - (amount_of_dollars * 100);
}

void Teller_window::close_teller()
{
	// Precondition: called by full service facility
	// Postcondition: closes given teller and sets cash to 0

	open_or_closed = CLOSED;
	amount_of_cash = 0;
}

int Teller_window::withdraw(long int cash_out)
{
	// Precondition: called by full service facility to withdraw from Teller window
	// Postconidtion: checks if withdrawal can be made then executes

	if (open_or_closed == CLOSED)
	{
		return 0;	// lane closed
	}
	else if (amount_of_cash < cash_out)
	{
		return 1;	// not enough cash
	}
	else
	{
		amount_of_cash = amount_of_cash - cash_out;
		amount_of_dollars = amount_of_cash / 100;
		amount_of_cents = amount_of_cash - (amount_of_dollars * 100);
		return 2;	// transaction success
	}
}

int Teller_window::deposit(long int cash_in)
{
	// Precondition: called by full service facility to deposit to Teller window
	// Postcondition: checks if deposit can be made then executes

	if (open_or_closed == CLOSED)
	{
		cout << "Window not open.\n\n";
		return 0;
	}
	else
	{
		amount_of_cash = amount_of_cash + cash_in;
		amount_of_dollars = amount_of_cash / 100;
		amount_of_cents = amount_of_cash - (amount_of_dollars * 100);
		return 1;
	}
}

void Teller_window::print()
{
	// Precondition: called by full service facility to print status of teller windows
	// Postcondition: prints 'closed' if open_or_closed = 0 and 'open' if open_or_closed = 1, also prints amount
		// of cash given

	if (open_or_closed == CLOSED)
	{
		cout << "closed ($" << setw(6) << amount_of_dollars << ".";
		if (amount_of_cents < 10)
		{
			cout << "0" << amount_of_cents << ")\n";
		}
		else
		{
			cout << amount_of_cents << ")\n";
		}
	}
	if (open_or_closed == OPEN)
	{
		cout << "open   ($" << setw(6) << amount_of_dollars << ".";
		if (amount_of_cents < 10)
		{
			cout << "0" << amount_of_cents << ")\n";
		}
		else
		{
			cout << amount_of_cents << ")\n";
		}
	}
}
