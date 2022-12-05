//Transaction.h

#ifndef TRANSACTION_H
#define TRANSACTION_H

#pragma once

#include <string>
#include <iostream>

using namespace std;

class Transaction
{
    friend ostream & operator<<(ostream &out, const Transaction &trans);

public:
    //constructor/destructor
    Transaction();
    ~Transaction();

    Transaction(char type, string firstName, string lastName, int accountNumber);

    Transaction(char type, int accountNumber);
    Transaction(char type, int accountNumber, int fundNumber);
    Transaction(char type, int accountNumber, int fundNumber, int amount);
    //transaction that fails to process
    Transaction(char type, int accountNumber, int fundNumber, int amount, string fail);

    Transaction(char type, int accountNumber, int fundNumber, int amount, int transferAccountNumber, int transferFundNumber);
    //transaction that fails to process
    Transaction(char type, int accountNumber, int fundNumber, int amount, int transferAccountNumber, int transferFundNumber, string failString);

    //getters
    char getTransactionType() const;
    string getFirstName() const;
    string getLastName() const;
    int getAccountID() const;
    int getTransferAccountID() const;
    int getFundID() const;
    int getTransferFundID() const;
    int getAmount() const;
    bool failed();

private:
    char transactionType;
    string firstName;
    string lastName;
    string fail;
    int accountID, fundID, transferAccountID, transferFundID, amount;
};

#endif //TRANSACTION_H
