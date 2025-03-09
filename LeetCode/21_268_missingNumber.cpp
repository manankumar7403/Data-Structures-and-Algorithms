// Given an array nums containing n distinct numbers in the range [0, n], return the only number in the
// range that is missing from the array. 

// Example 1:
// Input: nums = [3,0,1]
// Output: 2
// Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing
// number in the range since it does not appear in nums.

// Example 2:
// Input: nums = [0,1]
// Output: 2
// Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing
// number in the range since it does not appear in nums.

// Example 3:
// Input: nums = [9,6,4,2,3,5,7,0,1]
// Output: 8
// Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing
// number in the range since it does not appear in nums.

// Constraints:
// n == nums.length
// 1 <= n <= 104
// 0 <= nums[i] <= n
// All the numbers of nums are unique.

#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int>& nums)
{
    int n = nums.size();
    int total_sum = (n*(n+1))/2;
    for(auto x: nums)
    {
        total_sum -= x;
    }
    return total_sum;
}

int main()
{
    int n;
    cout << "Enter the size of the vector array: " << endl;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements in the vector array: " << endl;    
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }

    int result = missingNumber(nums);
    cout << result << endl;
    return 0;
}

// Time complexity - O(n)
// Space complexity - O(1)