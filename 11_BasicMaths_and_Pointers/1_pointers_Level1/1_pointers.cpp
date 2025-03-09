// #include <iostream>
// using namespace std;
// int main()
// {
//     int a = 5;
//     int b = 5;
//     cout << a << endl;
//     cout << "Address of a: " << &a << endl;    // & is the 'address of' symbol

//     cout << b << endl;
//     cout << "Address of b: " << &b << endl;
//     return 0;
// }
// ________________________________________________________________________________
// ✨✨✨
// Pointer is not a data type
// It is just a variable that stores the address of another variable.

// #include <iostream>
// using namespace std;
// int main()
// {
//     int a = 5;

//     // Create pointer
//     int* ptr = &a;      // ptr is a pointer to a which contains integer data

//     // access the value ptr is pointing to
//     cout << *ptr << endl;        // to access the value we use the deference operator *

//     // experiment
//     cout << "value of a is: " << a << endl; 
//     cout << "Address of a is: " << &a << endl;
//     cout << "Value stored at ptr is: " << ptr << endl;
//     cout << "Value ptr is pointing to: " << *ptr << endl;
//     cout << "Address of ptr is: " << &ptr << endl;
//     return 0;
// }

// ____________________________________________________________________________________
// ✨✨✨✨
/*
#include <iostream>
using namespace std;

int main()
{
    int a = 5;
    int *p = &a;
    cout << sizeof(p) << endl;

    char ch = 'b';
    char *c = &ch;
    cout << sizeof(c) << endl;

    double dtr = 5.03;
    double *d = &dtr;
    cout << sizeof(d) << endl;

    // All 3 give 8 as sizeof p is the size of the address as pointer is always storing the address, no matter
    // the datatype it points to is an integer, float, char, double etc.....

    
    // The output you are getting is because `sizeof` returns the size in bytes of the object representation of its
    // operand. In many modern systems, pointers are typically represented using 8 bytes (64 bits), regardless of
    // the type of the data they point to. This is why you see `sizeof(p)`, `sizeof(c)`, and `sizeof(d)` all giving
    // the output of 8.
    
    // It's important to note that the size of a pointer is not determined by the type of the object it points to;
    // instead, it's determined by the architecture of the system. On 64-bit systems, pointers are usually 8 bytes,
    // and on 32-bit systems, they are typically 4 bytes.
    
    // So, even though `a` is an `int`, `ch` is a `char`, and `dtr` is a `double`, the size of their respective
    // pointers (`p`, `c`, and `d`) is the same because they are all pointers, and the size of a pointer is
    // determined by the system architecture.
    

    return 0;
}
*/
// ___________________________________________________________________________________

/*
#include <iostream>
using namespace std;

int main()
{
    // BAD PRACTICE - trying to access memory location which is not provided -> segmentation fault(some systems)
    // int* ptr;
    // cout << *ptr << endl;

    // INSTEAD DO:

    // NULL POINTER
    // int* ptr = 0;
    // cout << *ptr << endl;         // OR

    int* ptr = nullptr;  
    cout << *ptr << endl;

    return 0;
}
*/
// ____________________________________________________________________________________

// #include <iostream>
// using namespace std;
// int main()
// {
//     int a = 5;
//     int* ptr = &a;

//     // copying the pointer
//     int* secptr = ptr; 

//     cout << *ptr << endl; 
//     cout << *secptr << endl; 
// }

// ______________________________________________________________________________________

#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    int* p = &a;
    int* q = p;
    int* r = q;

    cout << a << endl;                         // 10
    cout << &a << endl;                        // address of a
    cout << p << endl;                         // address of a
    cout << &p << endl;                        // address of p
    cout << *p << endl;                        // 10
    cout << q << endl;                         // address of a
    cout << &q << endl;                        // address of q
    cout << *q << endl;                        // 10
    cout << r << endl;                         // address of a
    cout << &r << endl;                        // address of r
    cout << *r << endl;                        // 10
    cout << (*p + *q + *r) << endl;            // (10 + 10 + 10) = 30
    cout << (*p)*2 + (*r)*3 << endl;           // (10)*2 + (10)*3 = 20+30=50
    cout << (*p/2) - (*q/2) << endl;           // (10/2) - (10/2) = 0

    return 0;
}