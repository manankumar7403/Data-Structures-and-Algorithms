/*
class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {
        
    }
    
    void push(int x) {
        while(!q1.empty()){
            q1.pop();
            q2.push(q1.front());
        }

        q1.push(x);

        while(!q2.empty()){
            q2.pop();
            q1.push(q2.front());
        }

    }
    
    int pop() {
        int ans = q1.front();
        q1.pop();
        return ans;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};
*/
// ____________________________________________________________________________________________________________________
// 🔴🔴SOLUTION🔴🔴

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

// TC -> push: O(n), pop,top,empty: O(1)
// SC -> O(2n) = O(n)