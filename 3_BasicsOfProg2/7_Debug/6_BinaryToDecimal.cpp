// Q6. Convert given Binary number to Decimal.
// int binaryToDecimal(int b){
//     int ans;
//     int c=0;
//     while(b){
//         ans=(b % 10) * (1 << c++);
//         b/=10;
//     }
//     return ans;
// }

// SOLUTION

#include <iostream>
using namespace std;

int binaryToDecimal(int b) {
    int ans = 0;
    int i = 0;
    while (b) {
        ans = ans + (b % 10) * (1 << i++);
        b /= 10;
    }
    return ans;
}

int main() {
    int binaryInput;
    cout << "Enter a binary number: ";
    cin >> binaryInput;

    int decimalResult = binaryToDecimal(binaryInput);
    cout << "Decimal equivalent: " << decimalResult << endl;

    return 0;
}

// while(b) means until b becomes zero
