#ifndef FUND_H
#define FUND_H
#include <string>
#include <vector>
#include "Transaction.h"
#pragma once

using namespace std;
class Fund
{
public:
    Fund();
    ~Fund();

    void AddAmount(int amount);
    void SubtractAmount(int amount);
    bool IsValid(int amount);
    void History( Transaction transaction);
    string DisplayHistory() const;
    void SetFundName(string name);
    int GetBalance() const;
    string GetFundName() const;
    friend ostream& operator<<(ostream& stream, const Fund& other);
    void SetBalanceToZero();

private:
    string fund_name_;
    int balance_;
    vector<Transaction> fund_history_;
};
#endif