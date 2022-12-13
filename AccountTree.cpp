
#include "AccountTree.h"

AccountTree::AccountTree()
{
	root = NULL;
}

AccountTree::~AccountTree()
{
	Empty();
}

bool AccountTree::Insert(Account *insert)
	// Adding accounts to the BST
{
	int insertAccountID = stoi(insert->getId());
	if (insertAccountID < 1000 || insertAccountID > 9999)
		
	// Insert account to tree if the account ID from the que is valid 
	{
		cerr << "ERROR: Account Number Not Valid" << endl; 
		return false;
		
	// If invalid display error message
	
	}

	if (root == NULL)
	{
		root = new Node;
		root->pAcct = insert;
		root->left = NULL;
		root->right = NULL;

		return true;
	}
	else
	{
		Node *current = root;
		return RecursiveInsert(current, insert);
	}
	return false;
}

bool AccountTree::Retrieve(const int &accountNumber, Account *&acc) const
	
	// Retrieving and returning account from the tree that was called from the que
{
	Node *current = root;
	bool search = false;

	while (!search)
	{
		if (current != NULL && accountNumber == stoi(current->pAcct->getId()))
		{
			search = true;
			acc = current->pAcct;
			return search;
		}
		else if (current != NULL && accountNumber > stoi(current->pAcct->getId()))
		{
			current = current->right;
		}
		else if (current != NULL && accountNumber < stoi(current->pAcct->getId()))
		{
			current = current->left;
		}
		else
		{
			search = true;
		}
	}
	return false;
}

void AccountTree::Display() const
	
	// Displays contents of BST
{
	if (root == NULL)
	{
		cerr << "ERROR: ACCOUNT LIST IS EMPTY" << endl;
		
	// Notification message  when BST is empty
		
	}
	recursivePrint(root);
}

void AccountTree::Empty()
	
	// Empty contents of BST
{
	delete root;
	root = NULL;
}

bool AccountTree::isEmpty() const
	
	// Check is BST is empty
{
	if (root->left == NULL && root->right == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void AccountTree::recursivePrint(Node *current) const
{
	if (current->right != NULL && current->left != NULL)
	{
		recursivePrint(current->right);
		cout << *(current->pAcct) << endl;
		recursivePrint(current->left);
	}
	else if (current->left != NULL)
	{
		cout << *(current->pAcct) << endl;
		recursivePrint(current->left);
	}
	else if (current->right != NULL)
	{
		cout << *(current->pAcct) << endl;
		recursivePrint(current->right);
	}
	else
	{
		cout << *(current->pAcct) << endl;
	}
}

bool AccountTree::RecursiveInsert(Node *current, Account *insert)
{
	if (stoi(insert->getId()) > stoi(current->pAcct->getId()))
	{
		if (current->right == NULL)
		{
			Node *insInTree = new Node();
			insInTree->pAcct = insert;
			insInTree->left = NULL;
			insInTree->right = NULL;
			current->right = insInTree;
			return true;
		}
		else
		{
			return RecursiveInsert(current->right, insert);
		}
	}
	else if (stoi(insert->getId()) < stoi(current->pAcct->getId()))
	{
		if (current->left == NULL)
		{
			Node *insInTree = new Node();
			insInTree->pAcct = insert;
			insInTree->left = NULL;
			insInTree->right = NULL;
			current->left = insInTree;
			return true;
		}
		else
		{
			return RecursiveInsert(current->left, insert);
		}
	}
	else
	{
		return false;
	}
}
