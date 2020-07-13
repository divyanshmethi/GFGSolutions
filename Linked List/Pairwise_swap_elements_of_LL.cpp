Node* pairWiseSwap(struct Node* head) {
    int temp;
    Node* copy = head;
    while(head && head->next)
    {
        temp = head->data;
        head->data = head->next->data;
        head->next->data = temp;
        head = head->next->next;
    }
    return copy;
}
