// 🔴🔴🔴🔴 IMPORTANT!! 🔴🔴🔴🔴
// IN ARRAYS, WE HAVE PASS BY REFERENCE, ALWAYS.
// It means we are not creating a copy but passing the address of the original array to the
// function, meaning we are always working on the original array.
// WOULD UNDERSTAND MORE CLEARLY WHEN LEARNING ABOUT POINTERS.
// Remember, in pass by value we used to create a copy of the variable and perform
// operations on the copy.

// In pass by reference concept, we are not creating a different copy but using the same array to
// perform the operations. You change, modify, update the ORIGINAL ARRAY ONLY. 
// Also note, that in the main function if we name the array 'arr', we can call it by some
// different name in the function say 'brr'.

// sizeof() determines the total size of the array (memory it is occupying), not the total elements.
// Example:
// int arr[10] = {1,2,3};
// sizeof(arr)/sizeof(int) = (4*10)/(4) = 10

// As we can't determine the size of the array elements, how many actual elements are there in
// the array, it's a good practice to also take the input size while creating array.


// #include <iostream>
// using namespace std;

// void printArray(int arr[], int size)
// {
//     for(int i=0; i<size; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout<<endl;
// }

// void inc(int arr[], int size)
// {
//     arr[0] = arr[0] + 10;
//     printArray(arr, size);
// }

// int main()
// {
//     int arr[] = {5,6};
//     int size = 2;
//     inc(arr, size);
//     printArray(arr, size);
// }
// We get 15 6 in both the main function and the printArray function

#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
}

void inc(int arr[], int size)
{
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    printArray(arr, size);
}

int main()
{
    int arr[] = {1,2,3};
    int size = 3;
    inc(arr, size);
    printArray(arr, size);
}


