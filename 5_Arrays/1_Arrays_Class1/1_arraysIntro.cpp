#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    // DECLARING AN ARRAY
    // int arr[5];
    // cout<<arr<<endl;
    // creates an array arr of type int and size 5 and prints the hexadecimal contiguous memory location.

    // INITIALISING AN ARRAY
    // int arr[] = {1,2,3,4,5};
    // 5 continuous address

    // Static array - size given
    // int brr[5] = {2,4,6,8,10};
    // 5 continuous address

    // int crr[10] = {1,3,5,7,9};
    // first 5 values are 1,3,5,7,9
    // and the last 5 are 0

    // int drr[4] = {1,2,3,4,5};
    // gives error -too many initializers

// ________________________________________________________________________________________________

    /*
    int arr[] = {2,4,6,8,10};

    // printing value at 2nd index
    // cout<<arr[2]<<endl;

    // printing all values
    for (int i=0; i<5; i++)
    {
        cout<<arr[i]<<" ";
    }
    */
// _______________________________________________________________________________________________

// Taking user input in array

    /*
    int arr[10];
    cout<<"Enter the values in array: "<< endl;
    for(int i=0; i<10; i++)
    {
        cin>>arr[i];
    }
    cout<<"Values in the array are: "<<endl;
    for(int i=0; i<10; i++)
    {
        cout<<arr[i]<<" ";
    }
    */
// ________________________________________________________________________________________________


// Q1. Take 5 elements input in an array and print their doubles.

    /*
    int arr[5];
    cout<<"Enter the values in array: "<<endl;
    for(int i=0; i<5; i++)
    {
        cin>>arr[i];
    }
    cout<<"The double values are: "<< endl;
    for(int i=0; i<5; i++)
    {
        cout<<arr[i]*2<<" ";
    }
    */
// ________________________________________________________________________________________________

// Q2. Given array, change all elements to 1.

    /*
    int arr[5] = {1,3,5,7,9};
    for(int i=0; i<5; i++)
    {
        arr[i] = 1;
    }
    for(int i=0; i<5; i++)
    {
        cout<<arr[i]<<" ";
    }
    */

// ________________________________________________________________________________________________

// Q3. What happens to the remaining values when you put array size as 10 but only add 2 nos.?

    /*
    int arr[10] = {1,2};
    for(int i=0; i<10; i++)
    {
        cout<<arr[i]<<" ";
    }
    */

    // we get 0 in remaining positions

// ________________________________________________________________________________________________

// Q4. What values do we get when array size declared as 10 but no values are given?

    /*
    int arr[10];
    for(int i=0; i<10; i++)
    {
        cout<<arr[i]<<" ";
    }
    */

    // we get garbage values

// ________________________________________________________________________________________________

// Q5. All 0 values?

    /*
    int arr[10] = {0};
    for(int i=0; i<10; i++)
    {
        cout<<arr[i]<<" ";
    }
    */

    // we get 0 at all positions

// ________________________________________________________________________________________________

}