// GFG
// Did 0 1 Knapsack in DP1 Class 3
/*
Given weights and values of n items, we need to put these items in a knapsack of capacity w to get the maximum total value in
the knapsack. Return a double value representing the maximum value in knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item here. The details of structure/class is defined in the comments
above the given function.

Examples:
Input: n = 3, w = 50, value[] = [60,100,120], weight[] = [10,20,30]
Output: 240.000000
Explanation: Take the item with value 60 and weight 10, value 100 and weight 20 and split the third item with value 120 and
weight 30, to fit it into weight 20. so it becomes (120/30)*20=80, so the total value becomes 60+100+80.0=240.0 Thus, total
maximum value of item we can have is 240.00 from the given capacity of sack. 
Input: n = 2, w = 50, value[] = [60,100], weight[] = [10,20]
Output: 160.000000
Explanation: Take both the items completely, without breaking. Total maximum value of item we can have is 160.00 from the given
capacity of sack.

Expected Time Complexity : O(n log n)
Expected Auxilliary Space: O(1)

Constraints:
1 <= n <= 10^5
1 <= w <= 10^9
1 <= valuei, weighti <= 10^4
*/
// _____________________________________________________________________________________________________________________

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Item{
    int value;
    int weight;
};

static bool myComp(pair<double, Item> a, pair<double, Item> b)
{
    return a.first > b.first;
}

double fractionalKnapsack(int W, Item arr[], int n)
{
    vector<pair<double, Item>> v;
    for (int i = 0; i < n; i++)
    {
        double perUnitValue = (1.0 * arr[i].value) / arr[i].weight;
        pair<double, Item> p = make_pair(perUnitValue, arr[i]);
        v.push_back(p);
    }
    sort(v.begin(), v.end(), myComp);

    double totalValue = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i].second.weight > W)
        {
            // can only take a fraction of a value
            totalValue = totalValue + W * v[i].first;
            W = 0;
        }
        else
        {
            totalValue = totalValue + v[i].second.value;
            W = W - v[i].second.weight;
        }
    }
    return totalValue;
}

int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    
    Item arr[n];
    cout << "Enter the value and weight of each item:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].value >> arr[i].weight;
    }
    
    cout << "Enter the maximum capacity of the knapsack: ";
    cin >> W;
    
    double maxValue = fractionalKnapsack(W, arr, n);
    
    cout << "The maximum value that can be obtained is: " << maxValue << endl;
    
    return 0;
}

//Time Complexity : O(n log n)
//Auxilliary Space: O(1)