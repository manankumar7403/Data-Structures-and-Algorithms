#include <iostream>
using namespace std;
int main()
{
    int arr[8] = {10,20,30,40,50,60,70,80};
    int size = 8;
    int start = 0;
    int end = size-1;

    while(start <= end)
    {
        // swap(arr[start], arr[end]);      // in-built

        // for self-built
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        
        start++;
        end--;
    }

    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}