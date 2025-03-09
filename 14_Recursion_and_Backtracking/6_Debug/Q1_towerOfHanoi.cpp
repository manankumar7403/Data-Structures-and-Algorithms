// Q1. Debug the code. This is 🔴🔴🔴🔴 Tower of Hanoi Problem. 🔴🔴🔴🔴
// void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
//     if (n == 0) {
//         return;
//     }
//     towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
//     cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;
//     towerOfHanoi(n - 1, aux_rod, from_rod, to_rod);
// }
// ________________________________________________________________________________

#include <iostream>
using namespace std;

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 0) {
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);  // Corrected order of arguments
}

int main() {
    int n = 3;
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}


// TC -> O(2^n)
// SC -> O(n)