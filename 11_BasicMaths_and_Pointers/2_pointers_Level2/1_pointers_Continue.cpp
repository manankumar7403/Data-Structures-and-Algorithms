// ✨✨✨✨  VERY IMPORTANT ✨✨✨✨
/*
#include <iostream>
using namespace std;
int main()
{
    int arr[4] = {12, 14, 16, 18};

    cout << arr << endl;
    cout << arr[0] << endl;
    cout << &arr << endl;
    cout << &arr[0] << endl;
    // arr, &arr, and &arr[0] gives the same address (base address).

    int* p = arr;
    cout << p << endl;              // gives address of arr,&arr,&arr[0]
    cout << &p << endl;             // gives address of p
    cout << *p << endl;             // gives value stored at address of arr -> 12
    // p and &p give different address due to pointers functionality

    return 0;
}
*/
// ______________________________________________________________________________________

/*
#include <iostream>
using namespace std;
int main()
{
    int arr[4] = {12, 14, 16, 18};
    cout << *arr << endl;        // 12
    cout << arr[0] << endl;      // 12
    cout << *arr + 1 << endl;    // 13
    cout << *(arr) + 1 << endl;  // 13
    cout << *(arr + 1) << endl;  // 14
    cout << arr[1] << endl;      // 14
    cout << *(arr + 2) << endl;  // 16
    cout << arr[2] << endl;      // 16
    return 0;
}
*/
// NOTE: ✨
// arr[i] is the same as *(arr + i)
// even i[arr] is valid because it actualli is *(i + arr)
// ________________________________________________________________________________________

/*
#include <iostream>
using namespace std;
int main()
{
    int arr[4] = {12, 14, 16, 18};
    int i = 0;
    cout << arr[i] << endl;     // prints 12
    cout << i[arr] << endl;     // still prints 12
    cout << *(arr + i) << endl; // prints 12
    cout << *(i + arr) << endl; // prints 12
    return 0;
}
*/
// _________________________________________________________________________________________
/*
#include <iostream>
using namespace std;
int main()
{
    int arr[4] = {12, 14, 16, 18};
    
    // arr = arr + 2;   // gives error (some compilers)  becuase arr is located at some defined memory address, say 104, and behaves like a constant pointer.

    int* p = arr;
    p = p + 2;
    cout << *p << endl;   // doesn't give error -> gives 16

    // So we can use pointers to access a sub-part of the array

    return 0;
}
*/
// ________________________________________________________________________________________

/*
#include <iostream>
using namespace std;
int main()
{
    int arr[10];
    cout << sizeof(arr) << endl;    // 40    (10*4=40)

    int* p = arr;
    cout << sizeof(p) << endl;      // 8     (size of pointer is 8 for 64-bit systems)

    cout << sizeof(*p) << endl;      // 4    (*p=arr, arr means arr[0] which will be an int, int size is 4)

    return 0;
}
*/
// _______________________________________________________________________________________

// ✨✨✨✨✨ Character arrays ✨✨✨✨✨
// #include <iostream>
// using namespace std;

// int main()
// {
//     char ch[10] = "Babbar";
//     char* c = ch;
//     cout << c << endl;          // prints "Babbar" -> cout implementation for char is different from int.
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//     char ch[10] = "Babbar";
//     char* c = ch;

//     cout << ch << endl;             // prints Babbar
//     cout << &ch << endl;            // prints address of ch
//     cout << ch[0] << endl;          // prints B
//     cout << &c << endl;             // prints address of c
//     cout << *c << endl;             // prints B
//     cout << c << endl;              // prints Babbar
//     return 0;
// }

// *c = *(c + 0)
//    = c[0]
//    =
// ______________________________________________________________________________________________
/*
#include <iostream>
using namespace std;

int main()
{
    char name[9] = "SherBano";
    char* c = &name[0];

    cout << name << endl;                   // prints SherBano
    cout << &name << endl;                  // prints address of name
    cout << *(name + 3) << endl;            // prints r
    cout << c << endl;                      // prints SherBano
    cout << &c << endl;                     // prints address of c
    cout << *(c+3) << endl;                 // prints r
    cout << c+2 << endl;                    // prints erBano
    cout << *c << endl;                     // prints S
    cout << c+8 << endl;                    // don't have 8th index, so doesn't print anything
    return 0;
}
*/

// ____________________________________________________________________________________________
/*
#include <iostream>
using namespace std;

int main()
{   
    char ch = 'k';
    char* cptr = &ch;
    cout << cptr << endl;  // get k and then garbage values until we encounter null character.
    return 0;
}

// In case of string, the null character is present at the end, but here we will keep on going until
// we encounter one, that's why we get garbage values.
*/
// _____________________________________________________________________________________________

#include <iostream>
using namespace std;

int main()
{
    char name[10] = "Babbar";
    cout << name << endl;

    // char* c = "Babbar";
    // cout << c << endl; 
    return 0;
}

// char* c = "Babbar";
//     cout << c << endl;

// This is a bad practice and also gives error in modern g++ compilers.
