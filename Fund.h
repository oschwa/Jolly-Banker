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
	int getBalance() const;
	char getFundID() const;
	std::string getName() const;
	vector<Transaction> getHistory();

	// utility methods
	bool add(int amountToAdd);
	bool withdraw(int amountToWithdraw);
	bool addTransaction(Transaction trans);

	// operator overloads
	bool operator<(const Fund &other) const;
	bool operator>(const Fund &other) const;
	bool operator<=(const Fund &other) const;
	bool operator>=(const Fund &other) const;
	bool operator==(const Fund &other) const;
};

#endif
