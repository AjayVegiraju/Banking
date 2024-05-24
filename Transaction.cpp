#include "Transaction.h"
#include <string>
#include <iostream>
using namespace std;
Transaction::Transaction()
{
}

Transaction::Transaction(char trans_type_, std::string firstName, std::string lastName, int first_account_number_)
{
    trans_type_ = trans_type_;
    first_name_ = firstName;
    last_name_ = lastName;
    first_account_number_ = first_account_number_;
    passed_trans_ = true;
}

Transaction::Transaction(char type, int accountNumber, int fundNumber, int amount)
{
    trans_type_ = type;
    first_account_number_ = accountNumber;
    first_acc_fund_ = fundNumber;
    amount_ = amount;
    passed_trans_ = true;
}

Transaction::Transaction(char type, int accountNumber, int fundNumber, int amount, int transferAccountNumber, int transferFundNumber)
{
    trans_type_ = type;
    first_account_number_ = accountNumber;
    first_acc_fund_ = fundNumber;
    amount_ = amount;
    sec_account_number_ = transferAccountNumber;
    sec_acc_fund_ = transferFundNumber;
    passed_trans_ = true;
}

Transaction::Transaction(char type, int accountNumber)
{
    trans_type_ = type;
    first_account_number_ = accountNumber;
    passed_trans_ = true;
}

Transaction::Transaction(char type, int accountNumber, int fundNumber)
{
    trans_type_ = type;
    first_account_number_ = accountNumber;
    first_acc_fund_ = fundNumber;
    passed_trans_ = true;
}
// Transaction::Transaction(char type, int first_account_number, int first_acc_fund, int amount, int sec_account_number, int sec_acc_fund)
// {
//     trans_type_ = type;
//     first_account_number_ = first_account_number_;
//     sec_account_number_ = sec_account_number;
//     first_acc_fund_ = first_acc_fund;
//     sec_acc_fund_ = sec_acc_fund;
//     amount_ = amount;
// }

// void Transaction::setName(string name)
// {

//     int pos = name.find(" ");

//     first_name_ = name.substr(0, pos);
//     last_name_ = name.substr(pos + 1, name.length());
// }

/*
string first_name_, last_name_;
    int first_account_number_;
    int sec_account_number_;
    int first_acc_fund;
    int sec_acc_fund_;
    int amount_;
    char trans_type_;
*/
Transaction::~Transaction()
{
}

//----------------------------------------------------------------

std::string Transaction::GetFirstName()
{
    return first_name_;
}

std::string Transaction::GetLastName()
{
    return last_name_;
}

int Transaction::GetFirstAccountNumber() const
{
    return first_account_number_;
}

int Transaction::GetSecondAccountNumber() const
{
    return sec_account_number_;
}

int Transaction::GetFirstAccFund() const
{
    return first_acc_fund_;
}

int Transaction::GetSecondAccFund() const
{
    return sec_acc_fund_;
}

int Transaction::GetAmount() const
{
    return amount_;
}

char Transaction::GetTransType() const
{
    return trans_type_;
}

void Transaction::SetBool()
{
    passed_trans_ = false;
}

string Transaction::DisplayTransactions() const
{
    string result = "";

    if (GetTransType() == 'D' || GetTransType() == 'W')
    {
        result += " " + string(1, GetTransType()) + " " + to_string(GetFirstAccountNumber()) + " " + to_string(GetFirstAccFund()) + " " + to_string(GetAmount());
    }
    else if (GetTransType() == 'T')
    {
        result += " " + string(1, GetTransType()) + " " + to_string(GetFirstAccountNumber()) + " " + to_string(GetFirstAccFund()) + " " + to_string(GetAmount()) + " " + to_string(GetSecondAccountNumber()) + " " + to_string(GetSecondAccFund());
    }

    return result;
}

ostream &operator<<(ostream &out, const Transaction &trans)
{

if(trans.passed_trans_){
    if (trans.GetTransType() == 'D' || trans.GetTransType() == 'W')
    {
        out << " " << trans.GetTransType() << " " << trans.GetFirstAccountNumber() << " " << trans.GetFirstAccFund() << " " << trans.GetAmount();
    }
    else if (trans.GetTransType() == 'T')
    {
        out << " " << trans.GetTransType() << " " << trans.GetFirstAccountNumber() << " " << trans.GetFirstAccFund() << " " << trans.GetSecondAccountNumber() << " " << trans.GetSecondAccFund() << " " << trans.GetAmount();
    }
}else{
    if (trans.GetTransType() == 'D' || trans.GetTransType() == 'W')
    {
        out << " " << trans.GetTransType() << " " << trans.GetFirstAccountNumber() << " " << trans.GetFirstAccFund() << " " << trans.GetAmount() << " (Failed)";
    }
    else if (trans.GetTransType() == 'T')
    {
        out << " " << trans.GetTransType() << " " << trans.GetFirstAccountNumber() << " " << trans.GetFirstAccFund() << " " << trans.GetSecondAccountNumber() << " " << trans.GetSecondAccFund() << " " << trans.GetAmount() << " (Failed)";
    }
}

    return out;
}