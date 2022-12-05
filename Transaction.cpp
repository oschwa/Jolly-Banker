//Transaction.cpp

#include "Transaction.h"

Transaction::Transaction()
{

}

Transaction::~Transaction()
{

}

Transaction::Transaction(char type, string firstName, string lastName, int accountNumber)
{
    this->transactionType = type;
    this->firstName = firstName;
    this->lastName = lastName;
    this->accountID = accountNumber;
}

Transaction::Transaction(char type, int accountNumber)
{
    this->transactionType = type;
    this->accountID = accountNumber;
}

Transaction::Transaction(char type, int accountNumber, int fundNumber)
{
    this->transactionType = type;
    this->accountID = accountNumber;
    this->fundID = fundNumber;
}

Transaction::Transaction(char type, int accountNumber, int fundNumber, int amount)
{
    this->transactionType = type;
    this->accountID = accountNumber;
    this->fundID = fundNumber;
    this->amount = amount;
}

//transaction that fails to process
Transaction::Transaction(char type, int accountNumber, int fundNumber, int amount, string failString)
{
    this->transactionType = type;
    this->accountID = accountNumber;
    this->fundID = fundNumber;
    this->amount = amount;
    this->fail = failString;
}

Transaction::Transaction(char type, int accountNumber, int fundNumber, int amount, int transferAccountNumber, int transferFundNumber)
{
    this->transactionType = type;
    this->accountID = accountNumber;
    this->transferAccountID = transferAccountNumber;
    this->fundID = fundNumber;
    this->transferFundID = transferFundNumber;
    this->amount = amount;
}

//transaction that fails to process
Transaction::Transaction(char type, int accountNumber, int fundNumber, int amount, int transferAccountNumber, int transferFundNumber, string failString)
{
    this->transactionType = type;
    this->accountID = accountNumber;
    this->transferAccountID = transferAccountNumber;
    this->fundID = fundNumber;
    this->transferFundID = transferFundNumber;
    this->amount = amount;
    this->fail = failString;
}


char Transaction::getTransactionType() const
{
    return transactionType;
}

string Transaction::getFirstName() const
{
    return firstName;
}

string Transaction::getLastName() const
{
    return lastName;
}

int Transaction::getAccountID() const
{
    return accountID;
}

int Transaction::getTransferAccountID() const
{
    return transferAccountID;
}

int Transaction::getFundID() const
{
    return fundID;
}

int Transaction::getTransferFundID() const
{
    return transferFundID;
}

int Transaction::getAmount() const
{
    return amount;
}

//Checks if 'fail' is empty, if it is empty the transaction is successfull, if it is not empty the transaction has failed
bool Transaction::failed()
{
    if (fail.empty())
    {
        return true;
    }
    return false;
}

//overload operator
//If 'fail' is empty then transaction is successful and successfull message is shown,
//if 'fail' is not empty then transaction has failed and failed message is shown
ostream & operator<<(ostream & out, const Transaction & trans)
{
    if (trans.fail.empty())
    {
        //show message: "successful transaction"
    }
    else
    {
        //show message: "failed transaction"
    }
}