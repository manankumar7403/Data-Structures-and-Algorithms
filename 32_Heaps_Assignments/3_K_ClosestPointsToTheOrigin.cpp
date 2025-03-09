// 🔴🔴LEETCODE 973-> K Closest Points To Origin🔴🔴
/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k
closest points to the origin (0, 0).
The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)^2 + (y1 - y2)^2).
You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

Example 1:
Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].

Example 2:
Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.

Constraints:
1 <= k <= points.length <= 10^4
-10^4 <= xi, yi <= 10^4
*/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class myComp
{
public:
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        int distA = (a.first * a.first) + (a.second * a.second);
        int distB = (b.first * b.first) + (b.second * b.second);
        return distA > distB;
    }
};

vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    vector<vector<int>> ans;
    // pair<x,y>, vector<pair<pairs>>, custom Comparator
    // what is inserted, what is stored, which order is it stored
    priority_queue<pair<int, int>, vector<pair<int, int>>, myComp> pq; // Min heap->giving higher priority to point closer to origin

    for (auto p : points)
    {
        pq.push({p[0], p[1]});
    }

    while (!pq.empty() && k--)
    {
        auto &top = pq.top();
        ans.push_back({top.first, top.second});
        pq.pop();
    }
    return ans;
}

int main()
{
    int n, k;
    cout << "Enter the number of points:" << endl;
    cin >> n;
    cout << "Enter the points:" << endl;
    vector<vector<int>>points(n, vector<int>(2));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<2; j++)
        {
            cin >> points[i][j];
        }
    }

    cout << "Enter the k closest points:" << endl;
    cin >> k;

    vector<vector<int>>res = kClosest(points, k);
    cout << k << " closest points to the origin are:" << endl;
    for(auto i: res)
    {
        for(auto j: i)
        {
            cout << j << ",";
        }
        cout << endl;
    }

    return 0;
}

// TC -> O(nlogn)
// SC -> O(n)