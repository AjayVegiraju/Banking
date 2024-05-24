#include "jolly_banker.h"
#include <fstream>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

Bank::Bank()
{
   
}

//----------------------------------------------------------------

Bank::~Bank()
{

}

//----------------------------------------------------------------

void Bank::ReadIn(string file_name)
{
    ifstream infile(file_name);
    if (!infile)
    {
        cout << "file could not be opened" << endl;
    }
    else
    {

        string line;
        char t;

        for (;;)
        {

            infile >> t;

            if (infile.eof())
            {
                break;
            }
            else
            {
                if (t == 'O')
                {
                    int account;
                    string first_name;
                    string last_name;
                    infile >> account;
                    infile >> first_name;
                    infile >> last_name;
                    Account *new_account = new Account(account, first_name, last_name);
                    accounts_.Insert(new_account);
                    new_account = nullptr;
                }
                else if (t == 'D' || t == 'W')
                {

                    int account, fund, amount;
                    infile >> account;
                    
                    infile >> fund;
                    infile >> amount;
                    Transaction nextItem(t, account, fund, amount);
                    transactions_.push(nextItem);

                    //(char type, int first_account_number = 0, int first_acc_fund = 0, int amount = 0 int sec_account_number = 0, int sec_acc_fund = 0)
                }
                else if (t == 'A')
                {
                    int account;
                    infile >> account;

                    Transaction nextItem(t, account);
                    transactions_.push(nextItem);
                }
                else if (t == 'F')
                {
                    int account;
                    int fund;
                    infile >> account;
                    infile >> fund;

                    Transaction nextItem(t, account, fund);
                    transactions_.push(nextItem);
                }
                else if (t == 'T')
                {
                    int account, fund, second_account, second_fund, amount;
                    infile >> account;
                    infile >> fund;
                    infile >> second_account;
                    infile >> second_fund;
                    infile >> amount;

                    Transaction nextItem(t, account, fund, amount, second_account, second_fund);
                    transactions_.push(nextItem);
                }
            }
        }
    }

    infile.close();
}

//----------------------------------------------------------------

string Bank::Execute()
{
    while (!transactions_.empty())
    {
        Transaction nextItem = transactions_.front();
        if (nextItem.GetTransType() == 'D')
        {
            if(nextItem.GetFirstAccFund()>8||nextItem.GetFirstAccFund()<0){
                cerr<< "ERROR: Invalid fund number. Transaction Refused"<<endl;
            }else{
                Account *one;
            if (accounts_.Retrieve(nextItem.GetFirstAccountNumber(), one))
            {
                
                one->deposit(nextItem);
            }
            else{

            }
            }
            
                
        }
        else if (nextItem.GetTransType() == 'W')
        {
            Account *one;
            if (accounts_.Retrieve(nextItem.GetFirstAccountNumber(), one))
                one->withdraw(nextItem);
         
            
        }
        else if (nextItem.GetTransType() == 'A')
        {
           
            Account *one;
            if (accounts_.Retrieve(nextItem.GetFirstAccountNumber(), one)){
               
                cout << *one;
               
            }
            
                
        }
        else if (nextItem.GetTransType() == 'F')
        {
            Account *one;
            if (accounts_.Retrieve(nextItem.GetFirstAccountNumber(), one))
            {
                cout << "\n" << one->displayFundHistory(nextItem.GetFirstAccFund());
         
            }
        }
        else if (nextItem.GetTransType() == 'T')
        {
            Account *one, *two;
            if (accounts_.Retrieve(nextItem.GetFirstAccountNumber(), one))
            {
                if (accounts_.Retrieve(nextItem.GetSecondAccountNumber(), two))
                {
                    one->withdraw(nextItem);
                    two->transferInto(nextItem);
                }
                else
                {
                    
                }
            }
            else
            {
                
            }
        }
        else
        {
            cout << "invalid transaction type" << endl;
        }
        transactions_.pop();
    }

    return "";
}

void Bank::Output()
{
    
     accounts_.Display();
  
}
