// Lumberjack Mirko needs to chop down M metres of wood. It is an easy job for him since he has a
// nifty new woodcutting machine that can take down forests like wildfire. However, Mirko is only allowed
// to cut a single row of trees.

// Mirkos machine works as follows: Mirko sets a height parameter H (in metres), and the machine raises
// a giant sawblade to that height and cuts off all tree parts higher than H (of course, trees not higher
// than H meters remain intact). Mirko then takes the parts that were cut off. For example, if the tree
// row contains trees with heights of 20, 15, 10, and 17 metres, and Mirko raises his sawblade to 15 metres,
// the remaining tree heights after cutting will be 15, 15, 10, and 15 metres, respectively, while Mirko
// will take 5 metres off the first tree and 2 metres off the fourth tree (7 metres of wood in total).

// Mirko is ecologically minded, so he doesn‟t want to cut off more wood than necessary.
// That‟s why he wants to set his sawblade as high as possible. Help Mirko find the maximum integer
// height of the sawblade that still allows him to cut off at least M metres of wood.

// Input
// The first line of input contains two space-separated positive integers, N
// (the number of trees, 1 ≤ N ≤ 1 000 000) and M (Mirko‟s required wood amount, 1 ≤ M ≤ 2 000 000 000).

// The second line of input contains N space-separated positive integers less than 1 000 000 000,
// the heights of each tree (in metres). The sum of all heights will exceed M, thus Mirko will
// always be able to obtain the required amount of wood.

// Output
// The first and only line of output must contain the required height setting.

// Example

// Input:
// 4 7
// 20 15 10 17
// Output:
// 15

// Input:
// 5 20
// 4 42 40 26 46
// Output:
// 36
// ___________________________________________________________________________________________

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossibleSolution(vector<long long int>&trees, long long int m, long long int mid)
{
    long long int woodCollected = 0;
    for(int i=0; i<trees.size(); i++)
    {
        if(trees[i] > mid)    // if the tree height is greater than the saw blade height, only then we can collect the wood
        {
            woodCollected = woodCollected + trees[i] - mid; // woodCollected is equal to height of the current tree - saw blade height
        }
    }
    return woodCollected >= m;
}

long long int maxSawBladeHeight(vector<long long int>&trees, long long int m)
{
    long long int start = 0, end, ans = -1;
    end = *max_element(trees.begin(), trees.end());  // returns the max element for getting the tree with the max height (need to search the answer upto that height of saw blade)
    
    while(start <= end)
    {
        long long mid = start + (end-start)/2;
        if(isPossibleSolution(trees, m, mid))
        {
            // store ans
            ans = mid;
            // try increasing the height of saw blade to get closer to the desired wood length, and to minimize wastage
            start = mid+1;
        }
        else
        {
            // solution not found -> need to reduce the height of the saw blade 
            end = mid-1;
        }
    }
    return ans;
}

int main()
{
    long long int n,m;
    cout << "Enter the total number of trees: " << endl;
    cin >> n;
    cout << "Enter Mirko's required wood amount: " << endl;
    cin >> m;

    vector<long long int> trees;

    long long int height;

    cout << "Enter the height of each tree: " << endl;
    for(int i=0; i<n; i++)
    {
        cout << "Height of tree " << (i+1) << ": ";
        cin >> height;
        trees.push_back(height);
    }
    
    cout << "Required height setting of machine: " << maxSawBladeHeight(trees, m) << endl;
    return 0;
}
