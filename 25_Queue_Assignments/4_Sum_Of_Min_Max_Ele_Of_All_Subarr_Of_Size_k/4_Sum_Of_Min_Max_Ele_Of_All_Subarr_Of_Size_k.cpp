//⭐⭐ Pre-Requisite: Queues Class 3: Sliding Window Maximum ⭐⭐
// GFG: https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/
/*
Given an array of both positive and negative integers, the task is to compute sum of minimum and maximum elements of all
sub-array of size k.
Examples: 
Input : arr[] = {2, 5, -1, 7, -3, -1, -2}  
        K = 4
Output : 18
Explanation : Subarrays of size 4 are : 
     {2, 5, -1, 7},   min + max = -1 + 7 = 6
     {5, -1, 7, -3},  min + max = -3 + 7 = 4      
     {-1, 7, -3, -1}, min + max = -3 + 7 = 4
     {7, -3, -1, -2}, min + max = -3 + 7 = 4   
     
     Missing sub arrays - 
     
     {2, -1, 7, -3}
     {2, 7, -3, -1}
     {2, -3, -1, -2}
     {5, 7, -3, -1}
     {5, -3, -1, -2}
     and few more -- why these were not considered??
     Considering missing arrays result coming as 27
     
     Sum of all min & max = 6 + 4 + 4 + 4 = 18    
*/

#include<iostream>
#include<deque>
#include<vector>
using namespace std;

int sumOfMinMaxOfAllWindowsOfSizeK(vector<int> &nums, int k)
{
    deque<int> dq(k), dq2(k);
    int ans = 0;

    // first window of k size
    for (int i = 0; i < k; i++)
    {
        // chote element remove kardo
        while (!dq.empty() && nums[i] >= nums[dq.back()])
        {
            dq.pop_back();
        }

        // bade element remove kardo
        while (!dq2.empty() && nums[i] <= nums[dq2.back()])
        {
            dq2.pop_back();
        }
        // inserting index, so that we can check out of window elements
        dq.push_back(i);
        dq2.push_back(i);
    }

    // store answer for first window
    ans = ans + nums[dq.front()] + nums[dq2.front()];

    // remaining windows ko process karna hai
    for (int i = k; i < nums.size(); i++)
    {
        // out of window ko remove kardo
        if (!dq.empty() && i - dq.front() >= k)
        {
            dq.pop_front();
        }
        if (!dq2.empty() && i - dq2.front() >= k)
        {
            dq2.pop_front();
        }

        // ab firse current element ke liye chote element ko remove karna hai us particular window ke andar
        while (!dq.empty() && nums[i] >= nums[dq.back()])
        {
            dq.pop_back();
        }

        // ab firse current element ke liye bade element ko remove karna hai us particular window ke andar
        while (!dq2.empty() && nums[i] <= nums[dq2.back()])
        {
            dq2.pop_back();
        }
        // inserting index, so that we can check out of window elements
        dq.push_back(i);
        dq2.push_back(i);

        // current window ka answer store karna hai
        ans = ans + nums[dq.front()] + nums[dq2.front()];
    }

    return ans;
}

int main()
{
    int n, k;
    cout << "Enter the size of the array:" << endl;
    cin >> n;
    cout << "Enter the size of each sub-array:" << endl;
    cin >> k;
    vector<int>nums(n);
    cout << "Enter the elements in the array:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }
    int result = sumOfMinMaxOfAllWindowsOfSizeK(nums, k);
    cout << "Sum of max and min elements of all subarrays of size k is " << result << endl;
    return 0;
}

// TC -> O(n)
// SC -> O(k)