// Given an array of integers nums, calculate the pivot index of this array.
// The pivot index is the index where the sum of all the numbers strictly to the left of the index is
// equal to the sum of all the numbers strictly to the index's right.
// If the index is on the left edge of the array, then the left sum is 0 because there are no elements
// to the left. This also applies to the right edge of the array.
// Return the leftmost pivot index. If no such index exists, return -1.

// Example 1:
// Input: nums = [1,7,3,6,5,6]
// Output: 3
// Explanation:
// The pivot index is 3.
// Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
// Right sum = nums[4] + nums[5] = 5 + 6 = 11

// Example 2:
// Input: nums = [1,2,3]
// Output: -1
// Explanation:
// There is no index that satisfies the conditions in the problem statement.

// Example 3:
// Input: nums = [2,1,-1]
// Output: 0
// Explanation:
// The pivot index is 0.
// Left sum = 0 (no elements to the left of index 0)
// Right sum = nums[1] + nums[2] = 1 + -1 = 0
 

// Constraints:
// 1 <= nums.length <= 10^4
// -1000 <= nums[i] <= 1000

#include <iostream>
#include <vector>
using namespace std;

int pivotIndex(vector<int>& nums)
{
    // LeftSum + Element at PivotIndex + rightSum = totalSum
    // Ele at pivotIndex = totalSum - 2leftSum (because , leftSum = rightSum)
    // now return i when above is true

    int totalSum = 0;
    for(int i=0; i<nums.size(); i++)
    {
        totalSum = totalSum + nums[i];
    }

    int leftSum = 0;
    for(int i=0; i<nums.size(); i++)
    {
        if(nums[i] == totalSum - 2 * leftSum)
        {
            return i;
        }
        leftSum = leftSum + nums[i];
    }
    return -1;
}

int main()
{
    int n;
    cout << "Enter the size of the vector: " << endl;
    cin >> n;
    vector<int>nums(n);
    cout << "Enter the elements in the vector: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }
    cout << "Pivot index is " << pivotIndex(nums) << endl;
    return 0;
}

// T.C. - O(N)
// S.C. - O(1)

// __________________________________________________________________________________________

// Explanation: nums = [1, 7, 3, 6, 5, 6]

// totalSum = totalSum + nums[i] = 1+7+3+6+5+6 = 28

// leftSum = 0

// i = 0 to 5
// 1) i = 0
//     nums[i] == totalSum - 2 * leftSum ?
//     1 == 28 - 2*0 = 28 -> False
//     leftSum = leftSum + nums[i] = 0 + 1 = 1

// 2) i = 1
//     nums[i] == totalSum - 2 * leftSum ?
//     7 == 28 - 2*1 = 26 -> False
//     leftSum = leftSum + nums[i] = 1 + 7 = 8

// 3) i = 2
//     nums[i] == totalSum - 2 * leftSum ?
//     3 == 28 - 2*8 = 12 -> False
//     leftSum = leftSum + nums[i] = 8 + 3 = 11

// 4) i = 3
//     nums[i] == totalSum - 2 * leftSum ?
//     6 == 28 - 2*11 = 6 -> True
//     return i

//     Therefore, returns 3


