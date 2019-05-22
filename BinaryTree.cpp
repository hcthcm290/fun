#include "stdafx.h"
#include <iostream>

using namespace std;

int max(int a, int b)
{
	if (a > b)
	{
		return a;
	} 
	return b;
}

struct node
{
	int info;
	node* pLeft;
	node *pRight;
};

struct Tree
{
	node* Root;
};

void init(Tree& t)
{
	t.Root = NULL;
}

node* getNode(int x)
{
	node* t;
	t = new node;
	if (t == NULL)
	{
		return NULL;
	}

	t->info = x;
	t->pLeft = t->pRight = NULL;
	return t;
}

void insert(node& n, node* p)
{
	if (p->info < n.info)
	{
		if (n.pLeft == NULL)
		{
			n.pLeft = p;
			return;
		}
		else
		{
			insert(*n.pLeft, p);
			return;
		}
	}
	else
	{
		if (n.pRight == NULL)
		{
			n.pRight = p;
			return;
		}
		else
		{
			insert(*n.pRight, p);
			return;
		}
	}
}
void insert(Tree& t, int x)
{
	node* p = getNode(x);
	if (t.Root == NULL)
	{
		t.Root = p;
		return;
	}
	insert(*t.Root, p);
}

void LNR(node* n)
{
	if (n == NULL)
	{
		return;
	}

	LNR(n->pLeft);
	cout << n->info << " ";
	LNR(n->pRight);
}
node* find(const Tree& t, int x)
{
	node* p = t.Root;
	while (p != NULL)
	{
		if (p->info == x)
		{
			return p;
		}
		else if (x < p->info)
		{
			p = p->pLeft;
		}
		else
		{
			p = p->pRight;
		}
	}
	cout << "ERROR 404 not found!" << endl;
	return NULL;
}
int Height(node* t)
{
	if (t == NULL)
	{
		return 0;
	}
	return max(Height(t->pLeft) + 1, Height(t->pRight) + 1);
}
int CountNodeWithLeaf(node* t)
{
	if (t == NULL)
	{
		return 0;
	}
	if (t->pLeft == NULL && t->pRight == NULL)
	{
		return 0;
	}
	return CountNodeWithLeaf(t->pLeft) + CountNodeWithLeaf(t->pRight) + 1;
}

int main()
{
	int n;
	Tree t;
	init(t);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		insert(t, temp);
	}
	LNR(t.Root);
	cout << endl;
	cout << CountNodeWithLeaf(t.Root);
}

