/*
Say the queue is 10 20 30 40 50 60 70 80
first half: 10 20 30 40
second half: 50 60 70 80
interleaved queue: 10 50 20 60 30 70 40 80
*/
// _________________________________________________________________________________________________

#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int> &q)
{
    // Step A: Separate both halves
    int n = q.size();                                   // say 8 (10 20 30 40 50 60 70 80)
    if(q.empty())
    {
        cout << "The queue is empty!" << endl;
        return;
    }
    queue<int> q2;
    for(int i=0; i<n/2; i++)                            // n = 8; n/2 = 4
    {
        int temp = q.front();
        q.pop();
        q2.push(temp);                            // q2 = 10 20 30 40
    }

    // Step B: Interleaving start kardo - normal case (original queue ki length even hai)
    while(!q.empty() && !q2.empty())
    {
        int first = q2.front();
        q2.pop();

        q.push(first);

        int second = q.front();
        q.pop();

        q.push(second);
    }

    // 50 60 70 80 10             // q2 has 20 30 40 now
    // 60 70 80 10 50
    // 60 70 80 10 50 20          // q2 has 30 40 now
    // 70 80 10 50 20 60
    // 70 80 10 50 20 60 30       // q2 has 40 now
    // 80 10 50 20 60 30 70
    // 80 10 50 20 60 30 70 40    // q2 gets empty here
    // 10 50 20 60 30 70 40 80    // q2 gets empty here

    // Length of original queue is odd -> push the remaining element of q to the last of q
    if(n&1)
    {
        int element = q.front();
        q.pop();
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
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);

    cout << "Normal queue is:" << endl;
    printQueue(q);

    cout << "The interleave queue is:" << endl;
    interleaveQueue(q);
    printQueue(q);

    return 0;
}