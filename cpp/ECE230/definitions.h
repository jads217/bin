// Jonathan Adams
// Account type definitions

#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#define account_type_savings 0			// savings account type number
#define account_type_interest_checking 1		// interest-checking account type number
#define account_type_business_checking 2		// business-checking account type number
#define account_type_cd 3			// CD account type number
#define OPEN 1				// signifies teller window or drive-through is open
#define CLOSED 0			// signifies teller window or drive-through is closed
#define OPEN_FACILITY 1		// gives call to operations that will create a new facility
#define OPEN_DRIVE_THROUGH_LANE 2		// gives call to operations that will open a drive-through lane at a facility
#define CLOSE_DRIVE_THROUGH_LANE 3		// gives call to operations that will close a drive-through lane at a facility
#define OPEN_TELLER_WINDOW 4		// gives call to operations that will open a teller window at a facility
#define CLOSE_TELLER_WINDOW 5		// gives call to operations that will close a teller window at a facility
#define ADD_CASH_TO_ATM 6			// gives call to operations that will add cash to an ATM facility
#define PRINT_FACILITIES 7			// gives call to operations that will print current status of all existing facilities
#define OPEN_ACCOUNT 8			// gives call to operations that will open a new account of specified type
#define CLOSE_ACCOUNT 9			// gives call to operations that will close an account of specified type
#define CLOSE_FACILITY 10		// gives call to operations that will close a particular facility
#define PRINT_ACCOUNTS 11		// gives call to operations that will print current status of all existing accounts
#define WITHDRAWAL 12		// gives call to operations that will process a withdrawal from a particular account at a particular facility
#define DEPOSIT 13			// gives call to operations that will process a deposit from a particular accoun at a particular facility
#define ADD_INTEREST 14		// gives call to operations that will add interest to existing accounts
#define QUIT 100			// gives call to operations that will quit the simulation
#define ATM_CONST 1			// indicates ATM type to be opened
#define DRIVE_THROUGH 2		// indicates drive-through facility to be opened
#define FULL_SERVICE 3		// indicates full service facility to be opened
#define WINDOW 1		// indicates where money is withdrawn/deposited
#define LANE 2			// indicates where money is withdrawn/deposited

#endif