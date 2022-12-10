#pragma once
#include "Account.h"

class AccountTree
{
public:
	AccountTree();
	~AccountTree();

	bool Insert(Account *insert);
	bool Retrieve(const int &accountNumber, Account *&acc) const;
	void Display() const;

	void Empty();
	bool isEmpty() const;

private:
	struct Node
	{
		Node *left;
		Node *right;
		Account *pAcct;
	};
	Node *root;
	bool RecursiveInsert(Node *cur, Account *insert);
	void recursivePrint(Node *printNode) const;
};
