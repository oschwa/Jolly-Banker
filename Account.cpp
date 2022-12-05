#include "Account.h"

Account::Account() {}

Account::Account(std::string firstName, std::string lastName, std::string id) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->id = id;
}

Account::~Account() {}

bool Account::deposit(int f, double amt) {
    //Locate index with desired Fund object in 'funds' and use the 
    //add() method to add the 'amt' to it. 
    //Include handling for incorrect Fund number.
    //Include handling for negative 'amt' value.
    return false;
}

bool Account::removeFund(std::string fundNum) {
    //Locate index with desired Fund object in 'funds' and 
    //remove from array.
}

bool Account::withdrawFromFund(std::string fundNum, double amt) {
    //Locate index with desired Fund object in 'funds' and use the 
    //withdraw() method to subtract the 'amt' from it.
    //Include handling for incorrect Fund number.
    //Include handling for negative 'amt' value.
    return false;
}

std::string Account::checkFund(std::string fundNum) {
    //Locate index with desired Fund object in 'funds' and use the 
    //check() method to view balance.
    //Include handling for incorrect Fund number.
}

