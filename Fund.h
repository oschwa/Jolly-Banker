#ifndef FUND_H
#define FUND_H
#include <iostream>
#include <string>
#include <vector>
#include "Transaction.h"

class Fund
{
private:
	// total amount of money in account
	int balance;

	// name of account
	std::string name;

	// one digit id of fund
	char fundID;

	// vector for transaction history
	vector<Transaction> history;

public:
	// constructor / destructor
	Fund();
	Fund(char fundID, std::string fundName);
	~Fund();

	// setter / getters
	int getBalance();
	char getFundID();
	std::string getName();
	vector<Transaction> getHistory();

	// utility methods
	bool add(int amountToAdd);
	bool withdraw(int amountToWithdraw);
	bool addTransaction(Transaction trans);

	// operator overloads
	bool operator<(const Fund &other);
	bool operator>(const Fund &other);
	bool operator<=(const Fund &other);
	bool operator>=(const Fund &other);
	bool operator==(const Fund &other);
};

#endif
