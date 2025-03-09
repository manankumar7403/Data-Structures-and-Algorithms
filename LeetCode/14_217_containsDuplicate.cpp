// Given an integer array nums, return true if any value appears at least twice in the array,
// and return false if every element is distinct.
// Example 1:

// Input: nums = [1,2,3,1]
// Output: true
// Example 2:

// Input: nums = [1,2,3,4]
// Output: false
// Example 3:

// Input: nums = [1,1,1,3,3,4,3,2,4,2]
// Output: true

// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;

// bool containsDuplicate(vector<int>& nums) {
//     sort(nums.begin(), nums.end());
//     int n = nums.size()-1;
//     for(int i=0; i<n; i++)
//     {
//         if(nums[i] == nums[i+1])
//         {
//             return true;
//         }
//     }
//     return false;
// }

// int main() {
//     int n;
//     cout << "Enter the number of elements in the array: ";
//     cin >> n;
    
//     vector<int> nums(n);
//     cout << "Enter the elements in the array: " << endl;
//     for (int i = 0; i < n; i++) {
//         cin >> nums[i];
//     }

//     bool result = containsDuplicate(nums);
    
//     if (result) {
//         cout << "One value appears atleast twice." << endl;
//     } else {
//         cout << "No value appears atleast twice." << endl;
//     }

//     return 0;
// }
// Time Complexity - O(nlogn)

// ___________________________________________________________________________

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
    for(int num: nums)
    {
        if(seen.count(num) > 0)
        {
            return true;
        }
        else
        {
            seen.insert(num);
        }
    }
    return false;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter the elements in the array: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    bool result = containsDuplicate(nums);
    
    if (result) {
        cout << "One value appears atleast twice." << endl;
    } else {
        cout << "No value appears atleast twice." << endl;
    }
    return 0;
}

// Time complexity - O(n)

// if (seen.count(num) > 0): This line checks whether the current element num is already
// present in the seen unordered_set. The count function is used to determine how many elements
// in the set have the same value as num. If count returns a value greater than 0, it means
// that num is already in the set, indicating a duplicate.

// seen.insert(num);: If the current element num is not a duplicate, it is inserted into the
// seen unordered_set using the insert method. This allows the code to keep track of elements
// it has seen during the loop.

// Example:
// Input: nums = [1,2,3,1]
// Output: true

// Initially, 'seen' unordered set is empty.
// 1) seen.count(1) > 0 ? No, its not there already, so seen.insert(1) -> 1 is inserted in seen.
// 2) seen.count(2) > 0 ? No, its not there already, so seen.insert(2) -> 2 is inserted in seen.
// 3) seen.count(3) > 0 ? No, its not there already, so seen.insert(3) -> 3 is inserted in seen.
// 4) seen.count(1) > 0 ? Yes, 1 is there already, so returns true -> indicating a duplicate.