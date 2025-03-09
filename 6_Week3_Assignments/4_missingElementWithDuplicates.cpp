// #include <iostream>
// using namespace std;

// void findMissing(int *a, int n)
// {
//     // visited method
//     for(int i=0; i<n; i++)
//     {
//         int index = abs(a[i]);
//         if(a[index - 1] > 0)
//         {
//             a[index - 1] *= -1;
//         }
//     }

//     // all positive integers are missing
//     for(int i=0; i<n; i++)
//     {
//         if(a[i] > 0)
//         {
//             cout<<i+1<<" ";
//         }
//     }
// }

// int main()
// {
//     int n;
//     int a[] = {1,3,5,3,4};
//     n = sizeof(a)/sizeof(int);
//     findMissing (a, n);
//     return 0;
// }
// TC - O(n)
// SC - O(1)

// 1) int index = abs(1) = 1
// a[1-1] = a[0] = 1>0
// a[0]*=-1  -> 1 becomes -1
// arr = {-1,3,5,3,4}

// 2) int index = abs(3) = 3
// a[2]=5 > 0
// a[2] *=-1  -> 5 becomes -5
// arr = {-1,3,-5,3,4}

// 3) int index = abs(-5) = 5
// a[4] = 4
// a[4] *=-1   -> 4 becomes -4
// arr = {-1,3,-5,3,-4}

// 4) int index = abs(3) = 3
// a[2] = -5

// 5) int index = abs(4) = 4
// a[3] = 3
// a[3] *=-1    -> 3 becomes -3
// arr = {-1,3,-5,-3,-4}

// now the for loop
// a[i] = a[1] = 3 > 0
// cout<<1+1 = 2 -> the missing element
// _____________________________________________________________________________________________________

// 2nd method - swapping

#include <iostream>
using namespace std;

void findMissing(int *a, int n)
{
    int i=0;
    while(i < n)
    {
        int index = a[i] - 1;
        if(a[i] != a[index])
        {
            swap(a[i], a[index]);
        }
        else
        {
            i++;
        }
    }
    for(int i=0; i<n; i++)
    {
        if(a[i] != i+1)
        {
            cout << i+1 <<" ";
        }
    }
    cout << endl;
}


int main()
{
    int n;
    int a[] = {5,3,3,3,1};
    n = sizeof(a)/sizeof(int);
    findMissing (a, n);
    return 0;
}

// TC - O(N)
// SC - O(1)

