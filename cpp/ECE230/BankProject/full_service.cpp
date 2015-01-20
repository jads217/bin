// Jonathan Adams
// Full service class functions

#include "utility_classes.h"

Full_service::Full_service(int location_id_in, Address address_in, int num_teller_windows_in, int number_of_lanes_in)
{
	// Precondition: called when Full service facility is initialized
	// Postcondition: gets input of facility information in addition to number of lanes and number of teller windows
		// also intializes drive through lanes and teller windows

	location_id = location_id_in;
	address = address_in;
	num_teller_windows = num_teller_windows_in;
	number_of_lanes = number_of_lanes_in;
	teller_window = new Teller_window[num_teller_windows];
	drive_through_lane = new Drive_through_lane[number_of_lanes];
}

Full_service::~Full_service()
{
	// destructor clears all memory pertaining to full service class

	delete [] drive_through_lane;
	delete [] teller_window;
}

void Full_service::open_lane(int location_id, int lane_number)
{
	// Precondition: called when lane status is changed in Full service class
	// Postcondition: returns error since Full service class has no drive through lanes

	if (lane_number > number_of_lanes)
	{
		cout << "ERROR: Cannot set lane status for a full-service facility (id " << location_id << ", lane " << lane_number << ")!\n\n";
	}
	else
	{
		drive_through_lane[lane_number].open_lane();
	}
}

void Full_service::close_lane(int location_id, int lane_number)
{
	// Precondition: called when lane status is changed in Full service class
	// Postcondition: returns error since Full service class has no drive through lanes

	if (lane_number > number_of_lanes)
	{
		cout << "ERROR: Cannot set lane status for a full-service facility (id " << location_id << ", lane " << lane_number << ")!\n\n";
	}
	else
	{
        drive_through_lane[lane_number].close_lane();
	}
}

void Full_service::open_teller(int location_id, int teller_number, long int cash_in)
{
	// Precondition: called when window status is changed to open in Full service class
	// Postcondition: sets specific teller window to Open

	teller_window[teller_number].open_teller(cash_in);
}

void Full_service::close_teller(int location_id, int teller_number)
{
	// Precondition: called when window status is changed to closed in Full service class
	// Postcondition: sets specific teller window to Closed

	teller_window[teller_number].close_teller();
}

void Full_service::add_cash(int location_id, long int cash_in)
{
	// Precondition: called when cash is added
	// Postcondition: cannot add cash because it is not an ATM

	cout << "ERROR: Cannot add cash to a full-service facility (id " << location_id << ")!\n\n";
}

int Full_service::get_type()
{
	// returns facility type Full service

	return FULL_SERVICE;
}

int Full_service::withdraw(long int cash_out, int lane_number, int teller_number)
{
	// Precondition: called when withdrawal is attempted on full service facility
	// Postcondition: checks if withdrawal is possible, then executes

	if (lane_number != 99)
	{
        if (lane_number > number_of_lanes)
		{
			cout << "ERROR: Cannot withdraw from lane for full-service facility (id " << location_id << ", lane " << lane_number
				<< ")!\n\n";
			return 0;
		}
		else if (drive_through_lane[lane_number].withdraw() == 0)
		{
			cout << "ERROR: Cannot withdraw from closed lane for full-service facility (id " << location_id << ", lane "
				<< lane_number << ")!\n\n";
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		if (teller_number > num_teller_windows)
		{
			cout << "ERROR: Cannot withdraw from window for full-service facility (id " << location_id << ", window " << teller_number
				<< ")!\n\n";
			return 0;
		}
		else if (teller_window[teller_number].withdraw(cash_out) == 0)
		{
			cout << "ERROR: Cannot withdraw from closed window for full-service facility (id " << location_id << ", window "
				<< teller_number << ")!\n\n";
		}
		else if (teller_window[teller_number].withdraw(cash_out) == 1)
		{
			cout << "ERROR: Inadequate cash for withdrawal at full-service facility (id " << location_id << ", window "
				<< teller_number << ")!\n\n";
			return 0;
		}
		else
		{
			return 1;
		}
	}
}

int Full_service::deposit(long int cash_in, int lane_number, int teller_number)
{
	// Precondition: called if deposit is attempted at full service facility
	// Postcondition: checks if deposit can be made then executes

	if (lane_number != 99)
	{
        if (lane_number > number_of_lanes)
		{
			cout << "ERROR: Cannot deposit from lane for full-service facility (id " << location_id << ", lane " << lane_number
				<< ")!\n\n";
			return 0;
		}
		else if (drive_through_lane[lane_number].deposit() == 0)
		{
			cout << "ERROR: Cannot deposit from closed lane for full-service facility (id " << location_id << ", lane "
				<< lane_number << ")!\n\n";
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		if (teller_number > num_teller_windows)
		{
			cout << "ERROR: Cannot deposit from window for full-service facility (id " << location_id << ", window " << teller_number
				<< ")!\n\n";
			return 0;
		}
		else if (teller_window[teller_number].deposit(cash_in) == 0)
		{
			cout << "ERROR: Cannot deposit from closed window for full-service facility (id " << location_id << ", window "
				<< teller_number << ")!\n\n";
			return 0;
		}
		else
		{
			return 1;
		}
	}
}

void Full_service::print()
{
	// Precondition: called when Full service information is printed
	// Postcondition: calls facility print function and then prints number of teller windows and number of drive
		// through lanes

	Facility::print();	// calls Facility print function
	cout << "\nWindows:\n";
	for (int i = 0; i < num_teller_windows; i++)
	{
		// prints out for each teller window available
		if (i < 10)
		{
			// checks if extra zero needs to be printed to hold place

			cout << "Window 0" << i << ":\t";
			teller_window[i].print();
		}
		else
		{
			cout << "Window " << i << ":\t";
			teller_window[i].print();
		}
	}
	
	cout << "\nDrive-Throughs:\n";

	for (int j = 0; j < number_of_lanes; j++)
	{
		// prints out for each lane available

		if (j < 10)
		{
			// checks if extra zero needs to be printed to hold place

			cout << "Lane 0" << j << ":\t";
			drive_through_lane[j].print();
		}
		else
		{
			cout << "Lane " << j << ":\t";
			drive_through_lane[j].print();
		}
	}
	cout << endl << endl;
}
