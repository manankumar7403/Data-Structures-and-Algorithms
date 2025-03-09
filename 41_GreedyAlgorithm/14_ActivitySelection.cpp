// GFG
// ⭐⭐Same as N Meetings in One Room⭐⭐
/*
Given N activities with their start and finish day given in array start[] and end[]. Select the maximum number of activities
that can be performed by a single person, assuming that a person can only work on a single activity at a given day.
Note : Duration of the activity includes both starting and ending day.

Example 1:
Input:
N = 2
start[] = {2, 1}
end[] = {2, 2}
Output: 
1
Explanation:
A person can perform only one of the
given activities.
Example 2:

Input:
N = 4
start[] = {1, 3, 2, 5}
end[] = {2, 4, 3, 6}
Output: 
3
Explanation:
A person can perform activities 1, 2
and 4.

Your Task :
You don't need to read input or print anything. Your task is to complete the function activityselection() which takes
array start[], array end[] and integer N as input parameters and returns the maximum number of activities that can be done.

Expected Time Complexity : O(N * Log(N))
Expected Auxilliary Space : O(N)

Constraints:
1 ≤ N ≤ 2*10^5
1 ≤ start[i] ≤ end[i] ≤ 10^9
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

static bool myComp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second; // ascending
}

// Function to find the maximum number of activities that can
// be performed by a single person.
int activitySelection(vector<int> start, vector<int> end, int n)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> p = make_pair(start[i], end[i]);
        v.push_back(p);
    }
    sort(v.begin(), v.end(), myComp);

    int activities = 1;
    int ansEnd = v[0].second;
    for (int i = 1; i < n; i++)
    {
        if (v[i].first > ansEnd)
        {
            activities++;
            ansEnd = v[i].second;
        }
    }
    return activities;
}

int main()
{
    int n;
    cout << "Enter the number of the activities:" << endl;
    cin >> n;
    vector<int>start(n);
    vector<int>end(n);
    cout << "Enter the start time of the activities:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> start[i];
    }
    cout << "Enter the end time of the activities:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> end[i];
    }
    int ans = activitySelection(start, end, n);
    cout << "Maximum number of activities: " << ans << endl;
    return 0;
}

// Time Complexity : O(n*Logn)
// Auxilliary Space : O(n)