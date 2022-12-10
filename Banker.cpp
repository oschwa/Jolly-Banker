#include "Banker.h"
#include "TransactionReader.h"
#include "Account.h"

int main()
{
	return 0;
}

bool Banker::read(std::string fileName)
{
	reader = TransactionReader(this->transactionQueue);
	return (reader.read(fileName));
}

bool Banker::execute()
{
	while (!transactionQueue->empty())
	{
		Transaction toDo = transactionQueue->front();

		// TODO: complete transaction

		transactionQueue->pop();
	}
	return true;
}

bool Banker::openAccount(std::string firstName, std::string lastName, std::string ID)
{
	Account *newAccount = new Account(firstName, lastName, ID);
	return (this->accounts.Insert(newAccount));
}

void Banker::viewHistory(const Account &a)
{
	a.viewHistory();
}

void Banker::viewHistory(const Account &a, int fund)
{
	a.viewHistory(fund);
}

bool Banker::transferFunds(Account &a, int fundA, Account &b, int fundB, int amount)
{
	if (a.withdraw(fundA, amount))
	{
		return (b.deposit(fundB, amount));
	}
	return false;
}

bool Banker::deposit(Account &a, int fund, int amount)
{
	return a.deposit(fund, amount);
}

bool Banker::withdraw(Account &a, int fund, int amount)
{
	return a.withdraw(fund, amount);
}