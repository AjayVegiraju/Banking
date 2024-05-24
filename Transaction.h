#ifndef TRANSACTION_H_
#define TRANSACTION_H_
#include <iostream>
#include <string>
#include <vector>

#pragma once
using namespace std;

class Transaction
{
public:
    Transaction();
    ~Transaction();
    Transaction(char type, string firstName, string lastName,int first_account_number_);
	Transaction(char type, int accountNumber, int fundNumber, int amount);
	Transaction(char type, int accountNumber, int fundNumber, int amount, int transferAccountNumber, int transferFundNumber);
	Transaction(char type, int accountNumber);
	Transaction(char type, int accountNumber, int fundNumber);
    // Transaction(char trans_type_, string firstName, string lastName, int first_account_number_);
    // Transaction(char type, int first_account_number = 0, int first_acc_fund = 0, int amount = 0, int sec_account_number = 0, int sec_acc_fund = 0);
    // void setName(string name);
    string GetFirstName();
    string GetLastName();
    int GetFirstAccountNumber() const;
    int GetSecondAccountNumber() const;
    int GetFirstAccFund() const;
    int GetSecondAccFund() const;
    int GetAmount() const;
    char GetTransType() const;
    string DisplayTransactions() const;
    void SetBool();

    friend ostream & operator<<(ostream &out, const Transaction &trans);

private:
    string first_name_;
    string last_name_;
    int first_account_number_;
    int sec_account_number_;
    int first_acc_fund_;
    int sec_acc_fund_;
    int amount_;
    char trans_type_;
    bool passed_trans_ = true;
};

#endif