// Boyer - Moore Voting Algorithm
#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int> &nums)
{
    int candidate, count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (count == 0)
        {
            candidate = nums[i];       // If count=0, then candidate becomes the current element
        }
        if (nums[i] == candidate)
        {
            count++;                  // If the same candidate repeats again, count is incremented
        }
        else
        {
            count--;                 // If different candiate comes, then count is decremented
        }
    }
    
    // Now, we have got the candiate element but we do not know if it is actually the majority element.
    // We need to add a second pass through the array to count the occurences of the candidate element.

    count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == candidate)
        {
            count++;
        }
    }

    // Now, we will check if the candidate element appears more than n/2 times, where n is the size of the array.
    if (count > nums.size() / 2)
    {
        return candidate;
    }
    else
    {
        return -1;
    }
}

int main() {
    vector<int> nums = {1, 2, 3, 2, 2, 4, 2};
    cout << "The majority element is: " << majorityElement(nums) << endl;
    return 0;
}