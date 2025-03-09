#include <iostream>
#include <climits>
using namespace std;

int getMax(int num[], int n)
{
    int maxi = INT_MIN;
    for(int i=0; i<n; i++)
    {
        maxi = max(maxi, num[i]);
    }
    return maxi;
}

int getMin(int num[], int n)
{
    int mini = INT_MAX;
    for(int i=0; i<n; i++)
    {
        mini = min(mini, num[i]);
    }
    return mini;
}


int main()
{
    cout<<"Enter the size of the array(max 10): ";
    int size;
    cin>>size;
    cout<<"Enter the elements in the array: "<<endl;
    int num[10];
    for(int i=0; i<size; i++)
    {
        cin>>num[i];
    }
    cout<<"Maximum element is: "<<getMax(num,size)<<"."<<endl;
    cout<<"Minimum element is: "<<getMin(num,size)<<"."<<endl;
    return 0;
}