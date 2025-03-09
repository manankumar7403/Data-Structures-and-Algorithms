// 🔴🔴LEETCODE 503 -> Next Greater Element 2🔴🔴
/*
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next
greater number for every element in nums.
The next greater number of a number x is the first greater number to its traversing-order next in the array, which means
you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

Example 1:
Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.

Example 2:
Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]

Constraints:
1 <= nums.length <= 10^4
-10^9 <= nums[i] <= 10^9
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    vector<int> right(n, -1);
    stack<int> s;
    for (int i = 2 * n - 1; i >= 0; i--) // visualizing the array as double array to get the next greater eg: og:1 2 1, new: 1 2 1 1 2 1
    {
        while (!s.empty() && s.top() <= nums[i % n]) // doing i%n everywhere to ensure the circular nature of the array
        {
            s.pop();
        }
        // agar stack empty nahi hai toh next bada element mil gya
        if (!s.empty())
        {
            // usko right[i] wali position me daal denge
            right[i % n] = s.top();
        }
        // aakhir me use bade element ko stack me insert karenge kyuki vo left wale elements ka answer ho sakta hai
        s.push(nums[i % n]);
    }
    return right;
}

int main()
{
    int n;
    cout << "Enter the size of the array:" << endl;
    cin >> n;
    vector<int>nums(n);
    cout << "Enter the elements in the array:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }

    vector<int> result = nextGreaterElements(nums);
    for(auto i: result)
    {
        cout << i << " ";
    }
    return 0;
}

// TC -> O(n)
// SC -> O(n)