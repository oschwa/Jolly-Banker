#ifndef TRANSACTION_READER_CPP
#define TRANSACTION_READER_CPP

#include "TransactionReader.h"

TransactionReader::TransactionReader() {}

TransactionReader::TransactionReader(std::queue<Transaction> *transactionQueue)
{
    readerQueue = transactionQueue;
}

bool TransactionReader::read(std::string fileName)
{
    std::ifstream inFile;
    inFile.open(fileName);
    std::string line;
    while (std::getline(inFile, line))
    {
        defineTransaction(line);
    }
    inFile.close();
    return true;
}

void TransactionReader::defineTransaction(std::string line)
{
    Transaction t;
    char type = line[0];
    if (type == 'D' || type == 'W')
    {
        t = buildTransaction(line, type);
    }
    else if (type == 'T')
    {
        t = defineFundTransfer(line, type);
    }
    else if (type == 'H')
    {
        // History
    }
    else if (type == 'O')
    {
        t = defineAccountOpen(line, type);
    }
    readerQueue->push(t);
}

Transaction &TransactionReader::buildTransaction(std::string line, char type)
{
    std::string accountId;
    std::string amt;
    char f;
    int i;
    // Account id obtained here.
    for (i = 2; i < 6; i++)
    {
        accountId += line[i];
    }
    // Fund index is converted to int.
    f = line[i];
    // Deposit amount obtained here.
    for (i += 2; i < line.size(); i++)
    {
        amt += line[i];
    }

    int converted_accId = std::stoi(accountId);
    int converted_amt = std::stoi(amt);
    Transaction *new_T = new Transaction(type, converted_accId, f - 48, converted_amt);
    return *new_T;
}

Transaction &TransactionReader::defineAccountOpen(std::string line, char type)
{
    std::string firstName = "";
    std::string lastName = "";
    std::string accountId = "";

    int i;
    for (i = 2; i < line.size(); i++)
    {
        if (line[i] == ' ')
        {
            break;
        }
        firstName += line[i];
    }

    for (i += 1; i < line.size(); i++)
    {
        if (line[i] == ' ')
        {
            break;
        }
        lastName += line[i];
    }

    for (i += 1; i < line.size(); i++)
    {
        if (line[i] == ' ')
        {
            break;
        }
        accountId += line[i];
    }

    int converted_accId = std::stoi(accountId);
    Transaction *new_T = new Transaction(type, firstName, lastName, converted_accId);
    return *new_T;
}
/*
REVISION CHECKLIST:
- Exception Handling.
- Algorithm Efficiency Changes.
*/
Transaction &TransactionReader::defineFundTransfer(std::string line, char type)
{
    Transaction *new_T;
    std::string accountId_1 = "";
    std::string accountId_2 = "";
    int fund_index_1;
    int fund_index_2;
    std::string amt;
    /*
    Transfers follow this format:
    [Transaction Type] [Account Number (Fund index as last integer)] [Amount] [Account Number (Fund index as last integer)]
    */

    // integer used for iterating through input line.
    int i;

    // First Account number identified.
    for (i = 2; i < 6; i++)
    {
        accountId_1 += line[i];
    }

    std::cout << accountId_1 << std::endl;

    // First fund index obtained.
    fund_index_1 = line[i];

    std::cout << fund_index_1 << std::endl;

    // Amount to be transferred identified.
    for (i += 2; i < line.size(); i++)
    {
        if (line[i] == ' ')
        {
            break;
        }
        amt += line[i];
    }

    cout << amt << endl;

    // Second Account number identified.
    for (i += 1; i < line.size(); i++)
    {
        if (i == line.size() - 1)
        {
            break;
        }
        accountId_2 += line[i];
    }

    std::cout << accountId_2 << std::endl;

    // Second Fund index obtained.
    fund_index_2 = line[i];

    std::cout << fund_index_2 << std::endl;

    // Transaction established.
    new_T = new Transaction(type, std::stoi(accountId_1), fund_index_1 - 48,
                            std::stoi(amt), std::stoi(accountId_2), fund_index_2 - 48);

    cout << new_T->getFundID() << " " << new_T->getTransferToFundID() << endl;

    return *new_T;
}

Transaction &TransactionReader::defineHistoryQuery(std::string line, char type)
{
    Transaction *new_T;
    std::string account;

    // Store account Id for lookup.
    for (int i = 2; i < line.size(); i++)
    {
        account += line[i];
    }

    // Determine if a Fund index is included.
    if (account.size() == 5)
    {
        int f_index = account[account.size() - 1];
        account.erase(account.size() - 1);
        new_T = new Transaction(type, std::stoi(account), f_index - 48);
        return *new_T;
    }

    new_T = new Transaction(type, std::stoi(account));
    return *new_T;
}

#endif // TRANSACTION_READER_CPP