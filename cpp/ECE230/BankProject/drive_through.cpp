// Jonathan Adams
// Drive-through class functions

#include "utility_classes.h"

Drive_through::Drive_through(int location_id_in, Address address_in, int number_of_lanes_in)
{
	// Precondition: called when Drive through facility class is initialized
	// Postcondition: gets input of facility information in addition to number of lanes, also intitializes
		// drive through lanes
	location_id = location_id_in;
	address = address_in;
	number_of_lanes = number_of_lanes_in;
	drive_through_lane = new Drive_through_lane[number_of_lanes];
}

Drive_through::~Drive_through()
{
	// destructor clears all memory pertaining to Drive-through class

	delete [] drive_through_lane;	// delete drive-through lane pointer
}

void Drive_through::open_lane(int location_id, int lane_number)
{
	// Precondition: called when lane status is changed to open in Drive through class
	// Postcondition: changes specific lane status to Open

	drive_through_lane[lane_number].open_lane();
}

void Drive_through::close_lane(int location_id, int lane_number)
{
	// Precondition: called when lane status is changed to closed in Drive through class
	// Postcondition: changes specific lane status to Closed

	drive_through_lane[lane_number].close_lane();
}

void Drive_through::open_teller(int location_id, int teller_number, long int cash_in)
{
	// Precondition: called when teller window status is changed to open in Drive through class
	// Postcondition: returns error since Drive through class has no teller windows

	cout << "ERROR: Cannot set window status for a drive-through facility (id " << location_id << ", window "
		<< teller_number << ")!\n\n";
}

void Drive_through::close_teller(int location_id, int teller_number)
{
	// Precondition: called when teller window status is changed to closed in Drive through class
	// Postcondition: returns error since Drive through class has no teller windows

	cout << "ERROR: Cannot set window status for a drive-through facility (id " << location_id << ", window "
		<< teller_number << ")!\n\n";
}

void Drive_through::add_cash(int location_id, long int cash_in)
{
	// Precondition: called when cash is added
	// Postcondition: cannot add cash because it is not an ATM

	cout << "ERROR: Cannot add cash to a drive-through facility (id " << location_id << ")!\n\n";
}

int Drive_through::get_type()
{
	// returns facility type Drive-through

	return DRIVE_THROUGH;
}

int Drive_through::withdraw(long int cash_out, int lane_number, int teller_number)
{
	// Precondition: called when withdrawal is attempted at drive through facility
	// Postcondition: check if withdrawal can be made then executes

	if (lane_number > number_of_lanes)
	{
		cout << "ERROR: Cannot withdraw from lane for drive-through facility (id " << location_id << ", lane " << lane_number << ")!\n\n";
		return 0;
	}
	else if (drive_through_lane[lane_number].withdraw() == 0)
	{
		cout << "ERROR: Cannot withdraw from closed lane for drive-through facility (id " << location_id << ", lane " << lane_number
			<< ")!\n\n";
		return 0;
	}
	else
	{
		return 1;
	}
}

int Drive_through::deposit(long int cash_in, int lane_number, int teller_number)
{
	// Precondition: called when deposit is attempted at drive through facility
	// Postcondition: checks if deposit can be made then executes

	if (lane_number > number_of_lanes)
	{
		cout << "ERROR: Cannot deposit from lane for drive-through facility (id " << location_id << ", lane " << lane_number << ")!\n\n";
		return 0;
	}
	else if (drive_through_lane[lane_number].deposit() == 0)
	{
		cout << "ERROR: Cannot deposit from closed lane for drive-through facility (id " << location_id << ", lane " << lane_number
			<< ")!\n\n";
		return 0;
	}
	else
	{
		return 1;
	}
}

void Drive_through::print()
{
	// Precondition: called when Drive through facility information is printed
	// Postcondition: calls facility print function, then prints number of lanes

	Facility::print();	// calls Facility print function
	
	cout << "\nDrive-Throughs:\n";

	for (int i = 0; i < number_of_lanes; i++)
	{
		// prints out for each lane available

		if (i < 10)
		{
			// checks if extra zero needs to be printed to hold place
			cout << "Lane 0" << i << ":\t";
			drive_through_lane[i].print();
		}
		else
		{
			cout << "Lane " << i << ":\t";
			drive_through_lane[i].print();
		}
	}
	
	cout << endl << endl;
}