// Q1 Debug the code. This code is implementation for binary search.

// #include <iostream>
// using namespace std;

// int binarySearch(int arr[], int left, int right, int x) {
//     if (right >= left) {
//         int mid = (left + right) / 2;
//         if (arr[mid] == x)
//             return mid;
//         else if (arr[mid] > x)
//             binarySearch(arr, left, mid - 1, x);
//         else
//             binarySearch(arr, mid + 1, right, x);
//     }
//     return -1;
// }

// int main() {
//     int arr[] = { 2, 3, 4, 10, 40 };
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int x = 10;
//     int result = binarySearch(arr, 0, n - 1, x);
//     if (result == -1)
//         cout << "Element not found.";
//     else
//         cout << "Element found at index " << result << endl;
//     return 0;
// }
// ___________________________________________________________________________________________

// SOLUTION:

#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int x)
{
    while (left <= right)
    {
        int mid = left + (right - left)/2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] > x)
        {
            return binarySearch(arr, left, mid - 1, x);
        }
        else
        {
            return binarySearch(arr, mid + 1, right, x);
        }
        mid = left + (right - left)/2;
    }
    return -1;
}

int main()
{
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1)
        cout << "Element not found.";
    else
        cout << "Element found at index " << result << endl;
    return 0;
}