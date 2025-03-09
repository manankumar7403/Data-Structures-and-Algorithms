// 🔴🔴LEETCODE 232 -> Implement Queue Using Stacks🔴🔴
/*
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions
of a normal queue (push, peek, pop, and empty).
Implement the MyQueue class:
void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty
operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque
(double-ended queue) as long as you use only a stack's standard operations.
 
Example 1:
Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]
Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false

Constraints:
1 <= x <= 9
At most 100 calls will be made to push, pop, peek, and empty.
All the calls to pop and peek are valid.
 
Follow-up: Can you implement the queue such that each operation is amortized O(1) time complexity? In other words,
performing n operations will take overall O(n) time even if one of those operations may take longer.
*/

// _____________________________________________________________________________________________________________
// 🔴🔴METHOD 1🔴🔴
/*
#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    stack<int> s1, s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s1.empty())
        {
            int topS1 = s1.top();
            s2.push(topS1);
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty())
        {
            int topS2 = s2.top();
            s1.push(topS2);
            s2.pop();
        }
    }
    
    int pop() {
        int popEle = -1;
        if(!s1.empty())
        {
            popEle = s1.top();
            s1.pop();
        }
        return popEle;
    }
    
    int peek() {
        if(!s1.empty())
        {
            return s1.top();
        }
        return -1;
    }
    
    bool empty() {
        return (s1.empty() && s2.empty());
    }
};

int main() {
    MyQueue q;
    
    // Push elements into the queue
    q.push(1);
    q.push(2);
    q.push(3);
    
    // Display queue using pop and peek
    cout << "Front element: " << q.peek() << endl; // Should print 1
    
    cout << "Dequeuing..." << endl;
    while (!q.empty()) {
        cout << q.pop() << " ";
    }
    cout << endl;
    
    // Check if queue is empty
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;
    
    return 0;
}

// TC -> Push: O(n), Peek, Pop, Empty: O(1)
// SC -> O(2n) = O(n)

*/

// _____________________________________________________________________________________________________________
// 🔴🔴METHOD 2🔴🔴

#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    stack<int>s1, s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s1.empty() && s2.empty()) return -1;

        int pop = -1;
        if(!s2.empty())
        {
            pop = s2.top();
        }
        else
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            pop = s2.top();
        }
        s2.pop();
        return pop;
    }
    
    int peek() {
        int front = -1;
        if(!s2.empty())
        {
            front = s2.top();
        }
        else
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            front = s2.top();
        }
        return front;
    }
    
    bool empty() {
        return (s1.empty() && s2.empty());
    }
};

int main() {
    MyQueue q;
    
    // Push elements into the queue
    q.push(1);
    q.push(2);
    q.push(3);
    
    // Display queue using pop and peek
    cout << "Front element: " << q.peek() << endl; // Should print 1
    
    cout << "Dequeuing..." << endl;
    while (!q.empty()) {
        cout << q.pop() << " ";
    }
    cout << endl;
    
    // Check if queue is empty
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;
    
    return 0;
}

// TC -> push, empty: O(1), pop and peek/front: O(n)
// SC -> O(2n) = O(n)

