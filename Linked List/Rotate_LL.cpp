Node* rotate(Node* head, int k)
{
    Node* temp = head;
    while(temp->next)
    {
        temp = temp->next;
    }
    temp->next = head;
    temp = head;
    for(int i = 0;i < k - 1;i++)
    {
        temp = temp->next;
    }
    Node* temp1 = temp->next;
    temp->next = NULL;
    return temp1;
}
