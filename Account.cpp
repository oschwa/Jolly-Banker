#include "Account.h"

/*
FIXME: Fund array is initialized in this constructor.
*/
Account::Account() {}

Account::Account(std::string firstName, std::string lastName, std::string id) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->id = id;
}

Account::~Account() {}

bool Account::addFund(std::string fundNum, std::string fundName) {
    //Create Fund object here.
    //Add Fund object to array, check to make sure that it isn't full.
    //Also check to make sure the Fund array doesn't already have this Fund.
    return false;
}

bool Account::addToFund(std::string fundNum, double amt) {
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

