// 🔴🔴🔴🔴 LEETCODE 155 Min. Stack 🔴🔴🔴🔴 
// Refer 21_Stacks -> 3_Stacks_Class3 -> 1_minStack -> 1_minStack.cpp
/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
Implement the MinStack class:
MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

Example 1:
Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2

Constraints:

-2^31 <= val <= 2^31 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 10^4 calls will be made to push, pop, top, and getMin.
*/

// ____________________________________________________________________________________________

#include <iostream>
#include <vector>
using namespace std;

class MinStack {
public:
    vector<pair<int, int> > st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty())   // actual value bhi val hogi aur min value bhi val hogi
        {
            pair<int, int> p = make_pair(val, val);
            st.push_back(p);
        }
        else
        {
            pair<int, int> p;
            p.first = val;
            p.second = min(val, st.back().second);
            st.push_back(p);
        }
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.back().first;    // actual element
    }
    
    int getMin() {
        return st.back().second;   // minimum element in the stack
    }
};

/*
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
*/

int main() {
    // Instantiate MinStack object
    MinStack* obj = new MinStack();

    // Push elements onto the stack
    obj->push(-2);
    obj->push(0);
    obj->push(-3);

    // Retrieve the minimum element in the stack
    cout << "Min element: " << obj->getMin() << endl;

    // Pop the top element
    obj->pop();

    // Retrieve the top element of the stack
    cout << "Top element: " << obj->top() << endl;

    // Retrieve the minimum element in the stack after pop
    cout << "Min element: " << obj->getMin() << endl;

    // Clean up the allocated memory
    delete obj;

    return 0;
}

// Time Complexity:
// Push: O(1)
// Pop: O(1)
// Top: O(1)
// getMin: O(1)
// Space Complexity: O(n)