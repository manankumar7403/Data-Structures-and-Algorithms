/*
3. Debug the code. Idea is to use stack involved in recursion to reverse the queue.

void reverseQueue(queue<int> &q) {
    q.pop();
    reverseQueue(q);
    q.push(q.front());
}
*/

// __________________________________________________________________________________________________________________
// 🔴🔴SOLUTION🔴🔴

#include<iostream>
#include<queue>
using namespace std;

void reverseQueue(queue<int>& q)
{
    if(q.empty())
    {
        return;
    }
    int x = q.front();
    q.pop();
    reverseQueue(q);
    q.push(x);
}

int main()
{
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    reverseQueue(q);
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}