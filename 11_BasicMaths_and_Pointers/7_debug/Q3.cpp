// Q3. Debug the code. Why is the code not returning the expected output?
// int* foo() {
//     int x = 10;
//     int* p = &x;
//     return p;
// }

// int main() {
//     int* q = foo();
//     cout << *q << endl; // Expected output: 10, Actual output: some random value
//     return 0;
// }
// _________________________________________________________________________________

// THE CODE GIVEN IN THE QUESTION WORKS AS EXPECTED

// #include <iostream>
// using namespace std;

// int* foo() {
//     int x = 10;
//     int* p = &x;
//     return p;
// }

// int main() {
//     int* q = foo();
//     cout << *q << endl;
//     return 0;
// }

// OR

#include <iostream>
using namespace std;

int* foo() {
    int* p = new int;
    *p = 10;
    return p;
}

int main() {
    int* q = foo();
    cout << *q << endl;
    return 0;
}