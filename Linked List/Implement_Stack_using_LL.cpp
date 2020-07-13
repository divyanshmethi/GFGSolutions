void MyStack ::push(int x) {
    if(top==NULL)
    {
        top = new StackNode(x);
        return;
    }
    StackNode* temp = new StackNode(x);
    temp->next = top;
    top = temp;
    return;
}

/* The method pop which return the element
  poped out of the stack*/
int MyStack ::pop() {
    if(top==NULL)
    {
        return -1;
    }
    int data;
    data = top->data;
    if(top->next==NULL)
    {
        delete(top);
        top = NULL;
    }
    else
    {
        StackNode* temp = top;
        top = top->next;
        delete(temp);
    }
    return data;
}
