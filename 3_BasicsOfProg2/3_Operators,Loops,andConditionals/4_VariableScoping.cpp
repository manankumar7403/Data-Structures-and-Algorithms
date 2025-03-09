/*
#include <iostream>
using namespace std;
int main()
{
    // Variable Scoping
    // Here all the variables are in their respective blocks {}, so they all are
    // 🔴LOCAL VARIABLES🔴

    //Declaration
    int a;

    //Initialisation
    int b = 5;

    //Updation
    b=10;

    if (true)
    {
        int b = 15;
        cout<<b<<endl;
    }

    cout<<b<<endl;
}

// The scope of the variables a and b are in the entire main block.
// but in the if condition, b is initialised again and printed. So the scope of this b is 
// in the if block only. Therefore, when we print both statements, the b in the if block
// prints 15 and the b outside the if block prints 10.

*/

// -----------------------------------_________________________----------------------------

// 🔴GLOBAL VARIABLES🔴
#include <iostream>
using namespace std;

int raja = 420;   // GLOBAL VARIABLE
int babbar = 7;

int main()
{
    //Declaration
    int a;

    //Initialisation
    int b = 5;

    //Updation
    b=10;
    cout<<raja<<endl;

    if (true)
    {
        int b = 15;
        int babbar = 1985;
        cout<<b<<endl;
        cout<<raja<<endl;
        cout<<babbar<<endl;
    }

    cout<<b<<endl;
}

// Here, the global variable 'raja' is declared outside the scope(main function),
// so it can be used inside every block.
// Using GLOBAL VARIABLE is a bad practice.
