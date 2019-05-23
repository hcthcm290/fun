#include <bits/stdc++.h>

using namespace std;

typedef int ll;
typedef ll infoType;

vector<ll> a;
ll m=0, M=0;


struct Node
{
    int X;
    infoType info;
    Node*pLeft = NULL;
    Node*pRight = NULL;
};

typedef Node* Tree;

Node*GetNode(infoType i)
{
    Node*p=new Node;
    if(!p)
        return p;
    p->info = i;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

void insert_BST(Node* &N, int x, ll c=0)
{
    if(!N)
    {
        Node* p;
        p = new Node;
        p = GetNode(x);
        N = p;
        N->X = c;
        return;
    }
    if(x <= N->info)
        insert_BST(N->pLeft, x, c-1);
    else
        insert_BST(N->pRight,x, c+1);
}

void search(Node* n)
{
    if(n == NULL)
        return;
    queue<Node*> Q;
    Q.push(n);
    a.push_back(n->info);
    while(Q.empty() != true)
    {
        Node* current = Q.front();
        Q.pop();
        if(current->pLeft != NULL)
        {

            if(current->pLeft->X < m)
            {
                a.push_back(current->pLeft->info);
                m -= 1;
            }
            Q.push(current->pLeft);
        }
        if(current->pRight != NULL)
        {
            if(current->pRight->X > M)
            {
                a.push_back(current->pRight->info);
                M += 1;
            }
            Q.push(current->pRight);
        }

    }
}

void Input(Tree&T)
{
    ll n;
    cin>>n;
    while(n--)
    {
        infoType X;
        cin>>X;
        insert_BST(T,X,0);
    }
}

int main()
{
    Tree T = NULL;
    Input(T);
    search(T);
    sort(a.begin(),a.end());
    for(ll i=0; i<a.size(); i++)
        cout<<a[i]<<' ';
    return 0;
}
