#include "Banker.h"
#include "TransactionReader.h"

int main()
{
	return 0;
}

bool Banker::read(std::string fileName)
{
	reader = TransactionReader(this->transactionQueue);
	reader.read(fileName);
}

bool Banker::execute()
{
	while (!transactionQueue->empty())
	{
		Transaction toDo = transactionQueue->front();

		// complete transaction

		transactionQueue->pop();
	}
}

bool Banker::openAccount(std::string firstName, std::string lastName, std::string ID)
{
}

bool Banker::viewHistory(const Account &a)
{
}

bool Banker::viewHistory(const Account &a, int fund)
{
}

bool Banker::transferFunds(Account &a, int fund1, int fund2)
{
}

bool Banker::transferFunds(Account &a, int fundA, Account &b, int fundB, int amount)
{
}

bool Banker::deposit(Account &a, int fund, int amount)
{
}

bool Banker::withdraw(Account &a, int fund, int amount)
{
}