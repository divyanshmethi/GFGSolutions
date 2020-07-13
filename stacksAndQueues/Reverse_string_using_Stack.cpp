#include<iostream>
using namespace std;

void reverse(char *str, int len)
{
    stack<char> st;
    for(int i = 0;i<len;i++)
    {
        st.push(str[i]);
    }
    int i = 0;
    while(!st.empty())
    {
        str[i] = st.top();
        st.pop();
        i++;
    }
}
