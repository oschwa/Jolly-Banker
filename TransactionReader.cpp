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
        while (true) {
            std::string line;
            inFile >> line;
            defineTransaction(line);
        }
    }
    inFile.close();
    return true;
}

void TransactionReader::defineTransaction(std::string line) {
    Transaction t;
    char type = line[0];
    if (type == 'D' || type == 'W') {
        buildTransaction(line, type, t);
    }
    else if (type == 'T') {
        //Transfer
    }
    else if (type == 'H') {
        //History
    }
    else if (type == 'O') {
        defineAccountOpen(line, type, t);
    }

    readerQueue->push(t);
}

void TransactionReader::buildTransaction(std::string line, char type, Transaction& t) {
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
    Transaction newTransaction (type, std::stoi(accountId), f, std::stoi(amt));
    t = newTransaction;
}

void TransactionReader::defineAccountOpen(std::string line, char type, Transaction& t) {
    std::string firstName;
    std::string lastName;
    std::string accountId;

    int i;
    for (i = 2; i < line.size(); i++) {
        if (line[i]==' ') {
            break;
        }
        firstName += line[i];
    }

    for (i += 1; i < line.size(); i++) {
        if (line[i]==' ') {
            break;
        }
        lastName += line[i];
    }

    for (i += 1; i < line.size(); i++) {
        if (line[i]==' ') {
            break;
        }
        accountId += line[i];
    }

    Transaction newTransaction (type, firstName, lastName, stoi(accountId));
    t = newTransaction;
}

#endif //TRANSACTION_READER_CPP