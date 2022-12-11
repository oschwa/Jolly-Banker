#ifndef TRANSACTION_READER_H
#define TRANSACTION_READER_H
#include "Transaction.h"
#include <queue>
#include <iostream>
#include <fstream>
#include <cerrno>

class TransactionReader {
private: 
    /*
    'readerQueue' holds the address to Banker's 
    'transactionQueue'.
    */
    std::queue<Transaction> * readerQueue;
public:
    TransactionReader();
    /*
    Constructor for TransactionReader object.
    readerQueue is assigned to transactionQueue here.
    */
    TransactionReader(queue<Transaction> * transactionQueue);
    /*
    Method for reading file input.
    Pre: Requires pointer to a Transaction queue.
    Post: Returns boolean indicating success or failure.
    */
    bool read(std::string file);
    /*
    Method for creating Transaction objects from file 
    input.
    Pre: Requires string for line from file.
    Post: Returns a Transaction object reference.
    */
    void defineTransaction(std::string line);

    Transaction& defineDepositWithdrawal(std::string line, char type);

    Transaction& defineAccountOpen(std::string line, char type);

    Transaction& defineFundTransfer(std::string line, char type);
    
    Transaction& defineHistoryQuery(std::string line, char type);

};

#endif //TRANSACTION_READER_H