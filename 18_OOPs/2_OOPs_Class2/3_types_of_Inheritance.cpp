// Types of Inheritance
// 1) Single level inheritance
// 2) Multi level inheritance
// 3) Multiple inheritance
// 4) Hierarchical inheritance
// 5) Hybrid inheritance

// 1) Single-level inheritance
/*
#include <iostream>
using namespace std;

class Car
{
    public:
        string name;
        int weight;
        int age;

        void speedUp()
        {
            cout << "Speeding Up!" << endl;
        }
        void applyBreak()
        {
            cout << "Apply break!" << endl;
        }
};

class Scorpio: public Car
{
    
};

int main()
{
    Scorpio babbarWali;
    babbarWali.speedUp();
    return 0;
}
*/
// ______________________________________________________________________________________________________

// 2) Multi level inheritance
/*
#include <iostream>
using namespace std;

class Fruit
{
    public:
        string name;
};

class Mango: public Fruit
{
    public:
        int weight;
};

class Alphonso: public Mango
{
    public:
        int sugarLevel;
};

int main()
{
    Alphonso a;
    cout << a.name << " " << a.weight << " " << a.sugarLevel << endl;
    return 0;
}
*/
// ________________________________________________________________________________________________

// 3) Multiple Inheritance
/*
#include <iostream>
using namespace std;

class A
{
    public:
        int physics;
        int chemistry;
        // Constructor A
        A()
        {
            physics = 99;
            chemistry = 101;
        }
};

class B
{
    public:
        int chemistry;
        // Constructor B
        B()
        {
            chemistry = 420;
        }
};

class C: public A, public B
{
    public:
        int maths;
        // Constructor C
        C()
        {
            maths = 500;
        }

};

int main()
{
    C obj;
    cout << obj.physics << " " << obj.A::chemistry << " " << obj.B::chemistry << " " << obj.maths << endl;
    // For same variable problem(diamond problem) -> use scope resolution operator -> ::
    return 0;
}
*/
// _________________________________________________________________________________________________

// 4) Hierarchical Inheritance
/*
#include <iostream>
using namespace std;

class Car
{
    public:
        int age;
        int weight;
        string name;

        void speedUp()
        {
            cout << "Speeding Up!" << endl;
        }
};

class Scorpio:public Car
{

};

class Fortuner:public Car
{
    
};

int main()
{
    Scorpio s11;
    s11.speedUp();

    Fortuner f11;
    f11.speedUp();
    return 0;
}
*/
// ______________________________________________________________________________________________________

// 5) Hybrid Inheritance -> could be a mixture of any number of combinations of the 4 types of inheritance
// discussed above