// Q2. Print full pyramid like an Equilateral Triangle.
// #include <iostream>
// using namespace std;
// int main()
// {
// int k, n;
// cout << "Enter the number of rows : ";
// cin >> n;
// cout << " ";
// for (int i=1; i<=n; i++)
// {

// for (int j=1; j<=n-i; j++)
// cout << " ';

// for (j=1,k=i-1; j<=2*i-1; j++,k--)
// {
// if (1 || j <= k)
// cout << j;
// else
// cout << k;
// }
// cout << endl;

// cout << " ";

// }
// return 0;
// }

// SOLUTION
#include<iostream>
using namespace std;
int main()
{
    int rows;
    cout<<"Enter the number of rows: ";
    cin>>rows;
    for (int i=1; i<=rows; i++)
    {
        for(int j=1; j<=rows-i; j++)
        {
            cout<<"  ";
        }

        for(int j=1; j<i+1; j++)
        {
            cout<<j<<" ";
        }

        int ele = (i-1);
        for(int j=1; j<i; j++)
        {
            cout<<ele--<<" ";
        }
        cout<<endl;
    }
}