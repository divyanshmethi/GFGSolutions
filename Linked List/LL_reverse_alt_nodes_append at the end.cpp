void rearrange(struct Node *head)
{
    Node* temp = head;
    Node* toDelete;
    Node* lastNode = head;
    Node* prev;
    int count = 0;
    while(lastNode)
    {
        count++;
        lastNode = lastNode->next;
    }
    int size = count/2;
    int A[size];
    count = 0;
    while(temp && temp->next)
    {
        if(count < size)
        {
            A[count] = temp->next->data;
            count++;
        }
        toDelete = temp->next;
        temp->next = temp->next->next;
        prev = temp;
        temp = temp->next;
        delete(toDelete);
    }
    if(!temp)
        temp = prev;
    for(int i = count - 1;i>=0;i--)
    {
        temp->next = new Node(A[i]);
        temp = temp->next;
    }
}

