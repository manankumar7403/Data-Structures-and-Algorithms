#include<iostream>
using namespace std;

void clearithBit(int n, int i)
{
    int mask = ~(1 << i);
    int ans = n & mask;
    cout << "After clearing " << i << " bit: " << ans << endl;
}

int main()
{
    int n, i;
    cout << "Enter a number:" << endl;
    cin >> n;
    cout << "Enter the bit:" << endl;
    cin >> i;

    clearithBit(n, i);
    return 0;
}