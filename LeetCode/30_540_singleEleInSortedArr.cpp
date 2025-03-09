// You are given a sorted array consisting of only integers where every element appears exactly twice,
// except for one element which appears exactly once.
// Return the single element that appears only once.
// Your solution must run in O(log n) time and O(1) space.

// Example 1:
// Input: nums = [1,1,2,3,3,4,4,8,8]
// Output: 2

// Example 2:
// Input: nums = [3,3,7,7,10,11,11]
// Output: 10

// Constraints:
// 1 <= nums.length <= 10^5
// 0 <= nums[i] <= 10^5

// All elements occur even number of times except one.
// All repeating occurrence of elements appear in pairs and pairs are not adjacent (there cannot be more than
// 2 consecutive occurrence of any element).
// Find the element that appears odd number of times.
// arr = [1,1,2,2,3,3,4,4,3,600,600,4, 4]
       // 0 1 2 3 4 5 6 7 8  9  10  11 12    -> Index values
// answer is 3

#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int> &nums)
{
    int start = 0;
    int end = nums.size() - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (start == end)
        {
            // single element
            return nums[start];
        }

        // 2 cases -> mid is even/mid is odd
        if (mid % 2 == 0)
        {
            // mid is even
            if (nums[mid] == nums[mid + 1]) // standing on the left of the answer
            {
                start = mid + 2; // so searching right now
            }
            else
            {
                end = mid; // either end is the ans or we need to search left
            }
        }
        else
        {
            // mid is odd
            if (nums[mid] == nums[mid - 1]) // standing on the left of the answer
            {
                start = mid + 1; // so searching on right now
            }
            else
            {
                // we are on the right of the answer and we need to search left
                end = mid - 1;
            }
        }
        mid = start + (end - start) / 2;
    }
    return -1;
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

    int result = singleNonDuplicate(nums);
    cout << "The desired number is: ";
    cout << result << endl;
    return 0;
}

// Sample array
// arr{1, 1, 2, 2, 3, 3, 4, 4, 3, 600, 600, 4, 4};

// Output
// 3