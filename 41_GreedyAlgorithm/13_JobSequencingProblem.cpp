// GFG
/*
Given a set of N jobs where each jobi has a deadline and profit associated with it.
Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with
job if and only if the job is completed by its deadline.
Find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job. Deadline of the job is the time
before which job needs to be completed to earn the profit.

Example 1:
Input:
N = 4
Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output:
2 60
Explanation:
Job1 and Job3 can be done with
maximum profit of 60 (20+40).

Example 2:
Input:
N = 5
Jobs = {(1,2,100),(2,1,19),(3,2,27),
        (4,1,25),(5,1,15)}
Output:
2 127
Explanation:
2 jobs can be done with
maximum profit of 127 (100+27).

Your Task :
You don't need to read input or print anything. Your task is to complete the function JobScheduling() which takes an integer N
and an array of Jobs(Job id, Deadline, Profit) as input and returns the count of jobs and maximum profit as a list or vector of
2 elements.

Expected Time Complexity: O(NlogN)
Expected Auxilliary Space: O(N)

Constraints:
1 <= N <= 10^5
1 <= Deadline <= N
1 <= Profit <= 500
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

static bool cmp(Job a, Job b)
{
    return a.profit > b.profit;
}

// Function to find the maximum profit and the number of jobs done.
vector<int> JobScheduling(Job arr[], int n)
{
    sort(arr, arr + n, cmp);

    int maxDeadline = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxDeadline = max(maxDeadline, arr[i].dead);
    }
    vector<int> schedule(maxDeadline + 1, -1);

    int count = 0;
    int maxProfit = 0;
    for (int i = 0; i < n; i++)
    {
        int currProfit = arr[i].profit;
        int currJobID = arr[i].id;
        int currDead = arr[i].dead;
        for (int k = currDead; k > 0; k--)
        {
            if (schedule[k] == -1)
            {
                count++;
                maxProfit = maxProfit + currProfit;
                schedule[k] = currJobID;
                break;
            }
        }
    }
    vector<int> ans;
    ans.push_back(count);
    ans.push_back(maxProfit);
    return ans;
}

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    Job jobs[n];
    cout << "Enter the job details (Job ID, Deadline, Profit):" << endl;
    for (int i = 0; i < n; i++) {
        int id, deadline, profit;
        cin >> id >> deadline >> profit;
        jobs[i] = {id, deadline, profit};
    }

    vector<int> result = JobScheduling(jobs, n);
    cout << "Number of jobs done: " << result[0] << endl;
    cout << "Maximum profit: " << result[1] << endl;

    return 0;
}

// TC -> O(nlogn) + O(n.d) = O(n.d), n is the vector size and d is the max deadline
// SC -> O(d)
