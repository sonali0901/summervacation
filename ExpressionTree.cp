#include <iostream>
#include <bits/stdc++.h>
struct node{
	char a;
	node * left, *right;
};
struct node * create(char a)
{
	node * n = new node();
	n->a = a;
	n->left =NULL;
	n->right = NULL;
	return n;
}
using namespace std;
node * infix(string s)
{
	stack <node *> st;
	for(int i=0;i<s.length();i++)
	{
		if(isalnum(s[i]))
		{
			node * n = create(s[i]);
			st.push(n);
		}
		else
		{
			node * n = create(s[i]);
			n->right = st.top();
			st.pop();
			n->left = st.top();
			st.pop();
			st.push(n);
		}
	}
	
	return st.top();
}
void inorder(node *root)
{
	if(root)
	{
		inorder(root->left);
		cout<<root->a<<" ";
		inorder(root->right);
	}
}
int main() {
	string s;
	cin>>s;
	node * root = infix(s);
	inorder(root);
	return 0;
}
