#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include <string>
#include <iostream>
#include "Transaction.h"
#include "Fund.h"
#include <fstream>

using namespace std;

class Account
{
    
    public:
        Account();
        Account(int acc_num, string first_name, string last_name);
        
        int getData() const;

        Account& operator=(const Account& other);
        bool operator==(const Account& other) const;
        bool operator!=(const Account& other) const;
        bool operator<(const Account& other) const;
        bool operator>(const Account& other) const;
        bool operator<=(const Account& other) const;
        bool operator>=(const Account& other) const;
        bool withdraw(Transaction transaction);
        bool deposit(Transaction transaction);
        bool transferInto(Transaction transaction);
        string displayFundBalances() const;
        string displayFundHistory(int fund_number) const;
        string displayAccountHistory() const;


        int getAccNum();
        string getFirstName();
        string getLastName();
        

        friend ostream& operator<<(ostream& stream, const Account& other);
    private:
    int acc_num_;
    string first_name_;
    string last_name_;
    Fund funds[8];
};
#endif