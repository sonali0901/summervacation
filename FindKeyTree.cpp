#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node * left, *right;
};
Node * newNode(int data)
{
	Node * n=new Node();
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	return n;
}
bool findkey(Node *root, int key)
{
	if(root)
	{
		if(root->data == key)
		return true;
		else
		{
			return findkey(root->left, key)||findkey(root->right, key);
		}
	}
}
int main()
{
Node *root = newNode(2);
    root->left        = newNode(7);
    root->right       = newNode(5);
    root->left->right = newNode(6);
    root->left->right->left=newNode(1);
    root->left->right->right=newNode(11);
    root->right->right=newNode(9);
    root->right->right->left=newNode(4);
    int key = 70;
    cout << findkey(root, key) << endl;
    return 0;
}
