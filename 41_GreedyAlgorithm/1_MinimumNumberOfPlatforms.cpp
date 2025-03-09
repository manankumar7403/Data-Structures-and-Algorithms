// GFG
/*
Given arrival and departure times of all trains that reach a railway station. Find the minimum number of platforms
required for the railway station so that no train is kept waiting.
Consider that all the trains arrive on the same day and leave on the same day. Arrival and departure time can never
be the same for a train but we can have arrival time of one train equal to departure time of the other. At any given
instance of time, same platform can not be used for both departure of a train and arrival of another train. In such
cases, we need different platforms.

Examples:
Input: n = 6, arr[] = {0900, 0940, 0950, 1100, 1500, 1800}, 
            dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
Output: 3
Explanation: There are three trains during the time 0940 to 1200. So we need minimum 3 platforms.
Input: n = 3, arr[] = {0900, 1235, 1100}, 
            dep[] = {1000, 1240, 1200}
Output: 1
Explanation: All train times are mutually exlusive. So we need only one platform
Input: n = 3, arr[] = {1000, 0935, 1100}, 
            dep[] = {1200, 1240, 1130}
Output: 3
Explanation: All 3 trains have to be their from 11:00 to 11:30

Note: Time intervals are in the 24-hour format(HHMM) , where the first two characters represent hour (between 00 to 23 )
and the last two characters represent minutes (this will be <= 59 and >= 0).

Expected Time Complexity: O(nLogn)
Expected Auxiliary Space: O(n)
Constraints:
1 ≤ n ≤ 50000
0000 ≤ arr[i] ≤ dep[i] ≤ 2359
*/
// ________________________________________________________________________________________________________________

// 🔴🔴Type 1: When array given depicts the time in integer🔴🔴

// 🔴🔴Method 1: When changing the original arrays is allowed🔴🔴
/*
#include<iostream>
#include<algorithm>
using namespace std;

int findPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);
    int i = 1, j = 0, platformsNeeded = 1, maxPlatforms = 1;
    while (i < n)
    {
        if (arr[i] <= dep[j])
        {
            platformsNeeded++;
            i++;
        }
        else
        {
            platformsNeeded--;
            j++;
        }
        maxPlatforms = max(maxPlatforms, count);
    }
    return maxPlatforms;
}

int main()
{
    int n;
    cout << "Enter the number of trains:" << endl;
    cin >> n;
    int arr[n];
    int dep[n];
    cout << "Enter the arrival time:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the departure time:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> dep[i];
    }
    cout << "Minimum platforms required: " << findPlatform(arr, dep, n) << endl;
    return 0;
}
// TC -> O(nlogn)
// SC -> O(1)
*/

// __________________________________________________________________________________________________________________

// 🔴🔴Method 2: When changing the original arrays is not allowed🔴🔴
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static bool myComp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first == b.first)
    {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int findPlatform(int arr[], int dep[], int n)
{
    vector<pair<int, int>> events;
    for (int i = 0; i < n; i++)
    {
        events.push_back({arr[i], 1});  // arrival event
        events.push_back({dep[i], -1}); // departure event
    }

    // Sort events first by time, then by type of event (arrival before departure)
    sort(events.begin(), events.end(), myComp);

    int platformsNeeded = 0, maxPlatforms = 0;
    for (int i = 0; i < events.size(); i++)
    {
        platformsNeeded = platformsNeeded + events[i].second;
        maxPlatforms = max(maxPlatforms, platformsNeeded);
    }

    return maxPlatforms;
}

int main() {
    int n;
    cout << "Enter the number of trains:" << endl;
    cin >> n;
    int arr[n];
    int dep[n];
    cout << "Enter the arrival time:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the departure time:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> dep[i];
    }
    cout << "Minimum platforms required: " << findPlatform(arr, dep, n) << endl;
    return 0;
}
// TC -> O(nlogn)
// SC -> O(n)
*/

// __________________________________________________________________________________________________________________

// 🔴🔴Type 2: When array given depicts the time in string🔴🔴

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Function to convert time in HH:MM format to minutes past midnight
int convertToMinutes(const string& time)
{
    int hours = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(3,2));
    return hours * 60 + minutes;
}

int findPlatform(vector<string>& arr, vector<string>& dep, int n)
{
    vector<int> arrMinutes(n);
    vector<int> depMinutes(n);

    // Convert times to minutes past midnight
    for(int i=0; i<n; i++)
    {
        arrMinutes[i] = convertToMinutes(arr[i]);
        depMinutes[i] = convertToMinutes(dep[i]);
    }

    sort(arrMinutes.begin(), arrMinutes.end());
    sort(depMinutes.begin(), depMinutes.end());
    
    int i = 1, j = 0, platformsNeeded = 1, maxPlatforms = 1;
    while (i < n && j < n)
    {
        if (arrMinutes[i] <= depMinutes[j])
        {
            platformsNeeded++;
            i++;
        }
        else
        {
            platformsNeeded--;
            j++;
        }
        maxPlatforms = max(maxPlatforms, platformsNeeded);
    }
    return maxPlatforms;
}

int main()
{
    int n;
    cout << "Enter the number of trains:" << endl;
    cin >> n;
    vector<string> arr(n);
    vector<string> dep(n);
    cout << "Enter the arrival times (HH:MM):" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the departure times (HH:MM):" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> dep[i];
    }
    cout << "Minimum platforms required: " << findPlatform(arr, dep, n) << endl;
    return 0;
}
