// Q5. Debug the code -> This is for GCD
// int gcd(int a, int b)
// {
//     if (a == 0)
//         return b;
//     return gcd(a % b, a);
// }
// __________________________________________________________________________________________________

#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main()
{
    int a, b;
    cout << "Enter a: " << endl;
    cin >> a;
    cout << "Enter b: " << endl;
    cin >> b;
    cout << "GCD of " << a << " and " << b << " is: " << gcd(a, b) << endl;
    return 0;
}