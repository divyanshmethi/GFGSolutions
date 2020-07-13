#include<iostream>
using namespace std;

void deleteNode(Node *node)
{
    Node* temp;
    temp = node->next;
    node->data = node->next->data;
    node->next = node->next->next;
    delete(temp);
}
