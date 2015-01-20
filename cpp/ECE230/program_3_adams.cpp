// Jonathan Adams
// ECE 230 Program 3
// due Thursday, Feb. 12

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

#include "definitions.h"
#include "account_class.h"
#include "utility_classes.h"

using namespace std;

using std::cout;
using std::cin;
using std::endl;

int main()
{
	Account *account;		// pointer to Account class
	Address *address;		// pointer to Address class
	string inp_acc_id;		// string used to get account id number from file
	long int account_id;	// account id number
	string inp_acc_bal;		// string used to get account balance from file
	double account_balance;	// account balance
	string inp_acc_type;	// string used to get account type from file
	int account_type;		// account type number
	string first_name;		// first name of account holder
	string last_name;		// last name of account holder
	string street;			// street address
	string city;
	string state;
	string zip;

	// allows for data to be read from text file
	ifstream inp;
	inp.open("prg3data.txt", ios::in);
	
	for (int i = 0; i < 5; i++)
	{
		
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

		// print information
		address = new Address(street, city, state, zip);

		account = new Account(first_name, last_name, account_id, *address, account_balance, account_type);
		account ->printAccount();

		// delete class information once line has been printed
		delete account;
		delete address;
	}

return 0;
}