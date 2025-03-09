#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the nth fibonacci num: ";
    cin >> n;
    int a = 0;
    int b = 1;
    cout<<a<<" "<<b<<" ";
    int ans;
    for(int i=2; i<n; i++)
    {
        ans = a+b;
        a=b;
        b=ans;
        cout<<b<<" ";
    }
    return 0;
}