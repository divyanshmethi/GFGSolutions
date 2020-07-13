struct Node* reverseList(struct Node *head)
{
    if(!head || !head->next)
    {
        return head;
    }
    Node* curr = head,* prev = NULL,* next = head->next;
    while(next)
    {
        curr->next = prev;
        prev = curr;
        curr = next;
        next = next->next;
    }
    curr->next = prev;
    return curr;
}

