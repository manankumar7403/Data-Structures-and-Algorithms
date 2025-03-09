/*
⭐⭐
Given N items where each item has some weight and profit associated with it and also given a bag with capacity W,
[i.e., the bag can hold at most W weight in it]. The task is to put the items into the bag such that the sum of profits
associated with them is the maximum possible. 
Note: The constraint here is we can either put an item completely into the bag or cannot put it at all [It is not possible to
put a part of an item into the bag].

Examples:
Input: N = 3, W = 4, profit[] = {1, 2, 3}, weight[] = {4, 5, 1}
Output: 3
Explanation: There are two items which have weight less than or equal to 4. If we select the item with weight 4, the possible
profit is 1. And if we select the item with weight 1, the possible profit is 3. So the maximum possible profit is 3. Note that
we cannot put both the items with weight 4 and 1 together as the capacity of the bag is 4.
Input: N = 3, W = 3, profit[] = {1, 2, 3}, weight[] = {4, 5, 6}
Output: 0
⭐⭐
*/
// __________________________________________________________________________________________________________________

// 🔴🔴Recursion Approach🔴🔴
/*
#include<iostream>
#include<vector>
using namespace std;

// index here -> index of the last element
int solveUsingRecursion(int weight[], int value[], int index, int capacity)
{
    // base case -> only 1 item
    if(index == 0)
    {
        if(weight[0] <= capacity)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }

    // include and exclude
    int include = 0;
    if(weight[index] <= capacity)
    {
        // value[index] ko add karna dhyan rakhna
        include = value[index] + solveUsingRecursion(weight, value, index-1, capacity-weight[index]);
    }

    int exclude = 0 + solveUsingRecursion(weight, value, index-1, capacity);
    int ans = max(include, exclude);
    return ans;
}

int main()
{
    int weight[] = {4,5,1};
    int value[] = {1,2,3};
    int n = 3;
    int capacity = 4;

    int ans = solveUsingRecursion(weight, value, n-1, capacity);
    cout << "Maximum profit is: " << ans << endl;
    return 0;
}
*/

// _______________________________________________________________________________________________________________________

// 🔴🔴Memoization (Top-Down) Approach🔴🔴
/*
#include<iostream>
#include<vector>
using namespace std;

// index here -> index of the last element
int solveUsingMem(int weight[], int value[], int index, int capacity, vector<vector<int> >&dp)
{
    // base case -> only 1 item
    if(index == 0)
    {
        if(weight[0] <= capacity)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }

    // Step2: Check if the value is already present inside the dp array or not
    if(dp[index][capacity] != -1)
    {
        return dp[index][capacity];
    }

    // include and exclude
    int include = 0;
    if(weight[index] <= capacity)
    {
        include = value[index] + solveUsingMem(weight, value, index-1, capacity-weight[index], dp);
    }

    int exclude = 0 + solveUsingMem(weight, value, index-1, capacity, dp);
    
    // Step3: Store the value in dp array
    dp[index][capacity] = max(include, exclude);
    return dp[index][capacity];
}

int main()
{
    int weight[] = {4,5,1};
    int value[] = {1,2,3};
    int n = 3;
    int capacity = 4;

    // Step1: Create a 2D dp array as index and capacity both are changing so we have 2 changing variables
    vector<vector<int> >dp(n, vector<int>(capacity+1, -1));    // n rows as index goes from 0 to n-1(total n), and capacity+1 columns as it goes from capacity to 0 (capacity+1)
    int ans = solveUsingMem(weight, value, n-1, capacity, dp);
    cout << "Maximum profit is: " << ans << endl;
    return 0;
}
*/
// _________________________________________________________________________________________________________________________
/*
// 🔴🔴Tabulation (Bottom-Up) Approach🔴🔴

#include<iostream>
#include<vector>
using namespace std;

int solveUsingTab(int weight[], int value[], int n, int capacity)
{
    // Step1: Create a 2D dp array as index and capacity both are changing so we have 2 changing variables
    vector<vector<int> >dp(n, vector<int>(capacity+1, 0));

    // Step2: Handling the base case
    for(int w=weight[0]; w<=capacity; w++)
    {
        if(weight[0] <= capacity)
        {
            dp[0][w] = value[0];
        }
        else{
            dp[0][w] = 0;
        }
    }

    //Step3: Main logic
    for(int index = 1; index < n; index++)
    {
        for(int wt = 0; wt <= capacity; wt++)
        {
            // include and exclude
            int include = 0;
            if (weight[index] <= wt)
            {
                include = value[index] + dp[index - 1][wt - weight[index]];
            }
            int exclude = 0 + dp[index - 1][wt];
            dp[index][wt] = max(include, exclude);
        }
    }
    return dp[n-1][capacity];
}

int main()
{
    int weight[] = {4,5,1};
    int value[] = {1,2,3};
    int n = 3;
    int capacity = 4;

    int ans = solveUsingTab(weight, value, n, capacity);
    cout << "Maximum profit is: " << ans << endl;
    return 0;
}
*/

// ___________________________________________________________________________________________________________________
// 🔴🔴Space Optimization Approach - 1 O(m+n)🔴🔴
/*
#include<iostream>
#include<vector>
using namespace std;

int solveUsingSO(int weight[], int value[], int n, int capacity)
{
    // dp array is dependent on dp[index - 1][wt - weight[index]] and dp[index - 1][wt]
    // so instead of using 2d array we can use 2 1d arrays which store previous and curr of index
    vector<int> prev(capacity+1, 0);
    vector<int> curr(capacity+1, 0);

    // Handling the base case
    for(int w=weight[0]; w<=capacity; w++)
    {
        if(weight[0] <= capacity)
        {
            prev[w] = value[0];
        }
        else{
            prev[w] = 0;
        }
    }

    // Main logic
    for(int index = 1; index < n; index++)
    {
        for(int wt = 0; wt <= capacity; wt++)
        {
            // include and exclude
            int include = 0;
            if (weight[index] <= wt)
            {
                include = value[index] + prev[wt - weight[index]];
            }
            int exclude = 0 + prev[wt];
            curr[wt] = max(include, exclude);
        }
        // Shifting
        prev = curr;
    }
    return prev[capacity];
}

int main()
{
    int weight[] = {4,5,1};
    int value[] = {1,2,3};
    int n = 3;
    int capacity = 4;

    int ans = solveUsingSO(weight, value, n, capacity);
    cout << "Maximum profit is: " << ans << endl;
    return 0;
}
*/
// ____________________________________________________________________________________________________________________

// 🔴🔴Space Optimization Approach - 2 O(n)🔴🔴

#include<iostream>
#include<vector>
using namespace std;

int solveUsingSO(int weight[], int value[], int n, int capacity)
{
    // We only need prev[wt-weight[index]] of prev and prev[wt] for every curr[wt] which could be achieved using 1 array only.
    vector<int> curr(capacity+1, 0);

    // Handling the base case
    for(int w=weight[0]; w<=capacity; w++)
    {
        if(weight[0] <= capacity)
        {
            curr[w] = value[0];
        }
        else{
            curr[w] = 0;
        }
    }

    // Main logic
    for(int index = 1; index < n; index++)
    {
        // only using 1 array so curr[wt] is dependent on curr[wt] and curr[wt-weight[index]] so if we go from left to right 
        // next element of curr[wt] might require curr[wt] but that's overwritten, so go from right to left as curr[wt] is
        // dependent on curr[wt] and PREVIOUS VALUE SOMEHWERE curr[wt-weight[index]]
        for(int wt = capacity; wt >= 0; wt--)
        {
            // include and exclude
            int include = 0;
            if (weight[index] <= wt)
            {
                include = value[index] + curr[wt - weight[index]];
            }
            int exclude = 0 + curr[wt];
            curr[wt] = max(include, exclude);
        }
    }
    return curr[capacity];
}

int main()
{
    int weight[] = {4,5,1};
    int value[] = {1,2,3};
    int n = 3;
    int capacity = 4;

    int ans = solveUsingSO(weight, value, n, capacity);
    cout << "Maximum profit is: " << ans << endl;
    return 0;
}
