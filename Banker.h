#ifndef BANKER_H
#define BANKER_H

#pragma once

#include "AccountTree.h"
#include "TransactionReader.h"
#include "Transaction.h"
// #include "Account.h"
#include <queue>
#include <fstream>
#include <iostream>

class Banker
{
private:
	AccountTree accounts;
	queue<Transaction> *transactionQueue;
	TransactionReader reader;

public:
	// constructors
	Banker(ifstream inputFile);
	~Banker();

	// utility methods
	bool read(string fileName);
	bool execute();
	bool openAccount(std::string firstName, std::string lastName, string ID);
	bool viewHistory(const Account &a);
	bool viewHistory(const Account &a, int fund);
	bool transferFunds(Account &a, int fund1, int fund2);
	bool transferFunds(Account &a, int fundA, Account &b, int fundB, int amount);
	bool deposit(Account &a, int fund, int amount);
	bool withdraw(Account &a, int fund, int amount);
};

#endif
