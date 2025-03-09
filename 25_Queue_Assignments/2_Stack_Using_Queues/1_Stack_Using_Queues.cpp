// 🔴🔴LEETCODE 225 -> Implement Stack Using Queues🔴🔴
/*
Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions
of a normal stack (push, top, pop, and empty).
Implement the MyStack class:
void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.
Notes:

You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is
empty operations are valid.
Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque
(double-ended queue) as long as you use only a queue's standard operations.
 
Example 1:
Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]
Explanation
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False

Constraints:
1 <= x <= 9
At most 100 calls will be made to push, pop, top, and empty.
All the calls to pop and top are valid.
 
Follow-up: Can you implement the stack using only one queue?
*/

// ____________________________________________________________________________________________________________________
// 🔴🔴METHOD 1 - Using 2 queues🔴🔴
/*
#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:
    queue<int> q1, q2;

    MyStack() {
        
    }

    void push(int x) {
        q2.push(x);
        while(!q1.empty())
        {
            int top = q1.front();
            q2.push(top);
            q1.pop();
        }
        while(!q2.empty())
        {
            int top = q2.front();
            q1.push(top);
            q2.pop();
        }
    }

    int pop() {
        int pop = -1;
        if(!q1.empty())
        {
            pop = q1.front();
            q1.pop();
        }
        return pop;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return (q1.empty() && q2.empty());
    }
};

int main() {
    MyStack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Top of stack: " << stack.top() << endl; // Output: 3

    stack.pop();

    cout << "Top of stack after pop: " << stack.top() << endl; // Output: 2

    cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << endl; // Output: No

    stack.pop();
    stack.pop();

    cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << endl; // Output: Yes

    return 0;
}
*/
// TC -> push: O(n), pop,top,empty: O(1)
// SC -> O(2n) = O(n)

// ____________________________________________________________________________________________________________________

// 🔴🔴METHOD 2 - Using 1 queue🔴🔴

#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for(int i=0; i<q.size()-1; i++)
        {
            int front = q.front();
            q.pop();
            q.push(front);
        }
    }
    
    int pop() {
        int top = q.front();
        q.pop();
        return top;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Top of stack: " << stack.top() << endl; // Output: 3

    stack.pop();

    cout << "Top of stack after pop: " << stack.top() << endl; // Output: 2

    cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << endl; // Output: No

    stack.pop();
    stack.pop();

    cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << endl; // Output: Yes

    return 0;
}

// TC -> push: O(n), pop, top, empty: O(1)
// SC -> O(n)