// ⭐⭐Important Question⭐⭐

#include<iostream>
using namespace std;

bool checkPowerOf2(int n)
{
    if((n & (n-1)) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int n;
    cout << "Enter the number:" << endl;
    cin >> n;
    if(checkPowerOf2(n))
    {
        cout << n << " is a power of 2." << endl;
    }
    else
    {
        cout << n << " is not a power of 2." << endl;
    }
    return 0;
}