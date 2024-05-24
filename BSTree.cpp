#include "BSTree.h"

BSTree::BSTree()
{
    root_ = nullptr;
}
//----------------------------------------------------------------

BSTree::~BSTree()
{
    size_=0;
    MakeEmpty(root_);
    
}

//----------------------------------------------------------------

void BSTree::MakeEmpty(Node* root)
{
    if(root==nullptr)return;
    MakeEmpty(root->left);
    MakeEmpty(root->right);
    delete root;
}

//----------------------------------------------------------------

bool BSTree::isEmpty() const{
    return root_ == nullptr;
}

//----------------------------------------------------------------

bool BSTree::Retrieve(const int &account_id, Account *&account) const
{
    
	Node *current = root_;
	bool search = false;


	while (!search) 
	{
		if (current != nullptr && account_id == current->p_acct->getAccNum())
		{
			search = true;
			account = current->p_acct;
			return search;
		}
		else if(current != nullptr && account_id > current->p_acct->getAccNum())
		{
			current = current->right;
		}
		else if (current != nullptr && account_id < current->p_acct->getAccNum())
		{
			current = current->left;
		}
		else
		{
			search = true;
		}

	}
	cerr << "ERROR: Account Number " << account_id  << " Cannot Be Found. Transferal refused"<< endl;
	return false;
}

// bool BSTree::Retrieve(const int &account_id, Account *&account)
// {
//     if(isEmpty())return false;
//     else{
//         int num = account_id;
//         Node* cur = root_;
//         return RetrieveHelper(cur, num, account);

//     }

// }

// //----------------------------------------------------------------

// bool BSTree::RetrieveHelper(Node* cur, int& account_id, Account *&account)
// {
//     if(cur == nullptr)return false;
//     if(account_id == cur->p_acct->getAccNum()){
//         account = cur->p_acct;
//         return true;
//     }

//     if(account_id < cur->p_acct->getAccNum())
//     {
//         if(cur->left == nullptr)return false;
//         RetrieveHelper(cur->left, account_id, account);
//     }else if(account_id > cur->p_acct->getAccNum())
//     {
//         if(cur->right == nullptr)return false;
//         RetrieveHelper(cur->right, account_id, account);
//     }

//     return false;
// }

//----------------------------------------------------------------

bool BSTree::Insert(Account* account)
{
    
    if (root_ == nullptr)
    {
        root_ = new Node(account, nullptr, nullptr);
    }
    else
    {
        Node* cur = root_;
        return InsertHelper(cur, account);
    }
    size_++;
    return true;
}



bool BSTree::InsertHelper(Node *cur, Account *account)
{
    
    if(account->getAccNum() > cur->p_acct->getAccNum()){
        if(cur->right == nullptr){
            Node* newNode = new Node(account, nullptr, nullptr);
            cur->right = newNode;
            return true;
            
        }else{
            return InsertHelper(cur->right, account);
        }
    }else if(account->getAccNum() < cur->p_acct->getAccNum()){
        if(cur->left == nullptr){
            Node* newNode = new Node(account, nullptr, nullptr);
            cur->left = newNode;
            return true;
        }else{
            return InsertHelper(cur->left, account);
        }
    }else{
        cerr << "ERROR: Account " << account->getAccNum() << " is already open. Transaction refused."<< endl;
        return false;
    }
    
}

//----------------------------------------------------------------

BSTree &BSTree::operator=(BSTree &tree)
{
    root_ = tree.root_;
    return *this;
}

//----------------------------------------------------------------

int BSTree::Size() const{
    return size_;
}

//----------------------------------------------------------------

void BSTree::Display() const
{
    if (root_ == nullptr)
	{
		cerr << "ERROR: ACCOUNT LIST IS EMPTY" << endl;
	}
	
    printHelper(root_);
    
    
}

//----------------------------------------------------------------

void BSTree::printHelper(Node *current) const
{
    if (current == nullptr) return;

    printHelper(current->left);
    cout<<current->p_acct->displayFundBalances();
    printHelper(current->right);
    
}

//----------------------------------------------------------------
