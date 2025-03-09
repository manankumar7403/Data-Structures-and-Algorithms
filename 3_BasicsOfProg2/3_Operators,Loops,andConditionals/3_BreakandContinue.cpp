// BREAK KEYWORD
// #include <iostream>
// using namespace std;
// int main()
// {
//     int n;
//     cout<<"Enter a number: ";
//     cin>>n;
//     for (int i=0; i<n; i++)
//     {
//         cout<<"Manan"<<endl;
//         break;
//     }
//     cout<<"Kumar";
// }

// Here, "Manan" would be printed 5 times for n = 5 followed by "Kumar" if break keyword is absent.
// If break keyword is present, "Manan" would be printed once and then break keyword would be encountered.
// As soon as break keyword is encounered, the loop terminates and exits, printing the statement outside
// the loop i.e., "Kumar"

// -----------------------------------------------------------------
// CONTINUE KEYWORD
#include <iostream>
using namespace std;
int main()
{
    int n = 5;
    for (int i=0; i<n; i++)
    {
        continue;
        cout<<i<<endl;
    }
    cout<<"Kumar";
}

//Here, n=5
// As soon as the loop encounters the keyword "continue", it starts again without printing i.
// So the loop goes from 0 to 4 without printing anything.
// After 5 loops, the loop terminates, exits, and prints "Kumar" which is outside the loop.

