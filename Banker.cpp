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
		Account *toFind;

		switch (toDo.getTransactionType())
		{
		case 'O':
			if (this->openAccount(toDo.getFirstName(), toDo.getLastName(), to_string(toDo.getAccountID())))
				break;
			else
			{
				cout << "Account " << toDo.getAccountID() << " is already open. Transaction Failed";
				break;
			}
		case 'D':

			if (!this->accounts.Retrieve(toDo.getAccountID(), toFind))
			{
				cout << "Account " << toDo.getAccountID() << " not found. Deposit refused";
				break;
			}
			if (!toFind->deposit(toDo.getFundID(), toDo.getAmount()))
			{
				// SET TRANSACTION TO FAILED
			}
			break;
		case 'W':
			if (!this->accounts.Retrieve(toDo.getAccountID(), toFind))
			{
				cout << "Account " << toDo.getAccountID() << " not found. Withdrawal refused";
				break;
			}
			if (!toFind->withdraw(toDo.getFundID(), toDo.getAmount()))
			{
				// SET TRANSACTION TO FAILED
			}
			break;
		case 'T':
			Account *toFind2;
			if (!this->accounts.Retrieve(toDo.getAccountID(), toFind))
			{
				cout << "Account " << toDo.getAccountID() << " not found. Tranferal refused";
				break;
			}
			if (!this->accounts.Retrieve(toDo.getAccountID(), toFind))
			{
				cout << "Account " << toDo.getTransferToAccountID() << " not found. Tranferal refused";
				break;
			}
			if (!this->transferFunds(*toFind, toDo.getFundID(), *toFind2, toDo.getTransferToFundID(), toDo.getAmount()))
			{
				// SET TRANSACTION TO FAILED
			}
			break;
		case 'H':
			if (!this->accounts.Retrieve(toDo.getAccountID(), toFind))
			{
				cout << "Account " << toDo.getAccountID() << " not found. History request refused";
				break;
			}
			// TODO: MAKE SURE TO TAKE CARE OF BOTH CASES. SPECIFIC FUND OR EVERY FUND
			break;
		}

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