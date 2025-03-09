// Q4. Debug the code.
// int main() {
//     int* p;
//     *p = 10;
//     return 0;
// }
// ________________________________________________________________

// By typing int *p = 10; you say to compiler:
// Lets have a pointer on integer, called "p". Set p to 10 => p points on address 10 on memory.
// By typing cout << *p << endl; you say to compiler:
// Show me -as a integer- what is at the address 10 on memory.

// The code
// int *p = 10;

// Is equivalent to:
// int *p;
// p = 10; 

// Is not equivalent to:
// int *p;
// *p = 10; 

// Corrected code:

#include <iostream>
using namespace std;

int main() {
    int i;
    int* p = &i;
    *p = 10;
    cout << *p << endl;   // prints 10
    return 0;
}