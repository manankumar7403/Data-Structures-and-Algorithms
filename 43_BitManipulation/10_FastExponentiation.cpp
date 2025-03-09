#include<iostream>
using namespace std;

int powerOptimized(int a, int n)
{
    int ans = 1;
    while(n > 0)
    {
        int last_bit = (n & 1);
        if(last_bit)
        {
            ans = ans * a;
        }
        a = a * a;
        n = n >> 1;
    }
    return ans;
}

int main()
{
    int a, n;
    cout << "Enter the number:" << endl;
    cin >> a;
    cout << "Enter the power:" << endl;
    cin >> n;
    cout << powerOptimized(a, n);
}

// TC -> O(logn)
// SC -> O(1)