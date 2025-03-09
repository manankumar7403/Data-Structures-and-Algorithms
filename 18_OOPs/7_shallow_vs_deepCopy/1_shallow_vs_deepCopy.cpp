/*
#include <iostream>
using namespace std;

class abc{
public:
    int x;
    int *y;
    abc(int _x, int _y):x(_x), y(new int (_y)) {}

    void print() const{
        printf("X:%d\nPTR Y:%p\nContent of Y (*y):%d\n\n", x, y, *y);  // %p is for memory address of the pointer
    }
};

int main()
{
    abc a(1, 2);
    a.print();
    return 0;   
}
*/
// ____________________________________________________________________________________________________________
/*
#include <iostream>
using namespace std;

class abc{
public:
    int x;
    int *y;
    abc(int _x, int _y):x(_x), y(new int (_y)) {}

    void print() const{
        printf("X:%d\nPTR Y:%p\nContent of Y (*y):%d\n\n", x, y, *y);  // %p is for memory address of the pointer
    }
};

int main()
{
    abc a(1, 2);
    cout << "Printing a\n";
    a.print();

    // abc b(a); // OR
    abc b = a;   // galti idhar yeh hogi ki X aur Y ka pointer same ho jayega, kyuki COPY CONSTRUCTOR IS CALLED
    cout << "Printing b\n";
    b.print();

    *b.y = 20;
    cout << "Printing b\n";
    b.print();
    cout << "Printing a\n";
    a.print();
    return 0;   
}
*/
// _____________________________________________________________________________________________________
/*
#include <iostream>
using namespace std;

class abc{
public:
    int x;
    int *y;
    abc(int _x, int _y):x(_x), y(new int (_y)) {}

    // Default dumb copy constructor: it does SHALLOW COPY -> jo pointer a ke andar tha ussi ko b me copy kar dia
    abc(const abc &obj)
    {
        x = obj.x;
        y = obj.y;
    }

    void print() const{
        printf("X:%d\nPTR Y:%p\nContent of Y (*y):%d\n\n", x, y, *y);  // %p is for memory address of the pointer
    }
};

int main()
{
    abc a(1, 2);
    cout << "Printing a\n";
    a.print();

    // abc b(a); // OR
    abc b = a;   // galti idhar yeh hogi ki X aur Y ka pointer same ho jayega, kyuki COPY CONSTRUCTOR IS CALLED
    cout << "Printing b\n";
    b.print();

    *b.y = 20;
    cout << "Printing b\n";
    b.print();
    cout << "Printing a\n";
    a.print();
    return 0;   
}
*/
// _____________________________________________________________________________________________________

// FIXING THE ABOVE PROBLEM USING DEEP COPY
/*
#include <iostream>
using namespace std;

class abc{
public:
    int x;
    int *y;
    abc(int _x, int _y):x(_x), y(new int (_y)) {}

    // Default dumb copy constructor: it does SHALLOW COPY -> jo pointer a ke andar tha ussi ko b me copy kar dia
    // abc(const abc &obj)
    // {
    //     x = obj.x;
    //     y = obj.y;
    // }

    // OUR SMART DEEP COPY
    abc(const abc &obj)
    {
        x = obj.x;
        y = new int(*obj.y);
    }

    void print() const{
        printf("X:%d\nPTR Y:%p\nContent of Y (*y):%d\n\n", x, y, *y);  // %p is for memory address of the pointer
    }
};

int main()
{
    abc a(1, 2);
    cout << "Printing a\n";
    a.print();

    abc b = a;
    cout << "Printing b\n";
    b.print();

    *b.y = 20;
    cout << "Printing b\n";
    b.print();
    cout << "Printing a\n";
    a.print();
    return 0;   
}
*/
// ________________________________________________________________________________________________________

// SOME MORE PROBLEMS IN SHALLOW COPY

#include <iostream>
using namespace std;

class abc{
public:
    int x;
    int *y;
    abc(int _x, int _y):x(_x), y(new int (_y)) {}   // Constructor using init list

    // Default dumb copy constructor: it does SHALLOW COPY -> jo pointer a ke andar tha ussi ko b me copy kar dia
    abc(const abc &obj)
    {
        x = obj.x;
        y = obj.y;
    }

    void print() const{
        printf("X:%d\nPTR Y:%p\nContent of Y (*y):%d\n\n", x, y, *y);  // %p is for memory address of the pointer
    }

    // Destructor for memory deallocation -> to avoid memory leaks
    ~abc()
    {
        delete y;
    }
};

int main()
{
    abc *a  = new abc(1, 2);
    abc b = *a;
    delete a;        // a ka destructor call hua
    b.print();     // malloc -> double free ho rha hai
    return 0;   
}

// jab a ko delete kiya tab
// tab a khud delete hua, x delete hua a wala
// ~abc destructor call hua toh y ka content bhi delete ho gya (poora y ka content, a aur b dono se) -> a ka 
// poora wajood khatam

// ab b.print() kar rhe toh jo a se x copy hua tha b mein vo toh print ho gya
// jo x se y pointer copy kiya tha uska address toh print ho gya
// PAR
// y ka content ab 2 nhi hai random value hai (garbage ya 0) kyuki y ka content delete ho gya tha upar

// fir return 0; hua and b bhi delete hi rha hoga memory se toh b ka sab kuch except y delete ho gya
// fir y delete hua ~abc me jaake toh *b.y yaani *y par jo pada tha usse delete kardo par vo toh tabhi delete
// ho chuka hai jab humne a delete kiya tha, isliye malloc: double free of an object error hai

// ISLIYE SHALLOW COPY KI JAGAH DEEP COPY USE KARNI HAI