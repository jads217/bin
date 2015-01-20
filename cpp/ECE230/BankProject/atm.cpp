// Jonathan Adams
// ATM Class functions

#include "utility_classes.h"

ATM::ATM(long int location_id_in, Address address_in)
{
	// Precondition: called when ATM class is initialized
	// Postcondition: sets amount of cash to zero and gets facility information
	
	location_id = location_id_in;
	address = address_in;
	amount_of_cash = 0;
	amount_of_dollars = amount_of_cash / 100;
	amount_of_cents = amount_of_cash - (amount_of_dollars * 100);
}

void ATM::open_lane(int location_id, int lane_number)
{
	// Precondition: called when lane status is changed in ATM class
	// Postcondition: returns error since ATM class has no drive through lanes

	cout << "ERROR: Cannot set lane status for ATM facility (id " << location_id << ", lane "
		<< lane_number << ")!\n\n";
}

void ATM::close_lane(int location_id, int lane_number)
{
	// Precondition: called when lane status is changed in ATM class
	// Postcondition: returns error since ATM class has no drive through lanes

	cout << "ERROR: Cannot set lane status for ATM facility (id " << location_id << ", lane "
		<< lane_number << ")!\n\n";
}

void ATM::open_teller(int location_id, int teller_number, long int cash_in)
{
	// Precondition: called when teller window status is changed to open in ATM class
	// Postcondition: returns error since ATM class has no teller windows

	cout << "ERROR: Cannot set window status for an ATM facility (id " << location_id << ", window "
		<< teller_number << ")!\n\n";
}

void ATM::close_teller(int location_id, int teller_number)
{
	// Precondition: called when teller window status is changed to closed in ATM class
	// Postcondition: returns error since ATM class has no teller windows

	cout << "ERROR: Cannot set window status for an ATM facility (id " << location_id << ", window "
		<< teller_number << ")!\n\n";
}

void ATM::add_cash(int location_id, long int cash_in)
{
	// Precondition: called when cash is added to ATM
	// Postcondition: adds given cash to existing cash in ATM

	amount_of_cash = amount_of_cash + cash_in;
	amount_of_dollars = amount_of_cash / 100;
	amount_of_cents = amount_of_cash - (amount_of_dollars * 100);
}

int ATM::get_type()
{
	// returns facility type ATM

	return ATM_CONST;
}

int ATM::withdraw(long int cash_out, int lane_number, int teller_number)
{
	// Precondition: called if withdrawal is attempted from ATM
	// Postcondition: checks if withdrawal can be made then executes

	if (cash_out > amount_of_cash)
	{
		cout << "ERROR: Inadequate cash for withdrawal at ATM facility (id " << location_id << ")!\n\n";
		return 0;
	}
	else
	{
		amount_of_cash = amount_of_cash - cash_out;
		amount_of_dollars = amount_of_cash / 100;
		amount_of_cents = amount_of_cash - (amount_of_dollars * 100);
		return 1;
	}
}

int ATM::deposit(long int cash_in, int lane_number, int teller_number)
{
	// function will not be called because deposit cannot be made at ATM

	return 0;
}

void ATM::print()
{
	// Precondition: called when ATM information is printed
	// Postcondition: calls facility print function, then prints amount of money in ATM

	Facility::print();	// calls Facility print function

	cout << "\nATM Cash Stash: $" << setw(6) << amount_of_dollars;
	
	if (amount_of_cents < 10)
	{
		// checks if extra zero needs to be printed to hold place

		cout << ".0" << amount_of_cents << "\n\n\n";
	}
	else
		cout << "." << amount_of_cents << "\n\n\n";
}