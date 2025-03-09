/*
Debug the code.
class Animal {
public:
    string name;
    Animal() {
        cout << "Animal Constructor called!" << endl;
    }
    ~Animal() {
        cout << "Animal Destructor called!" << endl;
    }
};

class Dog : public Animal {
public:
    string breed;
    Dog(string breed) : Animal() {
        this->breed = breed;
        cout << "Dog Constructor called!" << endl;
    }
    ~Dog() : ~Animal() {
        cout << "Dog Destructor called!" << endl;
    }
};

int main() {
    Dog* dog = new Dog("Poodle");
    delete dog;
    return 0;
}
*/
// _____________________________________________________________________________________________________

#include <iostream>
using namespace std;

class Animal {
public:
    string name;
    Animal() {
        cout << "Animal Constructor called!" << endl;
    }
    virtual ~Animal() {
        cout << "Animal Destructor called!" << endl;
    }
};

class Dog : public Animal {
public:
    string breed;
    Dog(string breed) : Animal() {
        this->breed = breed;
        cout << "Dog Constructor called!" << endl;
    }
    ~Dog() {
        cout << "Dog Destructor called!" << endl;
    }
};

int main() {
    Dog* dog = new Dog("Poodle");
    delete dog;
    return 0;
}