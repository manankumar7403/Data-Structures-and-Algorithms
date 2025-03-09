// Given an array nums with n objects colored red, white, or blue, sort them in-place so
// that objects of the same color are adjacent, with the colors in the order red, white, and blue.
// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
// You must solve this problem without using the library's sort function.
// Example 1:
// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

// Example 2:
// Input: nums = [2,0,1]
// Output: [0,1,2]

#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int>& nums)
{
    int l=0, m=0, h=nums.size()-1;
    while(m<=h)
    {
        if(nums[m]==0)
        {
            swap(nums[l], nums[m]);
            l++;
            m++;
        }
        else if(nums[m]==1)
        {
            m++;
        }
        else
        {
            swap(nums[m], nums[h]);
            h--;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the size of the vector: " << endl;
    cin >> n;

    vector<int> nums(n);
    
    cout << "Enter the elements in the vector: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }
    
    sortColors(nums);
    
    for(int j: nums)
    {
        cout << j << " ";
    }
    
    cout << endl;
    return 0;
}

// Time Complexity - O(n)