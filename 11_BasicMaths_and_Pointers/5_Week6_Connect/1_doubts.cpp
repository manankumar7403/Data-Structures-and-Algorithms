// #include <iostream>
// using namespace std;
// int main()
// {
//     int arr[10];
//     int* p = &arr;    // gives error
//     return 0;
// }

// even though arr and &arr points to the same memory location, (first index of arr)
// pointer at &arr gives error
// ________________________________________________________________________________

// #include <iostream>
// using namespace std;
// int main()
// {
//     int arr[10];
//     int(*p)[10] = &arr;
//     cout << "Working fine!" << endl;  // rectifies the error
//     return 0;
// }
// ___________________________________________________________________________________

/*
Q- But why does int *p[10] = &arr doesn't run but int (*p)[10] = &arr does?
A- First of all (*p)[10] is a pointer array of 10 integers for array arr[10].

In C++, `int *p[10]` declares an array of 10 pointers to integers, while `int (*p)[10]` declares a pointer
to an array of 10 integers. Let's break down the two declarations:

1. `int *p[10]`: This declares an array of 10 pointers to integers. If you write `&arr` on the right-hand side,
    it would be trying to assign the address of an array to the array of pointers, which is not compatible.
    The correct usage would be to declare an array of 10 integers and assign the address of the array to
    each element of the array of pointers:

    int arr[10];
    int *p[10];
    
    for (int i = 0; i < 10; ++i) {
        p[i] = &arr[i];
    }

2. `int (*p)[10]`: This declares a pointer `p` to an array of 10 integers. If you write `&arr` on the
    right-hand side, it would correctly assign the address of the entire array to the pointer:

    int arr[10];
    int (*p)[10] = &arr;

So, the correct syntax depends on whether you want an array of pointers or a pointer to an array. In your
specific case, you are looking for a pointer to an array, so `int (*p)[10] = &arr` is the correct syntax.
*/
// ___________________________________________________________________________________

#include <iostream>
using namespace std;
int main()
{
    int arr[10];
    cout << arr << endl << endl;
    int(*p)[10] = &arr;
    for(int i=0; i<10; i++)
    {
        cout << p[i] << endl;
    }
    return 0;
}