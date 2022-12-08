#ifndef TRANSACTION_READER_CPP
#define TRANSACTION_READER_CPP

#include "TransactionReader.h"

TransactionReader::TransactionReader(std::queue<Transaction> * transactionQueue) {
    readerQueue = transactionQueue;
}

bool TransactionReader::read(std::string fileName) {
    std::ifstream inFile;
    inFile.open(fileName);
    if (inFile.is_open()) {
        std::string line;
        inFile >> line;
        defineTransaction(line);
    }
}

bool TransactionReader::defineTransaction(std::string line) {
    char type = line[0];
    if (type == 'D' || type == 'W') {
        buildTransaction(line, type);
    }
    else if (type == 'T') {
        //Transfer
    }
    else if (type == 'H') {
        //History
    }
    else if (type == 'O') {
        //Open account
    }
    else {
        return false;
    }
}

bool buildTransaction(std::string line, char type) {
    std::string accountId;
        std::string amt;
        int f;
        int i;
        //Account id obtained here.
        for (i = 2; i < line.size(); i++) {
            if (line[i]==' ') {
                break;
            }
            accountId += line[i];
        }
        //Fund index is converted to int.
        f = accountId[accountId.size()-1];
        //Deposit amount obtained here.
        for (i += 1; i < line.size(); i++) {
            amt += line[i];
        }
        Transaction t (type, std::stoi(accountId), f, std::stoi(amt));
}

#endif //TRANSACTION_READER_CPP