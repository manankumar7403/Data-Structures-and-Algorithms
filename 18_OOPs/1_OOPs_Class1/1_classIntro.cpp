/*
#include <iostream>
using namespace std;

class Animal
{

};

int main()
{
    cout << "Sizeof empty class is: " << sizeof(Animal) << endl; // size of empty class is 1 byte.
    return 0;
}
*/
// ________________________________________________________________________________________________________

/*
#include <iostream>
using namespace std;

class Animal
{
    int age;
    int weight;
    char ch;
};

int main()
{
    cout << "Sizeof empty class is: " << sizeof(Animal) << endl; // Gives 12 -> Learn about Padding and Greedy Alignment
    return 0;
}
*/
// _________________________________________________________________________________________________________

// ⭐⭐⭐⭐  State or Properties and Behaviour ⭐⭐⭐⭐
/*
#include <iostream>
using namespace std;

class Animal
{
    // State or Properties;
    // 3 types of Access Modifiers -> public, private, and protected
    private:                // couldn't be accessed outside class. Use setters and getters to do that
    int weight;

    public:                 // could be access within or outside class
    int age;
    string type;

    // Behaviour
    void eat()
    {
        cout << "Eating!" << endl;
    }

    void sleep()
    {
        cout << "Sleeping!" << endl;
    }


    // Getters and Setters
    int getWeight()
    {
        return weight;
    }
    void setWeight(int w)
    {
        weight = w;
    }
};

int main()
{
    // Now, har ek state ko memory allocate karni hai -> Object Creation se start karo

    // Object Creation -> 2 Methods: 1) Static Memory Allocation 2) Dynamic Memory Allocation

    // Static Memory Allocation
    Animal ramesh;
    ramesh.age = 12;
    ramesh.type = "Lion";

    // agar kisi obj ki property ko access karna hai toh '.' use karo
    cout << "Age of ramesh is: " << ramesh.age << endl; // gives 12
    cout << "Type of ramesh is: " << ramesh.type << endl; // gives Lion

    ramesh.eat();  // prints Eating!
    ramesh.sleep();  // prints Sleeping!

    // To access private member
    ramesh.setWeight(101);
    cout << "Weight of ramesh is: " << ramesh.getWeight() << endl; // gives 101

    return 0;
}
*/

// __________________________________________________________________________________________________

// ⭐⭐⭐⭐ Dynamic Memory Allocation ⭐⭐⭐⭐
/*
#include <iostream>
using namespace std;

class Animal
{
    // State or Properties;
    // 3 types of Access Modifiers -> public, private, and protected
    private:                // couldn't be accessed outside class. Use setters and getters to do that
    int weight;

    public:                 // could be access within or outside class
    int age;
    string type;

    // Behaviour
    void eat()
    {
        cout << "Eating!" << endl;
    }

    void sleep()
    {
        cout << "Sleeping!" << endl;
    }


    // Getters and Setters
    int getWeight()
    {
        return weight;
    }
    // void setWeight(int w)
    // {
    //     weight = w;
    // }
    void setWeight(int weight)
    {
        this->weight = weight;  // this->weight, this is a pointer to the current object
    }
};

int main()
{
    // Dynamic Memory Allocation
    
    Animal* suresh = new Animal;
    // 1st method for initializing
    (*suresh).age = 15;
    (*suresh).type = "cat";

    // 2nd method for initializing
    suresh->age = 17;
    suresh->type = "dog";
    cout << suresh->age << endl;
    cout << suresh->type << endl;
    suresh->eat();
    suresh->sleep();
    return 0;
}
*/
// ________________________________________________________________________________________________________
// ⭐⭐⭐⭐ CONSTRUCTORS ⭐⭐⭐⭐
/*
#include <iostream>
using namespace std;

class Animal
{
    // State or properties
    private:
    int weight;

    public:
    int age;
    string type;

    // Default Constructor
    Animal()
    {
        this->weight = 0;
        this->age = 0;
        this->type = "";
        cout << "Constructor Called" << endl;
    }

    // Parameterised Constructor
    Animal(int age)
    {
        this->age = age;
        cout << "Parameterised constructor called" << endl;
    }

    Animal(int age, int weight)
    {
        this->age = age;
        this->weight = weight;
        cout << "Parameterised constructor 2 called" << endl;
    }

    Animal(int age, int weight, string type)
    {
        this->age = age;
        this->weight = weight;
        this->type = type;
        cout << "Parameterised constructor 3 called" << endl;
    }

    // Copy Constructor
    Animal(Animal &obj)   // pass by reference to prevent making copies again and again -> infinite loop
    {
        this->age = obj.age;
        this->weight = obj.weight;
        this->type = obj.type;
        cout << "I am inside copy constructor!" << endl;
    }

    // Behaviour
    void eat()
    {
        cout << "Eating!" << endl;
    }

    void sleep()
    {
        cout << "Sleeping!" << endl;
    }


    // Getters and Setters
    int getWeight()
    {
        return weight;
    }
    
    void setWeight(int weight)
    {
        this->weight = weight;  // this->weight, this is a pointer to the current object
    }
};

int main()
{
    // Constructor called for static
    // Animal a;                          // Constructor called

    // Constructor called for dynamic
    // Animal* b = new Animal;           // Constructor called

    // Animal a;                           // Constructor called
    // Animal* b = new Animal(100);        // Parameterised Constructor called
    
    // Animal a(10);                       // Parameterised Constructor called
    // Animal* b = new Animal(100);        // Parameterised Constructor called

    // Animal a(10);                       // Parameterised Constructor called
    // Animal* b = new Animal(100, 10);    // Parameterised Constructor 2 called

    Animal a(10);                                  // Parameterised Constructor called
    Animal* b = new Animal(100, 10);               // Parameterised Constructor 2 called
    Animal* c = new Animal(100, 10, "Supreme");    // Parameterised Constructor 3 called

    // Object Copy
    Animal d = a;            // I am inside copy constructor!
    // OR
    Animal e(*b);            // I am inside copy constructor!
    // OR
    Animal animal1(d);       // I am inside copy constructor!
    
    return 0;
}
*/
// ________________________________________________________________________________________________________
/*
#include <iostream>
using namespace std;

class Animal
{
    // State or properties
    private:
    int weight;

    public:
    int age;
    string type;

    // Default Constructor
    Animal()
    {
        this->weight = 0;
        this->age = 0;
        this->type = "";
        cout << "Constructor Called" << endl;
    }

    // Parameterised Constructor
    Animal(int age)
    {
        this->age = age;
        cout << "Parameterised constructor called" << endl;
    }

    Animal(int age, int weight)
    {
        this->age = age;
        this->weight = weight;
        cout << "Parameterised constructor 2 called" << endl;
    }

    Animal(int age, int weight, string type)
    {
        this->age = age;
        this->weight = weight;
        this->type = type;
        cout << "Parameterised constructor 3 called" << endl;
    }

    // Copy Constructor
    Animal(Animal &obj)   // pass by reference to prevent making copies again and again -> infinite loop
    {
        this->age = obj.age;
        this->weight = obj.weight;
        this->type = obj.type;
        cout << "I am inside copy constructor!" << endl;
    }

    // Behaviour
    void eat()
    {
        cout << "Eating!" << endl;
    }

    void sleep()
    {
        cout << "Sleeping!" << endl;
    }


    // Getters and Setters
    int getWeight()
    {
        return weight;
    }
    
    void setWeight(int weight)
    {
        this->weight = weight;  // this->weight, this is a pointer to the current object
    }

    void print()
    {
        cout << this->age << " " << this->weight << " " << this->type << endl;
    }
};

int main()
{
    Animal a;
    a.age = 20;
    a.setWeight(101);
    a.type = "babbar";
    
    Animal b = a;
    cout << "a -> ";
    a.print();
    cout << "b -> ";
    b.print();

    a.type[0] = 'G';
    cout << "a -> ";
    a.print();

    cout << "b -> ";
    b.print();
    return 0;
}
*/
// __________________________________________________________________________________________
// ⭐⭐⭐⭐ DESTRUCTOR ⭐⭐⭐⭐

#include <iostream>
using namespace std;

class Animal
{
    // State or properties
    private:
    int weight;

    public:
    int age;
    string type;

    // Default Constructor
    // Animal()
    // {
    //     this->weight = 0;
    //     this->age = 0;
    //     this->type = "";
    //     cout << "Constructor Called" << endl;
    // }

    // Behaviour
    void eat()
    {
        cout << "Eating!" << endl;
    }

    void sleep()
    {
        cout << "Sleeping!" << endl;
    }


    // Getters and Setters
    int getWeight()
    {
        return weight;
    }
    
    void setWeight(int weight)
    {
        this->weight = weight;  // this->weight, this is a pointer to the current object
    }

    void print()
    {
        cout << this->age << " " << this->weight << " " << this->type << endl;
    }

    // Destructor
    ~Animal()
    {
        cout << "I am inside destructor" << endl;
    }
};

int main()
{
    cout << "a object creation" << endl;
    Animal a;
    a.age = 5;
    //a is Destructed automatically -> static memory

    cout << "b object creation" << endl;
    Animal* b = new Animal();
    b->age = 12;

    // b should be destructed manually using delete -> dynamic memory
    delete b;

    return 0;
}
