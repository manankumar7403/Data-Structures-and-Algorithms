// Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all
// the integers in the range [1, n] that do not appear in nums.
// Example 1:
// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [5,6]

// Example 2:
// Input: nums = [1,1]
// Output: [2]

#include <iostream>
#include <vector>
using namespace std;

vector<int> findMissing(vector<int>& a, int n)
{
    int i=0;
    while(i < n)
    {
        int index = a[i] - 1;
        if(a[i] != a[index])
        {
            swap(a[i], a[index]);
        }
        else
        {
            i++;
        }
    }

    vector<int> result;
    for(int i=0; i<n; i++)
    {
        if(a[i] != i+1)
        {
            result.push_back(i+1);
        }
    }
    return result;
}


int main()
{
    int n;
    cout << "Enter the size of the vector: " << endl;
    cin >> n;
    vector<int>a(n);
    cout << "Enter the elements in the vector: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    vector<int> ans = findMissing(a, n);
    for(auto j: ans)
    {
        cout << j << " ";
    }
    cout << endl;
    return 0;
}

// TC - O(N)
// SC - O(1)
