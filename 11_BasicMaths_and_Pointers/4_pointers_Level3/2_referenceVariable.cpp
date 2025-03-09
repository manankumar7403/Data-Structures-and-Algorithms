// As pointers, may be confusing, we have another method for providing the same functionality of pointers
// => REFERENCE VARIABLES

// say int a = 5;
// we can have another variable b that is present in the same Symbol Table of a and when we call b (which is
// pointing to the value of a, we will get the same functionality of pointers.)

// 🔴🔴🔴🔴 REFERENCE VARIABLES 🔴🔴🔴🔴

// int a = 5;
// int& b = a;  => Syntax of REFERENCE VARIABLE

/*
#include <iostream>
using namespace std;
int main()
{
    int a = 5;
    
    // Creating a reference variable  (same memory location but different name)
    int& b = a;

    cout << a << endl;  // prints 5
    cout << b << endl;  // prints 5

    a++;
    cout << a << endl;  // prints 6
    cout << b << endl;  // prints 6

    b++;
    cout << a << endl;  // prints 7
    cout << b << endl;  // prints 7

    return 0;
}
*/

/*
1) We can't set reference variable to null but pointer could be set to null so reference variables are more safe.
2) Pointers are difficult to understand while reference variabels are readable and more easy to understand.
3) Generally, reference variables are used for pass by reference.
*/
// __________________________________________________________________________________________

// #include <iostream>
// using namespace std;

// void solve(int num)   // pass by value
// {
//     num++;
// }

// int main()
// {
//     int a = 5;
//     solve(a);
//     cout << a << endl;
//     return 0;
// }
// pass by value, value of a remains 5 only.


// #include <iostream>
// using namespace std;

// void solve(int& num)    // pass by reference
// {
//     num++;
// }

// int main()
// {
//     int a = 5;
//     solve(a);
//     cout << a << endl;   // prints 6
//     return 0;
// }
// ________________________________________________________________________________________

/*
#include <iostream>
using namespace std;

void solve(int* num)
{
    *num = *num + 1;
}

int main()
{
    int a = 12;
    solve(&a);              // Pass by reference for pointers 
    cout << a << endl;
    return 0;
}
*/
// _______________________________________________________________________________________________

#include <iostream>
using namespace std;

void solve(int*& p)   // passing by reference of p
{
    p = p + 1;       // changing the address of p
}

int main()
{
    int a = 5;
    int* p = &a;

    cout << "before" << endl;
    cout << p << endl;            // initial address of p, say 104
    cout << *p << endl;           // 5

    solve(p);
    cout << "after" << endl;
    cout << p << endl;          // updated address of p, 104+1 = 108
    cout << *p << endl;        // garbage value

    return 0;
}