// Jonathan Adams
// Class declarations for Address class

#ifndef UTILITY_CLASSES_H
#define UTILITY_CLASSES_H

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

#include "definitions.h"

class Address
{
	// Precondition: groups all Address information
	// Postcondition:  declares all of the variables and constructors associated with the Address
 
public:
	Address() {}
	Address(string street, string city, string state, string zip);	// will be used to initialize values for 
																	// Address variables
	void printAddress();		// will be used to display Address variables

private:
	string street;		// array of up to 30 characters to hold street information
	string city;		// array of up to 20 characters to hold city name
	string state;		// array of 2 characters to hold state abbreviation
	string zip;		// holds zip code plus 4 digits
};

class Facility
{
	// Precondition: sets up a grouping for those variables and necessary functions common to all types of facilities
	// Postcondition: declares all of the variables and pointers excluse to Facility

public:
	Facility() {}			// default constructor
	Facility(int location_id_in, Address address_in);		// intializing constructor
	virtual ~Facility();		// destructor
	virtual void open_lane(int location_id, int lane_number) = 0;		// pure virtual function for opening a drive through lane
	virtual void close_lane(int location_id, int lane_number) = 0;		// pure virtual function for closing a drive through lane
	virtual void open_teller(int location_id, int teller_number, long int cash_in) = 0;	// pure virtual function for opening a teller window
	virtual void close_teller(int location_id, int teller_number) = 0;	// pure virtual function for closing a teller window
	virtual void add_cash(int location_id, long int cash_in) = 0;		// pure virtual function for adding cash to an ATM
	int get_id();		// gets id of facility being changed from Facility array
	virtual int get_type() = 0;			// pure virtual function which gets type of facility to be changed from Facility array
	virtual int withdraw(long int cash_out, int lane_number, int teller_number) = 0;	// pure
															// virtual function for a withdrawal
	virtual int deposit(long int cash_in, int lane_number, int teller_number) = 0;		// pure
															// virtual function for a deposit
	virtual void print();		// print function

protected:
	int location_id;
	Address address;
};

class Drive_through_lane
{
	// Precondition: provides grouping for everything specific to a drive through lane
		// called by a full service or drive through faciliity
	// Postcondition:  sets all drive through lanes to CLOSED

public:
	Drive_through_lane();	// default constructor
	void open_lane();	// opens specific lane
	void close_lane();	// closes specific lane
	int withdraw();		// makes withdrawal
	int deposit();		// makes deposit
	virtual void print();		// print function for drive through lane class

private:
	int open_or_closed;		// tells whether lane is open or closed
};

class Teller_window
{
	// Precondition:  provides grouping for everything specific to a teller window
		// called by full service facility
	// Postcondition:  sets all teller windows to closed with zero cash

public:
	Teller_window();		// default constructor
	void open_teller(long int cash_in);	// opens specific teller window
	void close_teller();	// closes specific teller window
	int withdraw(long int cash_out);		// makes withdrawal
	int deposit(long int cash_in);		// makes deposit
	virtual void print();		// print function for teller window class

private:
	int open_or_closed;		// tells whether window is open or closed
	long int amount_of_cash;		// gives amount of cash at window
	int amount_of_dollars;		// used to store amount of dollars at window
	int amount_of_cents;		// used to store amount of cents at window
};

class ATM : public Facility 
{
	// Precondition: sets up a grouping for those variables and necessary functions specific to location type ATM
	// Postcondition: declares all variables and functions exclusive to ATMs

public:
	ATM() {}			// default constructor
	ATM(long int location_id_in, Address address_in);		// intializing constructor
	virtual void open_lane(int location_id, int lane_number);		// function for opening a drive through lane
	virtual void close_lane(int location_id, int lane_number);		// function for closing a drive through lane
	virtual void open_teller(int location_id, int teller_number, long int cash_in);	// function for opening a teller window
	virtual void close_teller(int location_id, int teller_number);	// function for closing a teller window
	virtual void add_cash(int location_id, long int cash_in);		// function for adding cash to ATM
	virtual int get_type();			// returns facility type
	virtual int withdraw(long int cash_out, int, int);		// makes withdrawal
	virtual int deposit(long int, int, int);	// no deposit to ATM facility
	virtual void print();		// print function

private:
	long int amount_of_cash;
	int amount_of_dollars;
	int amount_of_cents;
};

class Drive_through : public Facility
{
	// Precondition: sets up a grouping for those variables and necessary functions specific to a Drive-through facility type
	// Postcondition: declares all variables and functions exclusive to Drive throughs

public:
	Drive_through() {}			// default constructor
	Drive_through(int location_id_in, Address address_in, int number_of_lanes_in);		// intializing constructor
	virtual ~Drive_through();			// destructor
	void open_lane(int location_id, int lane_number);		// function for opening a drive through lane
	void close_lane(int location_id, int lane_number);		// function for closing a drive through lane
	void open_teller(int location_id, int teller_number, long int cash_in);	// function for opening a teller window
	void close_teller(int location_id, int teller_number);	// function for closing a teller window
	void add_cash(int location_id, long int cash_in);		// function for adding cash
	virtual int get_type();			// returns facility type
	int withdraw(long int cash_out, int lane_number, int);		// makes withdrawal
	int deposit(long int cash_in, int lane_number, int);		// makes deposit
	virtual void print();			// print function

private:
	int number_of_lanes;
	Drive_through_lane *drive_through_lane;		// pointer to Drive through lane class to get info on individual lanes
};

class Full_service : public Facility
{
	// Precondition: requires input from data file
	// Postcondition: sets up a grouping for those variables and necessary functions specific to a Full service facility type

public:
	Full_service() {}			// default constructor
	Full_service(int location_id, Address address_in, int num_teller_windows_in, int number_of_lanes_in);	// initializing constructor
	virtual ~Full_service();		// destructor
	void open_lane(int location_id, int lane_number);		// function for opening a drive through lane
	void close_lane(int location_id, int lane_number);		// function for closing a drive through lane
	void open_teller(int location_id, int teller_number, long int cash_in);	// function for opening a teller window
	void close_teller(int location_id, int teller_number);	// function for closing a teller window
	void add_cash(int location_id, long int cash_in);		// function for adding cash to ATM
	virtual int get_type();			// returns facility type
	int withdraw(long int cash_out, int lane_number, int teller_number);	// makes withdrawal
	int deposit(long int cash_in, int lane_number, int teller_number);		// makes deposit
	virtual void print();		// print function

private:
	int num_teller_windows;
	int number_of_lanes;
	Teller_window *teller_window;	// pointer to Teller window class to get information on individual windows
	Drive_through_lane *drive_through_lane;	// pointer to Drive_through_lane class to get info on individual lanes
};


#endif