// 🔴🔴LEETCODE 347 -> Top K Frequent Elements🔴🔴
/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in
any order.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]

Constraints:
1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> counts;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
    for (auto i : nums)
    {
        counts[i]++; // stores the number, frequency
    }

    for (auto &i : counts)
    {
        min_heap.push({i.second, i.first}); // stores frequency, number
        if (min_heap.size() > k)
        {
            min_heap.pop();
        }
    }

    vector<int> res;
    while (k--)
    {
        res.push_back(min_heap.top().second); // stores number
        min_heap.pop();
    }
    return res;
}

int main()
{
    int n, k;
    cout << "Enter the size of the array:" << endl;
    cin >> n;
    vector<int>nums(n);
    cout << "Enter the elements in the array:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }
    cout << "Enter the value of k:" << endl;
    cin >> k;
    vector<int> res = topKFrequent(nums, k);
    for(int i: res)
    {
        cout << i << " ";
    }

    return 0;
}


// TC -> O(nlogk)
// SC -> O(k)