/*
#include <iostream>
using namespace std;

void numberShow(int num)
{
    cout << num << endl;
}

int main()
{
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    return 0;
}
*/
// Function calling overhead and stack unwinding is too much here (need an alternative) -> inline functions
// Only use with small size of code, otherwise the executable size would be a lot.
// _____________________________________________________________________________________________________
/*
#include <iostream>
using namespace std;

inline void numberShow(int num)
{
    cout << num << endl;
}

int main()
{
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    return 0;
}
*/
// What is actually happening here?
// The compiler behaves like
// cout << 10 << endl;
// cout << 10 << endl;
// cout << 10 << endl;
// cout << 10 << endl;
// cout << 10 << endl;
// cout << 10 << endl;
// cout << 10 << endl;
// cout << 10 << endl;
// cout << 10 << endl;
// cout << 10 << endl;
// __________________________________________________________________________________________________________

// ⭐⭐⭐⭐ Inline functions work at compiling time while MACROS(#define) work
// at pre-processing
// REMEMBER that pre-processing is done before compiling
// Toh MACROS se toh code ka size badhta hai par inline se zaroori nahi hai ki badhe
// kyuki inline chote codes ke saath hi use karte hai