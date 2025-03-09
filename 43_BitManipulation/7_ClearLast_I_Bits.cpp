#include<iostream>
using namespace std;

void clearLastIBits(int n, int i)
{
    int mask = (-1 << i);
    n = n & mask;
    cout << "After clearing last " << i << " bits: " << n << endl;
}

int main()
{
    int n, i;
    cout << "Enter a number:" << endl;
    cin >> n;
    cout << "Enter the bit:" << endl;
    cin >> i;

    clearLastIBits(n, i);
    return 0;
}