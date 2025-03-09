#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    if(n<0)
    {
        cout<<"Enter a positive number!";
        return 1;
    }

    vector<int> binaryno;

    if(n==0)
    {
        binaryno.push_back(0);
    }

    while(n>0)
    {
        binaryno.push_back(n%2);
        n=n/2;
    }

    for(int i = binaryno.size() - 1; i>=0; i--)
    {
        cout<<binaryno[i];
    }
    cout<<endl;
    return 0;
}