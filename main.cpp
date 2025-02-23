/*
Developer: Charles Austin Gaines
Date: 02/08/2025
Purpose: Driver code to implement Investment calculator. 
Used for the visual learning of compound interest*/

#include <iostream>
#include "InvestmentCalculator.h"

using namespace std;

int main() {
	double initialInvestment,
		monthlyDeposit,
		annualInterest;
	int numYears;
	char choice;

	do {
		// Prompt user for initial investment amount
		cout << "Enter initial investment amount: ";
		cin >> initialInvestment;

		// Validate input is positive
		while (initialInvestment <= 0) {
			cout << "Invalid input. Enter a positive amount:";
			cin >> initialInvestment;
		}

		// Prompt user for monthly deposit amount
		cout << "Enter monthly deposit amount: ";
		cin >> monthlyDeposit;

		// Validate input is positive 
		while (monthlyDeposit < 0) {
			cout << " Invalid input. Enter a positive amount: ";
			cin >> monthlyDeposit;
		}

		// Prompt user for annual interest rate
		cout << "Enter annual interest rate (%): ";
		cin >> annualInterest;

		// Validate input is positive 
		while (annualInterest <= 0) {
			cout << "Invalid input. Enter a positive percentage: ";
			cin >> annualInterest;
		}

		// Prompt user for the number of years
		cout << "Enter number of years: ";
		cin >> numYears;

		// Validate input is positve
		while (numYears <= 0) {
			cout << "Invalid input. Enter a positive number of years: ";
			cin >> numYears;
		}

		// Create an instance of user inputs
		InvestmentCalculator calculator(initialInvestment, monthlyDeposit, annualInterest, numYears);

		// Display results for investment growth without additional deposits
		cout << "\nBalance and Interest Without Additional Monthly Deposits:\n";
		calculator.calculateWithoutDeposit();

		// Display results for investment growth with additional monthly deposits
		cout << "\nBalance and Interest With Additional Monthly Deposits:\n";
		calculator.caluclateWithDeposit();
		
		
		// Ask the user if they want to test different values
		cout << "\nWould you like to test different values? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
	
	// Exit message
	cout << "Thank you for using Airgead Banking Investment Calculator!\n";

	return 0;
}

