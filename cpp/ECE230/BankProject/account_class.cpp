// Jonathan Adams
// Definitions for Account member functions

//#include <iomanip>

//using std::setw;
//using std::setprecision;

//#include "utility_classes.h"
#include "account_class.h"
//#include "definitions.h"

Account::Account(string first_name_in, string last_name_in, long int account_id_in, Address address_in, double account_balance_in, long int account_type_in)
{
	// initializing constructor takes input and stores it in private members of Account class

	first_name = first_name_in;
	last_name = last_name_in;
	account_id = account_id_in;
	address = address_in;
	account_balance = account_balance_in;
	account_type = account_type_in;
}

int Account::get_account_id()
{
	// returns id number of accounts stored in account array

	return account_id;
}

int Account::get_account_type()
{
	// returns type of account from account stored in array

	return account_type;
}

double Account::get_balance()
{
	// returns current balance for requested account

	return account_balance;
}

double Account::account_withdraw(long int cash_out)
{
	// Precondition: called when all conditions for withdrawal have been met
	// Postcondition: withdraws cash from particular account

	long int dollars = cash_out / 100;
	double cents = ((double)(cash_out - (dollars * 100)))/ 100.0;

	account_balance = account_balance - (dollars + cents);
	return account_balance;
}

double Account::account_deposit(long int cash_in)
{
	// Precondition: called when all conditions for deposit have been met
	// Postcondition: deposits cash to particular account

	double dollars = ((double)cash_in) / 100.0;
	double cents = ((double)(cash_in - (dollars * 100)))/ 100.0;

	account_balance = account_balance + (dollars + cents);
	return account_balance;
}

void Account::add_interest()
{
	// adds interest to all current accounts

	if (account_type == account_type_savings)
	{
		// increase savings accounts by 2%

		account_balance = account_balance * 1.02;
	}
	if (account_type == account_type_interest_checking)
	{
		// increase interest checking accounts by 1.5%

		account_balance = account_balance * 1.015;
	}
	if (account_type == account_type_business_checking)
	{
		// no interest on business checking accounts

		account_balance = account_balance;
	}
	if (account_type == account_type_cd)
	{
		// increase CD accounts by 3.75%

		account_balance = account_balance * 1.0375;
	}
}

void Account::printAccount()
{
	// prints status of all current accounts at time of function call

	cout << "Account Holder: " << endl;
	cout << first_name << " " << last_name << endl;
	address.printAddress();

	cout << endl << "Account Status: " << endl;

	if (account_type == account_type_savings)
	{
		cout << "Account Type:   savings\n";
	}
	if (account_type == account_type_interest_checking)
	{
		cout << "Account Type:   interest-checking\n";
	}
	if (account_type == account_type_business_checking)
	{
		cout << "Account Type:   business-checking\n";
	}
	if (account_type == account_type_cd)
	{
		cout << "Account Type:   CD\n";
	}

	cout << "Account Number: " << account_id << endl;

	cout << "Balance:        " << setprecision(2) << fixed << account_balance << endl << endl << endl;

}
