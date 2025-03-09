#include <iostream>
using namespace std;
int main()
{
    int i, n;
    cout<<"Enter the number of digits: ";
    cin>>n;

    int arr[n];
    for (i=0; i<n; i++)
    {
        cout<<"Enter the "<<i+1<<" digit: "<<endl;
        cin>>arr[i];
    }

    double num = 0;
    for (i=0; i<n; i++)
    {
        num = num * 10 + arr[i];
    }

    cout<<"Number created from entered digits: "<<num<<endl;
    return 0;
}