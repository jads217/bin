// Jonathan Adams
// ECE 230 Program 6
// due Wednesday, March 10

#include "account_class.h"
#include "utility_classes.h"

int main()
{
	// Precondition: beginning of program
	// Postcondition: gets inputs from data file and directs them to correct classes, runs all program functions

	// define variables and pointers needed
	Address *address;		// pointer to Address class
	ATM *atm;				// pointer to ATM class
	Drive_through *drive_through;	// pointer to drive through class
	Full_service *full_service;		// pointer to full service class

	typedef Facility *facility_pointer;			// defines facility_pointer as an alias of Facility*
	facility_pointer Facility_database[20];		// array of pointers which serves as an alias for Facility
	
	int switch_command;			// switch command number

	string inp_facility_type;		// string used to get facility type indicator
	int facility_type;			// facility type indicator

	string inp_location_id;		// string used to get location id number from file
	int location_id;	// location id number
	int find_location_id;	// used to search for location id in Facility array
	string street;			// street address
	string city;
	string state;
	string zip;
	
	string inp_number_of_lanes;		// string used to get number of drive through lanes from file
	int number_of_lanes;		// number of drive through lanes
	
	string inp_num_teller_windows;		// string used to get number of teller windows from file
	int num_teller_windows;		// number of teller windows

	string inp_lane_number;			// string used to get specific lane number to be modified
	int lane_number;			// specific lane number to be modified

	string inp_teller_number;		// string used to get specific teller number to be modified
	int teller_number;			// specific lane number to be modified

	string inp_cash_in;			// string used to get cash to be added
	long int cash_in;			// cash to be added
	
	string inp_cash_out;		// string used to get cash to be taken out
	long int cash_out;			// cash to be taken out

	long int dollars;
	int cents;

	int facility_number = 0;	// will be used to place new pointers into positions in array
	
	int check_array;		// used to search array for corresponding id number
	int print_array;		// used to print array members

	Account *account;		// pointer to Account class

	string inp_acc_type;	// string used to get account type indicator
	int account_type;		// facility type indicator

	string inp_junk;		// string used to skip rest of data line in withdrawal and deposit functions

	int account_number = 0;		// will be used to place new pointers into positions in array

	int account_index;		// used to recall information from correct account pointer
	int facility_index;		// used to recall information from correct facility pointer

	typedef Account *account_pointer;		// defines account_pointer as an alias of Account*
	account_pointer Account_database[20];	// array of pointers which serves as alias for Account

	string inp_acc_id;		// string used to get account id
	long int account_id;		// account id number
	long int find_account_id;		// used to find account id number in string of accounts

	string first_name;
	string last_name;

	string inp_acc_bal;		// string used to get account balance from file
	double account_balance;		// account balance

	string inp_lane_or_window;		// sting used to get lane or window determinant for full service class
	int lane_or_window;


	// allows for data to be read from text file
	ifstream inp;
	inp.open("prg6data.txt", ios::in);
	
	do {
		// Precondition: begins reading from data file to perform given actions
		// Postcondition: 

		inp >> switch_command;
		if ((switch_command != 7) || (switch_command != 11) || (switch_command != 14))
		{
			inp.get();
		}
        
		switch (switch_command)
		{
		case OPEN_FACILITY:
			// installs given attributes to a new facility type
			
			getline(inp, inp_facility_type, ',');		// read in facility type indicator as string
			facility_type = strtol(inp_facility_type.c_str(), NULL, 10);	// convert facility type string to long int
			
			switch (facility_type)
			{
			case ATM_CONST:
				// opens new ATM with given attributes

				// extract data as strings from file to ATM class
				getline(inp, inp_location_id, ',');
				getline(inp, street, ',');
				getline(inp, city, ',');
				getline(inp, state, ',');
				getline(inp, zip, '\n');

				// convert location string to long int
				location_id = strtol(inp_location_id.c_str(), NULL, 10);

				address = new Address(street, city, state, zip);	// create new Address pointer
				atm = new ATM(location_id, *address);		// creates new ATM pointer

				// puts new ATM pointer into Facility array
				Facility_database[facility_number] = new ATM(location_id, *address); 
				facility_number++;

				delete address;		// delete address pointer
				delete atm;		// delete atm pointer

				break;

			case DRIVE_THROUGH:
				// opens new Drive-through facility with given attributes

				// extract data as strings from file to drive through class
				getline(inp, inp_location_id, ',');
				getline(inp, street, ',');
				getline(inp, city, ',');
				getline(inp, state, ',');
				getline(inp, zip, ',');
				getline(inp, inp_number_of_lanes, '\n');

				// convert location string to long int
				location_id = strtol(inp_location_id.c_str(), NULL, 10);

				// convert number of lanes to long int
				number_of_lanes = strtol(inp_number_of_lanes.c_str(), NULL, 10);

				address = new Address(street, city, state, zip);	// create new Address pointer
                drive_through = new Drive_through(location_id, *address, number_of_lanes);	// create new Drive through pointer

				// puts new Drive-through pointer into Facility array
				Facility_database[facility_number] = new Drive_through(location_id, *address, number_of_lanes);
				facility_number++;

				delete address;		// delete address pointer
				delete drive_through;	// delete drive through pointer

				break;

			case FULL_SERVICE:
				// opens new Full Service facility with given attributes

				// extract data as strings from file to full service class
				getline(inp, inp_location_id, ',');
				getline(inp, street, ',');
				getline(inp, city, ',');
				getline(inp, state, ',');
				getline(inp, zip, ',');
				getline(inp, inp_num_teller_windows, ',');
				getline(inp, inp_number_of_lanes, '\n');

				// convert location id string to long int
				location_id = strtol(inp_location_id.c_str(), NULL, 10);

				// convert number of teller windows to long int
				num_teller_windows = strtol(inp_num_teller_windows.c_str(), NULL, 10);

				// convert number of lanes to long int
				number_of_lanes = strtol(inp_number_of_lanes.c_str(), NULL, 10);

				address = new Address(street, city, state, zip);	// create new Address pointer
				// create new full service pointer
				full_service = new Full_service(location_id, *address, num_teller_windows, number_of_lanes);
                
				// puts new Full service pointer into Facility array
				Facility_database[facility_number] = new Full_service(location_id, *address, num_teller_windows, number_of_lanes);
				facility_number++;

				delete address;		// delete address pointer
				delete full_service;	// delete full service pointer

				break;
			}
		
			break;

		case OPEN_DRIVE_THROUGH_LANE:
			// sets specific drive through lane to OPEN
			
			// get data from file
			getline(inp, inp_location_id, ',');
			getline(inp, inp_lane_number, '\n');

			// convert location id string to long int
			find_location_id = strtol(inp_location_id.c_str(), NULL, 10);

			// convert lane number string to long int
			lane_number = strtol(inp_lane_number.c_str(), NULL, 10);

			for (check_array = 0; check_array < facility_number; check_array++)
			{
				if (Facility_database[check_array] ->get_id() == find_location_id)
				{
					Facility_database[check_array] ->open_lane(find_location_id, lane_number);
				}
			}

			break;

		case CLOSE_DRIVE_THROUGH_LANE:
			// sets specific drive through lane to CLOSED

			// get data from file
			getline(inp, inp_location_id, ',');
			getline(inp, inp_lane_number, '\n');

			// convert location id string to long int
			find_location_id = strtol(inp_location_id.c_str(), NULL, 10);

			// convert lane number string to long int
			lane_number = strtol(inp_lane_number.c_str(), NULL, 10);

			for (check_array = 0; check_array < facility_number; check_array++)
			{
				if (Facility_database[check_array] ->get_id() == find_location_id)
				{
					Facility_database[check_array] ->close_lane(find_location_id, lane_number);

					break;
				}
			}


			break;

		case OPEN_TELLER_WINDOW:
			// sets specific teller window to OPEN

			// get data from file
			getline(inp, inp_location_id, ',');
			getline(inp, inp_teller_number, ',');
			getline(inp, inp_cash_in, '\n');

			// convert location id string to long int
			find_location_id = strtol(inp_location_id.c_str(), NULL, 10);

			// convert teller number string to long int
 			teller_number = strtol(inp_teller_number.c_str(), NULL, 10);

			// convert cash in string to long int
			cash_in = strtol(inp_cash_in.c_str(), NULL, 10);

			for (check_array = 0; check_array < facility_number; check_array++)
			{
				if (Facility_database[check_array] ->get_id() == find_location_id)
				{
					Facility_database[check_array] ->open_teller(find_location_id, teller_number, cash_in);

					break;
				}
			}


			break;

		case CLOSE_TELLER_WINDOW:
			// sets specific teller window to CLOSED

			// get data from file
			getline(inp, inp_location_id, ',');
			getline(inp, inp_teller_number, '\n');

			// convert location id string to long int
			find_location_id = strtol(inp_location_id.c_str(), NULL, 10);

			// convert teller number string to long int
			teller_number = strtol(inp_teller_number.c_str(), NULL, 10);

			for (check_array = 0; check_array < facility_number; check_array++)
			{
				if (Facility_database[check_array] ->get_id() == find_location_id)
				{
					Facility_database[check_array] ->close_teller(find_location_id, teller_number);

					break;
				}
			}

			break;

		case ADD_CASH_TO_ATM:
			// adds given amount of cash to ATM

			// get data from file
			getline(inp, inp_location_id, ',');
			getline(inp, inp_cash_in, '\n');

			// convert location id string to long int
			find_location_id = strtol(inp_location_id.c_str(), NULL, 10);

			// convert cash_in string to long int
			cash_in = strtol(inp_cash_in.c_str(), NULL, 10);

			for (check_array = 0; check_array < facility_number; check_array++)
			{
				if (Facility_database[check_array] ->get_id() == find_location_id)
				{
					Facility_database[check_array] ->add_cash(find_location_id, cash_in);

					break;
				}
			}

			break;

		case PRINT_FACILITIES:
			// prints all information regarding current facilities

			for (print_array = 0; print_array < facility_number; print_array++)
			{
				Facility_database[print_array] ->print();
			}

			break;

		case OPEN_ACCOUNT:
			// opens a new account of given type

			// extract data as strings from file
			getline(inp, inp_acc_id, ',');
			getline(inp, first_name, ',');
			getline(inp, last_name, ',');
			getline(inp, street, ',');
			getline(inp, city, ',');
			getline(inp, state, ',');
			getline(inp, zip, ',');
			getline(inp, inp_acc_bal, ',');
			getline(inp, inp_acc_type, '\n');

			// convert strings to real types
			account_id = strtol(inp_acc_id.c_str(), NULL, 10);
			account_balance = strtod(inp_acc_bal.c_str(), NULL);
			account_type = strtol(inp_acc_type.c_str(), NULL, 10);

			address = new Address(street, city, state, zip);	// create new address pointer

			// create new account pointer
			account = new Account(first_name, last_name, account_id, *address, account_balance, account_type);

			// puts new Account pointer into Account array
			Account_database[account_number] = new Account(first_name, last_name, account_id, *address, account_balance, account_type);
			account_number++;

			delete address;		// delete address pointer
			delete account;		// delete account pointer

			break;

		case CLOSE_ACCOUNT:
			// closes a specified account

			// extract data as string from file
			getline(inp, inp_acc_id, '\n');

			find_account_id = strtol(inp_acc_id.c_str(), NULL, 10);		// convert string to type long int
			
			for (check_array = 0; check_array < account_number; check_array++)
			{
				if ((Account_database[check_array] ->get_account_id() == find_account_id))
				{
					if (check_array != (account_number - 1))
					{
						for (int delete_index = check_array; delete_index < account_number; delete_index++)
						{
							// replace account pointer to be deleted with account pointer immediately following and pull up rest of
								// array elements
							Account_database[delete_index] = Account_database[delete_index + 1];
						}
					}
					account_number--;		// decrease length of array by one
					break;
				}
			}

			break;

		case CLOSE_FACILITY:
			// closes a specified facility

			// extract data as string from file
			getline(inp, inp_location_id, '\n');
			
			// convert location id string to long int
			find_location_id = strtol(inp_location_id.c_str(), NULL, 10);

			for (check_array = 0; check_array < facility_number; check_array++)
			{
				if ((Facility_database[check_array] ->get_id() == find_location_id))
				{
					Facility_database[check_array] ->~Facility();	// sends pointer to destructor to be deleted

					if (check_array != (facility_number - 1))
					{
						for (int delete_index = check_array; delete_index < facility_number; delete_index++)
						{
							// replace facility pointer to be deleted with facility pointer immediately following and pull up rest
								// of array elements
							Facility_database[delete_index] = Facility_database[delete_index + 1];
						}
					}
					facility_number--;		// decrease length of array by one
					break;
				}
			}

			break;

		case PRINT_ACCOUNTS:
			// prints all information regarding current accounts

			for (print_array = 0; print_array < account_number; print_array++)
			{
				Account_database[print_array] ->printAccount();
			}

			break;

		case WITHDRAWAL:
			// processes a withdrawal from a particular account at a particular facility

			// get account id number from file
			getline(inp, inp_acc_id, ',');
			find_account_id = strtol(inp_acc_id.c_str(), NULL, 10);

			for (check_array = 0; check_array < account_number; check_array++)
			{
				// find account pointer corresponding to given account id
				if (Account_database[check_array] ->get_account_id() == find_account_id)
				{
					account_index = check_array;		// save array index number
					check_array = account_number;		// quit for loop early
				}
			}

			if (Account_database[account_index] ->get_account_type() == account_type_cd)
			{
				// test for type of account, if CD no withdrawal can be made

				getline(inp, inp_junk, '\n');	// skip data from rest of line

				cout << "ERROR: Cannot withdraw from CD (acct " << find_account_id << ")!\n\n";
			}
			else
			{
				// not CD
                // get amount of cash to be withdrawn from data file
				getline(inp, inp_cash_out, ',');
				cash_out = strtol(inp_cash_out.c_str(), NULL, 10);

				if (((Account_database[account_index] ->get_balance()) * 100) < cash_out)
				{
					// check if there is enough money to be withdrawn

					cout << "ERROR: Inadequate balance for withdrawal (acct " << find_account_id << ")!\n\n";

					getline(inp, inp_junk, '\n');	// skip data from rest of line
				}
				else
				{
					// get facility id number
					inp >> find_location_id;

					for (check_array = 0; check_array < facility_number; check_array++)
					{
						// find facility pointer corresponding to given location id
						if (Facility_database[check_array] ->get_id() == find_location_id)
						{
							facility_index = check_array;
							check_array = facility_number;
						}
					}

					switch (Facility_database[facility_index] ->get_type())
					{
						// directs withdrawal to correct facility

					case ATM_CONST:
						
						// test if withdrawal can be made from given facility
						if (Facility_database[facility_index] ->withdraw(cash_out, 0, 0) == 1)
						{
							Account_database[account_index] ->account_withdraw(cash_out);
							dollars = cash_out / 100;
							cents = cash_out - (dollars * 100);
							if (cents < 10)
							{
                                cout << "Withdrawal: $" << dollars << ".0" << cents << " from account "
									<< find_account_id << "." << endl << endl;
							}
							else
							{
								cout << "Withdrawal: $" << dollars << "." << cents << " from account "
									<< find_account_id << "." << endl << endl;
							}
						}
						
					
						break;

					case DRIVE_THROUGH:
                        
						inp.get();
						inp >> lane_number;

						// test is withdrawal can be made from given facility
						if (Facility_database[facility_index] ->withdraw(cash_out, lane_number, 0) == 1)
						{
							Account_database[account_index] ->account_withdraw(cash_out);
							dollars = cash_out / 100;
							cents = cash_out - (dollars * 100);
							if (cents < 10)
							{
                                cout << "Withdrawal: $" << dollars << ".0" << cents << " from account "
									<< find_account_id << "." << endl << endl;
							}
							else
							{
								cout << "Withdrawal: $" << dollars << "." << cents << " from account "
									<< find_account_id << "." << endl << endl;
							}
						}
						
						break;

					case FULL_SERVICE:

						inp.get();
						// get lane or window determinant
						getline(inp, inp_lane_or_window, ',');
						// change to type int
						lane_or_window = strtol(inp_lane_or_window.c_str(), NULL, 10);

						if (lane_or_window == WINDOW)
						{
							inp >> teller_number;	// get window number from data

							if (Facility_database[facility_index] ->withdraw(cash_out, 99, teller_number) == 1)
							{
								account_balance = Account_database[account_index] ->account_withdraw(cash_out);
								dollars = cash_out / 100;
								cents = cash_out - (dollars * 100);
								if (cents < 10)
								{
                                    cout << "Withdrawal: $" << dollars <<".0" << cents << " from account "
										<< find_account_id << "." << endl << endl;
								}
								else
								{
									cout << "Withdrawal: $" << dollars << "." << cents << " from account "
										<< find_account_id << "." << endl << endl;
								}
							}

							break;
						}
						if (lane_or_window == LANE)
						{
							inp >> lane_number;		// get lane number from data

							if (Facility_database[facility_index] ->withdraw(cash_out, lane_number, 0) == 1)
							{
								Account_database[account_index] ->account_withdraw(cash_out);
								dollars = cash_out / 100;
								cents = cash_out - (dollars * 100);
								if (cents < 10)
								{
                                    cout << "Withdrawal: $" << dollars << ".0" << cents << " from account "
										<< find_account_id << "." << endl << endl;
								}
								else
								{
									cout << "Withdrawal: $" << dollars << "." << cents << " from account "
										<< find_account_id << "." << endl << endl;
								}
							}

							break;
						}

						break;
					}
				}
			}

			break;

		case DEPOSIT:
			// processes a deposit from a particular account at a particular facility

			// get account id number from file
			getline(inp, inp_acc_id, ',');
			find_account_id = strtol(inp_acc_id.c_str(), NULL, 10);

			for (check_array = 0; check_array < account_number; check_array++)
			{
				// find account pointer corresponding to given account id
				if (Account_database[check_array] ->get_account_id() == find_account_id)
				{
					account_index = check_array;		// save array index number
					check_array = account_number;		// quit for loop early
				}
			}

			if (Account_database[account_index] ->get_account_type() == account_type_cd)
			{
				// test for type of account, if CD no deposit can be made

				getline(inp, inp_junk, '\n');	// skip data from rest of line

				cout << "ERROR: Cannot deposit to CD (acct " << find_account_id << ")!\n\n";
			}
			else
			{
				// not CD
                // get amount of cash to be deposited from data file
				getline(inp, inp_cash_in, ',');
				cash_in = strtol(inp_cash_in.c_str(), NULL, 10);
		
				// get facility id number
				inp >> find_location_id;

				for (check_array = 0; check_array < facility_number; check_array++)
				{
					// find facility pointer corresponding to given location id
					if (Facility_database[check_array] ->get_id() == find_location_id)
					{
						facility_index = check_array;
						check_array = facility_number;
					}
				}
				
				switch (Facility_database[facility_index] ->get_type())
				{
					// directs withdrawal to correct facility

				case ATM_CONST:
					// deposits cannot be made at ATMs
				
					cout << "ERROR: Cannot perform deposit at ATM facility (id " << find_location_id << ")!\n\n";
					
					break;

				case DRIVE_THROUGH:
					// attempts deposit at drive through facility
                        
					inp.get();
					inp >> lane_number;

					// test if deposit can be made from given facility
					if (Facility_database[facility_index] ->deposit(cash_in, lane_number, 0) == 1)
					{
						Account_database[account_index] ->account_deposit(cash_in);
						dollars = cash_in / 100;
						cents = cash_in - (dollars * 100);
						if (cents < 10)
						{
                            cout << "Deposit: $" << dollars << ".0" << cents << " to account "
								<< find_account_id << "." << endl << endl;
						}
						else
						{
							cout << "Deposit: $" << dollars << "." << cents << " to account "
								<< find_account_id << "." << endl << endl;
						}
					}
					
					break;

				case FULL_SERVICE:

					inp.get();
					// get lane or window determinant
					getline(inp, inp_lane_or_window, ',');
					// change to type int
					lane_or_window = strtol(inp_lane_or_window.c_str(), NULL, 10);

					if (lane_or_window == WINDOW)
					{
						inp >> teller_number;	// get window number from data

						if (Facility_database[facility_index] ->deposit(cash_in, 99, teller_number) == 1)
						{
							account_balance = Account_database[account_index] ->account_deposit(cash_in);
							dollars = cash_in / 100;
							cents = cash_in - (dollars * 100);
							if (cents < 10)
							{
								cout << "Deposit: $" << dollars << ".0" << cents << " to account "
									<< find_account_id << "." << endl << endl;
							}
							else
							{
                                cout << "Deposit: $" << dollars << "." << cents << " to account "
									<< find_account_id << "." << endl << endl;
							}
						}

						break;
					}
					if (lane_or_window == LANE)
					{
						inp >> lane_number;		// get lane number from data

						if (Facility_database[facility_index] ->deposit(cash_in, lane_number, 0) == 1)
						{
							Account_database[account_index] ->account_deposit(cash_in);
							dollars = cash_in / 100;
							cents = cash_in - (dollars * 100);
							if (cents < 10)
							{
								cout << "Deposit: $" << dollars << ".0" << cents << " to account "
									<< find_account_id << "." << endl << endl;
							}
							else
							{
                                cout << "Deposit: $" << dollars << "." << cents << " to account "
									<< find_account_id << "." << endl << endl;
							}
						}

						break;
					}

					break;
				}
			}
			
			break;

		case ADD_INTEREST:
			// adds interest to all current accounts

			for (int interest_array = 0; interest_array < account_number; interest_array++)
			{
				Account_database[interest_array] ->add_interest();
			}

			break;

		case QUIT:
			// signifies end of simulation

			cout << "*****End of simulation******\n\n";
			
			break;	
		}
	}
	while (switch_command != QUIT);


return 0;
}