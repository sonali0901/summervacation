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
int maxele(Node *root)
{
	int max =0;
	if(root==NULL)
	return 0;
	queue<Node *> q;
	q.push(root);
	while(!q.empty())
	{
		Node * temp = q.front();
		q.pop();
		if(temp->data>max)
		max = temp->data;
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
			
	}
	return max;
}
int main()
{
    // Let us construct the Binary Tree shown in the
    // above figure
    struct Node *root = newNode(2);
    root->left        = newNode(7);
    root->right       = newNode(5);
    root->left->right = newNode(6);
    root->left->right->left=newNode(1);
    root->left->right->right=newNode(11);
    root->right->right=newNode(9);
    root->right->right->left=newNode(4);
 
    printf ("Maximum element is %d \n", maxele(root));
    return 0;
}
