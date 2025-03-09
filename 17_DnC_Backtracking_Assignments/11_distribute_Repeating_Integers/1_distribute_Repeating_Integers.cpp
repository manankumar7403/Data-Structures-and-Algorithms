// 🔴🔴🔴🔴 LEETCODE 1655 -> Distribute Repeating Integers 🔴🔴🔴🔴
/*
You are given an array of n integers, nums, where there are at most 50 unique values in the array. You are
also given an array of m customer order quantities, quantity, where quantity[i] is the amount of integers the
ith customer ordered. Determine if it is possible to distribute nums such that:

1) The ith customer gets exactly quantity[i] integers,
2) The integers the ith customer gets are all equal, and
3) Every customer is satisfied.
Return true if it is possible to distribute nums according to the above conditions.

Example 1:
Input: nums = [1,2,3,4], quantity = [2]
Output: false
Explanation: The 0th customer cannot be given two different integers.

Example 2:
Input: nums = [1,2,3,3], quantity = [2]
Output: true
Explanation: The 0th customer is given [3,3]. The integers [1,2] are not used.

Example 3:
Input: nums = [1,1,2,2], quantity = [2,2]
Output: true
Explanation: The 0th customer is given [1,1], and the 1st customer is given [2,2].

Constraints:
n == nums.length
1 <= n <= 10^5
1 <= nums[i] <= 1000
m == quantity.length
1 <= m <= 10
1 <= quantity[i] <= 10^5
There are at most 50 unique values in nums.
*/
// ______________________________________________________________________________________________________

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool canDistributeHelper(vector<int> &counts, vector<int> &quantity, int ithCustomer)
{
    // Base Case
    if (ithCustomer == quantity.size()) // say nums=[1,1,2,2], quantity=[2,2], we need to provide for 0th customer and 1st customer, if ithCustomer == quantity.size() == 3, it means we have fulfilled the requirements of all the customers.
    {
        return true;
    }

    for (int i = 0; i < counts.size(); i++)
    {
        if (counts[i] >= quantity[ithCustomer]) // if frequency of an element is >= demand of the customer, we assign it
        {
            counts[i] = counts[i] - quantity[ithCustomer];

            if (canDistributeHelper(counts, quantity, ithCustomer + 1)) // checking for next customer (we will try to fulfill the need of the next customer), if we are unable to, we will backtrack
            {
                return true;
            }
            // Backtracking
            counts[i] = counts[i] + quantity[ithCustomer];
        }
    }
    return false; // not able to fulfill the demands of all the customers.
}

bool canDistribute(vector<int> &nums, vector<int> &quantity)
{
    unordered_map<int, int> countMap;
    for (auto num : nums)
    {
        countMap[num]++; // stores the number and frequency of nums array in key-value pair
    }
    vector<int> counts;
    for (auto it : countMap) // traversing the map to get the frequency
    {
        counts.push_back(it.second); // in 'counts' vector we stored the frequency of each element of nums array
    }

    sort(quantity.rbegin(), quantity.rend());        // sorting the quantity in decreasing order. This will reduce the number of comparisons as if the highest quanitity is not being fulfilled first, we can return false without checking the demands of smaller quantities.
    return canDistributeHelper(counts, quantity, 0); // 0 because first we need to satisfy the 0th customer
}

int main()
{
    int n, m;
    cout << "Enter the size of nums array: " << endl;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements in the nums array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << "Enter the size of quantity array: " << endl;
    cin >> m;
    vector<int> quantity(m);
    cout << "Enter the elements in the quantity array: " << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> quantity[i];
    }

    cout << canDistribute(nums, quantity);
    cout << endl;
    return 0;
}

// TC -> O(n log n + m * k), which simplifies to O(n * min(m, k)) because n log n dominates for large n.
// SC -> O(n + m)
// Learn DP and optimize this solution