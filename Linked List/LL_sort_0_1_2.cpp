Node* segregate(Node *head) {
    int count0 = 0,count1 = 0,count2 = 0;
    Node* temp = head;
    while(head)
    {
        if(head->data == 0)
        {
            count0++;
        }
        else if(head->data == 1)
        {
            count1++;
        }
        else if(head->data == 2)
        {
            count2++;
        }
        head = head->next;
    }
    head = temp;
    for(int i = 0;i<count0;i++)
    {
        temp->data = 0;
        temp = temp->next;
    }
    for(int i = 0;i<count1;i++)
    {
        temp->data = 1;
        temp = temp->next;
    }
    for(int i = 0;i<count2;i++)
    {
        temp->data = 2;
        temp = temp->next;
    }
    return head;
}
