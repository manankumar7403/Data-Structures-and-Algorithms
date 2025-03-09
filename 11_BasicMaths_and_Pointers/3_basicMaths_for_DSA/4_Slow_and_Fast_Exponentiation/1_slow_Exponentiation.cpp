#include <iostream>
using namespace std;

int slowExponentiation(int a, int b)
{
    int ans = 1;
    for(int i=0; i<b; i++)
    {
        ans = ans*a;
    }
    return ans;
}

// TC -> O(b)

int main()
{
    int a, b;
    cout << "Enter a: " << endl;
    cin >> a;
    cout << "Enter b: " << endl;
    cin >> b;
    cout << slowExponentiation(a, b) << endl;
    return 0;
}