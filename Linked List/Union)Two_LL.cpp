struct Node* makeUnion(struct Node* head1, struct Node* head2)
{
    Node* head = NULL;
    Node* rear = NULL;
    set<int> s;
    while(head1)
    {
        s.insert(head1->data);
        head1 = head1->next;
    }
    while(head2)
    {
        s.insert(head2->data);
        head2 = head2->next;
    }
    for(auto it : s)
    {
        if(!head)
        {
            head = new Node(it);
            rear = head;
        }
        else
        {
            rear->next = new Node(it);
            rear = rear->next;
        }
    }
    return head;
}
