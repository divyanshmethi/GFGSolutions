#include<iostream>
#include<queue>
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

void rightViewRecursiveUtil(Node* root,int level,int* maxLevel)
{
	if(!root)
	{
		return;
	}
	if(level > *maxLevel)
	{
		*maxLevel = level;
		cout<<root->data<<" ";
	}
	rightViewRecursiveUtil(root->right,level+1,maxLevel);
	rightViewRecursiveUtil(root->left,level+1,maxLevel);
}

void rightViewRecursive(Node* root)
{
	if(!root)
	{
		return;
	}
	int maxLevel = 0;
	rightViewRecursiveUtil(root,1,&maxLevel);
}

void rightViewIterative(Node* root)
{
	if(!root)
	{
		return;
	}
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	Node* ele;
	bool isLevel = false;
	while(!q.empty())
	{
		ele = q.front();
		q.pop();
		if(q.front()==NULL)
		{
			q.pop();
			cout<<ele->data<<" ";
			isLevel = true;
		}
		if(ele->left)
		{
			q.push(ele->left);
		}
		if(ele->right)
		{
			q.push(ele->right);
		}
		if(isLevel && !q.empty())
		{
			q.push(NULL);
			isLevel = false;
		}
	}
}

int main()
{
	Node* root = newNode(12);
    root->left = newNode(10);
    root->right = newNode(30);
    root->right->left = newNode(25);
    root->right->right = newNode(40);
    cout<<"Right View Recursive : "<<endl;
    rightViewRecursive(root);
    cout<<endl;
    cout<<"Right View Iterative : "<<endl;
  	rightViewIterative(root);
    return 0; 
}
