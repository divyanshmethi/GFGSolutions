Node* deleteAllOccurances(Node *head,int x)
{
    Node* temp;
    Node* cp = head;
    Node* prev = head;
    while(cp->data==x)
    {
        temp = cp;
        cp = cp->next;
        delete(temp);
    }
    head = head->next;
    while(head)
    {
        if(head->data == x)
        {
            prev->next = head->next;
            temp = head;
            head = head->next;
            delete(temp);
        }
        else
        {
            prev = head;
            head = head->next;
        }
    }
    return cp;
}
