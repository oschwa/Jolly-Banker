#include "Banker.h"
#include "TransactionReader.h"
#include "Account.h"

int main()
{
	return 0;
}

Banker::Banker()
{
	// TBD
}

Banker::Banker(ifstream inFile)
{
	// TBD
}

Banker::~Banker()
{
	// TBD
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
		Account *a;

		switch (toDo.getTransactionType())
		{
		case 'O':
			this->processOpen(toDo);
			break;
		case 'D':
			this->processDeposit(toDo, a);
			break;
		case 'W':
			this->processWithdrawl(toDo, a);
			break;
		case 'T':
			this->processTransfer(toDo, a);
			break;
		case 'H':
			this->processHistory(toDo, a);
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

void Banker::processOpen(Transaction &toDo)
{
	if (!this->openAccount(toDo.getFirstName(), toDo.getLastName(), to_string(toDo.getAccountID())))
	{
		cout << "Account " << toDo.getAccountID() << " is already open. Transaction Failed";
		toDo.setFailed(true);
	}
}

void Banker::processDeposit(Transaction &toDo, Account *a)
{
	if (!this->accounts.Retrieve(toDo.getAccountID(), a))
	{
		cout << "Account " << toDo.getAccountID() << " not found. Deposit refused";
		toDo.setFailed(true);
	}
	else if (!a->deposit(toDo.getFundID(), toDo.getAmount()))
	{
		toDo.setFailed(true);
	}
	a->addHistory(toDo.getFundID(), &toDo);
}

void Banker::processWithdrawl(Transaction &toDo, Account *a)
{
	if (!this->accounts.Retrieve(toDo.getAccountID(), a))
	{
		cout << "Account " << toDo.getAccountID() << " not found. Withdrawal refused";
		toDo.setFailed(true);
	}
	else if (!a->withdraw(toDo.getFundID(), toDo.getAmount()))
	{
		toDo.setFailed(true);
	}
	a->addHistory(toDo.getFundID(), &toDo);
}

void Banker::processTransfer(Transaction &toDo, Account *a)
{
	Account *a2;
	if (!this->accounts.Retrieve(toDo.getAccountID(), a))
	{
		cout << "Account " << toDo.getAccountID() << " not found. Tranferal refused";
		toDo.setFailed(true);
	}
	else if (!this->accounts.Retrieve(toDo.getTransferToAccountID(), a2))
	{
		cout << "Account " << toDo.getTransferToAccountID() << " not found. Tranferal refused";
		toDo.setFailed(true);
	}
	else if (!this->transferFunds(*a, toDo.getFundID(), *a2, toDo.getTransferToFundID(), toDo.getAmount()))
	{
		toDo.setFailed(true);
	}
	a->addHistory(toDo.getFundID(), &toDo);
}

void Banker::processHistory(Transaction &toDo, Account *a)
{
	if (!this->accounts.Retrieve(toDo.getAccountID(), a))
	{
		cout << "Account " << toDo.getAccountID() << " not found. History request refused";
		toDo.setFailed(true);
	}

	a->addHistory(toDo.getFundID(), &toDo);
}