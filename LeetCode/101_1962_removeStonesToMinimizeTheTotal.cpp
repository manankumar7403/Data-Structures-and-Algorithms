/*
🔴🔴🔴🔴 LEETCODE 1962 -> Remove Stones To Minimize the Total 🔴🔴🔴🔴
Refer 31_Heaps -> 4_HeapsClass4 -> 1_removeStonesToMinTheTotal.cpp

You are given a 0-indexed integer array piles, where piles[i] represents the number of stones in the ith pile, and an
integer k. You should apply the following operation exactly k times:

Choose any piles[i] and remove floor(piles[i] / 2) stones from it.
Notice that you can apply the operation on the same pile more than once.

Return the minimum possible total number of stones remaining after applying the k operations.

floor(x) is the greatest integer that is smaller than or equal to x (i.e., rounds x down).

Example 1:
Input: piles = [5,4,9], k = 2
Output: 12
Explanation: Steps of a possible scenario are:
- Apply the operation on pile 2. The resulting piles are [5,4,5].
- Apply the operation on pile 0. The resulting piles are [3,4,5].
The total number of stones in [3,4,5] is 12.

Example 2:
Input: piles = [4,3,6,7], k = 3
Output: 12
Explanation: Steps of a possible scenario are:
- Apply the operation on pile 2. The resulting piles are [4,3,3,7].
- Apply the operation on pile 3. The resulting piles are [4,3,3,4].
- Apply the operation on pile 0. The resulting piles are [2,3,3,4].
The total number of stones in [2,3,3,4] is 12.

Constraints:
1 <= piles.length <= 10^5
1 <= piles[i] <= 10^4
1 <= k <= 10^5
*/
// __________________________________________________________________________________________________________________

#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

int minStoneSum(vector<int> &piles, int k)
{
    priority_queue<int> maxHeap;
    for (int i = 0; i < piles.size(); i++)
    {
        maxHeap.push(piles[i]);
    }
    while (k--)
    {
        int maxElement = maxHeap.top();
        maxHeap.pop();
        maxElement = maxElement - floor(maxElement / 2);
        maxHeap.push(maxElement);
    }
    int sum = 0;
    while (!maxHeap.empty())
    {
        int temp = maxHeap.top();
        maxHeap.pop();
        sum = sum + temp;
    }
    return sum;
}

int main()
{
    int n, k;
    cout << "Enter the number of elements in the piles vector:" << endl;
    cin >> n;
    vector<int> piles(n);
    cout << "Enter the elements in the piles vector:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> piles[i];
    }

    cout << "Enter the number of operations:" << endl;
    cin >> k;

    int result = minStoneSum(piles, k);
    cout << "The total number of stones are: " << result;
    cout << endl;
    return 0;
}

// TC -> O(n + klogn)
// SC -> O(n)