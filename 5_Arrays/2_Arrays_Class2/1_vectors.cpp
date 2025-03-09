// Static array - size given
// int brr[5] = {2,4,6,8,10};

// 🔴🔴🔴🔴 IMPORTANT!! 🔴🔴🔴🔴
// For DYNAMIC ARRAYS, we use VECTOR
// No need to worry about size but memory loss possible
// Syntax vector<data_type> vector_name;
// Vector doubles it size after it gets full.
// Example: 5,7 -> size 2 (gets full)
//          5,7,10,20 -> size 4 (gets full)
//          5,7,10,20,30,40,50,60 -> size 8 (gets full)......


// INITIALISING A VECTOR

// vector<int> arr{10, 20, 30};
// 3 elements in vector -> 10, 20, 30

// vector<int> arr(10, -1);
// 10 elements all with -1 initialized

// To create a user-defined size array at runtime, we can:
// int n;
// cin >> n;
// vector<int> arr(n);

// Remember we shouldn't create an array with a user-input at runtime because it's a bad practice
// int arr[n];
// The reason why `int n; cin >> n; int arr[n];` is considered bad practice in C++ while `int n; cin >> n; vector<int> arr(n);`
// is not is related to how these two approaches handle memory allocation, storage, and error handling. Let me explain in more detail:

// 1. Array Size:
//    - `int n; cin >> n; int arr[n];`: In this approach, you are trying to create an array with a size determined at runtime based on the value of `n`. This is not standard C++, and although some compilers might allow it as an extension, it's not part of the official C++ standard.
//    - `int n; cin >> n; vector<int> arr(n);`: Here, you are using a standard C++ vector, which allows you to create a dynamic array with a size determined at runtime. This is the correct and recommended way to create a dynamic array in C++.

// 2. Memory Allocation:
//    - `int arr[n];` allocates memory on the stack. The stack memory is limited and can lead to a stack overflow if you try to allocate a large array. It's also less flexible because the array size must be known at compile-time.
//    - `vector<int> arr(n);` allocates memory on the heap. The heap memory is more flexible and suitable for dynamic memory allocation. Vectors manage their memory automatically, which means they can resize dynamically as needed, and you won't run into stack overflow issues.

// 3. Error Handling:
//    - In the first example, if `n` is a large number, it could lead to a stack overflow, causing the program to crash without a clear error message.
//    - In the second example, if `n` is too large to allocate memory on the heap, it may throw a `std::bad_alloc` exception, which can be caught and handled, providing better error reporting and more robust behavior.

// In summary, using `int arr[n];` to create an array with a runtime-determined size is not standard C++ and can lead to various issues, while using `vector<int> arr(n);` is the recommended approach for dynamic arrays in C++ because it handles memory allocation, resizing, and error handling more gracefully.


// To insert an element
// arr.push_back(5);

// To remove an element
// arr.pop_back(5);

// To determine the size of the vector array
// arr.size();

// To check if the vector array is empty or not
// arr.empty();

/*
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr;
    int ans = (sizeof(arr)/sizeof(int));  // platform-dependent output, could vary, not the write way to find the number of elements in the array
    cout<<ans<<endl;

    cout<<arr.size()<<endl;     // How many elements are currently there in the vector
    cout<<arr.capacity()<<endl; // How many elements can be stored in the vector

    return 0;
}
*/

/*
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // Creating a vector
    vector<int> arr;

    // Inserting elements
    arr.push_back(5);
    arr.push_back(6);

    // Printing
    for (int i=0; i<arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Remove/Delete
    arr.pop_back();

    // Printing
    for (int i=0; i<arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
*/

// #include <iostream>
// #include <vector>
// using namespace std;
// int main()
// {
//     // Creating a vector
//     vector<int> brr(10); // Initializing 10 elements with 0
//     cout<<"Size of brr: "<<brr.size() <<endl;  // prints 10
//     cout<<"Capacity of brr: "<<brr.capacity() <<endl;  // prints 10

//     for (int i=0; i<brr.size(); i++)
//     {
//         cout << brr[i] << " ";  // prints 10 0s
//     }
// }

// #include <iostream>
// #include <vector>
// using namespace std;
// int main()
// {
//     // Creating a vector
//     vector<int> brr(10, -1); // Initializing 10 elements with -1
//     cout<<"Size of brr: "<<brr.size() <<endl;  // prints 10
//     cout<<"Capacity of brr: "<<brr.capacity() <<endl;  // prints 10

//     for (int i=0; i<brr.size(); i++)
//     {
//         cout << brr[i] << " ";  // prints 10 -1s
//     }
// }

// _________________________________________________________________________________________________
// TAKING USER INPUT 
// #include <iostream>
// #include <vector>
// using namespace std;
// int main()
// {
//     int n;
//     cout<<"Enter the size of the vector array: ";
//     cin >> n;
//     // Creating a vector
//     vector<int> brr(n, 10);
//     cout<<"Size of brr: "<<brr.size() <<endl;
//     cout<<"Capacity of brr: "<<brr.capacity() <<endl;

//     for (int i=0; i<brr.size(); i++)
//     {
//         cout << brr[i] << " ";
//     }
// }

// __________________________________________________________________________________________

// INITIALIZING LIKE ARRAY

// #include <iostream>
// #include <vector>
// using namespace std;
// int main()
// {
//     vector<int> crr{10,20,30,40};
//     for (int i=0; i<crr.size(); i++)
//     {
//         cout << crr[i] << " ";
//     }
// }

// _____________________________________________________________________________________________
// VECTOR EMPTY OR NOT

// #include <iostream>
// #include <vector>
// using namespace std;
// int main()
// {
//     vector<int> crr;
//     cout<<"Vector crr is empty or not: "<<crr.empty() <<endl;

//     vector<int> drr(2, -1);
//     cout<<"Vector crr is empty or not: "<<drr.empty() <<endl;
// }