#include <iostream>
using namespace std;

int bs(int a[], int start, int end, int x)
{
    while(start <= end)
    {
        int mid = start + (end-start)/2;
        if(a[mid] == x)
        {
            return mid;
        }
        else if(x > a[mid])
        {
            // search right
            start = mid+1;
        }
        else
        {
            // search left
            end = mid-1;
        }
    }
    return -1;
}

int unboundedSearch(int a[], int n, int x)
{
    if(a[0] == x)
    {
        return 0;
    }
    int i = 0;
    int j = 1;
    while(a[j] < x)
    {
        i = j;
        j = j*2;
    }
    return bs(a, i, j, x);
}

int main()
{
    int a[] = {3,4,5,6,11,13,14,15,56,70};
    int n = sizeof(a)/sizeof(int);
    int x = 56;
    int ans = unboundedSearch(a, n, x);
    cout << "Index of " << x << " is " << ans << endl;
    return 0;
}



// Suppose we want to find the index of element 56. So, x = 56
// a[0] == x is not true.

// Initialize i=0 and j=1;
// a[j] < x => a[1] = 4 < 56
// i = 1
// j = 1*2=2

// a[2] = 5 < 56
// i = 2
// j = 2*2 = 4

// a[4] = 11 < 56
// i = 4
// j = 4*2 = 8

// a[8] = 56<56 => false

// Therefore, i=4 -> starting position of binary search
//           j=8 -> ending position of binary search

// So, binary search would be applied on sub-array from index 4 to 8 to find x = 56
// Sub-array of index 4 to 8 => arr=[11, 13, 14, 15, 56]