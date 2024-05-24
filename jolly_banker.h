#ifndef JOLLY_BANK_H_
#define JOLLY_BANK_H_
#include "Transaction.h"
#include <queue>
#include <iostream>
#include "BSTree.h"
#include "Account.h"
#include <fstream>
#pragma once

using namespace std;


class Bank
{
    
public:
    Bank();
    ~Bank();
    //function to read in transactions from the file to the queue
    void ReadIn(const string file_name);
    string Execute();
    void Output();

private:

        queue<Transaction> transactions_;
        BSTree accounts_;

};

#endif