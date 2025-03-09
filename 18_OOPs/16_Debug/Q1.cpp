/*
Debug the code.
#include<iostream>
using namespace std;

class Vehicle {
    protected:
        string make;
        string model;
        int year;
    public:
        Vehicle(string m, string md, int y) {
            make = m;
            model = md;
            year = y;
        }
};

class Car: public Vehicle {
    public:
        void getDetails() {
            cout << make << " " << model << " " << year << endl;
        }
};

int main() {
    Vehicle* v = new Car("Toyota", "Camry", 2021);
    v->getDetails();
    delete v;
    return 0;
}
*/
// _____________________________________________________________________________________________________

#include<iostream>
using namespace std;

class Vehicle {
    protected:
        string make;
        string model;
        int year;
    public:
        Vehicle(string m, string md, int y) {
            make = m;
            model = md;
            year = y;
        }
        virtual void getDetails() = 0; // declare as pure virtual function, means it has to be declared in any class that inherits Vehicle class
};

class Car: public Vehicle {
    public:
        // Constructor for Car class
        Car(string m, string md, int y): Vehicle(m, md, y) {};
        void getDetails() {
            cout << make << " " << model << " " << year << endl;
        }
};

int main() {
    Vehicle* v = new Car("Toyota", "Camry", 2021);
    v->getDetails();
    delete v;
    return 0;
}