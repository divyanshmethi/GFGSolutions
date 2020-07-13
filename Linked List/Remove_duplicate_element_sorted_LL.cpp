#include<iostream>
using namespace std;

Node *removeDuplicates(Node *root)
{
    Node* node;
    Node* temp = root;
    while(root->next)
    {
        if(root->data == root->next->data)
        {
            node = root->next;
            root->next = root->next->next;
            delete(node);
        }
        else
            root = root->next;
    }
    return temp;
}
