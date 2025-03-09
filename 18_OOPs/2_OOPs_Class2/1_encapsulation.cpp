#include <iostream>
using namespace std;

class Animal
{
    // public:                      // encapsulation (Data Hiding)
    private:                        // perfect encapsulation
        int age;
        int weight;

    public:
        void eat()
        {
            cout << "Eating!" << endl;
        }
        int getAge()
        {
            return this->age;
        }
        void setAge(int age)
        {
            this->age = age;
        }
};

int main()
{
    cout << "Hello World!" << endl;

    Animal myAnimal;              // creating an instance(object) myAnimal of class Animal
    myAnimal.eat();
    myAnimal.setAge(101);
    cout << "Age: " << myAnimal.getAge() <<  endl;
    return 0;
}