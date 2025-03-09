// You are given an array consisting of n integers which denote the position of a stall.
// You are also given an integer k which denotes the number of aggressive cows. You are given the task
// of assigning stalls to k cows such that the minimum distance between any two of them is the maximum
// possible.
// The first line of input contains two space-separated integers n and k.
// The second line contains n space-separated integers denoting the position of the stalls.

// Example 1:
// Input:
// n=5
// k=3
// stalls = [1 2 4 8 9]
// Output:
// 3
// Explanation:
// The first cow can be placed at stalls[0],
// the second cow can be placed at stalls[2] and
// the third cow can be placed at stalls[3].
// The minimum distance between cows, in this case, is 3,
// which also is the largest among all possible ways.

// Example 2:
// Input:
// n=5
// k=3
// stalls = [10 1 2 7 5]
// Output:
// 4
// Explanation:
// The first cow can be placed at stalls[0],
// the second cow can be placed at stalls[1] and
// the third cow can be placed at stalls[4].
// The minimum distance between cows, in this case, is 4,
// which also is the largest among all possible ways.

// Expected Time Complexity: O(n*log(10^9)).
// Expected Auxiliary Space: O(1).

// Constraints:
// 2 <= n <= 10^5
// 2 <= k <= n
// 0 <= stalls[i] <= 10^9

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossibleSolution(vector<int> &stalls, int k, int mid)
{
    // can we place k cows with at least 'mid' distance between them
    int cow = 1;         // will keep the count of how many cows placed
    int pos = stalls[0]; // placing first cow at 0th index

    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - pos >= mid)
        // if the current stall - position where last cow was placed is >= mid, we will place the
        // next cow (basically, we will only place the 2nd cow if the difference of distance between the
        // last placed cow and the cow to be placed is greater than or equal to mid(solution)).
        {
            cow++;           // increment current cow count
            pos = stalls[i]; // updating the position of the last cow -> meaning one more cow has been placed
        }
        if (cow == k)
        {
            return true;
        }
    }
    return false;
}

int solve(int n, int k, vector<int> &stalls)
{
    sort(stalls.begin(), stalls.end()); // assuming stalls are on a number line, so we sort
    int start = 0;
    int end = stalls[stalls.size() - 1] - stalls[0]; // end of the search space is the max pos - min pos
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isPossibleSolution(stalls, k, mid))
        {
            // if a possible solution is found,
            // store the ans
            ans = mid;

            // try to maximize the solution (distance between the cows)
            start = mid + 1;
        }
        else
        {
            // if possible solution not found in the current search space, try reducing the distance between the cows
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int n, k;
    cout << "Enter the position of stalls: " << endl;
    cin >> n;
    cout << "Enter the number of cows: " << endl;
    cin >> k;
    vector<int> stalls(n);
    cout << "Enter the value in stalls: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> stalls[i];
    }

    int result = solve(n, k, stalls);
    cout << "Largest possible minimum distance between cows: " << result << endl;
    return 0;
}