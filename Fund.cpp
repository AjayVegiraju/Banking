#include "Fund.h"

using namespace std;

Fund::Fund()
{
    balance_ = 0;
}

Fund::~Fund()
{
}

void Fund::SetBalanceToZero()
{
    balance_ = 0;
}

void Fund::History(Transaction transaction)
{
    fund_history_.push_back(transaction);
}
bool Fund::IsValid(int amount)
{
    return amount <= balance_;
}

void Fund::AddAmount(int amount)
{
    balance_ += amount;
}

void Fund::SubtractAmount(int amount)
{
    balance_ -= amount;
}

string Fund::DisplayHistory() const
{
    string result = "";
    if (fund_history_.size() == 0)
    {
        return " ";
    }
    else
    {

        for (int i = 0; i < fund_history_.size(); i++)
        {
            result += "  " + fund_history_[i].DisplayTransactions() + "\n";
        }
    }

    return result;
}

int Fund::GetBalance() const
{
    return balance_;
}

void Fund::SetFundName(string name)
{
    fund_name_ = name;
}

string Fund::GetFundName() const
{
    return fund_name_;
}

ostream &operator<<(ostream &stream, const Fund &other)
{
    stream << other.fund_name_ << ": $" << other.balance_ << "\n";
    if (!other.fund_history_.size() == 0)
    {
        
        for (int i = 0; i < other.fund_history_.size(); i++)
        {
            stream << "   " << other.fund_history_[i]<<endl;
        }
    }

    return stream;
}

