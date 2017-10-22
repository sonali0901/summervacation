#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newNode(int data)
{
	struct node *n = new node();
	n->left = NULL;
	n->right = NULL;
	n->data = data;
	return n;
	
}
int sum (node *root)
{
	if(root==NULL)
		return 0;
	if(root->left == NULL && root->right==NULL)
		return root->data;
	else
		return 2*root->data;
}
bool isSum ( node *root)
{
	if(root==NULL || root->left ==NULL && root->right ==NULL)
		return true;
	int leftsum = sum(root->left);
	int rightsum = sum(root->right);
	if(root->data == leftsum+rightsum && isSum(root->left)&&isSum(root->right))
	{
		return true;
	}
	return false;
}
int main() {
	struct node *root  = newNode(26);
    root->left         = newNode(10);
    root->right        = newNode(3);
    root->left->left   = newNode(4);
    root->left->right  = newNode(6);
    root->right->right = newNode(8);
    cout<< isSum(root);
	return 0;
}
