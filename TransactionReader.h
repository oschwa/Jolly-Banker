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
    /**
     * Constructor for TransactionReader object.
     * @param queue<Transaction> address of queue<Transaction>
     * in Banker class.
    */
    TransactionReader(queue<Transaction> * transactionQueue);
    /**
     * Method for reading file input.
     * @param std::string Name of file to be read.
     * @post Returns bool indicating success or failue.
    */
    bool read(std::string file);
    /**
     * Method for creating Transaction objects from file.
     * @param std::string Line from file to be read.
     * @post void.
    */
    void defineTransaction(std::string line);
    /**
     * Method for creating a Deposit / Withdrawl Transaction
     * Object.
     * @param std::string Line from file to be read.
     * @param char Letter representing type of transaction.
     * @post Returns Transaction object reference.
    */
    Transaction& defineDepositWithdrawal(std::string line, char type);
    /**
     * Method for creating an Account Open Transaction
     * Object.
     * @param std::string Line from file to be read.
     * @param char Letter representing type of transaction.
     * @post Returns Transaction object reference.
    */
    Transaction& defineAccountOpen(std::string line, char type);
    /**
     * Method for creating a Transfer Transaction
     * Object.
     * @param std::string Line from file to be read.
     * @param char Letter representing type of transaction.
     * @post Returns Transaction object reference.
    */
    Transaction& defineFundTransfer(std::string line, char type);
    /**
     * Method for creating a History Query Transaction
     * Object.
     * @param std::string Line from file to be read.
     * @param char Letter representing type of transaction.
     * @post Returns Transaction object reference.
    */
    Transaction& defineHistoryQuery(std::string line, char type);

};

#endif //TRANSACTION_READER_H