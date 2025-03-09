// Queue is 3 6 9 12 15
// k = 3
// k-reversed Queue is 9 6 3 12 15

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseK(queue<int> &q, int k)
{
    // Validity of k
    int n = q.size();
    if(k <= 0 || k > n)
    {
        return;
    }

    stack<int> st;

    // Step1: Put all k-elements in the stack
    for(int i=0; i<k; i++)
    {
        int element = q.front();
        q.pop();
        st.push(element);
    }
    // Stack is like 9
                 //  6
                 //  3

    // Step2: Put all elements from stack into queue
    while(!st.empty())
    {
        int element = st.top();
        st.pop();
        q.push(element);
    }
    // Now, queue is 12 15 9 6 3

    // Push the remaining n-k elements in the queue in same order
    for(int i=0; i<n-k; i++)
    {
        int element = q.front();
        q.pop();
        q.push(element);
    }
    // Now, queue is 9 6 3 12 15
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
    q.push(12);
    q.push(15);

    cout << "Enter the value of k:" << endl;
    int k;
    cin >> k;

    cout << "Elements in queue in normal order: " << endl;
    printQueue(q);

    cout << "Elements in queue in k-reversed order: " << endl;
    reverseK(q, k);
    printQueue(q);

    return 0;
}