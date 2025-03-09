#include <iostream>
using namespace std;

class Stack
{
    private:
        int* arr;
        int top1;        // index of top element of 1st stack
        int top2;        // index of top element of 2nd stack
        int size;       // size of the stack arr available for stack1 and stack2 combined

    public:
        // Constructor
        Stack(int size)
        {
            arr = new int[size];
            this->size = size;
            top1 = -1;
            top2 = size;
        
            // 🔴🔴 Initializing stack to 0 -> just for visualizing -> waise kabhi nahi karna
            for(int i=0; i<size; i++)
            {
                arr[i] = 0;
            }
        } 

        // Functions
        void push1(int data)
        {
            if(top2 - top1 == 1)
            {
                // Space not available
                cout << "OVERFLOW in Stack 1!" << endl;
            }
            else
            {
                // Space available
                top1++;
                arr[top1] = data;
            }
        }

        void pop1()
        {
            if(top1 == -1)
            {
                // Stack 1 is empty
                cout << "UNDERFLOW in Stack 1!" << endl; 
            }
            else
            {
                // Stack 1 not empty
                arr[top1] = 0;   // 🔴🔴 just for visualizing
                top1--;
            }
        }

        void push2(int data)
        {
            if(top2 - top1 == 1)
            {
                // Space not available
                cout << "OVERFLOW in Stack 2!" << endl;
            }
            else
            {
                // Space available
                top2--;
                arr[top2] = data;
            }
        }

        void pop2()
        {
            if(top2 == size)
            {
                // Stack 2 is empty
                cout << "UNDERFLOW in Stack 2!" << endl; 
            }
            else
            {
                // Stack 2 not empty
                arr[top2] = 0;   // 🔴🔴  just for visualizing
                top2++;
            }
        }


        // 🔴🔴 Bas visualizing ke liye print function daala hai -> ye waise kabhi nahi banana
        void print()
        {
            cout << endl;
            cout << "top1: " << top1 << endl;
            cout << "top2: " << top2 << endl;
            for(int i=0; i<size; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main()
{
    Stack s(10);

    s.push1(10);
    s.print();
    s.push1(20);
    s.print();
    s.push1(30);
    s.print();
    s.push1(40);
    s.print();
    s.push1(50);
    s.print();
    
    s.push2(100);
    s.print();
    s.push2(110);
    s.print();
    s.push2(120);
    s.print();
    s.push2(130);
    s.print();
    s.push2(140);
    s.print();

    s.pop1();
    s.print();
    s.pop1();
    s.print();
    s.pop1();
    s.print();
    s.pop1();
    s.print();
    s.pop1();
    s.print();
    
    s.push2(1000);
    s.print();

    return 0;
}