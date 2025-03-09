// 🔴🔴🔴🔴🔴 IMPORTANT!!!!! 🔴🔴🔴🔴🔴
// The in-built STL library sort function uses a combination of Quick Sort, Heap Sort, and Insertion
// Sort, so the time complexity is O(nlogn)

// O(nlogn) -> time complexity
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
#include <algorithm>    // for in-built sort
using namespace std;

bool uniqueOccurrences(vector<int> &arr)
{
    vector<int> ans;
    int size = arr.size();
    sort(arr.begin(), arr.end());
    int i=0;
    while(i<size)
    {
        int count = 1;
        for(int j=i+1; j<size; j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
            }
            else
            {
                break;
            }
        }
        ans.push_back(count);
        i = i+count;
    }
    size = ans.size();
    sort(ans.begin(), ans.end());
    for(int i=0; i<size-1; i++)
    {
        if(ans[i]==ans[i+1])
        {
            return false;
        }
    }
    return true;
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

// Time complexity- O(n^2*logn)