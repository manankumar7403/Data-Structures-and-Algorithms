// Q2. Debug the code. Why is the code crashing when trying to dereference a pointer?
// int main() {
//     int* p = NULL;
//     *p = 42;
//     return 0;
// }

// ___________________________________________________________________________________

// The code is crashing because it's attempting to dereference a null pointer (int* p = NULL;) and assign a
// value (*p = 42;). Dereferencing a null pointer leads to undefined behavior, and in this case, it results in a
// crash.

// To fix the code, allocate memory for the pointer before dereferencing it. Here's an example:

#include <iostream>
using namespace std;
int main() {
    int* p = new int; // Allocate memory for an integer
    *p = 42;          // Assign a value to the allocated memory
    cout << p << endl;
    delete p;         // Release the allocated memory
    cout << p << endl;
    return 0;
}

// In this corrected code, new int is used to allocate memory for an integer, and then *p is used to assign a
// value to the memory location pointed to by p. Finally, delete p is used to release the allocated memory.

// Note: Using new to allocate memory dynamically is just one way to solve the issue.
// Depending on the context of your program, you might use other memory allocation techniques or
// even avoid dynamic memory allocation altogether.
