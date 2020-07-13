#include<iostream>
using namespace std;

bool detectLoop(Node* head)
{
    if(!head)
    {
        return false;
    }
    Node* slow = head;
    Node* fast = head->next;
    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast)
        {
            return true;
        }
    }
    return false;
}
