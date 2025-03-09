#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int n;
    cout<<"Enter a number: ";
    cin >> n;
    int ans = 1;
    bool flag = false;
    for(int i=0; i<=30; i++)
    {
        if(ans == n)
        {
            flag = true;
            break;
        }
        if(ans < INT_MAX/2)
        {
            ans = ans * 2;
        }
    }
    cout<<flag;
}

// _________________________________________________________________
// 2nd method  🔴🔴🔴🔴🔴🔴 VERY IMPORTANT!!! 🔴🔴🔴🔴🔴🔴

// #include <iostream>
// #include <climits>
// using namespace std;
// int main()
// {
//     int n;
//     cout<<"Enter a number: ";
//     cin >> n;
//     bool ans = (n>0 && (n&(n-1))==0);
//     cout << ans << endl;
//     return 0;
// }