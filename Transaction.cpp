//Transaction.cpp

#include "Transaction.h"

Transaction::Transaction()
{

}

Transaction::~Transaction()
{

}

Transaction::Transaction(char typeOfTransaction, string firstName, string lastName, int accountNumber)
{
    this->transactionType = typeOfTransaction;
    this->firstName = firstName;
    this->lastName = lastName;
    this->accountID = accountNumber;
}

Transaction::Transaction(char typeOfTransaction, int accountNo)
{
    this->transactionType = typeOfTransaction;
    this->accountID = accountNo;
}

Transaction::Transaction(char typeOfTransaction, int accountNo, int fundNo)
{
    this->transactionType = typeOfTransaction;
    this->accountID = accountNo;
    this->fundID = fundNo;
}

Transaction::Transaction(char typeOfTransaction, int accountNo, int fundNo, int amount)
{
    this->transactionType = typeOfTransaction;
    this->accountID = accountNo;
    this->fundID = fundNo;
    this->amount = amount;
}

//transaction that fails to process
Transaction::Transaction(char typeOfTransaction, int accountNo, int fundNo, int amount, string failTran)
{
    this->transactionType = typeOfTransaction;
    this->accountID = accountNo;
    this->fundID = fundNo;
    this->amount = amount;
    this->fail = failTran;
}

Transaction::Transaction(char typeOfTransaction, int accountNo, int fundNo, int amount, int transferToAccount, int transferToFund)
{
    this->transactionType = typeOfTransaction;
    this->accountID = accountNo;
    this->transferToAccountID = transferToAccount;
    this->fundID = fundNo;
    this->transferFundID = transferToFund;
    this->amount = amount;
}

//transaction that fails to process
Transaction::Transaction(char typeOfTransaction, int accountNo, int fundNo, int amount, int transferToAccount, int transferToFund, string failTran)
{
    this->transactionType = typeOfTransaction;
    this->accountID = accountNo;
    this->transferToAccountID = transferToAccount;
    this->fundID = fundNo;
    this->transferFundID = transferToFund;
    this->amount = amount;
    this->fail = failTran;
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

int Transaction::getTransferToAccountID() const
{
    return transferToAccountID;
}

int Transaction::getFundID() const
{
    return fundID;
}

int Transaction::getTransferToFundID() const
{
    return transferFundID;
}

int Transaction::getAmount() const
{
    return amount;
}

//Checks if 'fail' is empty, if it is empty the transaction is successfull, if it is not empty the transaction has failedTransaction
bool Transaction::failedTransaction()
{
    if (fail.empty())
    {
        return true;
    }
    return false;
}

////overload operator
////If 'fail' is empty then transaction is successful and successfull message is shown,
////if 'fail' is not empty then transaction has failed and failedTransaction message is shown
//ostream & operator<<(ostream & out, const Transaction & trans)
//{
//    if (trans.fail.empty())
//    {
//        //show message: "successful transaction"
//    }
//    else
//    {
//        //show message: "failedTransaction transaction"
//    }
//}
