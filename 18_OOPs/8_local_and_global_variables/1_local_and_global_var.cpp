/*
#include <iostream>
using namespace std;

int x = 2;     // GLOBAL VARIABLE

int main()
{
    x = 4; // GLOBAL x  or ::x = 4;
    int x = 20;          // local x to main function
    cout << x << endl;   // prints 20 becuase local var > global var -> prints 20
    cout << ::x << endl;  // :: is to access the global variable  -> prints 4
    return 0;
}
*/
// scope ke andar uske local variable ko global variable se zyada preference milti hai
// _______________________________________________________________________________________________
/*
#include <iostream>
using namespace std;

int x = 2;

void fun()
{
    int x = 60;
    cout << x << endl;    // prints 60
    cout << ::x << endl;  // prints 4
}

int main()
{
    ::x = 4;
    int x = 20;
    cout << x << endl;    // prints 20
    cout << ::x << endl;  // prints 4

    {
        int x = 50;
        cout << x << endl;  // prints 50
        cout << ::x << endl;  // prints 4
    }
    
    fun();

    return 0;
}
*/
// ________________________________________________________________________________________________
#include <iostream>
using namespace std;

int x = 2;

void fun()
{
    int x = 60;
    cout << x << endl;       // prints 60
    ::x = 40;
    cout << ::x << endl;     // prints 40
}

int main()
{
    ::x = 4;
    int x = 20;
    cout << x << endl;    // prints 20
    cout << ::x << endl;  // prints 4

    {
        int x = 50;
        cout << x << endl;    // prints 50
        cout << ::x << endl;  // prints 4
    }
    
    fun();

    return 0;
}
