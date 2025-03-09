// 🔴🔴🔴🔴 Painter's Partition Problem 🔴🔴🔴🔴

// Dilpreet wants to paint his dog's home that has n boards with different lengths. The length of ith board
// is given by arr[i] where arr[] is an array of n integers. He hired k painters for this work and each
// painter takes 1 unit time to paint 1 unit of the board.

// The problem is to find the minimum time to get this job done if all painters start together with the
// constraint that any painter will only paint continuous boards, say boards numbered {2,3,4} or only board
// {1} or nothing but not boards {2,4,5}.

// Example 1:
// Input:
// n = 5
// k = 3
// arr[] = {5,10,30,20,15}
// Output: 35
// Explanation: The most optimal way will be:
// Painter 1 allocation : {5,10}
// Painter 2 allocation : {30}
// Painter 3 allocation : {20,15}
// Job will be done when all painters finish i.e. at time = max(5+10, 30, 20+15) = 35

// Example 2:
// Input:
// n = 4
// k = 2
// arr[] = {10,20,30,40}
// Output: 60
// Explanation: The most optimal way to paint:
// Painter 1 allocation : {10,20,30}
// Painter 2 allocation : {40}
// Job will be complete at time = 60

// Expected Time Complexity: O(n log m) , m = sum of all boards' length
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ n ≤ 10^5
// 1 ≤ k ≤ 10^5
// 1 ≤ arr[i] ≤ 10^5
// ____________________________________________________________________________________________

#include <iostream>
using namespace std;

bool isPossibleSolution(int arr[], int n, int k, long long sol) // sol is the mid only as mid will be the answer
{
    long long timeSum = 0; // will store the current time sum
    int painter = 1;       // how many allocated
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > sol) // if the length of the current board(time taken) is greater than the solution, it cannot be allocated
        {
            return false;
        }
        if (timeSum + arr[i] > sol) // if the current sum and board length(time taken) to be allocated is more than the solution, we go to the next painter
        {
            painter++;
            timeSum = arr[i]; // Giving the board to the next painter
            if (painter > k)
            {
                return false; // painters exceeded maximum painters
            }
        }
        else
        {
            timeSum = timeSum + arr[i]; // current time sum + arr[i] board length(time taken) by current painter not more than the solution, we will keep on adding
        }
    }
    return true;
}

// Function to calculate the minimum time required
long long minTime(int arr[], int n, int k)
{

    // creating the search space using start and end
    long long start = 0;
    long long end = 0;
    for (int i = 0; i < n; i++)
    {
        end += arr[i];
    }
    long long ans = -1;

    while (start <= end)
    {
        long long mid = start + (end - start) / 2;
        if (isPossibleSolution(arr, n, k, mid))
        {
            // store ans
            ans = mid;
            // minimize the solution to be more precise, therefore search left
            end = mid - 1; // if solution found, we will try to minimize it -> as small as possible
        }
        else
        {
            // solution not found in the current search space, search right
            start = mid + 1;
        }
    }
    return ans;
}
int main()
{
    int n, k;
    cout << "Enter the number of boards: " << endl;
    cin >> n;
    cout << "Enter the number of painters: " << endl;
    cin >> k;
    int arr[n];
    cout << "Enter the length of each board (time taken): " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Board " << (i + 1) << ": ";
        cin >> arr[i];
    }

    long long result = minTime(arr, n, k);

    if (result != -1)
    {
        cout << "The minimum number time required by the painters is: " << result << endl;
    }
    else
    {
        cout << "Not possible to allocate boards with the given constraints." << endl;
    }
    return 0;
}

// Time Complexity: O(N log M)
// Space Complexity: O(1)