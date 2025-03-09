//🔴🔴We can create Stacks without using the in-built STL lib. But, first implement using the STL lib. 🔴🔴
// Bases on LIFO (Last-In-First-Out) approach
/*
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    // Creation of stack
    stack<int> st;

    // Insertion
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    // remove
    st.pop();    // removes the element on top -> last inserted element

    // Check the element on the top
    cout << "Element on the top is: " << st.top() << endl;

    // Size of the stack is
    cout << "Size of the stack is: " << st.size() << endl;

    // Check if the stack is empty
    if(st.empty())
    {
        cout << "The stack is empty." << endl;
    }
    else
    {
        cout << "The stack is not empty." << endl;
    }

    return 0;
}
*/
// ________________________________________________________________________________________________________

// Index based accessing doesn't exist in stack, we can only access the top element.
// Here, is how you print the stack
/*
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
*/
// Answer: 40 30 20 10 -> answer hamesha reverse order me milega
// ________________________________________________________________________________________________________

/*
⭐⭐ To create own custom stack, we can create a class 'Stack' with properties and behaviour.
We can use array (normal or vector) or even a Linked List to create an Stack without in-built STL.
1) Properties -> int top, int* arr, int size etc.
2) Behaviour -> push, pop, top, size, empty, etc.
*/

// We would be using stack as we vectors are also a part of STL, which we tend to avoid.

#include <iostream>
using namespace std;

class Stack
{
    private:
        int* arr;
        int top;        // index of top element
        int size;       // size of the stack arr

    public:
        // Constructor
        Stack(int size)
        {
            arr = new int[size];
            this->size = size;
            top = -1;
        }


        // Functions

        void push(int data)
        {
            if(size - top > 1) // means that space is available, we will insert
            {
                top++;
                arr[top] = data;
            }
            else              // means that space is not available
            {
                // Space not available
                cout << "Stack overflow!" << endl;
            }
        }

        void pop()
        {
            if(top == -1)
            {
                // Means that stack is empty
                cout << "Stack underflow, can't delete element!" << endl;
            }
            else
            {
                // stack is not empty, we will decrement the top (not actually removing the top element but
                // assigning it to the prev element)
                top--;
            }
        }

        int getTop()
        {
            if(top == -1)
            {
                cout << "There is no element in stack, top not available." << endl;
            }
            else
            {
                // simply return the element top is pointing to
                return arr[top];
            }
            return 0;
        }

        // not the total size of the stack array but the number of valid elements in the stack.
        int getSize()
        {
            return top + 1;
        }

        bool isEmpty()
        {
            if(top == -1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};

int main()
{
    // Creation
    Stack s(10);

    // insertion
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    
    while(!s.isEmpty())
    {
        // Top element
        cout << s.getTop() << " ";
        // Deletion
        s.pop();
    }

    cout << endl;

    // Size
    cout << "Size of stack: " << s.getSize() << endl;

    return 0;
}
