#include<iostream>
using namespace std;

int getithBit(int n, int i)
{
    int mask = 1 << i;
    int ans = n & mask;
    if(ans == 0)
    {
        return 0;
    }
    else return 1;
}

int main()
{
    int n, i;
    cout << "Enter a number:" << endl;
    cin >> n;
    cout << "Enter the bit you want to know:" << endl;
    cin >> i;

    int ans = getithBit(n, i);
    cout << "ith bit is: " << ans << endl;
    return 0;
}