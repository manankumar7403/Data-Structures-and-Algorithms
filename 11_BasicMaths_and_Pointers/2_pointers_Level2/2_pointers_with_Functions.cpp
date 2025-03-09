/*
#include <iostream>
using namespace std;

void solve(int arr[])
{
    cout << "Size inside solve function: " << sizeof(arr) << endl;  // 8
}

int main()
{
    int arr[10] = {1, 2, 3, 4};
    cout << "Size inside main function: " << sizeof(arr) << endl;   // 40
    solve(arr);
    return 0;
}
*/
// ________________________________________________________________________________________
/*
#include <iostream>
using namespace std;

void solve(int arr[])
{
    cout << "Size inside the solve function: " << sizeof(arr) << endl;   // 8
    cout << "arr: " << arr << endl;    // address of arr defined in main function
    cout << "&arr: " << &arr << endl;  // different, address of pointer arr
    arr[0] = 50;                       // updating value of arr[0] to 50 from 1
}

int main()
{
    int arr[10] = {1,2,3,4};
    cout << "Size inside the main function: " << sizeof(arr) << endl;   // 40

    cout << "arr: " << arr << endl;            // address of arr
    cout << "&arr: " << &arr << endl;          // same, address of arr = address of &arr

    // printing array inside the main function
    for(int i=0; i<10; i++)
    {
        cout << arr[i] << " ";          // 1 2 3 4 0 0 0 0 0 0
    }
    cout << endl;
    cout << endl << endl << "Now calling the solve function: " << endl;

    solve(arr);

    cout << "Returning to main function: " << endl;

    for(int i=0; i<10; i++)
    {
        cout << arr[i] << " ";            // 50 2 3 4 0 0 0 0 0 0
    }
    cout << endl;
    
    return 0;
}
*/
// ________________________________________________________________________________________

#include <iostream>
using namespace std;

void update(int *p)
{
    cout <<"Address stored inside p is: " << p << endl;
    cout <<"Address of p is: " << &p << endl;
    *p = *p + 10;
}

int main()
{
    int a = 5;
    cout <<"Address of a is: " << &a << endl;
    int* ptr = &a;
    cout <<"Address stored in ptr is: " << ptr << endl;
    cout <<"Address of ptr is: " << &ptr << endl;
    update(ptr);
    cout <<"Value of a is: " << a << endl;     // prints 15

    return 0; 
}