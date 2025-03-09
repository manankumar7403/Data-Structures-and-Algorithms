#include <iostream>
using namespace std;
void printName()
{
    int n;
    cout<<"Enter the value of n: "<<endl;
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cout<<"Manan Kumar"<<endl;
    }
}

int main()
{
    // function call
    printName();
    return 0;
}

// In C++, the `return` statement is used to indicate the result or status of a function.
// The choice between `return 0`, `return 1`, and `return -1` (or any other integer value)
// depends on the specific requirements and conventions of the function and program you're
// writing. Here's what each of these values typically means:

// 1. `return 0`:
//    - This is often used to indicate a successful execution of a program or a function.
//    In many C and C++ programs, a return value of 0 from the `main` function typically
//    means that the program ran without any errors.

// 2. `return 1`:
//    - A return value of 1 is often used to indicate that the program or function encountered
//    some kind of error or unexpected situation. This value suggests that something went wrong
//    during the execution.

// 3. `return -1`:
//    - A return value of -1 can also be used to indicate an error or failure, similar to
//    `return 1`. It's often used when you want to distinguish different types of errors or
//    have negative values represent specific error conditions.

// The specific meaning of these return values can be further customized based on the context
// of your program. You can use other integer values as well, but it's important to establish
// clear conventions within your code and documentation so that other programmers (including
// yourself in the future) can understand the meaning of these return values.
