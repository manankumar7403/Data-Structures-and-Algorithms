// Doubly ended queue is also known as deque.
// Don't get confused in enqueuing dequeuing (insert delete) and deque(doubly-ended queue)

#include <iostream>
#include <deque>
using namespace std;

int main()
{
    // Creation
    deque<int> dq;

    dq.push_front(5);
    dq.push_front(10);

    dq.push_back(20);
    dq.push_back(30);

    cout << "Size of the Doubly-Ended Queue: " << dq.size() << endl;

    for (auto element : dq)
    {
        cout << element << " ";
    }
    cout << endl;

    dq.pop_front();

    cout << "Size of the Doubly-Ended Queue: " << dq.size() << endl;

    for (auto element : dq)
    {
        cout << element << " ";
    }
    cout << endl;

    dq.pop_back();

    cout << "Size of the Doubly-Ended Queue: " << dq.size() << endl;

    for (auto element : dq)
    {
        cout << element << " ";
    }
    cout << endl;

    cout << "Front: " << dq.front() << endl;
    cout << "Rear: " << dq.back() << endl;

    if(dq.empty())
    {
        cout << "Deque is empty!" << endl;
    }
    else
    {
        cout << "Deque is not empty!" << endl;
    }

    return 0;
}
// ______________________________________________________________________________________________________________

// Another way to print
/*

#include <iostream>
#include <deque>
using namespace std;

int main()
{
    // Creation
    deque<int> dq;

    dq.push_front(5);
    dq.push_front(10);

    dq.push_back(20);
    dq.push_back(30);

    cout << "Size of the Doubly-Ended Queue: " << dq.size() << endl;
    for(auto it = dq.begin(); it != dq.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    dq.pop_front();
    
    cout << "Size of the Doubly-Ended Queue: " << dq.size() << endl;
    for(auto it = dq.begin(); it != dq.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    dq.pop_back();

    cout << "Size of the Doubly-Ended Queue: " << dq.size() << endl;
    for(auto it = dq.begin(); it != dq.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}


*/