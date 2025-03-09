// ⭐⭐Important⭐⭐
// For Finding the bit we do: &1
// For setting the bit we do: |1

#include<iostream>
using namespace std;

void setithBit(int n, int i)
{
    int mask = 1 << i;
    int ans = n | mask;
    cout << "After setting " << i << " bit: " << ans << endl;
}

int main()
{
    int n, i;
    cout << "Enter a number:" << endl;
    cin >> n;
    cout << "Enter the bit:" << endl;
    cin >> i;

    setithBit(n, i);
    return 0;
}