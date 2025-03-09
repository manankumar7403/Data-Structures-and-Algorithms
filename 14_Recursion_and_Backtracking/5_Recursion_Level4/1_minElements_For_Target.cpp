// You need to find the minimum number of elements required to make the target.
// Refer the PDF slides for clear explanation.

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int solve(vector<int>& arr, int target)
{
    // Base case (either the leaf node would be 0 or -ve -> recursive tree)
    if(target == 0)   
    {
        return 0;
    }
    if(target < 0)
    {
        return INT_MAX;
    }

    // Lets solve one case
    int mini = INT_MAX; // Putting mini as INT_MAX -> for invalid case (leaf node is -1), we will return INT_MAX
    for(int i=0; i<arr.size(); i++)
    {
        // target - arr[i] => SAY target = 11 and one element is 2, so 11-2=9, and now target becomes 9 and we
        // will check until 9 becomes 0 or -1
        int ans = solve(arr, target - arr[i]);

        if(ans != INT_MAX)               // if ans is valid (0)
        // at the last step we are checking for target(updated)-arr[i], which is the second last target,
        // and not the target itself, so will add 1 more time that is why we do ans + 1
        mini = min(mini, ans+1);         
    }

    return mini;
}

int main()
{
    vector<int> arr{1, 2};
    int target = 5;

    int ans = solve(arr, target);
    cout << "Answer is: " << ans << endl;     // (1,2,2) -> 3 or (2,2,1) -> 3
    return 0;
}

