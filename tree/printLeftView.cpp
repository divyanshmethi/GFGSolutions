#include<iostream>
#include<queue>
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

void leftViewRecursiveUtil(Node* root,int level,int* maxLevel)
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
	leftViewRecursiveUtil(root->left,level+1,maxLevel);
	leftViewRecursiveUtil(root->right,level+1,maxLevel);
}

void leftViewRecursive(Node* root)
{
	if(!root)
	{
		return;
	}
	int maxLevel = 0;
	leftViewRecursiveUtil(root,1,&maxLevel);
}

void leftViewIterative(Node* root)
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
	bool isNext = true;
	while(!q.empty())
	{
		ele = q.front();
		q.pop();
		if(isNext)
		{
			cout<<ele->data<<" ";
			isNext = false;
		}
		if(q.front()==NULL)
		{
			q.pop();
			isLevel = true;
			isNext = true;
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
  
    leftViewRecursive(root);
    cout<<endl;
    leftViewIterative(root);
    cout<<endl;
    return 0; 
}
