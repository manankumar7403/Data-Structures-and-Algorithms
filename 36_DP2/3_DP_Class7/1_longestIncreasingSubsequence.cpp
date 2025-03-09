// ⭐⭐LEETCODE 300 -> Longest Increasing Subsequence⭐⭐
/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.

Example 1:
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:
Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:
Input: nums = [7,7,7,7,7,7,7]
Output: 1

Constraints:
1 <= nums.length <= 2500
-10^4 <= nums[i] <= 10^4
*/
// ____________________________________________________________________________________________________________________

/*
// 🔴🔴RECURSION🔴🔴

#include<iostream>
#include<vector>
using namespace std;

int solveUsingRecursion(vector<int> &nums, int curr, int prev)
{
    // Base condition
    if (curr >= nums.size())
        return 0;

    // include
    int include = 0;
    if (prev == -1 || nums[curr] > nums[prev])
    {
        include = 1 + solveUsingRecursion(nums, curr + 1, curr);
    }
    // exclude
    int exclude = 0 + solveUsingRecursion(nums, curr + 1, prev);

    int ans = max(include, exclude);
    return ans;
}

int lengthOfLIS(vector<int> &nums)
{
    int curr = 0;  // curr index
    int prev = -1; // prev index
    int ans = solveUsingRecursion(nums, curr, prev);
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    vector<int>nums(n);
    cout << "Enter the elements in the array: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }

    int ans = lengthOfLIS(nums);
    cout << "Length of LIS: " << ans << endl;
    return 0;
}
*/
// __________________________________________________________________________________________________________________

/*
// 🔴🔴MEMOIZATION (Top-Down)🔴🔴

#include<iostream>
#include<vector>
using namespace std;

int solveUsingMem(vector<int> &nums, int curr, int prev, vector<vector<int>> &dp)
{
    // doing prev+1 everywhere as prev=-1 is a negative index that will give error so prev=-1+1=0, which is valid index
    // Base condition
    if (curr >= nums.size())
        return 0;

    // Step2: Check if the answer is already present inside the array
    if (dp[curr][prev + 1] != -1)
        return dp[curr][prev + 1];

    // include
    int include = 0;
    if (prev == -1 || nums[curr] > nums[prev])
    {
        include = 1 + solveUsingMem(nums, curr + 1, curr, dp);
    }
    // exclude
    int exclude = 0 + solveUsingMem(nums, curr + 1, prev, dp);

    // Step3: Store the answer in dp array
    dp[curr][prev + 1] = max(include, exclude);
    return dp[curr][prev + 1];
}

int lengthOfLIS(vector<int> &nums)
{
    int curr = 0;  // curr index
    int prev = -1; // prev index

    int n = nums.size();
    // Step1: Create a dp array
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    int ans = solveUsingMem(nums, curr, prev, dp);
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    vector<int>nums(n);
    cout << "Enter the elements in the array: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }

    int ans = lengthOfLIS(nums);
    cout << "Length of LIS: " << ans << endl;
    return 0;
}
// TC -> O(nxm)
// Sc -> O(nxm)

*/
// ___________________________________________________________________________________________________________

/*
// 🔴🔴TABULATION (Bottom-Up)🔴🔴

#include<iostream>
#include<vector>
using namespace std;

int solveUsingTab(vector<int> &nums)
{
    int n = nums.size();
    // Step1: Create a dp array
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // doing prev+1 everywhere as prev=-1 is a negative index that will give error so prev=-1+1=0, which is valid index
    // Step2: Check the Base condition -> dp array already init with 0 so no need of this
    // if(curr >= nums.size()) return 0;

    // Step3: Main iteration logic
    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            // include
            int include = 0;
            if (prev == -1 || nums[curr] > nums[prev])
            {
                include = 1 + dp[curr + 1][curr + 1];   // prev-1 ka ans 0th idx, prev-0 ka ans 1st idx, har num ka ans +1 wale index par exist karta hai thats why we did curr+1 here
            }
            // exclude
            int exclude = 0 + dp[curr + 1][prev + 1];

            // Store the answer in dp array
            dp[curr][prev + 1] = max(include, exclude);
        }
    }
    return dp[0][-1 + 1];
}

int lengthOfLIS(vector<int> &nums)
{
    int ans = solveUsingTab(nums);
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    vector<int>nums(n);
    cout << "Enter the elements in the array: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }

    int ans = lengthOfLIS(nums);
    cout << "Length of LIS: " << ans << endl;
    return 0;
}
// TC -> O(nxm)
// Sc -> O(nxm)

*/
// _________________________________________________________________________________________________________________________

// 🔴🔴SPACE OPTIMIZATION🔴🔴
/*
#include<iostream>
#include<vector>
using namespace std;

int solveUsingSO(vector<int> &nums)
{
    int n = nums.size();
    vector<int> currRow(n + 1, 0);
    vector<int> nextRow(n + 1, 0);

    // doing prev+1 everywhere as prev=-1 is a negative index that will give error so prev=-1+1=0, which is valid index
    // Step2: Check the Base condition -> dp array already init with 0 so no need of this
    // if(curr >= nums.size()) return 0;

    // Step3: Main iteration logic
    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            // include
            int include = 0;
            if (prev == -1 || nums[curr] > nums[prev])
            {
                include = 1 + nextRow[curr + 1]; // prev-1 ka ans 0th idx, prev-0 ka ans 1st idx, har num ka ans +1 wale index par exist karta hai thats why we did curr+1 here
            }
            // exclude
            int exclude = 0 + nextRow[prev + 1];

            // Store the answer in dp array
            currRow[prev + 1] = max(include, exclude);
        }
        // Shifting
        nextRow = currRow;
    }
    return currRow[0];
}

int lengthOfLIS(vector<int> &nums)
{
    int ans = solveUsingSO(nums);
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    vector<int>nums(n);
    cout << "Enter the elements in the array: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }

    int ans = lengthOfLIS(nums);
    cout << "Length of LIS: " << ans << endl;
    return 0;
}
*/
// TC -> O(nxm)
// Sc -> O(n)

// ____________________________________________________________________________________________________________________

// 🔴🔴OPTIMAL SOLUTION🔴🔴

#include<iostream>
#include<vector>
using namespace std;

int solveOptimal(vector<int> &arr)
{
    // Base case
    if (arr.size() == 0)
        return 0;

    vector<int> ans;
    ans.push_back(arr[0]);
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > ans.back())
        {
            // include
            ans.push_back(arr[i]);
        }
        else
        {
            // overwrite
            // find index of the just bigger element
            int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
            ans[index] = arr[i];
        }
    }
    return ans.size();
}

int lengthOfLIS(vector<int> &nums)
{
    int ans = solveOptimal(nums);
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    vector<int>nums(n);
    cout << "Enter the elements in the array: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }

    int ans = lengthOfLIS(nums);
    cout << "Length of LIS: " << ans << endl;
    return 0;
}
// lower_bound returns the first occurence iterator of the element if the element is present or gives the just bigger element
// iterator than the element if the element is not present.
// to get the index we subtract ans.begin() from it as shown:
// int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();


// TC -> O(nlogn)  // n for for loop and lower_bound takes logn
// Sc -> O(n)