/*
#include <iostream>
using namespace std;

class A
{
    private:
        int x;
    
    public:
        // Constructor
        A(int _val):x(_val) {};
        
        // Getter
        int getX() const
        {
            return x;
        }
        // Setter
        void setX(int _val)
        {
            x = _val;
        }
};

class B      // class B prints the data members of class A
{
    public:
        void print(const A &a)   // a, A class ka obj hai aur vo const hai toh is scope ke andar A ke kisi bhi data member ko change nahi kr sakte
        {
            cout << a.getX() << endl;
        }
};

int main()
{
    A a(5);
    B b;
    b.print(a);
    return 0;
}
*/
// ___________________________________________________________________________________________________________

// Suppose B ke andar cout << a.getX() jo likha hai getter setters use karke uski jagah sirf a.x print krna hai
// toh kaise karnege?
/*
#include <iostream>
using namespace std;

class A
{
    private:
        int x;
    
    public:
        // Constructor
        A(int _val):x(_val) {};
        
        // // Getter
        // int getX() const
        // {
        //     return x;
        // }
        // // Setter
        // void setX(int _val)
        // {
        //     x = _val;
        // }

        friend class B;
};

class B      // class B prints the data members of class A
{
    public:
        void print(const A &a)   // a, A class ka obj hai aur vo const hai toh is scope ke andar A ke kisi bhi data member ko change nahi kr sakte
        {
            // cout << a.getX() << endl;
            cout << a.x << endl;   // kyuki ye friend hai ye A ke private members ko access kar paaya without using setters and getters
        }
};

int main()
{
    A a(5);
    B b;
    b.print(a);
    return 0;
}
*/
// ________________________________________________________________________________________________________

// Similarly hum A ke private data members kisi function me bhi access kara sakte hai
/*
#include <iostream>
using namespace std;

class A
{
    private:
        int x;
    
    public:
        // Constructor
        A(int _val):x(_val) {};

        friend class B;
        friend void fun(const A &);
};

class B      // class B prints the data members of class A
{
    public:
        void print(const A &a)   // a, A class ka obj hai aur vo const hai toh is scope ke andar A ke kisi bhi data member ko change nahi kr sakte
        {
            cout << a.x << endl;
        }
};

void fun(const A &a)
{
    cout << a.x << endl;
}

int main()
{
    A a(5);
    B b;
    b.print(a);
    fun(a);
    return 0;
}
*/
// ____________________________________________________________________________________________________

// Sabse behtar a me hi function bana do x ko print karne ka aur jaha jaha print karwana ho
// waha waha call kar do
#include <iostream>
using namespace std;

class A
{
    private:
        int x;
    
    public:
        // Constructor
        A(int _val):x(_val) {};

        void print() const
        {
            cout << x << endl;
        }


};

class B      // class B prints the data members of class A
{
    public:
        void print(const A &a)   // a, A class ka obj hai aur vo const hai toh is scope ke andar A ke kisi bhi data member ko change nahi kr sakte
        {
            a.print();
        }
};

int main()
{
    A a(5);
    B b;
    b.print(a);
    return 0;
}