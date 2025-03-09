#include <iostream>
using namespace std;

void update(int arr[], int n)
{
    cout << "Inside the function" << endl;

    // updating the array's first element
    arr[0] = 120;

    for(int i=0; i<3; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout << "Going back to the main function" << endl;
}

int main()
{
    int arr[3] = {1,2,3};
    update(arr,3);
    for(int i=0; i<3; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
    return 0;
}

// array passed by reference so updated in both 'update' and 'main' function.

// variables are passed by value (usually) -> void function (int x)
// sometimes also by reference -> void function (int &x)

// Arrays in C++ are typically passed by reference (or more accurately, by pointer) by default.
// When you pass an array to a function, you are generally passing a pointer to the first
// element of the array, so changes made to the array inside the function will affect the
// original array. For example:
// void modifyArray(int arr[], int size) {
//     for (int i = 0; i < size; i++) {
//         arr[i] = 0; // Changes will affect the original array.
//     }
// }
