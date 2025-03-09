/*
Given an array a[] of length N. You have to make the array stable.

Definition of the Stable Array: A array is called stable when, there exists a number X , such that every number from the
array occurs only X times or zero times.
The task is to find the minimum number that needs to be removed to make the array stable.

Example 1:
Input: a[] = {4,3,1,3,1,2}
Output: 2
Explanation : If we remove 1st and last element from the given array, then the array will be stable
resultant array: 3 1 3 1 (every element occurs only 2 times)

Example 2:
Input: a[] = {1,1,2,4,1,2,2}
Output: 1
Explanation : If we remove 4th element i.e. 4, then the array will be stable
resultant array: 1 1 2 1 2 2 (every element occurs only 3 times)
*/
// ________________________________________________________________________________________________________________

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int stableArray(vector<int>& arr)
{
    int n = arr.size();
    // Create a map to count the occurrences of each element in the array
    map<int, int> mp;  // element, count
    // Iterate through the array and increment the count in map
    for(auto &x: arr)
    {
        mp[x]++;
    }

    // Create a vector to store the count of occurrences for each element
    vector<int> count;
    for(auto i: mp)
    {
        count.push_back(i.second);
    }

    // Sort the vector to get elements with the least and maximum occurrences.
    sort(count.begin(), count.end());

    int ans = INT_MAX;

    // Iterate though the sorted count of occurrences for each element
    for(int i: count)
    {
        // Find the index of the element with the least count in the sorted vector
        int temp = lower_bound(count.begin(), count.end(), i) - count.begin();

        // Calculate the number of elements that need to be removed to make the array stable
        int after_removal = count.size() - temp; // gives us the no of diff counts that are greater than or equal to i.
        ans = min(ans, n - after_removal * i);
    }
    return ans;
}
/*
after_removal * i calculates the total number of elements that would remain if we keep only the counts greater than or
equal to i.
n - after_removal * i calculates how many elements need to be removed to make the array stable with the count i.
*/

int main()
{
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    vector<int>arr(n);
    cout << "Enter the elements in the array: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    int result = stableArray(arr);
    cout << "Min elements to be removed to make the array stable: " << result;
    return 0;
}

/*
TC -> O(nlogn)
SC -> O(n)
*/

/*

⭐⭐ https://cplusplus.com/reference/algorithm/lower_bound/

🔴🔴 Dry Run:

Array = {4,3,1,3,1,2}
Map = {4:1, 3:2, 1:2, 2:1}
count vector = {1,2,2,1}
sorted count vector = {1,1,2,2}

for(int i: count)
1) at i = 1 -> temp = 0 (1 is at index '0', which is equal to i=1)
    removed = 4-0=4
    ans = min(INT_MAX, 6-4*1) = 2

2) at i = 1 -> temp = 0 (1 is at index '0', which is equal to i=1)
    removed = 4-0=4
    ans = min(2, 6-4*1) = 2

3) at i = 2 -> temp = 2 (2 is at index '2', which is equal to i=2)
    removed = 4-2=2
    ans = min(2, 6-2*2) = 2

4) at i = 2 -> temp = 2 (2 is at index '2', which is equal to i=2)
    removed = 4-2=2
    ans = min(2, 6-2*2) = 2
*/