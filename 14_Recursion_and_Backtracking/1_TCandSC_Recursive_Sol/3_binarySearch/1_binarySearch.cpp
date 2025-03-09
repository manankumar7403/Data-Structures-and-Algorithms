#include <iostream>
using namespace std;

int BS(int a[], int key, int start, int end)
{
    if(start > end)
    {
        return -1;
    }
    int mid = start + (end-start)/2;
    if(a[mid] == key)
    {
        return mid;
    }
    else if(key > a[mid])
    {
        return BS(a, key, mid+1, end);
    }
    else
    {
        return BS(a, key, start, mid-1);
    }
}

int main()
{
    int a[10] = {1, 7, 9, 12, 15, 21, 13, 18, 4, 6};
    int key = 18;
    int start = 0;
    int end = 9;
    cout << key << " found at array index " << BS(a,key,start,end);
    cout << endl;
    return 0;
}

// TC -> O(logn)
// SC -> O(logn)