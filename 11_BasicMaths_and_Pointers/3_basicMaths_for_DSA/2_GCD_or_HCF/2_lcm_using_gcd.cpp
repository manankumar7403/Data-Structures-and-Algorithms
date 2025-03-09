#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if(a == 0) return b;
    if(b == 0) return a;
    while(a > 0 && b > 0)
    {
        if(a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    return a == 0 ? b : a;
}

int lcm(int a, int b)
{
    int res = abs((a * b) / gcd(a, b));
    return res;
}

int main()
{   
    int a, b;
    cout << "Enter a: " << endl;
    cin >> a;
    cout << "Enter b: " << endl;
    cin >> b;
    cout << "LCM of " << a << " and " << b << " is " << lcm(a, b) << endl;
    return 0;
}