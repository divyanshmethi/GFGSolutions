#include<iostream>
#include<queue>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
	Node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

void inorder(Node* root)
{
	if(!root)
	{
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void insert(Node* root,int key)
{
	queue<Node*> q;
	q.push(root);
	Node* ele;
	while(!q.empty())
	{
		ele = q.front();
		q.pop();
		if(!ele->left)
		{
			ele->left = new Node(key);
			return;
		}
		else
		{
			q.push(ele->left);
		}
		if(!ele->right)
		{
			ele->right = new Node(key);
			return;
		}
		else
		{
			q.push(ele->right);
		}
	}
}

void replaceAndDelete(Node*root,Node* endNode)
{
	queue<Node*> q;
	q.push(root);
	Node* ele;
	while(!q.empty())
	{
		ele = q.front();
		q.pop();
		if(ele == endNode)
		{
			ele = NULL;
			delete(endNode);
			return;
		}
		if(ele->right)
		{
			if(ele->right == endNode)
			{
				ele->right = NULL;
				delete(endNode);
				return;
			}
			else
			{
				q.push(ele->right);
			}
		}
		if(ele->left)
		{
			if(ele->left == endNode)
			{
				ele->left = NULL;
				delete(endNode);
				return;
			}
			else
			{
				q.push(ele->left);
			}
		}
	}
}

Node* deleteNumber(Node* root,int value)
{
	if(!root)
	{
		return NULL;
	}
	if(!root->left && !root->right)
	{
		if(root->data == value)
		{
			return NULL;
		}
		else
		{
			return root;
		}
	}
	queue<Node*> q;
	q.push(root);
	Node* ele;
	Node* nodeToDelete = NULL;
	while(!q.empty())
	{
		ele = q.front();
		q.pop();
		if(ele->data == value)
		{
			nodeToDelete = ele;
		}
		if(ele->left)
		{
			q.push(ele->left);
		}
		if(ele->right)
		{
			q.push(ele->right);
		}
	}
	if(nodeToDelete != NULL)
	{
		int data = ele->data;
		replaceAndDelete(root,ele);
		nodeToDelete->data = data;
	}
	return root;
}

void preorder(Node* root)
{
	if(!root)
	{
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(Node* root)
{
	if(!root)
	{
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

int findMin(Node* root)
{
	if(!root)
	{
		return INT_MAX;
	}
	return min(min(root->data,findMin(root->left)),findMin(root->right));
}

int findMax(Node* root)
{
	if(!root)
	{
		return INT_MIN;
	}
	return max(max(root->data,findMax(root->left)),findMax(root->right));
}

int main()
{
	Node* root = new Node(10);
    root->left = new Node(11);
    root->left->left = new Node(7);
    root->right = new Node(9);
    root->right->left = new Node(15);
    root->right->right = new Node(8);
    cout << "Inorder traversal before insertion:";
    inorder(root);
    int key = 12;
    insert(root, key);
    cout << endl;
    cout << "Inorder traversal after insertion:";
    inorder(root);
    cout<<endl;
    root = deleteNumber(root,10);
    cout << "Inorder traversal after insertion:";
    inorder(root);
    cout<<endl;
    cout<<"PreOrder traversal : "<<endl;
    preorder(root);
    cout<<endl;
    cout<<"PostOrder traversal : "<<endl;
    postorder(root);
    cout<<endl;
    cout<<"Minimum Value in the Binary tree is : "<<findMin(root)<<endl;
    cout<<"Minimum Value in the Binary tree is : "<<findMax(root)<<endl;
    return 0;
}
