// ⭐⭐⭐⭐ Constructor can never be virtual.
/*
#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base ctor\n";
    }

    ~Base()
    {
        cout << "Base dtor\n";
    }
};

class Derived: public Base
{
public:
    Derived()
    {
        cout << "Derived ctor\n";
    }

    ~Derived()
    {
        cout << "Derived dtor\n";
    }
};

int main()
{
    Base *b = new Derived(); //prints Base Ctor, Derived Ctor, Base dtor, mtlb derived ka dtor print nhi kar rha
    delete b;
    return 0;
}

// jab bird ka constructor call ho jaata hai uske baad virtual table picture me aata hai
// aur virtual table hi picture me nahi aaya aur virtual table hi ek tareeka hai ye batane ka ki actually
// me jo function virtual declare kiya gaya hai vo exactly kaha bind hua hai.
// Toh constructor ko virtual banane se pata hi nhi chalega ki vo constructor kaha point kar rha hai
*/
// ________________________________________________________________________________________________________

// ⭐⭐⭐⭐ Destructor can be virtual.
/*
#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base ctor\n";
    }

    ~Base()
    {
        cout << "Base dtor\n";
    }
};

class Derived: public Base
{
    int *a;
public:
    Derived()
    {
        a = new int[1000];
        cout << "Derived ctor\n";
    }

    ~Derived()
    {
        delete[] a;
        // We saw above that Derived dtor is not being executed, so a is not being deleted, we have encountered
        // a memory leak
        cout << "Derived dtor\n";
    }
};

int main()
{
    Base *b = new Derived();
    delete b;
    return 0;
}
*/
// To fix the issue "Derived dtor is not being executed, so a is not being deleted, we have encountered a
// memory leak"


// 🔴🔴🔴🔴 MAKE IT A PRACTICE TO ALWAYS DECLARE THE Base dtor as Virtual 
#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base ctor\n";
    }

    virtual ~Base()
    {
        cout << "Base dtor\n";
    }
};

class Derived: public Base
{
    int *a;
public:
    Derived()
    {
        a = new int[1000];
        cout << "Derived ctor\n";
    }

    ~Derived()
    {
        delete[] a;
        cout << "Derived dtor\n";
    }
};

int main()
{
    Base *b = new Derived();
    delete b;
    return 0;
}

// Now it prints
// Base ctor
// Derived ctor
// Derived dtor
// Base dtor
// means that 'a' heap memory is being deleted successfully.

// jab b ko delete kiya tab base ka destructor call hua aur kyuki vo virtual tha usne kaha pehle derived ka dtor
// call karo toh pehle derived dtor call hua fir base dtor call hua.