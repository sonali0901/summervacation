#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
};
struct ll{
	int data;
	ll* next;
};

node* create(int data)
{
	node *n1 = new node();
	n1->data = data;
	n1->left = n1->right = NULL;
	return n1;
}
void enter(ll** list, int data)
{
	ll* listnode = new ll();
	listnode->data = data;
	listnode->next = (*list);
	(*list) = listnode;
}

void printlist(ll* list)
{
	while(list)
	{
		cout<<list->data<<" ";
		list=list->next;
	}
	cout<<endl;
}

void inorderTraversal(node* root)
{
    if (root)
    {
        inorderTraversal( root->left );
        cout << root->data << " ";
        inorderTraversal( root->right );
    }
}

int main() {
	// your code goes here
	node * root = new node();
	ll* list = NULL;
	enter(&list, 36);
	enter(&list, 30);
	enter(&list, 25);
	enter(&list, 15);
	enter(&list, 12);
	enter(&list, 10);
	queue<node*> q;
	
	printlist(list);
	
	root->data = list->data;
	root->left=NULL;
	root->right= NULL;
	q.push(root);
	while(list)
	{
		node* n1 = q.front();
		q.pop();
		if(list->next){
			list=list->next;
			node *n2 = create(list->data);
			n1->left = n2;
			q.push(n2);
		}
		if(list)
		{
			list=list->next;
			if(list)
			{
			node *n2 = create(list->data);
			n1->right = n2;
			q.push(n2);
			}
		}
	}
	q = queue<node*>();
	q.push(root);
	/*while(!q.empty())
	{
		node * n1 = q.front();
		q.pop();
		cout<<n1->data;
		if(n1->left)
		q.push(n1->left);
		if(n1->right)
		q.push(n1->right);
	}*/
	inorderTraversal(root);
	return 0;
}
