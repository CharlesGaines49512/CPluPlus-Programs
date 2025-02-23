/*
Developer: Charles Austin Gaines
Date: 02/08/2025
Purpose: Header file for Airgead Investment calculator.
*/
#ifndef INVESTMENT_CALCULATOR_H
#define INVESTMENT_CALCULATOR_H

// Class definitions
class InvestmentCalculator {
private:
	double m_initialInvestment; // Initial investment
	double m_monthlyDeposit; // Monthly deposit
	double m_annualInterest; // Annual interest rate
	int m_numYears;	// Number of years for investments

public:
	// Constructor 
	InvestmentCalculator(double initialInvestment, double monthlyDeposit, double annualInterest,
		int numYears);
	
	// Function to calculate interest without monthly deposit
	void calculateWithoutDeposit();

	// Function to calculate compound interest with monthly deposit
	void caluclateWithDeposit(); 


};
#endif
