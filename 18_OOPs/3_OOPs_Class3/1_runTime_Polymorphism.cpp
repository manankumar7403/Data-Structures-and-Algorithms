// #include <iostream>
// using namespace std;

// class Animal
// {
//     public:
//         void speak()
//         {
//             cout << "Speaking!" << endl;
//         }
// };

// class Dog:public Animal
// {
//     public:
//         // override
//         void speak()
//         {
//             cout << "Barking!" << endl;
//         }
// };

// int main()
// {
//     Animal a;
//     a.speak();     // Speaking!
//     Dog b;
//     b.speak();     // Barking!
//     return 0;
// }
// _____________________________________________________________________________________________________

// #include <iostream>
// using namespace std;

// class Animal
// {
//     public:
//         void speak()
//         {
//             cout << "Speaking!" << endl;
//         }
// };

// class Dog:public Animal
// {
//     public:
//         // override
//         void speak()
//         {
//             cout << "Barking!" << endl;
//         }
// };

// int main()
// {
//     // Animal* a = new Animal();
//     // a->speak();     // Speaking!

//     // Dog* a = new Dog();
//     // a->speak();     // Barking!

//     // Upcasting -> Parent class ka pointer child class ke object par define karte ho toh usse upcasting kehte hai
//     Animal* a = new Dog();
//     a->speak();    // Speaking
//     return 0;
// }
// _____________________________________________________________________________________________
/*
#include <iostream>
using namespace std;

class Animal
{
    public:
        virtual void speak()
        {
            cout << "Speaking!" << endl;
        }
};

class Dog:public Animal
{
    public:
        // override
        void speak()
        {
            cout << "Barking!" << endl;
        }
};

int main()
{
    Animal* a = new Dog();
    // prints speaking if we don't put virtual in parent class Animal but we want to decide at runtime which
    // function should be called -> we use the virtual keyword on parent function
    a->speak();    // Barking
    return 0;
}
*/
// ________________________________________________________________________________________________
/*
#include <iostream>
using namespace std;

class Animal
{
    public:
        void speak()
        {
            cout << "Speaking!" << endl;
        }
};

class Dog:public Animal
{
    public:
        // override
        void speak()
        {
            cout << "Barking!" << endl;
        }
};

int main()
{
    // Downcasting
    Dog* b = (Dog* )new Animal();
    b->speak();    // Barking
    return 0;
}
*/
// upcasting karlo chahe downcasting karlo agar without virtual keyword ke karte ho toh tumhara pointer
// ka method call ho rha hoga, 
// agar virtual use kiya hai toh jis type ka object banaya hoga vo call hoga
// Virtual -> RHS
// without virtual -> LHS
// ____________________________________________________________________________________________________
/*
#include <iostream>
using namespace std;

class Animal
{
    public:
        virtual void speak()
        {
            cout << "Speaking!" << endl;
        }
};

class Dog:public Animal
{
    public:
        // override
        void speak()
        {
            cout << "Barking!" << endl;
        }
};

int main()
{
    // Downcasting
    Dog* b = (Dog* )new Animal();
    b->speak();    // Speaking
    return 0;
}
*/
// ___________________________________________________________________________________________________

// ____________________________________________________________________________________________
// ____________________________________________________________________________________________

// ⭐⭐⭐⭐ Playing with Constructors ⭐⭐⭐⭐ 

#include <iostream>
using namespace std;

class Animal
{
    public:
        Animal()
        {
            cout << "I am inside animal constructor!" << endl;
        }

        void speak()
        {
            cout << "Speaking!" << endl;
        }
};

class Dog:public Animal
{
    public:
        Dog()
        {
            cout << "I am inside dog constructor!" << endl;
        }

        // override
        void speak()
        {
            cout << "Barking!" << endl;
        }
};

int main()
{
    // Animal* a = new Animal();  // I am inside animal constructor!
    // Dog* a = new Dog(); // I am inside animal constructor! // I am inside dog constructor!
    // Animal* a = new Dog(); // I am inside animal constructor! // I am inside dog constructor!
    // Dog* a = (Dog*) new Animal(); // I am inside animal constructor!
    return 0;
}