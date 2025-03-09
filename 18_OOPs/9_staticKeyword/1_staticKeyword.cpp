/*
#include <iostream>
using namespace std;

class abc
{
public:
    int x, y;

    void print () const
    {
        // cout << x << " " << y << endl;  // hidden parameter passes 'this' which specifies that a is of this instance or b is of this instance
        cout << this->x << " " << this->y << endl;  // hidden parameter passes 'this' which specifies that a is of this instance or b is of this instance
    }
};

int main()
{
    abc obj1 = {1, 2};
    abc obj2 = {4, 5};
    obj1.print();
    obj2.print();
    return 0;
}
*/
// ____________________________________________________________________________________________________

// #include <iostream>
// using namespace std;

// class abc
// {
// public:
//     static int x, y;

//     void print () const
//     {
        
//         cout << x << " " << y << endl;
//     }
// };

// // static data members are declared like:
// // x aur y class (abc) ka hi variable hai unke instance (obj1 aur obj2) ke variable nahi hai
// // so int main function me hum obj1.x ko abc::x bhi likh sakte hai
// int abc::x;
// int abc::y;

// int main()
// {
//     abc obj1;
//     obj1.x = 1;
//     obj1.y = 2;
//     obj1.print();
//     abc obj2;
//     obj2.x = 10;
//     obj2.y = 20;
//     obj2.print();
//     return 0;
// }
// ___________________________________________________________________________________________________

// #include <iostream>
// using namespace std;

// class abc
// {
// public:
//     static int x, y;

//     static void print() // isko bhi static bana diya, ab ye bhi instance ka function nhi hai abc class ka hai
//     {
//         // no 'this' pointer accessible
//         // can't get this->x or this->y
//         cout << x << " " << y << endl;
//     }
// };

// int abc::x;
// int abc::y;

// int main()
// {
//     // abc obj1;
//     abc::x = 1;
//     abc::y = 2;
//     abc::print();
//     // abc obj2;
//     abc::x = 10;
//     abc::y = 20;
//     abc::print();
//     return 0;
// }
// _____________________________________________________________________________________________________

#include <iostream>
using namespace std;

class abc
{
public:
    int x, y;
    abc() : x(0), y(0) {}

    static void print()
    {
        
        // cout << x << " " << y << endl;
        // x aur y non-static hai toh ye kisi particular instance se relate kar rha hoga(kisi obj ka hoga)
        // par function static bana diya hai toh iske andar x aur y access karne par error dega
        // kuch aur kaam kara lo
        printf("I am in Static %s\n", __FUNCTION__);  // __FUNCTION__ MACROS hai function ka name print kar dega
    }
};

int main()
{
    abc obj1;
    abc::print();
    abc obj2;
    abc::print();
    abc::print();
    return 0;
}