#include<iostream>
using namespace std;

bool isPalindromeUtil(struct Node** left, struct Node* right) 
{
    if (right == NULL) 
        return true;
    bool isp = isPalindromeUtil(left, right->next); 
    if (isp == false) 
        return false;
    bool isp1 = (right->data == (*left)->data); 
    *left = (*left)->next; 
    return isp1; 
} 

bool isPalindrome(Node *head)
{
    if(!head)
    {
        return false;
    }
    return isPalindromeUtil(&head,head);
}
