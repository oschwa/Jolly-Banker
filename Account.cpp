#ifndef ACCOUNT_CPP
#define ACCOUNT_CPP
#include "Account.h"

Account::Account() {}

Account::Account(std::string firstName, std::string lastName, std::string id)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->id = id;
    this->funds[0] = Fund(0, "Money Market");
    this->funds[1] = Fund(1, "Prime Money Market");
    this->funds[2] = Fund(2, "Long-Term Bond");
    this->funds[3] = Fund(3, "Short-Term Bond");
    this->funds[4] = Fund(4, "500 Index Fund");
    this->funds[5] = Fund(5, "Capital Value Fund");
    this->funds[6] = Fund(6, "Growth Equity Fund");
    this->funds[7] = Fund(7, "Growth Index Fund");
    this->funds[8] = Fund(8, "Value Fund");
    this->funds[9] = Fund(9, "Value Stock Index");
}

Account::~Account() {}

bool Account::deposit(int f, int amt)
{
    if (f > 10 || f < 0)
    {
        return false;
    }
    return (funds[f].add(amt));
}

bool Account::withdraw(int f, int amt)
{
    if (f > 10 || f < 0)
    {
        return false;
    }
    return (funds[f].withdraw(amt));
}

bool Account::transfer(int f, int f1, int amt)
{
    if (f > 10 || f < 0)
    {
        return false;
    }
    else if (f1 > 10 || f1 < 0)
    {
        return false;
    }

    withdraw(f1, amt);
    deposit(f, amt);

    return true;
}

int Account::transferSend(int f, int amt)
{
    withdraw(f, amt);
    return amt;
}

bool Account::transferReceive(int f, int amt)
{
    if (f > 10 || f < 0)
    {
        return false;
    }

    deposit(f, amt);
    return true;
}

std::string Account::getFirstName() const
{
    return firstName;
}

std::string Account::getLastName() const
{
    return lastName;
}

std::string Account::getId() const
{
    return id;
}

int Account::getBalance(int f) const
{
    return funds[f].getBalance();
}

std::string Account::getNameOfFund(int f)
{
    return this->funds[f].getName();
}

void Account::viewHistory() const
{
    cout << "Transaction History for " << this->firstName << " " << this->lastName << " by fund." << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << funds[i] << endl
             << " ";
        funds[i].displayHistory();
    }
}

Fund &Account::getFund(int f)
{
    return funds[f];
}

void Account::viewHistory(int f) const
{
    cout << "Transaction History for " << this->firstName << " " << this->lastName << " ";
    cout << funds[f] << endl
         << " ";
    funds[f].displayHistory();
}

bool Account::addHistory(int f, Transaction *toAdd)
{
    return (this->funds[f].addTransaction(toAdd));
}

ostream &operator<<(ostream &OUT, const Account &a)
{
    OUT << a.firstName << " " << a.lastName << " Account ID: " << a.id << endl;
    for (int i = 0; i < 10; i++)
    {
        OUT << " " << a.funds[i] << endl;
    }
    return OUT;
}

#endif // FUNDS_CPP
