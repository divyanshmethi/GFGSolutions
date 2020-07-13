#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* left,*right;
};

Node* newNode(int data)
{
	Node* node = new Node();
	node->left = node->right = NULL;
	node->data = data;
	return node;
}

void printVerticalOrderUtil(Node* root,map<int,vector<int>> &m,int hd)
{
	if(!root)
	{
		return;
	}
	m[hd].push_back(root->data);
	printVerticalOrderUtil(root->left,m,hd-1);
	printVerticalOrderUtil(root->right,m,hd+1);
}

//Does not preserves the order of nodes
void printVerticalOrderWithoutOrderPreserved(Node* root)
{
	map<int,vector<int>> m;
	int hd = 0;
	printVerticalOrderUtil(root,m,hd);
	for(auto it : m)
	{
		for(auto i : it.second)
		{
			cout<<i<<" "; 
		}
		cout<<endl;
	}
}

void printVerticalOrderWithOrderPreserved(Node* root)
{
	if(!root)
	{
		return;
	}
	map<int,vector<int>> m;
	queue<pair<Node*,int>> q;
	int hd = 0;
	q.push(make_pair(root,hd));
	pair<Node*,int> ele;
	while(!q.empty())
	{
		ele = q.front();
		q.pop();
		hd = ele.second;	
		m[hd].push_back(ele.first->data);
		if(ele.first->left)
		{
			q.push(make_pair(ele.first->left,hd-1));
		}
		if(ele.first->right)
		{
			q.push(make_pair(ele.first->right,hd+1));
		}
	}
	for(auto it : m)
	{
		for(auto i : it.second)
		{
			cout<<i<<" "; 
		}
		cout<<endl;
	}
}

int main()
{
	Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
    root->right->right->right = newNode(9); 
    cout << "Vertical order traversal is"<<endl;
    printVerticalOrderWithOrderPreserved(root); 
    return 0; 
}
