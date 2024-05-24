#ifndef BSTREE_H
#define BSTREE_H
#include "Account.h"
#include <fstream>
#pragma once

class BSTree
{
    
public:
    BSTree();
    ~BSTree();

    bool Insert(Account* account);

    // retrieve object, first parameter is the ID of the account
    // second parameter holds pointer to found object, NULL if not found
    bool Retrieve(const int &account_id, Account *&account) const;
    BSTree &operator=(BSTree &tree);
    bool isEmpty() const;
    int Size() const;

    // displays the contents of a tree to cout
    void Display() const;

private:
    struct Node
    {
        Node *right = nullptr;
        Node *left = nullptr;
        Account *p_acct;
        
        Node(Account *account, Node *left, Node *right)
        {

            p_acct = account;
            left = left;
            right = right;
            
        }
        Node(Account *account){
            p_acct = account;
            left = nullptr;
            right = nullptr;
        }
        
    };
    Node *root_ = nullptr;
    bool InsertHelper(Node *cur, Account* account);
    void MakeEmpty(Node* root);
    void printHelper(Node *root) const;
    int size_;
};

#endif