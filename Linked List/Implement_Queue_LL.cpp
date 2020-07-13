#include<iostream>
using namespace std;

int MyQueue :: pop()
{
    if(front==NULL && rear==NULL)
    {
        return -1;
    }
    int data;
    if(front==rear)
    {
        data = front->data;
        delete(front);
        front = rear = NULL;
    }
    else
    {
        data = front->data;
        QueueNode* temp = front;
        front = front->next;
        delete(temp);
    }
        return data;
}
