#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    Node *left, *right;
    int data;
    int level;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
        level = 1;
    }
};

Node* Search(Node *root, int data)
{
    if (!root)
        return NULL;
    if (data == root->data)
        return root;
    else if (data < root->data)
        return NULL;
    else 
    {
        //data > root->data
        Node *p = NULL;
        if (root->left)
            p = Search(root->left, data);
        if (p)
            return p;
        else if (root->right)
            p = Search(root->right, data);
        return p;
    }
}

void Insert(Node *root, int data, int parent, bool left)
{
    Node *p = Search(root, parent);
    //chac chan co p
    if (left)
    {   
        p->left = new Node(data);
        p->left->level = p->level + 1;
    }
    else
    {    
        p->right = new Node(data);
        p->right->level = p->level + 1;
    }
}

void Swap(Node *root, int level, bool &yet)
{
    if (root->level > level)
        return;
    else if (root->level < level)
    {
        if (root->left)
            Swap(root->left, level, yet);
        if (root->right)
            Swap(root->right, level, yet);
    }
    else
    {
        Node *p = root->left;
        root->left = root->right;
        root->right = p;
        yet = true;
        return;
    }
}

void InOrder(Node *root)
{
    if (root)
    {
        InOrder(root->left);
        cout << root->data << " ";
        InOrder(root->right);
    }
}

void DeleteBinTree(Node *&root)
{
	if (!root)
		return;

	if (root->left)
	{
		DeleteBinTree(root->left);
		root->left = NULL;
	}
	if (root->right)
	{
		DeleteBinTree(root->right);
		root->right = NULL;
	}
	delete root;
	root = NULL;
}

int main() {
    int N, t1 = 0, t2 = 0, h = 0, T, K;
    cin >> N;
    Node *root = new Node(1), *p = NULL;
    while (t2 < N && t1 < N)
    {
        h++;
        cin >> t1 >> t2;
        if (t1 != -1)
            Insert(root, t1, h, true);
        if (t2 != -1)
            Insert(root, t2, h, false);
    }
    do
    {
        cin >> T;
    } while (T == -1);
    
    for (int i = 0; i < T; ++i)
    {
        cin >> K;
        int S = 0;
        bool yet;
        do
        {
            S += K;
            yet = false;
            Swap(root, S, yet);
        } while (yet);
        InOrder(root);
        cout << endl;
    }
    
    DeleteBinTree(root);
    return 0;
}
