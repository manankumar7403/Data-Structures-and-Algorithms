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

int solve(vector<int>& arr)
{
    int start = 0;
    int end = arr.size()-1;
    int mid = start + (end-start)/2;

    while(start <= end)
    {
        if(start == end)
        {
            // single element
            return start;
        }
        
        // 2 cases -> mid is even / mid is odd
        if(mid % 2 == 0)
        {
            // mid is even
            if(arr[mid] == arr[mid+1])    // standing on the left of the answer
            {
                start = mid+2;            // so searching on right now
            }
            else
            {
                end = mid;             // either end is the ans or we need to search left
            }
        }
        else
        {
            // mid is odd
            if(arr[mid] == arr[mid-1])  // standing on the left of the answer
            {
                start = mid+1;          // so searching on the right now
            }
            else
            {
                // we are on the right of the answer and we need to search left
                end = mid-1;
            }
        }
        mid = start + (end-start)/2;
    }
    return -1;
}

int main()
{
    vector<int> arr{1, 1, 2, 2, 3, 3, 4, 4, 3, 600, 600, 4, 4};
    int ans = solve(arr);
    cout << "index is " << ans << endl;
    cout << "value is " << arr[ans] << endl;
    return 0;
}
