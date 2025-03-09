// ⭐⭐VERY IMPORTANT QUESTION⭐⭐

#include<iostream>
using namespace std;

void clearBitsInRange(int n, int i, int j)
{
    int a = (-1 << (i+1));
    int b = (1 << j) - 1;
    int mask = a | b;
    n = n & mask;
    cout << "After clearing Bits in Range: " << n << endl;
}

int main()
{
    int n, i, j;
    cout << "Enter a number:" << endl;
    cin >> n;
    cout << "Enter the bit range:" << endl;
    cin >> i >> j;

    clearBitsInRange(n, i, j);
    return 0;
}