#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* left,*right;
};

Node* newNode(int data)
{
	Node* node = new Node();
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

int getHeight(Node* root)
{
	if(!root)
	{
		return 0;
	}
	int lHeight = 1 + getHeight(root->left);
	int rHeight = 1 + getHeight(root->right);
	return max(lHeight,rHeight);
}

bool isBalanced(Node* root)
{
	if(!root)
	{
		return true;
	}
	int leftHeight = getHeight(root->left);
	int rightHeight = getHeight(root->right);
	if(abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right))
	{
		return true;
	}
	return false;
}

int main()
{
	Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(8);
    
    if (isBalanced(root))
        cout << "Tree is balanced";
    else
        cout << "Tree is not balanced";
    return 0;
}
