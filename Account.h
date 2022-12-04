#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
class Account {
private:
    //Fund array goes here.

    //Unique four-digit identifier.
    std::string id;

    //Name
    std::string firstName, lastName;


public:
    Account();
    Account(std::string firstName, std::string lastName, std::string id);
    ~Account();


    bool addFund(std::string fundNum, std::string fundName);
    bool removeFund(std::string fundNum);
    bool addToFund(std::string fundNum, double amt);
    bool withdrawFromFund(std::string fundNum, double amt);
    std::string checkFund(std::string fundNum);
};

#endif //ACCOUNT_H