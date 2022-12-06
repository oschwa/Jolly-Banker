#include "Fund.h"

Fund::Fund()
{
    this->total = 0;
}

Fund::Fund(char fundID, std::string fundName)
{
    this->fundID = fundID;
    this->name = fundName;
    this->total = 0;
}

Fund::~Fund() {}

int Fund::getTotal()
{
    return this->total;
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
    this->total += amountToAdd;
}

bool Fund::withdraw(int amountToWithdraw)
{
    if (this->total - amountToWithdraw < 0)
        return false;

    this->total -= amountToWithdraw;
    return true;
}

std::string Fund::check()
{
    // TODO
}