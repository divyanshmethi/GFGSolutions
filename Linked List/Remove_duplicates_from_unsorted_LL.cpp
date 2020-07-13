#include<iostream>
using namespace std;

Node * removeDuplicates( Node *head) 
{
    set<int> s;
    Node* temp = head;
    s.insert(head->data);
    temp = temp->next;
    Node* prev = head;
    Node* t;
    while(temp)
    {
        if(s.find(temp->data) != s.end())
        {
            t = temp;
            prev->next = temp->next;
            delete(t);
        }
        else{
            s.insert(temp->data);
            prev = temp;
        }
        temp = temp->next;
    }
    return head;
}
