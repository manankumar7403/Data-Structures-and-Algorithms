// ⭐⭐LEETCODE 416 PARTITION EQUAL SUBSET SUM⭐⭐
/*
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in
both subsets is equal or false otherwise.

Example 1:
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:
Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.

Constraints:
1 <= nums.length <= 200
1 <= nums[i] <= 100
*/
// ___________________________________________________________________________________________________________________

// 🔴🔴SOLVE USING RECURSION🔴🔴
/*
#include <iostream>
#include <vector>
using namespace std;

bool solveUsingRecursion(int index, vector<int> &nums, int target)
{
    // Base case
    int n = nums.size();
    if (index >= n)
        return false;
    if (target < 0)
        return false;
    if (target == 0)
        return true;

    bool include = solveUsingRecursion(index + 1, nums, target - nums[index]);
    bool exclude = solveUsingRecursion(index + 1, nums, target);
    return (include || exclude);
}

bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }

    // if sum is odd then there cannot be two subsets with their sum = sum/2
    if (sum & 1)
        return false;

    int target = sum / 2;
    int index = 0;
    bool ans = solveUsingRecursion(index, nums, target);
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of the nums array: " << endl;
    cin >> n;
    vector<int>nums(n);
    cout << "Enter the elements in the nums array: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }
    if(canPartition(nums))
    {
        cout << "Two subsets with equal sum found" << endl;
    }
    else
    {
        cout << "Not possible" << endl;
    }
    return 0;
}
*/
// _______________________________________________________________________________________________________________________

// 🔴🔴MEMOIZATION (Top-Down)🔴🔴
/*
#include <iostream>
#include <vector>
using namespace std;
bool solveUsingMem(int index, vector<int> &nums, int target, vector<vector<int>> &dp)
{
    // Base case
    int n = nums.size();
    if (index >= n)
        return false;
    if (target < 0)
        return false;
    if (target == 0)    // we have to store 1 at 0 column as target(column) at 0 is true(1)
        return true;

    // Step2: Check if the answer is already present in the dp or not
    if (dp[index][target] != -1)
    {
        return dp[index][target];
    }

    bool include = solveUsingMem(index + 1, nums, target - nums[index], dp);
    bool exclude = solveUsingMem(index + 1, nums, target, dp);

    // Step3: Store the answer in dp and return
    dp[index][target] = (include || exclude);
    return dp[index][target];
}

bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }

    // if sum is odd then there cannot be two subsets with their sum = sum/2
    if (sum & 1)
        return false;

    int target = sum / 2;
    int index = 0;

    // Step1: Create the dp array
    vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
    bool ans = solveUsingMem(index, nums, target, dp);
    return ans;
}
int main()
{
    int n;
    cout << "Enter the size of the nums array: " << endl;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements in the nums array:";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    if (canPartition(nums))
    {
        cout << "Two subsets with equal sum found" << endl;
    }
    else
    {
        cout << "Not possible" << endl;
    }
    return 0;
}
*/
// ____________________________________________________________________________________________________________________

// 🔴🔴TABULATION (Bottom-Up)🔴🔴
/*
#include <iostream>
#include <vector>
using namespace std;

bool solveUsingTab(vector<int> &nums, int target)
{
    int n = nums.size();
    // Step1: Create the dp array
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    // Step2: Check the Base case
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }

    // Step3: Main logic of iteration
    for (int index = n - 1; index >= 0; index--)
    {
        for (int t = 1; t <= target; t++)
        {
            bool include = 0;
            if (t - nums[index] >= 0)
                include = dp[index + 1][t - nums[index]];
            bool exclude = dp[index + 1][t];
            dp[index][t] = (include || exclude);
        }
    }
    return dp[0][target];
}

bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }

    // if sum is odd then there cannot be two subsets with their sum = sum/2
    if (sum & 1)
        return false;

    int target = sum / 2;
    int index = 0;
    bool ans = solveUsingTab(nums, target);
    return ans;
}
int main()
{
    int n;
    cout << "Enter the size of the nums array: " << endl;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements in the nums array:";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    if (canPartition(nums))
    {
        cout << "Two subsets with equal sum found" << endl;
    }
    else
    {
        cout << "Not possible" << endl;
    }
    return 0;
}
*/
// ____________________________________________________________________________________________________________________

/*
// 🔴🔴Space Optimized Approach -1 O(m+n)🔴🔴
#include <iostream>
#include <vector>
using namespace std;
// A space optimization solution will include a solution of 2 1d arrays instead of 2d array reducing the space complexity
// from O(mxn) to O(m+n).
// dp[index][t] is dependent on dp[index+1][t-nums[index]] and dp[index+1][t]. So we need to focus on index+1 only, therefore
// we require a 'curr' array and a 'next' array.

bool solveUsingSO(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<int> curr(target + 1, 0);
    vector<int> next(target + 1, 0);
    // 0th index of every row should be marked as 1
    // for(int i=0; i<n; i++)
    // {
    //     dp[i][0] = 1;
    // }
    curr[0] = 1;
    next[0] = 1;

    for (int index = n - 1; index >= 0; index--)
    {
        for (int t = 1; t <= target; t++)
        {
            bool include = 0;
            if (t - nums[index] >= 0)
                include = next[t - nums[index]];
            bool exclude = next[t];
            curr[t] = (include || exclude);
        }
        // Shifting
        next = curr;
    }
    return curr[target];
}

bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }

    // if sum is odd then there cannot be two subsets with their sum = sum/2
    if (sum & 1)
        return false;

    int target = sum / 2;
    int index = 0;
    bool ans = solveUsingSO(nums, target);
    return ans;
}
int main()
{
    int n;
    cout << "Enter the size of the nums array: " << endl;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements in the nums array:";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    if (canPartition(nums))
    {
        cout << "Two subsets with equal sum found" << endl;
    }
    else
    {
        cout << "Not possible" << endl;
    }
    return 0;
}
*/

// _____________________________________________________________________________________________________________________

// 🔴🔴Space Optimized Approach -2 O(n)🔴🔴
#include <iostream>
#include <vector>
using namespace std;

bool solveUsingSO(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<int> curr(target + 1, 0);
    curr[0] = 1;

    for (int index = n - 1; index >= 0; index--)
    {
        // reversed the loop from target to 1 as curr[t] is dependent on curr[t-nums[index]] and curr[t] so curr[t]
        // would be overwritten but we might need it later so if we go from right to left we can avoid overwriting
        for (int t = target; t >= 1; t--)
        {
            bool include = 0;
            if (t - nums[index] >= 0)
                include = curr[t - nums[index]];
            bool exclude = curr[t];
            curr[t] = (include || exclude);
        }
    }
    return curr[target];
}

bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }

    // if sum is odd then there cannot be two subsets with their sum = sum/2
    if (sum & 1)
        return false;

    int target = sum / 2;
    int index = 0;
    bool ans = solveUsingSO(nums, target);
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of the nums array: " << endl;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements in the nums array:";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    if (canPartition(nums))
    {
        cout << "Two subsets with equal sum found" << endl;
    }
    else
    {
        cout << "Not possible" << endl;
    }
    return 0;
}

// TC -> O(mxn), SC -> O(n)