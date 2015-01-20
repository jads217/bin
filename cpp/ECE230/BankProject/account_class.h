// Jonathan Adams
// Class declarations for Account class

#ifndef ACCOUNT_CLASS_H
#define ACCOUNT_CLASS_H


#include "utility_classes.h"



class Account
{
	// stores values for account first name, last name, id number, account balance, and account type and calls constructors
		// needed to manipulate data

public:
	Account() {}
	Account(string first_name_in, string last_name_in, long int account_id_in, Address address_in, double account_balance_in, long int account_type_in);
	int get_account_id();		// matches id of account to be changed with its position in the account array
	int get_account_type();		// gives account type for given account
	double get_balance();		// returns account balance of given account
	double account_withdraw(long int cash_out);		// makes withdrawal from given account
	double account_deposit(long int cash_in);		// makes deposit to given account
	void add_interest();		// adds interest to all accounts
	void printAccount();

private:
	string first_name;
	string last_name;
	long int account_id;
	Address address;
	double account_balance;
	long int account_type;
};

#endif