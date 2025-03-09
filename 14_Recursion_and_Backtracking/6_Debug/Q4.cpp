// Q4. Debug the code. This code tries to implement 🔴🔴🔴🔴string to integer converter🔴🔴🔴🔴.

// int rec(char input[],int n){
//     if(input[0] = '\0')
//         return n;
//     n = n * 10 + input[0];
//     return rec(input + 1, n);
// }

// int stringToNumber(char input[]) {
//     int n = 0;
//     return rec(input, n);
// }
// __________________________________________________________________________________

#include <iostream>
using namespace std;

int rec(char input[],int n){
    if(input[0] == '\0') // Fix
        return n;
    n = n * 10 + input[0] - 48; // Fix
    return rec(input + 1, n);
}

int stringToNumber(char input[]) {
    int n = 0;
    return rec(input,n);
}

int main() {
    char input[100];
    cout << "Enter a number as a string: ";
    cin >> input;

    int result = stringToNumber(input);
    cout << "Converted integer: " << result << endl;
    return 0;
}