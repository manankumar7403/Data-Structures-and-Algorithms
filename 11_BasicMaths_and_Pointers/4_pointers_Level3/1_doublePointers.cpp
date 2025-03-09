/*
#include <iostream>
using namespace std;
int main()
{
    int a = 5;
    int* p = &a;
    int** q = &p;

    cout << &a << endl;     // address of a
    cout << a << endl;      // 5
    cout << p << endl;      // address of a
    cout << &p << endl;     // address of p
    cout << *p << endl;     // 5
    cout << q << endl;      // address of p
    cout << &q << endl;     // address of q
    cout << *q << endl;     // address of a
    cout << **q << endl;    // 5

    return 0;
}
*/
// ______________________________________________________________________________

/*
#include <iostream>
using namespace std;

void util(int* p)
{
    p = p + 1;
}

int main()
{
    int a = 5;
    int* p = &a;

    cout << "before" << endl;
    cout << a << endl;
    cout << p << endl;
    cout << *p << endl;

    util(p);

    cout << "after" << endl;
    cout << a << endl;
    cout << p << endl;
    cout << *p << endl;

    return 0;
}
*/
// Before = After as we are passing by value(p=p+1) not by reference(*p=*p+1) in the util function.
// So a copy of p is created in util function but that does not affect the main function.
// So values of "Before" and "After" remain same.
// _________________________________________________________________________________________________

/*
#include <iostream>
using namespace std;

void util(int* p)
{
    *p = *p + 1;
}

int main()
{
    int a = 5;
    int* p = &a;

    cout << "before" << endl;
    cout << a << endl;
    cout << p << endl;
    cout << *p << endl;

    util(p);

    cout << "after" << endl;
    cout << a << endl;
    cout << p << endl;
    cout << *p << endl;

    return 0;
}
*/
// This is pass by reference in the util function (*p = *p+1)
// ___________________________________________________________________________________________________

/*
#include <iostream>
using namespace std;

void solve(int** ptr)
{
    // ptr = ptr + 1;   // won't change the value of x
    // *ptr = *ptr + 1; // won't change the value of x
    **ptr =  **ptr + 1;  // x = x+1 => x = 12+1 = 13
}

int main()
{
    int x = 12;
    int* p = &x;
    int** q = &p;
    solve(q);
    cout << x << endl; 
    return 0;
}
*/
// ____________________________________________________________________________________________________

