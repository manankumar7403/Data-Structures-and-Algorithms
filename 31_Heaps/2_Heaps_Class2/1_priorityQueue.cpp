// ⭐⭐⭐⭐ Refer: https://en.cppreference.com/w/cpp/container/priority_queue ⭐⭐⭐⭐

/*
A priority queue is a data structure that stores elements with associated priorities and allows for efficient
retrieval of the element with the highest (or lowest) priority. A heap is a popular implementation of a priority
queue.

In a heap-based priority queue, the elements are stored in a binary heap data structure. A binary heap is a
complete binary tree where the key of each node is either greater than or equal to (max heap) or less than or equal
to (min heap) the keys of its children. In the context of a priority queue, a max heap is often used to implement
a max-priority queue, where the element with the highest priority is at the root of the heap, and a min heap is
used for a min-priority queue, where the element with the lowest priority is at the root.

The key operations on a priority queue implemented with a heap include:
1. **Insertion:** Adding a new element to the priority queue while maintaining the heap property.
2. **Deletion:** Removing the element with the highest (max heap) or lowest (min heap) priority from the
priority queue.
3. **Peek/Top:** Retrieving the element with the highest (max heap) or lowest (min heap) priority without removing it.
4. **Update Priority:** Modifying the priority of an existing element in the priority queue and adjusting the
heap to maintain the heap property.

Heap-based priority queues have efficient time complexities for these operations. The insertion and deletion
operations typically have O(log n) time complexity, where n is the number of elements in the priority queue.
This efficiency makes heaps suitable for scenarios where quick access to the highest (or lowest) priority element
is crucial, such as in scheduling algorithms or graph algorithms like Dijkstra's algorithm.
*/

// _______________________________________________________________________________________________

// PRIORITY QUEUE - MAX HEAP
/*
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> pq; // By default behaves like MAX HEAP, this is the STL way to create it

    // Testing the MAX HEAP property of priority_queue
    pq.push(3);
    pq.push(6);
    pq.push(9);
    pq.push(4);
    pq.push(8);

    cout << "Printing the top element:" << endl;
    cout << pq.top() << endl;
    pq.pop();
    cout << "Printing the top element:" << endl;
    cout << pq.top() << endl;
    pq.pop();
    cout << "Printing the top element:" << endl;
    cout << pq.top() << endl;
    pq.pop();
    cout << "Printing the top element:" << endl;
    cout << pq.top() << endl;
    pq.pop();
    cout << "Printing the top element:" << endl;
    cout << pq.top() << endl;
    pq.pop();

    cout << "Printing the size:" << endl;
    cout << pq.size() << endl;

    if(pq.empty())
    {
        cout << "MAX HEAP is empty!" << endl;
    }
    else
    {
        cout << "MAX HEAP is not empty!" << endl;
    }

    return 0;
}
*/

// __________________________________________________________________________________________________________________

// PRIORITY QUEUE - MIN HEAP
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    
    priority_queue<int, vector<int>, greater<int> > pq; // STL way of creating MIN HEAP
    // priority_queue<int> -> int type ka data store karega priority queue
    // vector<int> -> container darsha raha hai ki store kaise karna hai
    // greater<int> -> comparator wali property darsha raha hai -> MIN HEAP banane ke liye
    
    // Testing the MIN HEAP property of priority_queue
    pq.push(3);
    pq.push(6);
    pq.push(9);
    pq.push(4);
    pq.push(8);

    cout << "Printing the top element:" << endl;
    cout << pq.top() << endl;

    pq.pop();

    cout << "Size of MIN HEAP:" << endl;
    cout << pq.size() << endl;

    cout << "Printing the top element:" << endl;
    cout << pq.top() << endl;

    pq.pop();

    cout << "Printing the top element:" << endl;
    cout << pq.top() << endl;

    pq.pop();

    cout << "Printing the top element:" << endl;
    cout << pq.top() << endl;

    pq.pop();

    cout << "Printing the top element:" << endl;
    cout << pq.top() << endl;

    pq.pop();

    if(pq.empty())
    {
        cout << "MIN HEAP is empty!" << endl;
    }
    else
    {
        cout << "MIN HEAP is not empty!" << endl;
    }

    return 0;
}