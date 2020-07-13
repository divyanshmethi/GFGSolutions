Node* findIntersection(Node* head1, Node* head2)
{
    Node* head = NULL;
    Node* rear = NULL;
    while(head1 && head2)
    {
        if(head1->data==head2->data)
        {
            if(!head)
            {
                head = new Node(head1->data);
                rear = head;
            }
            else
            {
                rear->next = new Node(head1->data);
                rear = rear->next;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        else if(head1->data < head2->data)
        {
            head1 = head1->next;
        }
        else
        {
            head2 = head2->next;
        }
    }
    return head;
    return head;
}
