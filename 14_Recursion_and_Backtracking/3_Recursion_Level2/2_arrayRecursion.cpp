/*
#include <iostream>
using namespace std;

void print(int arr[], int n, int i)
{
    // Base case
    if(i >= n)
    {
        return;
    }

    // 1 case solve kardo
    cout << arr[i] << " ";

    // baaki recursion sambhal lega
    print(arr, n, i+1);         // i++ doesn't work as i is being copied first and then function is called so its never actually incremented, but ++i will work just fine.
}

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int n = 5;
    int i = 0;
    print(arr, n, i);
    return 0;
}
*/

// OR DO THIS FOR SAME OUTPUT

#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    // Base case
    if(n == 0)
    {
        return;
    }

    // 1 case solve kardo
    cout << arr[0] << " ";

    // baaki recursion sambhal lega
    print(arr+1, n-1);
}

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int n = 5;
    int i = 0;
    print(arr, n);
    return 0;
}