//Transaction.h

#ifndef TRANSACTION_H
#define TRANSACTION_H

#pragma once

#include <string>
#include <iostream>

using namespace std;

class Transaction
{
private:
    string firstName;
    string lastName;
    char transactionType;
    int accountID;
    int fundID;
    int transferToAccountID;
    int transferFundID;
    int amount;
    string fail;

public:
    //constructor/destructor
    Transaction();
    ~Transaction();

    Transaction(char typeOfTransaction, string firstName, string lastName, int accountNumber);

    Transaction(char typeOfTransaction, int accountNo);
    Transaction(char typeOfTransaction, int accountNo, int fundNo);
    Transaction(char typeOfTransaction, int accountNo, int fundNo, int amount);
    //transaction that fails to process
    Transaction(char typeOfTransaction, int accountNo, int fundNo, int amount, string failTran);

    Transaction(char typeOfTransaction, int accountNo, int fundNo, int amount,
                int transferToAccount, int transferToFund);
    //transaction that fails to process
    Transaction(char typeOfTransaction, int accountNo, int fundNo, int amount,
                int transferToAccount, int transferToFund, string failTran);

    //getters
    char getTransactionType() const;
    string getFirstName() const;
    string getLastName() const;
    int getAccountID() const;
    int getTransferToAccountID() const;
    int getFundID() const;
    int getTransferToFundID() const;
    int getAmount() const;

    bool failedTransaction();
};

#endif //TRANSACTION_H
