/*
#include <iostream>
using namespace std;

int main()
{
    const int x = 5;  // x is constant // initialization possible, re-assign impossible
    // x = 10; // gives error (assignment of read-only variable)
    cout << x << endl;
    return 0;
}
*/
// ____________________________________________________________________________________________________________

// CONST WITH POINTERS
// #include <iostream>
// using namespace std;

// int main()
// {
//     int *a = new int;
//     *a = 2;
//     cout << *a << endl;    // prints 2
//     delete a;   // a should be deleted here to avoid memory leak
//     int b = 5;
//     a = &b;
//     cout << *a << endl;   // prints 5
//     return 0;
// }

// CONST data, NON-CONST pointer
/*
#include <iostream>
using namespace std;

int main()
{
    const int *a = new int(2); // CONST data, NON-CONST pointer
    int const *a = new int(2); // same as above, if I write const before '*', content will be const
    // *a = 20;                // gives error, can't change the content of the pointer
    cout << *a << endl;
    int b = 20;
    a = &b;     // pointer itself can be reassigned
    cout << *a << endl;
    return 0;
}
*/
// _________________________________________________________________________________________________

// CONST pointer, NON-CONST data
/*
#include <iostream>
using namespace std;

int main()
{
    int *const a = new int(2);
    cout << *a << endl;  // prints 2
    *a = 20;  // chal jayega
    cout << *a << endl; // prints 20
    int b = 50;
    // a = &b;    // nahi chalega kyuki pointer is CONST
    return 0;
}
*/
// _________________________________________________________________________________________________

// CONST pointer, CONST data
/*
#include <iostream>
using namespace std;

int main()
{
    const int *const a = new int(10);
    cout << *a << endl;  // prints 10
    // *a = 50;  // gives error
    // cout << *a << endl;
    int b = 100;
    // a = &b; // gives error
    return 0;
}
*/
// _______________________________________________________________________________________________

// 🔴🔴🔴🔴 CONST FUNCTIONS 🔴🔴🔴🔴🔴
/*
#include <iostream>
using namespace std;

class abc
{
    int x;
    int *y;

public:
    // Constructor
    abc()
    {
        x = 0;
        y = new int(0);
    }

    abc(int _x, int _y)
    {
        x = _x;
        y = new int (_y);
    }

    int getX() const // now it won't modify x value in this function
    {
        return x;
    }
    void setX(int _val)
    {
        x = _val;
    }

    int getY() const
    {
        return *y;
    }
    void setY(int _val)
    {
        *y = _val;
    }
};

void printABC(const abc &a)
{
    cout << a.getX() << " " << a.getY() << endl;
}

int main()
{
    abc a(1, 2);
    printABC(a);
    return 0;
}
*/

// #include <iostream>
// using namespace std;

// class abc
// {
//     int x;
//     int *y;
//     int z;

// public:

//     abc(int _x, int _y, int _z = 0, int _u = 6)  // ye _z aur _u default arguments hai kyuki niche se bas (1,2) ki value aa rhi hai
//     default arguments hamesha right me aati hai -> int _x = 0 nhi likh sakte par int _y = 0 aur int _z = 0 likh sakte hai
//     {
//         x = _x;
//         y = new int (_y);
//         z = _z;
//     }

//     int getX() const // now it won't modify x value in this function
//     {
//       //x = 10;
//         return x;
//     }
//     void setX(int _val)
//     {
//         x = _val;
//     }

//     int getY() const
//     {
//         return *y;
//     }
//     void setY(int _val)
//     {
//         *y = _val;
//     }

//     int getZ() const
//     {
//         return z;
//     }
// };

// void printABC(const abc &a)
// {
//     cout << a.getX() << " " << a.getY() << " " << a.getZ() << endl;
// }

// int main()
// {
//     abc a(1, 2);
//     printABC(a);
//     return 0;
// }

// Making the const mutable
#include <iostream>
using namespace std;

class abc
{
    mutable int x;
    int *y;
    int z;

public:

    abc(int _x, int _y, int _z = 0, int _u = 6)  // ye _z aur _u default arguments hai kyuki niche se bas (1,2) ki value aa rhi hai
    {
        x = _x;
        y = new int (_y);
        z = _z;
    }

    int getX() const // now it won't modify x value in this function
    {
        x = 10;
        return x;
    }
    void setX(int _val)
    {
        x = _val;
    }

    int getY() const
    {
        return *y;
    }
    void setY(int _val)
    {
        *y = _val;
    }

    int getZ() const
    {
        return z;
    }
};

void printABC(const abc &a)
{
    cout << a.getX() << " " << a.getY() << " " << a.getZ() << endl;
}

int main()
{
    abc a(1, 2);
    printABC(a);
    return 0;
}
