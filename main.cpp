#include <iostream>
#include <string>
#include "Account.h"
#include "Checkings.h"
#include "Savings.h"
using namespace std;

void  Account::setAccountName(string firstname, string lastname)
{
	firstName = firstname;
	lastName = lastname;
}

string Account::getAccountName()
{
	accountName = firstName + " " + lastName;
	return(accountName);
}

void Account::setAccountNumber(int accno)
{
	accNumber = accno;
}
 
bool Account::login() //loging verification with predefined credentials
{
	int givenAccountNumber = -1;
	int givenPinNumber = -1;
	bool isAccountInvalid = true;
	bool isPinInvalid = true;

	cout << "-----------------------------" << endl;
	cout << "|          Welcome!         |" << endl;
	cout << "-----------------------------" << endl;

	while (isAccountInvalid) {

		cout << "Please enter your account number: ";
		cin >> givenAccountNumber;

		if (givenAccountNumber == accountNumber) {
			isAccountInvalid = false;
		}
		else {
			cout << "Invalid account number! Try again." << endl;
		}
	}

	while (isPinInvalid) {

		cout << "\nEnter your PIN: ";
		cin >> givenPinNumber;

		if (givenPinNumber == pinNumber) {
			isPinInvalid = false;
		}
		else {
			cout << "Invalid PIN number! Try again." << endl;
		}
	}

	return true;

}

void Checkings::setBalance(double deposit)
{
	c_balance = c_balance + deposit;
}

double Checkings::getBalance() const
{
	return c_balance;
}

void Checkings::setWithdraw()
{
	double wdraw = 0;
	cout << "Enter withdrawal amount: Rs.";
	cin >> wdraw;

	if (c_balance >= wdraw) {
		c_balance = c_balance - wdraw;
		cout << "Your updated Checkings balance is: Rs." << c_balance << endl;
	}
	else {
		cout << "Not able to withdraw Rs." << wdraw << " from account.";
		cout << "Not enough funds..." << endl;
	}
}

void Checkings::setDeposit()
{
	double dep = 0;
	cout << "Enter deposit amount: Rs.";
	cin >> dep;
	c_balance = c_balance + dep;
	cout << "Your updated Checkings balance is: Rs." << c_balance << endl;
}

double Checkings::getTransfer() //returns transfer ammount
{
	double wdraw = 0;
	cout << "Enter transfer amount: Rs.";
	cin >> wdraw;

	if (c_balance >= wdraw) {
		c_balance = c_balance - wdraw;
		cout << "Your updated Checkings balance is: Rs." << c_balance << endl;
		return wdraw;
	}
	else {
		cout << "Not able to withdraw Rs." << wdraw << " from account.";
		cout << "Not enough funds..." << endl;
		return 0.0;
	}
}

void Savings::setSavingsBalance(double deposit)
{
	s_balance = s_balance + deposit;
}


double Savings::getSavingsBalance() const
{
	return s_balance;
}

void Savings::setWithdraw()
{
	double wdraw = 0;
	cout << "Enter withdrawal amount: Rs.";
	cin >> wdraw;

	if (s_balance >= wdraw) {
		s_balance = s_balance - wdraw;
		cout << "Your updated Checkings balance is: Rs." << s_balance << endl;
	}
	else {
		cout << "Not able to withdraw Rs." << wdraw << " from account." << endl;
		cout << "Not enough funds..." << endl;
	}
}

void Savings::setDeposit()
{
	double dep = 0;
	cout << "Enter deposit amount: Rs.";
	cin >> dep;
	s_balance = s_balance + dep;
	cout << "Your updated Savings balance is: Rs." << getSavingsBalance() << endl;
}

double Savings::getTransfer() // returns transfer ammount
{
	double wdraw = 0;
	cout << "Enter transfer amount: Rs.";
	cin >> wdraw;

	if (s_balance >= wdraw) {
		s_balance = s_balance - wdraw;
		cout << "Your updated Savings balance is: Rs." << s_balance << endl;
		return wdraw;
	}
	else {
		cout << "Not able to withdraw Rs." << wdraw << " from account.";
		cout << "Not enough funds..." << endl;
		return 0.0;
	}
}

int mainMenu() { //function for main menu interface

	int choice = 0;

	cout << "\n-----------------------------" << endl;
	cout << "|What would you like to do? |" << endl;
	cout << "-----------------------------" << endl;
	cout << "| 1. Deposit                |" << endl;
	cout << "| 2. Withdraw               |" << endl;
	cout << "| 3. Check Balance          |" << endl;
	cout << "| 4. Transfer Money         |" << endl;
	cout << "| 5. [Exit]                 |" << endl;
	cout << "-----------------------------" << endl;

	cin >> choice;
	return choice;
}

int main()
{
	//class-objects instantiation
	Account accObj;
	Checkings checkObj;
	Savings savObj;

	//accObj.login(); //call for login page
	accObj.login();
	accObj.setAccountName("Shashank", "Kumar"); // Or whatever predefined name
	string fullName = accObj.getAccountName();

	cout << "-----------------------------" << endl;
	cout << "|    Welcome, " << fullName << "    |" << endl;
	cout << "-----------------------------" << endl;

	// if going to create x>1 number of bank accounts,
	// implement using an array of objects

	bool isNotFinished = true; //used to break do-while loop
	int accountChoice = -1;

	//loop through menu until user hits exit
	do {
		switch (mainMenu()) 
		{
			// call deposit function
		case 1:
			cout << "-------------------------------------------------" << endl;
			cout << "| Which account would you like to deposit into? |" << endl;
			cout << "-------------------------------------------------" << endl;
			cout << "| 1. Checking                                   |" << endl;
			cout << "| 2. Savings                                    |" << endl;
			cout << "-------------------------------------------------" << endl;

			cin >> accountChoice;
			switch (accountChoice) { //nested switch case to chose account type
			case 1:
				checkObj.setDeposit();
				break;
			case 2:
				savObj.setDeposit();
				break;
			default:
				cout << "Invalid choice! Please select again." << endl;
				break;
			}

			
			break;

			// call widthdraw
		case 2:
			cout << "-------------------------------------------------" << endl;
			cout << "|       Which account to widthdrwaw from?       |" << endl;
			cout << "-------------------------------------------------" << endl;
			cout << "| 1. Checking                                   |" << endl;
			cout << "| 2. Savings                                    |" << endl;
			cout << "-------------------------------------------------" << endl;

			cin >> accountChoice;
			switch (accountChoice) { //nested switch case to chose account type
			case 1:
				checkObj.setWithdraw();
				break;
			case 2:
				savObj.setWithdraw();
				break;
			default:
				cout << "Invalid choice! Please select again." << endl;
				break;
			}
		
			break;
		case 3:

			// call to check balance
			cout << "-------------------------------------------------" << endl;
			cout << "|       Check Account Balance for?              |" << endl;
			cout << "-------------------------------------------------" << endl;
			cout << "| 1. Checking                                   |" << endl;
			cout << "| 2. Savings                                    |" << endl;
			//cout << "| 3. Checking & Savings                         |" << endl;  Modular case (Not needed here)
			cout << "-------------------------------------------------" << endl;

			cin >> accountChoice;
			switch (accountChoice)
			{
			case 1:
				cout << "Your current Checking balance is Rs." << checkObj.getBalance(); // gets balance for checkings account
				break;

			case 2:
				cout << "Your current Savings balance is Rs." << savObj.getSavingsBalance(); // gets balance for savings account
				break;

			default:
				cout << "Invalid choice! Please select again." << endl;
				break;

			}

			break;


			// call for transfer
		case 4:

			cout << "-------------------------------------------------" << endl;
			cout << "| Select account you wish to transer from.       |" << endl;
			cout << "-------------------------------------------------" << endl;
			cout << "| 1. Checkings to Savings                                   |" << endl;
			cout << "| 2. Savings to Checkings                                    |" << endl;
			cout << "-------------------------------------------------" << endl << endl;

			cin >> accountChoice;
			switch (accountChoice)
			{
			case 1:
			{
				double depositTOsav = checkObj.getTransfer(); // Withdraw ammount from Checking
				savObj.setSavingsBalance(depositTOsav); // Deposit ammount to Savings
				break;
			}
			case 2:
			{
				double depositTOcheck = savObj.getTransfer(); // Withdraw ammount from Savings
				checkObj.setBalance(depositTOcheck); // Deposit ammount to Checkings
				break;
			}
			default:
				cout << " Invalid choice! Please select again." << endl;

			}

			break;

			// Call for EXIT on menu.
		case 5:
			cout << "Thank you for Choosing Chase Fargo of America." << endl;
			isNotFinished = false;
			break;

		default:
			cout << "Invalid choice! Please select again." << endl;
			break;
		}

	} while (isNotFinished);


	system("pause");
	return 0;

}
