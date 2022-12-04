#ifndef FUND_H
#define FUND_H
#include <iostream>
#include <string>

class Fund
{
private:
	// total amount of money in account
	int total;

	// name of account
	std::string name;

	// one digit id of fund
	std::string fundID;

public:
	// constructor / destructor
	Fund();
	Fund(std::string fundID, std::string fundName);
	~Fund();

	// setter / getters
	int getTotal();
	std::string getFundID();
	std::string getName();

	// utility methods
	bool add(int amountToAdd);
	bool withdraw(int amountToWithdraw);
	std::string check();
};

#endif