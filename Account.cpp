#ifndef ACCOUNT_CPP
#define ACCOUNT_CPP
#include "Account.h"

Account::Account() {}

Account::Account(std::string firstName, std::string lastName, std::string id)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->id = id;
}

Account::~Account() {}

bool Account::deposit(int f, double amt)
{
    if (f > 10 || f < 0)
    {
        return false;
    }
    return (funds[f].add(amt));
}

bool Account::withdraw(int f, double amt)
{
    if (f > 10 || f < 0)
    {
        return false;
    }
    return (funds[f].withdraw(amt));
}

bool Account::transfer(int f, int f1, double amt)
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

int Account::transferSend(int f, double amt)
{
    withdraw(f, amt);
    return amt;
}

bool Account::transferReceive(int f, double amt)
{
    if (f > 10 || f < 0)
    {
        return false;
    }

    deposit(f, amt);
    return true;
}

std::string Account::getFirstName()
{
    return firstName;
}

std::string Account::getLastName()
{
    return lastName;
}

std::string Account::getId()
{
    return id;
}

Fund *Account::getFund(int f)
{
    return &funds[f];
}

int Account::getBalance(int f)
{
    return funds[f].getBalance();
}

#endif // FUNDS_CPP
