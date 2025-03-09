// 🔴🔴LEETCODE 3229 -> Minimum Operations To Make Array Equal To Target (Contest 407)🔴🔴
/*
You are given two positive integer arrays nums and target, of the same length.
In a single operation, you can select any 
subarray of nums and increment or decrement each element within that subarray by 1.
Return the minimum number of operations required to make nums equal to the array target.

Example 1:
Input: nums = [3,5,1,2], target = [4,6,2,4]
Output: 2
Explanation:
We will perform the following operations to make nums equal to target:
- Increment nums[0..3] by 1, nums = [4,6,2,3].
- Increment nums[3..3] by 1, nums = [4,6,2,4].

Example 2:
Input: nums = [1,3,2], target = [2,1,4]
Output: 5
Explanation:
We will perform the following operations to make nums equal to target:
- Increment nums[0..0] by 1, nums = [2,3,2].
- Decrement nums[1..1] by 1, nums = [2,2,2].
- Decrement nums[1..1] by 1, nums = [2,1,2].
- Increment nums[2..2] by 1, nums = [2,1,3].
- Increment nums[2..2] by 1, nums = [2,1,4].

Constraints:
1 <= nums.length == target.length <= 10^5
1 <= nums[i], target[i] <= 10^8
*/

/*
// ⭐⭐Greedy Approach⭐⭐

#include<iostream>
#include<vector>
using namespace std;

long long minimumOperations(vector<int> &nums, vector<int> &target)
{
    int n = nums.size();
    vector<int> diff(n, 0);
    for (int i = 0; i < n; i++)
    {
        diff[i] = nums[i] - target[i]; // storing the difference
    }
    long long ans = 0, incOp = 0, decOp = 0;
    for (int i = 0; i < n; i++)
    {
        if (diff[i] > 0) // handling positive difference subarray separately
        {
            if (incOp < diff[i]) // if the next element in the positive subarray is higher you have to calculate the extra bar len
            {
                int extra = diff[i] - incOp; // extra op is the dfference of diff[i] and the current bar(incOp)
                ans = ans + extra;           // store the ops in ans
            }
            incOp = diff[i]; // now that incOp bar length would be replaced by the highest bar
            decOp = 0;       // decOp will be 0 as negative element subarray is handled separatley and starts from 0
        }
        else if (diff[i] < 0) // handling negative difference subarray separately
        {
            if (decOp < -diff[i]) // if the next element in the -ve subarray is greater you have to calculate the extra bar len
            {
                int extra = -diff[i] - decOp; // using - everywhere to get +ve ans, extra op is diff b/w diff[i] and decOp
                ans = ans + extra;            // store the ops in ans
            }
            decOp = -diff[i]; // now that decOp bar length would be replaced by the highest bar
            incOp = 0;        // incOp will be 0 as positive element subarray is handled separatley and starts from 0
        }
        else
        {
            incOp = decOp = 0; // if diff = 0, put incOp and decOp bar as 0 to handle the upcoming increase or decrease diff[i]
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of the array:" << endl;
    cin >> n;
    vector<int>nums(n);
    cout << "Enter the nums array:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }
    vector<int>target(n);
    cout << "Enter the target array:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> target[i];
    }
    cout << "Minimum number of operations: " << minimumOperations(nums, target) << endl;; 
    return 0;
}
*/
// TC -> O(n)
// SC -> O(n)

// ________________________________________________________________________________________________________________


// ⭐⭐Greedy Approach (Space Optimized)⭐⭐

#include<iostream>
#include<vector>
using namespace std;

long long minimumOperations(vector<int> &nums, vector<int> &target)
{
    int n = nums.size();
    long long ans = 0, incOp = 0, decOp = 0;
    for (int i = 0; i < n; i++)
    {
        int diff = nums[i] - target[i]; // storing the difference
        if (diff > 0)                   // handling positive difference subarray separately
        {
            if (incOp < diff) // if the next element in the positive subarray is higher you have to calculate the extra bar len
            {
                int extra = diff - incOp; // extra op is the dfference of 'diff' and the current bar(incOp)
                ans = ans + extra;        // store the ops in ans
            }
            incOp = diff; // now that incOp bar length would be replaced by the highest bar
            decOp = 0;    // decOp will be 0 as negative element subarray is handled separatley and starts from 0
        }
        else if (diff < 0) // handling negative difference subarray separately
        {
            if (decOp < -diff) // if the next element in the -ve subarray is greater you have to calculate the extra bar len
            {
                int extra = -diff - decOp; // using - everywhere to get +ve ans, extra op is diff b/w diff and decOp
                ans = ans + extra;         // store the ops in ans
            }
            decOp = -diff; // now that decOp bar length would be replaced by the highest bar
            incOp = 0;     // incOp will be 0 as positive element subarray is handled separatley and starts from 0
        }
        else
        {
            incOp = decOp = 0; // if diff = 0, put incOp and decOp bar as 0 to handle the upcoming increase or decrease diff[i]
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of the array:" << endl;
    cin >> n;
    vector<int>nums(n);
    cout << "Enter the nums array:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }
    vector<int>target(n);
    cout << "Enter the target array:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> target[i];
    }
    cout << "Minimum number of operations: " << minimumOperations(nums, target) << endl;; 
    return 0;
}

// TC -> O(n)
// SC -> O(1)
