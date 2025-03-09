// GFG
/*
There is one meeting room in a firm. There are n meetings in the form of (start[i], end[i]) where start[i] is start time of
meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the
meeting room at a particular time? Return the maximum number of meetings that can be held in the meeting room.
Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

Examples :
Input: n = 6, start[] = {1,3,0,5,8,5}, end[] =  {2,4,6,7,9,9}
Output: 4
Explanation: Maximum four meetings can be held with given start and end timings. The meetings are - (1, 2),(3, 4), (5,7) and
(8,9)
Input: n = 3, start[] = {10, 12, 20}, end[] = {20, 25, 30}
Output: 1
Explanation: Only one meetings can be held with given start and end timings.
Expected Time Complexity : O(n*Logn)
Expected Auxilliary Space : O(n)

Constraints:
1 ≤ n ≤ 10^5
0 ≤ start[i] < end[i] ≤ 10^5
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

static bool myComp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second; // ascending
}

int maxMeetings(int start[], int end[], int n)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> p = make_pair(start[i], end[i]);
        v.push_back(p);
    }
    sort(v.begin(), v.end(), myComp);

    int meetings = 1;
    int ansEnd = v[0].second;
    for (int i = 1; i < n; i++)
    {
        if (v[i].first > ansEnd)
        {
            meetings++;
            ansEnd = v[i].second;
        }
    }
    return meetings;
}

int main()
{
    int n;
    cout << "Enter the number of the meetings:" << endl;
    cin >> n;
    int start[n];
    int end[n];
    cout << "Enter the start time of the meetings:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> start[i];
    }
    cout << "Enter the end time of the meetings:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> end[i];
    }
    int ans = maxMeetings(start, end, n);
    cout << "Maximum number of meetings: " << ans << endl;
    return 0;
}

// Time Complexity : O(n*Logn)
// Auxilliary Space : O(n)