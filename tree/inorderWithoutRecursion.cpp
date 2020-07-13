#include<bits/stdc++.h> 
using namespace std; 
  
struct Node 
{ 
    int data; 
    struct Node* left; 
    struct Node* right; 
    Node (int data) 
    { 
        this->data = data; 
        left = right = NULL; 
    }
};

void inOrder(Node* root)
{
	//First thought that comes to my mind is that I need a stack definetely
	stack<Node*> st;
	//In Recursive approach, we initialize the current node = root, which is the first node in our recursion
	//Thus, we initialize current node to root
	Node* curr = root;
	while(curr || st.empty()==false)
	{
		//We keep on visiting left node, till there is a left node
		while(curr)
		{
			st.push(curr);
			curr = curr->left;
		}
		//In recursive approach, once, node == NULL, recursion returns and we print the value of the last node, which is top of the stack
		//Same here, we take the top element, print it and pop it from the stack
		curr = st.top();
		st.pop();
		cout<<curr->data<<" ";
		//Then, we move to recursion on the right side of the node
		curr = curr->right;
	}
}

int main()
{
	struct Node *root = new Node(1); 
    root->left        = new Node(2); 
    root->right       = new Node(3); 
    root->left->left  = new Node(4); 
    root->left->right = new Node(5); 
  
    inOrder(root); 
    return 0;
}
