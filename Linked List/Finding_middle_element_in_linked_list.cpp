#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

int getMiddle(Node* head)
{
	if(!head)
	{
		return -1;
	}
	Node* slow = head,fast = head;
	while(slow && fast)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow->data;
}

int main()
{
	int test,n;
	cin>>test;
	for(int o = 0;o<test;o++)
	{
		cin>>n;
		int data;
		cin>>data;
		Node* head = new Node(data);
		Node* tail = head;
		for(int i = 0;i < n - 1;i++)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		cout<<getMiddle(head)<<endl;
	}
}
