#ifndef ACCOUNT_CPP
#define ACCOUNT_CPP
#include "Account.h"


Account::Account() {}

Account::Account(std::string firstName, std::string lastName, std::string id) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->id = stoi(id);
}

Account::~Account() {}

bool Account::deposit(int f, double amt) {
    if (f > 10 || f < 0) {
        return false;
    }
    funds[f].add(amt);
    return true;
}

bool Account::withdraw(int f, double amt) {
    if (f > 10 || f < 0) {
        return false;
    }
    funds[f].withdraw(amt);
}

bool Account::transfer(int f, int f1, double amt) {
    if (f > 10 || f < 0) {
        return false;
    }
    else if (f1 > 10 || f1 < 0) {
        return false;
    }

    withdraw(f1, amt);
    deposit(f, amt);

    return true;
}

double Account::transferSend(int f, double amt) {
    withdraw(f, amt);
    return amt;
}

bool Account::transferReceive(int f, double amt) {
    if (f > 10 || f < 0) {
        return false;
    }

    deposit(f, amt);
    return true;
}

std::string Account::getFirstName() {
    return firstName;
}

std::string Account::getLastName() {
    return lastName;
}

int Account::getId() {
    return id;
}

double check(int f) {
    //return funds[f].check();
}

std::ostream& operator << (std::ostream& os, const Account& a) {
    os << a.firstName << " " << a.lastName << " " << "Account ID:" << " " << a.id << endl;
    os << "Money Market: " << "$" << a.funds[0].getBalance() << endl;
    os << "Prime Money Market: " << "$" << a.funds[1].getBalance() << endl;
    os << "Long-Term Bond: " << "$" << a.funds[2].getBalance() << endl;
    os << "Short-Term Bond: " << "$" << a.funds[3].getBalance() << endl;
    os << "500 Index Fund : " << "$" << a.funds[4].getBalance() << endl;
    os << "Capital Value Fund: " << "$" << a.funds[5].getBalance() << endl;
    os << "Growth Equity Fund: " << "$" << a.funds[6].getBalance() << endl;
    os << "Growth Index Fund: " << "$" << a.funds[7].getBalance() << endl;
    os << "Value Fund: " << "$" << a.funds[8].getBalance() << endl;
    os << "Value Stock Index: " << "$" << a.funds[8].getBalance() << endl;
    return os;
}

#endif //FUNDS_CPP
