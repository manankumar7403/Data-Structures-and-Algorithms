/*
1. Debug the code. Queue Using 2 Stacks.

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        while (!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int t= s2.top();
        while (!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return t;
    }
    
    int peek() {
        while (!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int t= s2.top();
				s2.pop();
        while (!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return t;
    }
    
    bool empty() {
        return s1.empty();
    }
};
*/

// _______________________________________________________________________________________________________
// 🔴🔴SOLUTION🔴🔴

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
