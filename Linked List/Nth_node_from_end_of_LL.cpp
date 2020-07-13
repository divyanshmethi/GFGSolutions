#include<iostream>
using namespace std;

int getNthFromLast(Node *head, int n)
{
    if(!head)
    {
        return -1;
    }
    Node* temp = head, *temp1 = head;
    int count = 0;
    for(int i = 0;i<n && temp;i++)
    {
        count++;
        temp = temp->next;
    }
    if(temp==NULL && count < n)
    {
        return -1;
    }
    while(temp)
    {
        temp = temp->next;
        temp1 = temp1->next;
    }
    return temp1->data;
}
