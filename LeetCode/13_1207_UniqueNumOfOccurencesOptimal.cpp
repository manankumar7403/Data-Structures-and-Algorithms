// O(n) -> time complexity
// O(n) -> space complexity

// Example 1:
// Input: arr = [1,2,2,1,1,3]
// Output: true
// Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.

// Example 2:
// Input: arr = [1,2]
// Output: false

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool uniqueOccurrences(vector<int> &arr)
{
    unordered_map<int, int>freq;
    for(auto x: arr)
    {
        freq[x]++;
    }

    unordered_set<int> s;
    for(auto x: freq)
    {
        s.insert(x.second);
    }
    return freq.size() == s.size();
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements in the array: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bool result = uniqueOccurrences(arr);
    
    if (result) {
        cout << "The number of occurrences of each value is unique." << endl;
    } else {
        cout << "The number of occurrences of some values is not unique." << endl;
    }

    return 0;
}

// Time Complexity- O(n+m)