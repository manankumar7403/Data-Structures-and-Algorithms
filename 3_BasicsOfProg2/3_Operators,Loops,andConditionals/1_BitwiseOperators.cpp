// BITWISE OPERATORS IN C++
// AND (&)
// OR (|)
// NOT (~)
// XOR (^)
// LEFT SHIFT (<<)  (Gets multiplied by 2)
// RIGHT SHIFT (>>)

#include <iostream>
using namespace std;
int main()
{
    bool a = true;
    bool b = false;

    // BITWISE AND
    cout << (a & b);  // gives 0
    cout<<endl;

    // BITWISE OR
    cout<< (a|b);    // gives 1
    cout<<endl;

    // BITWISE NOT
    cout<< (~a);     // gives -2 (first true(1) is stored)
    // after 1 is stored (00000001, then it is negated -> 11111110)
    // first bit is 1 -> its a negative number
    // remaining bits -> 1111110
    // 2s complement -> 0000001 + 1
    // 0000010 -> 2
    // so -2 is the output
    cout<<endl;

    // BITWISE XOR
    cout<< (a^b);  // gives 1 (1 is true and 1 is false -> odd true so 1)
    cout<<endl;

    // OTHER EXPERIMENTS
    cout<< (2 & 3);  // gives 2 (perform bitwise and)
    cout<<endl;

    cout<< (5 & 10); // gives 0 (perform bitwise and)
    cout<<endl;

    cout<< (3 | 4);
    cout<<endl;

    // BITWISE LEFT SHIFT OPERATOR
    int c = 12;
    c = c << 1;
    cout<<c<<endl;  // prints 24
    
    int d = 12;
    d = d << 2;     // prints 48
    cout<<d<<endl;

    int e = 12;
    e = e << -1;
    cout<<e<<endl;  // prints garbage values (here, gives 0)

    // BITWISE RIGHT SHIFT OPERATOR
    int f = -128;
    f = f >> 2;
    cout<<f<<endl; // prints 6
}
