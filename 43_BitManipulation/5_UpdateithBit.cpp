#include<iostream>
using namespace std;

void clearithBit(int& n, int i)
{
    int mask = ~(1 << i);
    n = n & mask;
}

void updateithBit(int& n, int i, int target)
{
    clearithBit(n, i);
    int mask = target << i;
    n = n | mask;
    cout << "After updating " << n << endl;
}

int main()
{
    int n, i;
    cout << "Enter a number:" << endl;
    cin >> n;
    cout << "Enter the bit:" << endl;
    cin >> i;

    updateithBit(n, i, 1);
    return 0;
}