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

int expSearch(int a[], int n, int x)
{
    if(a[0] == x)
    {
        return 0;
    }
    int i = 1;
    while(i < n && a[i] <= x)
    {
        i*=2; // i=i*2 or i = i << 1
    }
    return bs(a, i/2, min(i, n-1), x);
}

int main()
{
    int a[] = {3,4,5,6,11,13,14,15,56,70};
    int n = sizeof(a)/sizeof(int);
    int x = 56;
    int ans = expSearch(a, n, x);
    cout << "Index of " << x << " is " << ans << endl;
    return 0;
}



// Suppose we want to find the index of element 56. So, x = 56
// a[0] == x is not true.

// Initialize i=1;
// 1<10 && a[1]=4<=56
// i*=2 => i=2

// 2<10 && a[2]=4<=56
// i*=2 => i=4

// 4<10 && a[4]=11<=56
// i*=2 => i=8

// 8<10 && a[8]=56<=56
// i*=2 => i=16

// Now 16<10 => false so loop will terminate
// i=16
// a[8]=56
// So final sub-array would be index 8 onwards towards the right.

// In bs we will send
// bs(a, i/2, min(i, n-1), x)

// where,
// a is the array
// i/2 is the actual index 16/2 = 8 (for a[8]=56) -> starting position of the binary search
// min(i, n-1) => min(16, 9) = 9 -> ending position of the binary search
// x is the target
