#include <iostream>
using namespace std;

int sumArr(int arr[], int n)
{
    int result = 0;
    for(int i=0; i<n; i++)
    {
        result+=arr[i];
    }
    return result;
}

int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    cout<<"Original array: " << endl;
    for(int i=0; i<10; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int total = sumArr(arr, 10);
    cout<<"Array sum: " << total;
    return 0;
}