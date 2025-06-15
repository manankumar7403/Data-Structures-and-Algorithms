// We need to left rotate an array by 1 element.
// Example arr = [1,2,3,4,5]
// Left rotated = [2,3,4,5,1]

#include <iostream>
#include <vector>
using namespace std;

void leftRotate(vector<int> &arr)
{
    int temp = arr[0];
    for(int i=1; i<arr.size(); i++)
    {
        arr[i-1] = arr[i];
    }
    arr[arr.size()-1] = temp;
}

int main()
{
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements in the array: " << endl;
    for(int i=0; i<arr.size(); i++)
    {
        cin >> arr[i];
    }
    cout << "The array is: " << endl;
    for(int i=0; i<arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    leftRotate(arr);

    cout << "The left rotated array is: " << endl;
    for(int i=0; i<arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

// here, I have not returned arr in the leftRotate function because we are just modifying 
// the same arr and not returning an integer, the modified arr could be directly accessed
// by calling the leftRotate function in the main function.


// Using array
// #include<bits/stdc++.h>

// using namespace std;
// void solve(int arr[], int n) {
//   int temp = arr[0]; // storing the first element of array in a variable
//   for (int i = 0; i < n - 1; i++) {
//     arr[i] = arr[i + 1];
//   }
//   arr[n - 1] = temp; // assigned the value of variable at the last index
//   for (int i = 0; i < n; i++) {
//     cout << arr[i] << " ";
//   }

// }
// int main() {
//   int n=5;
  
//   int arr[]= {1,2,3,4,5};
//   solve(arr, n);
// }
