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

void Account::viewHistory(int f) const
{
    cout << "Transaction History for " << this->firstName << " " << this->lastName << " ";
    cout << funds[f] << endl
         << " ";
    funds[f].displayHistory();
}

ostream &operator<<(ostream &OUT, const Account &a)
{
    OUT << a.firstName << " " << a.lastName << " Account ID: " << a.id;
    for (int i = 0; i < 10; i++)
    {
        OUT << " " << a.funds[i] << endl;
    }
}

#endif // FUNDS_CPP
