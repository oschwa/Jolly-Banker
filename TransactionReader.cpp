#ifndef TRANSACTION_READER_CPP
#define TRANSACTION_READER_CPP

#include "TransactionReader.h"

TransactionReader::TransactionReader() {

}
TransactionReader::TransactionReader(std::queue<Transaction> * transactionQueue) {
    readerQueue = transactionQueue;
}

bool TransactionReader::read(std::string fileName) {
    std::ifstream inFile;
    inFile.open(fileName);
    std::string line;
    while (std::getline(inFile, line)) {
        defineTransaction(line);
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
        t = defineAccountOpen(line, type, t);
    }
    readerQueue->push(t);
}

Transaction& TransactionReader::buildTransaction(std::string line, char type, Transaction t) {
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

    int converted_accId = std::stoi(accountId);
    int converted_amt = std::stoi(amt);
    Transaction new_T(type, converted_accId, f, converted_amt);
    return new_T;
}

Transaction& TransactionReader::defineAccountOpen(std::string line, char type, Transaction t) {
    std::string firstName = "";
    std::string lastName = "";
    std::string accountId = "";

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

    int converted_accId = std::stoi(accountId);
    Transaction new_T(type, firstName, lastName, converted_accId);
    return new_T;
}

#endif //TRANSACTION_READER_CPP