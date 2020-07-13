#include<iostream>
using namespace std;

queue<ll> modifyQueue(queue<ll> q, int k)
{
    stack<ll> s;
    while(!q.empty() && k)
    {
        s.push(q.front());
        q.pop();
        k--;
    }
    queue<ll> qe;
    while(!q.empty())
    {
        qe.push(q.front());
        q.pop();
    }
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    while(!qe.empty())
    {
        q.push(qe.front());
        qe.pop();
    }
    return q;
}
