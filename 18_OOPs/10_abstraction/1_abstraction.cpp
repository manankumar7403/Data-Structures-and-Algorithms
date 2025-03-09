// ⭐⭐⭐⭐ Abstraction using classes ⭐⭐⭐⭐
// #include <iostream>
// using namespace std;

// class AbstractionExample
// {
// private:
//     int num;
//     char ch;

// public:
//     void setMyValues(int n, char c)
//     {
//         num = n;
//         ch = c;
//     }

//     void getMyValues()
//     {
//         cout << "Number is: " << num << endl;
//         cout << "Char is: " << ch << endl;
//     }
// };

// int main()
// {
//     AbstractionExample exampleObject;
//     exampleObject.setMyValues(42, 'A');
//     exampleObject.getMyValues();

//     return 0;
// }
// ______________________________________________________________________________________________________

// Q- What is an abstract class?
// A- Class which cannot be instantiated(object cannot be created) and has a pure virtual function in it
/*
#include <iostream>
using namespace std;

class Demo
{
    public:
        virtual void f1() = 0;  // pure virtual function or abstract function
};

int main()
{
    Demo obj;
    obj.f1();  // object cannot be created for an abstract class -> gives error
}
*/
// __________________________________________________________________________________________________

#include <iostream>
using namespace std;

class Demo
{
    public:
        virtual void f1() = 0;  // pure virtual function or abstract function

        void f2()
        {
            cout << "This is f2 function" << endl;   // now to accesss this f2 function which belongs to abstract class Demo, we need to use inheritance
        }
};

class Abc: public Demo    // kyuki Demo abstract class hai toh Abc bhi inherit karke abstract class ban jayegi, toh fir usko kaise prevent kare -> using function over-riding, so we can create objects and call the functions
{
    public:
        // Same name and same parameter function -> to over-ride
        void f1()
        {
            cout << "This is f1 function" << endl;
        }
};

int main()
{
    Abc obj;
    obj.f1();  // object cannot be created for an abstract class -> gives error
    obj.f2();
}

// Toh abstract class isliye banayi jaati hai taaki uska direct object bana kar uske members ko access
// nahi kar paye, aur uske andar bina body wale function(pure virtual function) aur agar un functions ko use
// karna ho toh unko ek nayi class me inherit karke uski new definition likh paye(using function over-riding) 
