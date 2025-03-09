// 🔴🔴🔴🔴 LEETCODE 539 - Minimum Time Difference 🔴🔴🔴🔴

// Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference
// between any two time-points in the list. 

// Example 1:
// Input: timePoints = ["23:59","00:00"]
// Output: 1

// Example 2:
// Input: timePoints = ["00:00","23:59","00:00"]
// Output: 0

// Constraints:
// 2 <= timePoints.length <= 2 * 10^4
// timePoints[i] is in the format "HH:MM".

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

int findMinDifference(vector<string>& timePoints)
{
    // Step 1: convert time string into minutes integer value
    vector<int> minutes;
    for(int i=0; i<timePoints.size(); i++)
    {
        string curr = timePoints[i];
        int hrs = stoi(curr.substr(0,2));  // stoi is used to convert string to integer
        int min = stoi(curr.substr(3,2));
        int totalMinutes = hrs * 60 + min;
        minutes.push_back(totalMinutes);
    }

    // Step 2: sort
    sort(minutes.begin(), minutes.end());

    // Step 3: difference and calculate min difference 
    int mini = INT_MAX;
    int n = minutes.size();
    for(int i=0; i<n-1; i++)
    {
        int diff = minutes[i+1] - minutes[i];
        mini = min(mini, diff);
    }

    // Step 4: Handling the tough case (23:59 and 00:00)
    // After sorting 00:00 (0) comes at 0th index and 23:59 (1439) comes at last index.
    int lastDiff1 = (minutes[0] + 1440) - minutes[n-1];
    int lastDiff2 = minutes[n-1] - minutes[0];
    int lastDiff = min(lastDiff1, lastDiff2);
    mini = min(mini, lastDiff);
    return mini;
}

int main()
{
    vector<string> timePoints;
    string input;
    int numTimePoints;
    cout << "Enter the number of time points: " << endl;
    cin >> numTimePoints;

    cin.ignore();         // Ignores the newline character
    
    cout << "Enter time points (HH:MM): " << endl;
    for(int i=0; i<numTimePoints; i++)
    {
        getline(cin, input);
        timePoints.push_back(input);
    }

    int minDifference = findMinDifference(timePoints);
    cout << "Minimum difference: " << minDifference << endl;
    return 0;
}

// T.C. -> O(nlogn)
// S.C. -> O(n)

