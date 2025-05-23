// Q5. Debug the code. 
// Question:
// Given two integers M & N, calculate and return their multiplication using recursion.
// You can only use subtraction and addition for your calculation. No other operators are allowed.
// int multiplyNumbers(int m, int n) {
//     if(n < 0)
//         return 0;
//     return m + multiplyNumbers(m,n-1);
// }

// _________________________________________________________________________________________

#include <iostream>
using namespace std;

int multiplyNumbers(int m, int n) {
    if(n <= 0)
        return 0;
    return m + multiplyNumbers(m,n-1);
}

int main()
{
    int m, n;
    cin >> m;
    cin >> n;
    cout << multiplyNumbers(m, n);
    cout << endl;
    return 0;
}