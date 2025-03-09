// Polymorphism is of 2 types:
// 1) Compile - time polymorphism
// 2) Run - time polymorphism

// In compile-time polymorphism, we have
// 1) function overloading
// 2) operator overloading

// ________________________________________________________________________________________________________
// ⭐⭐⭐⭐ Compile - Time Polymorphism

// 1) function overloading -> Return type of same name functions shouldn't be changed,
// only the type of parameters(change the number of variables and type of variable only) should be changed.
/*
#include <iostream>
using namespace std;

class Maths
{
    public:
        int sum(int a, int b)
        {
            cout << "I am in first signature " << endl;
            return a + b;
        }

        int sum(int a, int b, int c)
        {
            cout << "I am in second signature " << endl;
            return a + b + c;
        }

        int sum(int a, float b)
        {
            cout << "I am in third signature " << endl;
            return a + b + 100;
        }
};

int main()
{
    Maths obj;

    // cout << obj.sum(2,5);     // calls the first signature -> prints 7
    // cout << obj.sum(2,5,20);     // calls the second signature -> prints 27
    cout << obj.sum(2,5.12f);     // calls the third signature -> prints 107
    return 0;
}
*/
// __________________________________________________________________________________________________

// 2) operator overloading
#include <iostream>
using namespace std;

class Param
{
    public:
        int val;

        void operator+(Param& obj2)   // obj2 is the input parameter(2)
        {
            int value1 = this->val;  // value of current object(7)
            int value2 = obj2.val;   // input parameter (2)
            cout << (value2 - value1) << endl; // (2-7) = -5
        }
};

int main()
{
    Param object1, object2;
    object1.val = 7;
    object2.val = 2;

    // This should print the difference between them
    object1 + object2;    // object1 is the current element and object2 is the input parameter, + is the function call
    return 0;
}
