#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include "Fund.h"
#include <iostream>
class Account {
private:
    
    //Array of client Fund objects.
    Fund funds[10];
    //Unique four-digit identifier.
    int id;
    //Name
    std::string firstName, lastName;


public:
    /*
    Default constructors and destructor.
    */
    Account();
    Account(std::string firstName, std::string lastName, std::string id);
    ~Account();

    /*
    Deposit method for depositing into 
    a Fund.
    Pre: Requires an integer for Fund index
    and a double for the amount being
    deposited.
    Post: Returns bool indicating success
    or failure.
    */
    bool deposit(int f, double amt);
    /*
    Withdraw method for withdrawing fro
    a Fund.
    Pre: Requires an integer for Fund index
    and a double for the amount being
    withdrawn.
    Post: Returns bool indicating success
    or failure. 
    */
    bool withdraw(int f, double amt);
    /*
    Transfer method for transferring between
    two Funds.
    Pre: Requires two integers for Fund indexes
    and a double for the amount being
    transferred.
    Post: Returns bool indicating success
    or failure.
    */
    bool transfer(int f, int f1, double amt);
    /*
    Transfer method for sending an amount to
    a different Account Fund.
    Pre: Requires an integer for Fund index,
    and a double for the amount being transferred.
    Post: Returns a double representing amount
    transferred.
    */
    double transferSend(int f, double amt);
    /*
    Transfer method for receiving an amount from
    a different Account Fund.
    Pre: Requires an integer for Fund index,
    and a double for the amount being transferred.
    Post: Returns a bool indicating success or failure.
    */
    bool transferReceive(int f, double amt);
    /*
    Method for retrieving first name.
    Pre: N/A
    Post: Returns string representing 
    Account first name.
    */
    std::string getFirstName();
    /*
    Method for retrieving last name.
    Pre: N/A
    Post: Returns string representing 
    Account last name.
    */
    std::string getLastName();
    /*
    Method for retrieving id.
    Pre: N/A
    Post: Returns string representing 
    Account id.
    */
    int getId();
    /*
    Method for viewing amount in a Fund.
    Pre: Requires integer for Fund index.
    Post: Returns double representing 
    amount in Fund.
    */
    int checkFund(int f);

    friend std::ostream& operator << (std::ostream& os, const Account& a);
};

#endif //ACCOUNT_H