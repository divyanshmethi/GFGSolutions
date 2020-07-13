#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *left,*right;
};

Node* newNode(int data)
{
	Node* node = new Node();
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

bool isBSTUtil(Node* root,int low,int high)
{
	if(root==NULL)
	{
		return true;
	}
	if(root->data > high || root->data < low)
	{
		return false;
	}
	return isBSTUtil(root->left,low,root->data - 1) && isBSTUtil(root->right,root->data + 1,high);
}

bool isBST(Node* root)
{
	return isBSTUtil(root,INT_MIN,INT_MAX);
}

int main()
{
	struct Node *root = newNode(3);
    root->left        = newNode(2);
    root->right       = newNode(5);
    root->left->left  = newNode(1);
    root->left->right = newNode(4);
    if (isBST(root)) 
        cout << "Is BST";
    else
        cout << "Not a BST";
}
