#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void SS(int low, int high) {
    vector<bool> isPrime(high-low+1, true);

    // Step 2: Mark non-primes using the Sieve of Eratosthenes algorithm
    for (int currentPrime = 2; currentPrime * currentPrime <= high; currentPrime++) {
        // Initialize sm (starting point) to the first multiple of currentPrime in the range [low, high]
        int startingMultiple = max(currentPrime * currentPrime, (low / currentPrime) * currentPrime);
        
        // If the starting point is below the lower limit, move it to the next multiple
        if (startingMultiple < low) {
            startingMultiple += currentPrime;
        }

        // Mark all multiples of currentPrime in the range [low, high] as non-prime
        for (int i = startingMultiple; i <= high; i += currentPrime) {
            isPrime[i - low] = false;  // Adjust the index to the range [0, high - low]
        }
    }
    cout << "Prime numbers in the range [" << low << ", " << high << "]: ";
    for (int i = max(low, 2); i <= high; i++) {
        if (isPrime[i - low]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int low, high;
    cout << "Enter the lower limit: ";
    cin >> low;
    cout << "Enter the upper limit: ";
    cin >> high;
    SS(low, high);
    return 0;
}

// Time Complexity: O((high-low+1) * log(log(high)))
// Space Complexity: O(high-low+1)