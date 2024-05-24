#include "Account.h"
#include <string>
using namespace std;

Account::Account()
{
}

Account::Account(int acc_num, string first_name, string last_name)
{
    acc_num_ = acc_num;
    first_name_ = first_name;
    last_name_ = last_name;
    string account_funds[] = {"Money Market", "Prime Money Market", "Long-Term Bond", "Short-Term Bond", "500 Index Fund", "Capital Value Fund", "Growth Equity Fund", "Growth Index Fund"};
    for (int i = 0; i < 8; i++)
    {
        funds[i].SetFundName(account_funds[i]);
    }
}

bool Account::withdraw(Transaction transaction)
{
    
    if (transaction.GetAmount() <= funds[transaction.GetFirstAccFund()].GetBalance())
    {
        funds[transaction.GetFirstAccFund()].SubtractAmount(transaction.GetAmount());
        funds[transaction.GetFirstAccFund()].History(transaction);
        return true;
    }
    else
    {
        //followeing are to take care of overdrawing from money market and bond funds
        if (transaction.GetFirstAccFund() == 0)
        {
            if (funds[1].GetBalance() >= transaction.GetAmount() - funds[transaction.GetFirstAccFund()].GetBalance())
            {
                funds[1].SubtractAmount(transaction.GetAmount() - funds[transaction.GetFirstAccFund()].GetBalance());
                funds[0].SetBalanceToZero();
                funds[transaction.GetFirstAccFund()].History(transaction);
                return true;
            }
            
        }else if (transaction.GetFirstAccFund() == 1)
        {

            if (funds[0].GetBalance() >= transaction.GetAmount() - funds[transaction.GetFirstAccFund()].GetBalance())
            {
                funds[0].SubtractAmount(transaction.GetAmount() - funds[transaction.GetFirstAccFund()].GetBalance());
                funds[1].SetBalanceToZero();
                funds[transaction.GetFirstAccFund()].History(transaction);
                return true;
            }
        } else if (transaction.GetFirstAccFund() == 2)
        {
            if (funds[3].GetBalance() >= transaction.GetAmount() - funds[transaction.GetFirstAccFund()].GetBalance())
            {
                funds[3].SubtractAmount(transaction.GetAmount() - funds[transaction.GetFirstAccFund()].GetBalance());
                funds[2].SetBalanceToZero();
                funds[transaction.GetFirstAccFund()].History(transaction);
                return true;
            }
        } else if (transaction.GetFirstAccFund() == 3)
        {
            if (funds[2].GetBalance() >= transaction.GetAmount() - funds[transaction.GetFirstAccFund()].GetBalance())
            {

                funds[2].SubtractAmount(transaction.GetAmount() - funds[transaction.GetFirstAccFund()].GetBalance());
                funds[3].SetBalanceToZero();
                funds[transaction.GetFirstAccFund()].History(transaction);
                return true;
            }
        }
        transaction.SetBool();
        cout <<"ERROR: Not enough funds to withdraw " <<transaction.GetAmount()<<" from "<<funds[transaction.GetFirstAccFund()].GetFundName()<<endl;
        funds[transaction.GetFirstAccFund()].History(transaction);
        return false;

        
    }
}

bool Account::deposit(Transaction transaction)
{
    funds[transaction.GetFirstAccFund()].AddAmount(transaction.GetAmount());
    funds[transaction.GetFirstAccFund()].History(transaction);
    return true;
}

bool Account::transferInto(Transaction transaction)
{
    funds[transaction.GetSecondAccFund()].AddAmount(transaction.GetAmount());
    funds[transaction.GetSecondAccFund()].History(transaction);
    return true;
}

bool Account::operator==(const Account &other) const
{
    if (acc_num_ == other.acc_num_)
        return true;

    return false;
}

bool Account::operator!=(const Account &other) const
{
    if (acc_num_ != other.acc_num_)
        return true;

    return false;
}

bool Account::operator<(const Account &other) const
{
    return acc_num_ < other.acc_num_;
}

bool Account::operator>(const Account &other) const
{
    return acc_num_ > other.acc_num_;
}

bool Account::operator<=(const Account &other) const
{
    return acc_num_ <= other.acc_num_;
}

bool Account::operator>=(const Account &other) const
{

    return acc_num_ > other.acc_num_;
}

Account &Account::operator=(const Account &other)
{
    acc_num_ = other.acc_num_;
    first_name_ = other.first_name_;
    last_name_ = other.last_name_;
    return *this;
}
int Account::getData() const
{
    return acc_num_;
}

int Account::getAccNum()
{
    return acc_num_;
}

string Account::getFirstName()
{
    return first_name_;
}

string Account::getLastName()
{
    return last_name_;
}

string Account::displayFundBalances() const
{
    
    string result = " ";
    result += last_name_ + " " + first_name_ + " Account ID: " + to_string(acc_num_) + "\n";
    for (int i = 0; i < 8; i++)
    {
        result += "  " + funds[i].GetFundName() + ": $" + to_string(funds[i].GetBalance()) + "\n";
    }
  
    cout<< "FINAL BALANCE:"<<endl;
        
    
    
    return result;
}

string Account::displayFundHistory(int fund_number) const
{
    string result = " ";
    result += "Transaction History for " + last_name_ + " " + first_name_ + " " + funds[fund_number].GetFundName() + ": $" + to_string(funds[fund_number].GetBalance()) + "\n";
    result += funds[fund_number].DisplayHistory();

    return result;
}


ostream &operator<<(ostream &stream, const Account &other)
{
    stream << "Transaction History from " << other.last_name_ << " " << other.first_name_ << " by fund." << endl;

    for (int i = 0; i < 8; i++)
    {
        stream << other.funds[i];
    }

    return stream;
}
