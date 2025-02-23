/*
Developer: Charles Austin Gaines
Date: 02/08/2025
Purpose: Investment calculator class and functions definitions*/



#include "InvestmentCalculator.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>

using namespace std;
//Constructor to initialize the class variables
InvestmentCalculator::InvestmentCalculator(double initialInvestment, double monthlyDeposit, 
	double annualInterest, int numYears){
	m_initialInvestment = initialInvestment;
	m_monthlyDeposit = monthlyDeposit;
	m_annualInterest = annualInterest; 
	m_numYears = numYears;

}

// Function to calculate compound interest without monthly deposit
void InvestmentCalculator::calculateWithoutDeposit() {
	double balance = m_initialInvestment;
	cout << "\n"; // Building header
	cout << setw(5) << left << "Year"
		<< setw(20) << right << "Year-End Balance"
		<< setw(20) << right << "Interest Earned" << endl;
	cout << string(45, '-') << endl;

	for (int year = 1; year <= m_numYears; ++year) {
		double interest = balance * (m_annualInterest / 100); // Apply annual interest
		balance += interest; // Update balance by adding interest

		// formatting output to fixed width
		
		ostringstream balanceStream, interestStream;
		balanceStream << "$" << fixed << setprecision(2) << balance;
		interestStream << "$" << fixed << setprecision(2) << interest;

		// Output with setw for columns
		cout << setw(5) << left << year
			<< setw(20) << right << balanceStream.str()
			<< setw(20) << right << interestStream.str() << endl;
	}
}

// Function to calculate compount interest with monthly deposit
void InvestmentCalculator::caluclateWithDeposit(){
	double balance = m_initialInvestment; // Initial balance
	cout << "\n"; // Header to set alignment
	cout << setw(5) << left << "Year"
		<< setw(20) << right << "Year-End Balance"
		<< setw(20) << right << "Interest Earned" << endl;
	cout << string(45, '-') << endl;

	// Loop through each year
	for (int year = 1; year <= m_numYears; ++year) {
		double interestEarned = 0; // Variable for yearly interest
		
		// Loop though each month in the year
		for (int month = 1; month <= 12; ++month) {
			double monthlyInterest = (balance + m_monthlyDeposit) * ((m_annualInterest / 100) / 12);
			interestEarned += monthlyInterest; // Accumulated interest
			balance += m_monthlyDeposit + monthlyInterest; // Updated balance
		}
		
		// Format output to fixed widths
		ostringstream balanceStream, interestStream;
		balanceStream << "$" << fixed << setprecision(2) << balance;
		interestStream << "$" << fixed << setprecision(2) << interestEarned;

		// Output with set columns
		cout << setw(5) << left << year
			<< setw(20) << right << balanceStream.str()
			<< setw(20) << right << interestStream.str() << endl;

	
	}
}