#include <iostream>
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
void util(Node *root, int &sum)
{
	if(root==NULL)
	return;
	if(root->left)
	{
		if(root->left->left==NULL && root->left->right==NULL)
		sum = sum+root->left->data;
	}
	util(root->left, sum);
	util(root->right, sum);
	
}
int leftLeavesSum( Node *root)
{
	int sum = 0;
	util(root, sum);
	return sum;
}
int main()
{
    // Let us construct the Binary Tree shown in the
    // above figure
    int sum = 0;
    struct Node *root         = newNode(20);
    root->left                = newNode(9);
    root->right               = newNode(49);
    root->right->left         = newNode(23);
    root->right->right        = newNode(52);
    root->right->right->left  = newNode(50);
    root->left->left          = newNode(5);
    root->left->right         = newNode(12);
    root->left->right->right  = newNode(12);
 
    cout << "Sum of left leaves is " << leftLeavesSum(root) << endl;
    return 0;
}
