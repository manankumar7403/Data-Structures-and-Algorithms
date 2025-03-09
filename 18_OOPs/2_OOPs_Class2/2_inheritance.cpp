// Check the mode of inheritance and base class access modifiers table.
/*
#include <iostream>
using namespace std;

// Parent Class
class Animal
{
    public:
        int age = 10;
        int weight = 10;
    
    void eat()
    {
        cout << "Eating!" << endl;
    }
};

// Child Class
class Dog:public Animal
{

};


int main()
{
    Dog d1;
    cout << d1.age << endl;       // prints 10
    cout << d1.weight << endl;    // prints 10
    d1.eat();     // prints Eating!
    return 0;
}
*/
// ___________________________________________________________________________________________________________

// #include <iostream>
// using namespace std;

// // Parent Class
// class Animal
// {
//     public:
//         int age = 10;
// };

// // Child Class
// class Dog:protected Animal    // protected sirf child class me access ho sakta hai outside nahi(outside vo private ki tarah behave karta hai)
// {
//     public:
//     void print()
//     {
//         cout << this->age;
//     }
// };


// int main()
// {
//     Dog d1;
//     // cout << d1.age << endl;      // not declared error
//     d1.print();
//     return 0;
// }
// ___________________________________________________________________________________________________

// #include <iostream>
// using namespace std;

// // Parent Class
// class Animal
// {
//     public:
//         int age = 10;
// };

// // Child Class
// class Dog:private Animal
// {
//     public:
//     void print()
//     {
//         cout << this->age;
//     }
// };


// int main()
// {
//     Dog d1;
//     // cout << d1.age << endl;      // not declared error
//     d1.print();
//     return 0;
// }
// ______________________________________________________________________________________________________

// ⭐⭐⭐⭐

// #include <iostream>
// using namespace std;

// // Parent Class
// class Animal
// {
//     protected:
//         int age = 10;
// };

// // Child Class
// class Dog:public Animal
// {
//     public:
//     void print()
//     {
//         cout << this->age;
//     }
// };


// int main()
// {
//     Dog d1;
//     // cout << d1.age << endl;      // not declared error
//     d1.print();
//     return 0;
// }
// ___________________________________________________________________________________________________

// #include <iostream>
// using namespace std;

// // Parent Class
// class Animal
// {
//     protected:
//         int age = 10;
// };

// // Child Class
// class Dog:protected Animal
// {
//     public:
//     void print()
//     {
//         cout << this->age;
//     }
// };


// int main()
// {
//     Dog d1;
//     // cout << d1.age << endl;      // not declared error
//     d1.print();
//     return 0;
// }
// ____________________________________________________________________________________________________

// #include <iostream>
// using namespace std;

// // Parent Class
// class Animal
// {
//     protected:
//         int age = 10;
// };

// // Child Class
// class Dog:private Animal
// {
//     public:
//     void print()
//     {
//         cout << this->age;
//     }
// };


// int main()
// {
//     Dog d1;
//     // cout << d1.age << endl;      // not declared error
//     d1.print();
//     return 0;
// }
// ______________________________________________________________________________________________________

// #include <iostream>
// using namespace std;

// // Parent Class
// class Animal
// {
//     private:
//         int age = 10;
// };

// // Child Class
// class Dog:public Animal
// {
//     public:
//     void print()
//     {
//         // cout << this->age;   // not declared error
//     }
// };


// int main()
// {
//     Dog d1;
//     // cout << d1.age << endl;      // not declared error
//     // d1.print();        // not declared error
//     return 0;
// }
// _______________________________________________________________________________

// #include <iostream>
// using namespace std;

// // Parent Class
// class Animal
// {
//     private:
//         int age = 10;
// };

// // Child Class
// class Dog:protected Animal
// {
//     public:
//     void print()
//     {
//         // cout << this->age;   // not declared here
//     }
// };


// int main()
// {
//     Dog d1;
//     // cout << d1.age << endl;      // not declared error
//     // d1.print();        // not declared error
//     return 0;
// }
// _____________________________________________________________________________________________________

#include <iostream>
using namespace std;

// Parent Class
class Animal
{
    private:
        int age = 10;
};

// Child Class
class Dog:private Animal
{
    public:
    void print()
    {
        // cout << this->age;   // not declared here
    }
};


int main()
{
    Dog d1;
    // cout << d1.age << endl;      // not declared error
    // d1.print();        // not declared error
    return 0;
}
