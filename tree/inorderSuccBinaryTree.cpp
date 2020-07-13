
#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* left,*right;
	Node(int data)
	{
		this->data = data;
		this->left = this->right = NULL;
	}
};

Node* newNode(int data)
{
	return new Node(data);
}

Node* findMin(Node* root)
{
	while(root->left)
	{
		root = root->left;
	}
	return root;
}

Node* findMax(Node* root)
{
	if(!root)
	{
		return NULL;
	}
	while(root->right)
	{
		root = root->right;
	}
	return root;
}

Node* findInorderSucc(Node* root,Node* node)
{
	if(!root)
	{
		return NULL;
	}
	Node* temp;
	if(root == node || (temp = findInorderSucc(root->left,node)) || (temp = findInorderSucc(root->right,node)))
	{
		if(temp)
		{
			if(root->left==temp)
				return root;
		}
		return root;
	}
	return NULL;
}

Node* inorderSuccesor(Node* root,Node* node)
{
	if(!root)
	{
		return NULL;
	}
	if(node->right)
	{
		return findMin(node->right);
	}
	else
	{
		Node* globalMax = findMax(root->right);
		if(globalMax && node==globalMax)
		{
			cout<<"Last node, No Inorder Successor"<<endl;
			return NULL;
		}
		return findInorderSucc(root,node);
	}
}

int main()
{
	Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->right = newNode(6); 
    
    Node* succ = inorderSuccesor(root, root->right);
    if(succ)
    	cout<<succ->data<<endl;
    succ = inorderSuccesor(root, root->left->left);
	if(succ)
		cout<<succ->data<<endl;
    succ = inorderSuccesor(root, root->right->right);
	if(succ)
		cout<<succ->data<<endl;
  
    return 0;
}
