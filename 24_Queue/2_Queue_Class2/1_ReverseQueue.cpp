/*
// Using Stack
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseQueue(queue<int> &q)
{
    stack<int> st;

    // Step1: Put all elements of queue in the stack
    while(!q.empty())
    {
        int element = q.front();
        q.pop();
        st.push(element);
    }

    // Step2: Put all elements from stack into queue
    while(!st.empty())
    {
        int element = st.top();
        st.pop();
        q.push(element);
    }
}

void printQueue(queue<int> q)
{
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    queue <int> q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);

    cout << "Elements in queue in normal order: " << endl;
    printQueue(q);

    cout << "Elements in queue in reverse order: " << endl;
    reverseQueue(q);
    printQueue(q);

    return 0;
}

TC -> O(n)
SC -> O(n)
*/
// _______________________________________________________________________________________________________

// Using Recursion
#include <iostream>
#include <queue>
using namespace std;

void reverseQueue(queue<int> &q)
{
    // Base Case
    if(q.empty())
    {
        return;
    }

    // Ek case solve karo
    int element = q.front();
    q.pop();

    // Recursion
    reverseQueue(q);

    // Backtracking
    q.push(element);
}

void printQueue(queue<int> q)
{
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    queue <int> q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);

    cout << "Elements in queue in normal order: " << endl;
    printQueue(q);

    cout << "Elements in queue in reverse order: " << endl;
    reverseQueue(q);
    printQueue(q);

    return 0;
}

// TC -> O(n)
// SC -> O(n)