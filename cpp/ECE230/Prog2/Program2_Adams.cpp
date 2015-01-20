// Jonathan Adams
// ECE 230 Program 2
// January 30, 2004

#include <iostream>
#include <fstream>
#include "Prg2Prototypes_Adams.h"
#include "Prg2DefinedConstants_Adams.h"

using namespace std;
using std::cout;
using std::cin;
using std::endl;

ifstream inp("prg2data.txt", ios::in);		// allow data to be retrieved from data file

// initialize variables from data file
int id_number;			// tax-payer ID number
int age;				// tax-payer age
int total_salary;		// total salary for year
int total_interest;		// total interest income for year
int total_dividend;		// total dividend income for you
int no_tax_interest;	// amount of interest income that is non-taxable
int num_exemptions;		// number of exemptions claimed


int main()
// Precondition:  main requires all variables and data file

// Postcondition:  main will take information from data file, send it to appropriate functions to test data,
	// calculate federal and state income taxes, and display information
{
	int num_data_sets;		// number of data sets in file
	inp >> num_data_sets;	// get number of data sets in file

	for ( int data_set = 1; data_set <= num_data_sets; data_set++ )
	// Precondition:  number of data sets in data file must be known to allow for loop to gather correct amount
		// of information from file

	// Postcondition:  loop will execute functions for number of data loops
	{
		inp >> id_number >> age >> total_salary >> total_interest >> total_dividend >> no_tax_interest
			>> num_exemptions;
		int federal_tax;
		int state_tax;

		cout << "Data set # " << data_set << endl << endl;
		
		if (data_is_ok())
		{
			federal_tax = federal_tax_owed(age, total_salary, total_interest, total_dividend, no_tax_interest, num_exemptions);
			state_tax = state_tax_owed(age, total_salary, total_interest, total_dividend);
			display(id_number, age, total_salary, total_interest, total_dividend, no_tax_interest, num_exemptions, federal_tax, state_tax);
			cout << "Enter any key to continue.\n";
			char ch1;
			cin >> ch1;
			cout << endl;
		}
		else
		{
			cout << "Data was invalid.  No calculations can be made.  Enter any key to continue.\n";
			char ch2;
			cin >> ch2;
			cout << endl;
		}
	}

	return 0;
}

int data_is_ok()
// Precondition:  data is sent to function data_is_ok to be tested
		
// Postcondition:  if data does is not valid, a warning is given for each incorrect piece, and data will
	// not be processed
{
	int data_test = 0;		// variable tells whether data is valid, 1 = no, 0 = yes

	if (id_number < 0)		// tests if ID number is valid
	{
		cout << "Invalid ID number!\n\n";
		data_test = 1;
	}

	if (age < 0)	// tests if age is valid
	{
		cout << "Invalid age!\n\n";
		data_test = 1;
	}

	if (total_salary < 0)	// tests if total salary is valid
	{
		cout << "Invalid total salary for year!\n\n";
		data_test = 1;
	}

	if (total_interest < 0)		// tests if total interest is valid
	{
		cout << "Invalid total interest income for the year!\n\n";
		data_test = 1;
	}

	if (total_dividend < 0)		// tests if total dividend is valid
	{
		cout << "Invalid total dividend income for the year!\n\n";
		data_test = 1;
	}

	if ((no_tax_interest < 0) || (no_tax_interest > total_interest))	// tests if non-taxable interest is valid
	{
		cout << "Invalid amount of non-taxable interest!\n\n";
		data_test = 1;
	}

	if (data_test == 1)		// data is not valid
	{
		return 0;
	}
	else			// data is valid
	{
		return 1;
	}
}

int federal_tax_owed(int age, int total_salary, int total_interest, int total_dividend, int no_tax_interest, int num_exemptions)
// Precondition:  necessary data from valid data sets are passed into the function to calculate the federal
	// income tax

// Postcondition:  federal income tax is calculated using given methods
{
	// define income variables
	int gross_income;
	int taxable_income;
	int check_senior = 0;		// variable used to store whether tax payer is senior or not

	if (age >= senior_age)
	// Precondition:  age needed to compare to senior age to see if tax payer is senior citizen
	// Postcondition:  if tax payer is senior, check_senior becomes 1 in order to give exemption
	{	
		check_senior = 1;
	}

	gross_income = total_salary + total_interest + total_dividend;
	
	taxable_income = gross_income - (no_tax_interest + (num_exemptions * exemption_amount) + (check_senior * exemption_amount));

	if (taxable_income > 0)
	// Precondition: taxable income needs to have been calculated
	// Postcondition:  if taxable income is greater than zero, federal tax is calculated; otherwise, no tax is applied
	{
		// define variables needed to compute federal tax
		int total_tax;
		int total_tax1;
		int total_tax2;
		int total_tax3;

		if (taxable_income <= fed_tax_break1)
		// if taxable income is less than $10000, it will be taxed at first break rate, otherwise, the first $10000
			// is taxed at that rate
		{
			total_tax = taxable_income * break1_rate;
			return total_tax;
		}
		else
		{
			total_tax1 = fed_tax_break1 * break1_rate;

			if (taxable_income <= fed_tax_break2)
			// if taxable income is less than $35000, the amount above $10000 will be taxed at the second break rate
				// and added to the first taxed amount, otherwise, the next $25000 will be taxed at the second break
				// rate and all taxable income above will be taxed at third break rate
			{
				total_tax = total_tax1 + ((taxable_income - fed_tax_break1) * break2_rate);
				return total_tax;
			}
			else
			{
				total_tax2 = (fed_tax_break2 - fed_tax_break1) * break2_rate;
				total_tax3 = (taxable_income - fed_tax_break2) * break3_rate;

				total_tax = total_tax1 + total_tax2 + total_tax3;
				return total_tax;
			}
		}
	}
	else
	{
		taxable_income = 0;
		return 0;
	}
}

int state_tax_owed(int age, int total_salary, int total_interest, int total_dividend)
// Precondition:  necessary data is passed in from data set to calculate state tax
// Postcondition:  state income tax is calculated using given methods
{
	int taxable_state_income;
	int check_senior = 0;
	int total_state_tax;

	if (age >= senior_age)
	// Precondition:  age needed to compare to senior age to see if tax payer is senior citizen
	// Postcondition:  if tax payer is senior, check_senior becomes 1 in order to give exemption
	{	
		check_senior = 1;
	}
	// taxable state income only has senior exemption
	taxable_state_income = total_salary + total_interest + total_dividend - (check_senior * state_senior_exemption);
	// single rate for state tax
	
	if (taxable_state_income > 0)
	// Precondition:  taxable income needs to have been calculated
	// Postcondition:  taxes taxable income above 0, otherwise tax is zero
	{
        total_state_tax = taxable_state_income * state_rate;
		return total_state_tax;
	}
	else
	{
		return 0;
	}
}

void display(int id_number, int age, int total_salary, int total_interest, int total_dividend, int no_tax_interest, int num_exemptions, int federal_tax, int state_tax)
// Precondition:  takes all data from project
// Postcondition:  arranges said data into readable output
{
	cout << "Tax-payer ID Number:               " << id_number << endl
		 << "Tax-payer Age:                     " << age << endl
		 << "Total salary for year:            $" << total_salary << endl
		 << "Total interest income for year:   $" << total_interest << endl
		 << "Total dividend income for year:   $" << total_dividend << endl
		 << "Non-taxable interest:             $" << no_tax_interest << endl
		 << "Number of exemptions:              " << num_exemptions << endl << endl
		 << "Federal tax owed:                 $" << federal_tax << endl
		 << "State tax owed:                   $" << state_tax << endl << endl;
	return;
}
