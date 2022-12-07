#include "Fund.h"

Fund::Fund()
{
    this->balance = 0;
}

Fund::Fund(char fundID, std::string fundName)
{
    this->fundID = fundID;
    this->name = fundName;
    this->balance = 0;
}

Fund::~Fund() {}

int Fund::getBalance()
{
    return this->balance;
}

char Fund::getFundID()
{
    return this->fundID;
}

std::string Fund::getName()
{
    return this->name;
}

vector<Transaction> Fund::getHistory()
{
    return this->history;
}

bool Fund::add(int amountToAdd)
{
    if (amountToAdd < 0)
        return false;
    this->balance += amountToAdd;
    return true;
}

bool Fund::withdraw(int amountToWithdraw)
{
    if (amountToWithdraw < 0)
        return false;
    if (this->balance - amountToWithdraw < 0)
        return false;

    this->balance -= amountToWithdraw;
    return true;
}

bool Fund::addTransaction(Transaction trans)
{
    this->history.push_back(trans);
}

bool Fund::operator<(const Fund &other)
{
    return (this->balance < other.balance);
}

bool Fund::operator>(const Fund &other)
{
    return (this->balance > other.balance);
}

bool Fund::operator<=(const Fund &other)
{
    return (this->balance <= other.balance);
}

bool Fund::operator>=(const Fund &other)
{
    return (this->balance >= other.balance);
}

bool Fund::operator==(const Fund &other)
{
    return (this->balance == other.balance);
}
