Node* findIntersection(Node* head1, Node* head2)
{
    set<int> s;
    while(head2)
    {
        s.insert(head2->data);
        head2 = head2->next;
    }
    Node* head = NULL;
    Node* rear = NULL;
    while(head1)
    {
        if(s.find(head1->data) != s.end())
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
        }
        head1 = head1->next;
    }
    return head;
}
