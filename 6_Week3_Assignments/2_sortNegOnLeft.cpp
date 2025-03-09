// Using Dutch National Flag or 2-pointer approach
// swap all negative elements to the left side and positive to the right side (order doesn't matter)
// arr = [1 2 -3 4 -5 6]
// sortedArray = [-5 -3 2 4 1 6]

#include <iostream>
#include <vector>
using namespace std;

void sortedArray(vector<int>& nums)
{
    int l=0, h=nums.size()-1;
    while(l<h)
    {
        if(nums[l] < 0)
        {
            l++;
        }
        else if(nums[h] > 0)
        {
            h--;
        }
        else
        {
            swap(nums[l], nums[h]);
        }
    }
}

int main()
{
    int n;
    cout << "Enter the size of the vector: " << endl;
    cin >> n;
    cout << "Enter the elements in the vector: " << endl;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }

    sortedArray(nums);

    for(int element: nums)
    {
        cout << element << " ";
    }

    cout<< endl;
    return 0;
}

// Time Complexity - O(n)